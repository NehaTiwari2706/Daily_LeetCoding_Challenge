/*
 Move Zeroes to end

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.


Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
Follow up: Could you minimize the total number of operations done?


BRUTE FORCE APPROACH
TC- O(n+m+n-m)=O(2n) & SC-(m)
class Solution {
public:
    void moveZeroes(vector<int>& a) {
       
        vector<int>temp;
        int n=a.size();

        for(int i=0;i<n;i++){
            if(a[i]!=0){
                temp.push_back(a[i]);
            }
        }
        
        int m=temp.size();
        for(int i=0;i<m;i++){
            a[i]=temp[i];
        }   

        for(int k=m;k<n;k++){
            a[k]=0;
        } 
    }
}; 

Optimal Solution 
TC-O(x+(n-x))=O(n) & SC-O(1) no extra space*/

class Solution {
public:
    void moveZeroes(vector<int>& a) {

    int j=-1;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }

    if(j==-1){
        return ;
    }

    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }

    return ;
}
};

