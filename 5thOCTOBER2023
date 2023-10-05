/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
 
Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
Follow up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count1 = 0,count2 = 0, nums1=-1,nums2=-1;
        for(int i=0;i<nums.size();i++){

            if(nums[i]==nums1){
                count1++;
            }
            else if(nums[i]==nums2){
                count2++;
            }
            else if(count1==0){
                nums1=nums[i];
                count1=1;
            }
            else if(count2==0){
                nums2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }

    vector<int>ans;
    count1=count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums1==nums[i]){
            count1++;
        }
        else if(nums2==nums[i]){
            count2++;
        }
    }

    if(count1 > nums.size()/3){
        ans.push_back(nums1);
    }
    if(count2 > nums.size()/3){
        ans.push_back(nums2);
    }
    return ans;
    }
};

//TC - 0(n + n) and SC-O(1)
