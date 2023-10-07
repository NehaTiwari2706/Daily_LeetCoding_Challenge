/*Check if an Array is Sorted

Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.


Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.

Complexity Analysis
Time Complexity: O(N)
Space Complexity: O(1)
*/

int isSorted(int n, vector<int> a) {
    // Write your code here.

    for(int i=1;i<n;i++){
      if (a[i] < a[i - 1]) {
        return 0;
      }
    }
    return 1;
}


// 1752. Check if Array Is Sorted and Rotated

/*Approach:
if array is sorted and rotated then, there is only 1 break point where (nums[x] > nums[x+1]),
if array is only sorted then, there is 0 break point.

Time complexity: O(N)
Space complexity: O(1)*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int size=nums.size();
        int count = 0;
        for(int i=0;i<size;i++){
            if(nums[i]>nums[(i+1)%size]){
                 count++;
            }
        }
        return (count<=1);
    }
};