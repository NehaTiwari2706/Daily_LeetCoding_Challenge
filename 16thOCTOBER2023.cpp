/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:
Input: rowIndex = 0
Output: [1]
Example 3:
Input: rowIndex = 1
Output: [1,1]
 
Constraints:
0 <= rowIndex <= 33

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      int n = rowIndex;
        vector<int>res;
        res.push_back(1);
        
        for(int i=1;i<=n;i++){
            int x = (int) (((long long)res.back()*(n-i+1))/i);
            res.push_back(x);
        }
        return res;
    }
};*/

// time - O(n)
// space - O(n)
/*Understand the recursive approach!
chetan_6780
Annual Badge 2022
42
2771
Jan 17, 2022
C
Recursion
What we know?
We Know that, if rowIndex==0 (first row) then we only have {1} in the row.
We also know that first and last element of our row will be 1 always.
We also Know that we can find currentRow[i] by adding previousRow[i-1] and previousRow[i].
Data for recursion,
from above discussion, now we can get 2 important things for recursion
Base Case: if(rowIndex==0) return {1};
Recurrence Relation: currentRow[i] = (previousRow[i-1]+previousRow[i]);
Before reading out please give it a try now.

Algorithm
We can start with currentRow[0] = 1
Now believe that, we get the previous row with recursive call previousRow = getRow(rowIndex-1);
Then fill the remaining elements of current row with recurrence relation
currentRow[i] = (previousRow[i-1]+previousRow[i]);
As we know, last element of row is 1, push 1 in the vector.
Return the current row i.e. currentRow*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      int n = rowIndex;
      // Base Case
      if(n==0) return {1};
      // current row with 1 value in it
      vector<int>currow={1};
      // get the previous row
      vector<int>prevrow=getRow(n-1);
      // Now fill the current row based on previous row
      for(int i=1;i<n;i++){
          currow.push_back(prevrow[i-1]+prevrow[i]);
      }
      // fill the last element of current row
      currow.push_back(1);
      return currow; 
    }
};

/*TC - O(n^2) & SC-O(n^2)*/
