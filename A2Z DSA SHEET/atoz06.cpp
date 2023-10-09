/* Rotate array by K elements

Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples:

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.

Solution :

Approach 1: Using a temp array 

For Rotating the Elements (to right)
Step 1: Copy the last k elements into the temp array.

Step 2: Shift n-k elements from the beginning by k position to the right

Step 3: Copy the elements into the main array from the temp array.

Code: */

class Solution {
public:
//BRUTE FORCE APPROACH   
void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if (n == 0)
           return;
        k = k % n;
        if (k > n)
            return;
        
        int temp[k+1];

        for(int i=n-k;i<n;i++){
            temp[i-n+k]=nums[i];
        }

        for(int i=n-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        } 
    }
};

//Output:

//After Rotating the elements to right
6 7 1 2 3 4 5

/*Time Complexity: O(n)
Space Complexity: O(k) since k array element needs to be stored in temp array*/


/*Approach 2: Using ” Reversal Algorithm “

Approach:

For Rotating Elements( to right)
Step 1: Reverse the last k elements of the array

Step 2: Reverse the first n-k elements of the array.

Step 3: Reverse the whole array.

For Eg , arr[]={1,2,3,4,5,6,7} , k=2

ANALYSIS :-
Time Complexity :- BigO(2N)
Space Complexity :- BigO(1) */

class Solution {
public:
//OPTIMAL APPROACH   
void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if (n == 0)
           return;
        k = k % n;
        if (k > n)
            return;

        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);    
}     

void reverse(vector<int>& nums, int s,int e){
        while(s<e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            s++;
            e--;
        }
    }  
};    


/*For Rotating the Elements (to left)
Brute force
Step 1: Copy the first k elements into the temp array.

Step 2: Shift n-k elements from last by k position to the left

Step 3: Copy the elements into the main array from the temp array.

Code:*/

vector<int> rotateArray(vector<int>nums, int k) {
    // Write your code here.
    int n = nums.size();
        k=k%n;
        int temp[k];

        for(int i=0;i<k;i++){
            temp[i]=nums[i];
        }

        for(int i=k;i<n;i++){
            nums[i-k]=nums[i];
        }
        
        for(int i=n-k;i<n;i++){
            nums[i]=temp[i-(n-k)];
        }

        return nums;
}

// TC - O(k)+O(n-k)+O(k)=O(n+k) & SC-O(k) since k array element needs to be stored in temp array
/*Output:
After Rotating the elements to left 3 4 5 6 7 1 2 */


//Using ” Reversal Algorithm (for left shift)""
//OPtimal Solution

void reverse(vector<int>&nums,int s,int e){
        while(s<=e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            s++;
            e--;
        }
}    
vector<int> rotateArray(vector<int>&nums, int k) {

    int n=nums.size();

    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
    reverse(nums,0,n-1);

    return nums;
}

//TC-O(k+n-k+n)=O(2n) & SC-O(1)

 




