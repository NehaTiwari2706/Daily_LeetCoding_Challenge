/*
343. Integer Break

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Constraints:
2 <= n <= 58
*/

//Recursive Solution 
class Solution {
public:
    int integerBreak(int n) {
        int ans=0,firstnum,secondnum,product=1;

        if(n==1){
          return 1;
        }
        else{
          ans = 1*(n-1);
          int i=1;
          while(i<=n){
              firstnum = i;
              secondnum = n-i;
              product = firstnum*max(secondnum,integerBreak(secondnum));
              if(product>ans){
                  ans=product;
              }
              i=i+1;
          }  
        }
    return ans;
    }
};

//Dynamic Programming Solution
class Solution {
public:
    int integerBreak(int n) {
        
        vector<int>dp(60);

        dp[1]=1;
        dp[2]=1;
        dp[3]=2;

        for(int i=4;i<=n;i++){
            int num=i;
            for(int j=1;j<=num;j++){
                int x=j;
                int y=num-x;

                dp[i]=max({dp[i],x*dp[y],dp[x]*y,x*y,dp[x]*dp[y]});
            }
        }
        return dp[n];
    }
};
