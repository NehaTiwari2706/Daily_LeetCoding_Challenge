/*
1361. Validate Binary Tree Nodes

You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], 
return true if and only if all the given nodes form exactly one valid binary tree.
If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

Example 1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false

Constraints:
n == leftChild.length == rightChild.length
1 <= n <= 104
-1 <= leftChild[i], rightChild[i] <= n - 1

Intuition
 what is the structure of a binary tree❓

Simply:
Each node has only one parent (Except for the root).
There is only one root.
Each node has at most 2 children (leaf nodes have no children).
There is no Cycle.🚴‍♀️


To start, it's worth noting that a valid binary tree exhibits specific characteristics. Primarily, there should be precisely one node with an in-degree of 0, which serves as the root, while all remaining nodes must maintain an in-degree of 1. Additionally, it's essential that every node is accessible from the root node. These insights establish the foundation for our strategy in addressing this issue.

Approach
In-Degree Computation:
We commence by initializing an 'indegree' array to monitor the in-degree of each node. To achieve this, we iterate through the 'leftChild' and 'rightChild' arrays, incrementing the in-degree of the corresponding nodes.

Root Node Determination:
Next, we traverse the 'indegree' array to pinpoint the root node (i.e., a node with an in-degree of 0). If we encounter multiple nodes with an in-degree of 0, or if no such node is found, we return 'False' as these conditions signify that the nodes do not constitute a valid binary tree.

Breadth-First Search (BFS):
With the root node identified, we proceed to perform a breadth-first search (BFS) traversal, commencing from the root and visiting all nodes in the tree. This traversal is managed using a queue, and we employ a 'visited' array to keep tabs on nodes already visited. If we encounter a node that has already been visited, we conclude with 'False' since this implies the existence of a cycle within the graph, which contravenes the tree structure.

Validation:
In the final step, we ensure the thorough visitation of all nodes by comparing the sum of the 'visited' array with 'n,' the total number of nodes. If these values match, it signifies that all nodes were reachable from the root, and we return 'True.' In the event of any disparity, 'False' is the outcome.

Complexity
- Time complexity:
In-degree calculation: O(n)
Root identification: O(n)
BFS traversal: O(n)
Validation: O(n)
Overall time complexity: O(n)

- Space complexity:
The space complexity is dominated by the indegree and visited arrays, each of size O(n), and the queue, which in the worst case can also be of size O(n).
Overall space complexity: O(n)
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftc, vector<int>& rightc) {
    
        vector<int>indegree(n,0);

        for(int i=0;i<n;i++){
            int left = leftc[i];
            int right = rightc[i];
            if(left!= -1){
                indegree[left]++;
            }
            if(right!= -1){
                indegree[right]++;
            }
        }

        int rootnode = -1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(rootnode == -1){
                    rootnode = i;
                }
                else{
                    return false;
                }
            }
        }

        if(rootnode ==-1){
            return false;
        }
        
        vector<int>seen(n,0);
        queue<int>q;
        q.push(rootnode);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(seen[node]){
                return false;
            }
            seen[node]=1;
            if(leftc[node]!=-1){
                q.push(leftc[node]);
            }
            if(rightc[node]!=-1){
                q.push(rightc[node]);
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            if(seen[i]==1){
               sum++;
            }   
        }


       return n==sum;
    }
};
