/*501. Find Mode in Binary Search Tree

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
Solution: 🚀
The solution for finding the mode(s) in a binary search tree (BST) with duplicates. The mode is the most frequently occurred element in the BST. Your solution uses an in-order traversal of the BST to collect all the values in the tree, and then it uses the collections.Counter class to count the frequency of each value. Finally, it finds the value(s) with the maximum frequency and returns them as the mode.
Here's a detailed explanation of algorithm:
1.Define a list self.inorderr to store the values obtained during an in-order traversal of the BST.
2. Define an inorder function that performs an in-order traversal of the BST. It appends the values to self.inorderr as it visits each node.
3. Call the inorder function with the root of the BST to populate self.inorderr with all the values.
4. Use collections.Counter to count the frequency of each value in self.inorderr, creating a dictionary where keys are values and values are their frequencies.
5. Find the maximum frequency (the mode) among the counted values using max(freq.values()).
6. Create a list comprehension that iterates through the keys (values) in freq and selects those keys where the frequency matches the maximum frequency found in step 5. This will give you all the mode(s) in the BST.
7. Return the list of mode(s).
Time Complexity:
The in-order traversal of the BST has a time complexity of O(n), where n is the number of nodes in the tree.
Counting the frequency of each value using collections.Counter also has a time complexity of O(n), as it iterates through the list of values.
Finding the maximum frequency in the frequency dictionary has a time complexity of O(n), as it iterates through the dictionary.
Overall, the time complexity of the algorithm is O(n).
Space Complexity:
The self.inorderr list is used to store all the values in the BST, which has a space complexity of O(n) since it can potentially store all the values in the tree.
The freq dictionary also has a space complexity of O(n) in the worst case, as it can store the frequency of all unique values in the tree.
Overall, the space complexity of the algorithm is O(n).
Code*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>pre;
        preorder(root,pre);
        unordered_map<int,int>freq;
        int maxx=0;

        for(int val:pre){
            freq[val]++;
            maxx = max(maxx,freq[val]);
        }

        vector<int>result;
        for(const auto& it:freq){
            if(maxx==it.second){
                result.push_back(it.first);
            }
        }
        return result;
    }

    void preorder(TreeNode* root,vector<int>&pre){

        if(root==NULL){
            return;
        }

        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
};
