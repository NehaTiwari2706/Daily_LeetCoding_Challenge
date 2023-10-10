/*
2009. Minimum Number of Operations to Make Array Continuous
Solved
Hard
Topics
Companies
Hint
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109



Intuition
The goal is to determine the minimum number of operations needed to make the numbers consecutive. To do this, we want to find the maximum unique element within a certain range, specifically from 'n' to 'n + nums.size() - 1', where 'n' can be any element from the array.

The idea is that if we choose 'n' as an element in the array, we have found the maximum value that doesn't need to be changed to make the numbers consecutive. Therefore, the result can be calculated as 'nums.size() - maximum unique element in the range (n to n + nums.size() - 1)'. This will give us the minimum number of operations required to make the numbers consecutive, as we are subtracting the count of numbers that don't need to be changed from the total count of numbers.

Approach
Sort the Array: The first step is to sort the input nums array in ascending order. This is done using sort(nums.begin(), nums.end()).

Remove Duplicates: After sorting, the code iterates through the sorted array to remove duplicate elements while maintaining a modified length in the variable l. This ensures that the array contains only unique elements in ascending order.

Choose a Reference Number 'n': The algorithm selects a reference number 'n' from the modified array. This 'n' represents the starting point for our consecutive sequence. The code starts with 'n' as the first element of the array.

Find the Maximum Consecutive Sequence: The code iterates through the modified array, keeping track of the maximum consecutive sequence that includes 'n'. It calculates the count of consecutive elements by comparing the difference between the current element and 'n' and incrementing the count until the difference exceeds the maximum possible difference 'n'. The maximum count is stored in the variable maxi.

Calculate the Minimum Operations: The minimum number of operations needed to make the numbers consecutive is determined by subtracting the maximum count maxi from the total number of unique elements in the modified array, which is represented by l.

Return the Result: Finally, the code returns the minimum number of operations as the result.

This approach ensures that we find the reference number 'n' that, when used as the starting point, maximizes the consecutive sequence within the array. Subtracting this maximum count from the total unique elements gives us the minimum number of operations required to make the numbers consecutive.

Complexity
Here are the time and space complexities for the given code:

Time Complexity:

Sorting the nums array takes O(n log n) time, where 'n' is the number of elements in the array.
Removing duplicates while iterating through the sorted array takes O(n) time, where 'n' is the number of elements in the array.
The consecutive sequence calculation also takes O(n) time in the worst case because for each element, we perform a while loop that goes through a portion of the array.
The overall time complexity is dominated by the sorting step, so the total time complexity is O(n log n).
Space Complexity:

The code modifies the input nums array in place, so there is no additional space used for storing a separate copy of the array.
The space used for variables like maxi, count, n, l, and loop indices is constant and not dependent on the size of the input array.
Therefore, the space complexity of the code is O(1), which means it uses a constant amount of extra space.
Code
*/class Solution {
public:
    int minOperations(vector<int>& nums){
        
        int s=nums.size();
        sort(nums.begin(),nums.end());
        
        int uniquelen = 1;

        for(int i=1;i<s;i++){
            if(nums[i]!=nums[i-1]){
                nums[uniquelen++] = nums[i];
            }
        }

        int ans = 0;
        int j = 0;
        int maxi = 0;
        for(int i=0;i<uniquelen; i++){
             while(j < uniquelen && nums[j]-nums[i] <= s-1){
                 j++;
                 ans++;
             }
             maxi = max(ans,maxi);
             ans--;
        }

        return s-maxi;
    }
};
