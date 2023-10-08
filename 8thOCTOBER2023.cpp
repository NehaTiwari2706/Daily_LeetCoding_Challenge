/*Approach
We need to find max dot product possible given two arrays nums1 and nums2.

We need to ensure that while finding the dot product, the relative order of the numbers in respective arrays is same.

We can achieve this using dynamic programming. But why?

This is because, at any point when we find the dot product of two numbers we need to add the maximum dot product till previous element to our current answer. This we do till all elements of both the arrays are accounted for.

The approach-

Make a 2d dp array of size m+1 x n+1, with all values initialized to INT_MIN.
Now, start two for loops from i = 1 to i = m and from j = 1 to j = n.
prod = nums1[i-1] * nums2[j-1] represents the dot product of the current two numbers. i-1 and j-1 because nums1 and nums2 are 0 indexed.
Now think of how you will find the maximum dot product till ith element of nums1 and jth element of nums2.
We can do this by adding the current dot product to the dot product till [i-1][j-1], but if [i-1][j-1] is < 0 then our answer will be reduced, so we take max(dp[i-1][j-1], 0). This ensures that answer for [i][j] stays at least the prod i.e current dot product.
But what if the prod is negative? To counter this we take also take the max of dp[i-1][j] and dp[i][j-1]. This means when our prod is negative, we will take into account the maximum of dot products till (nums1[0 to i-1] & nums2[0 to j]) and (nums1[0 to i] & nums2[0 to j - 1])
At last return dp[m][n] which tells maximum dot product till last element of nums1 and last element of nums2.

TC-O(n*m)  SC-O(n*m)*/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MIN));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int prod=nums1[i-1]*nums2[j-1];

                dp[i][j]=max({ prod+max(dp[i-1][j-1],0), dp[i][j-1], dp[i-1][j] });
            }
        }
        return dp[n][m];
    }
};
