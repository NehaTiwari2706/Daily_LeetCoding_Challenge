
/*
746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999*/

//Brute force approach //RECURSiON METHOD  
/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost,n-1), solve(cost,n-2));
        return ans;
    }

    int solve(vector<int>& cost,int n){
        
        if(n==0){
            return cost[0];
        }

        if(n==1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost,n-1), solve(cost,n-2));
        return ans;
    }
};*/

//Optimal solution //DP Memoization // TC-O(n) SC-O(n+n)

/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);

        int ans = min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        return ans;
    }

    int solve(vector<int>& cost,int n, vector<int>&dp){
        
        if(n==0){
            return cost[0];
        }

        if(n==1){
            return cost[1];
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = cost[n] + min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        return dp[n];
    }
};*/

//Tabulation //Bottom Up DP // TC-O(n) SC-O(n)

/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
    
        return solve(cost,n);
    }

    int solve(vector<int>& cost,int n){
        //1. creation of dp array
        vector<int>dp(n+1);
        //2. base case analyze
        dp[0] = cost[0];
        dp[1] = cost[1];

        //3rd step
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};*/
//Tabulation //Bottom Up DP // TC-O(n) SC-O(1) only using variable

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
    
        return solve(cost,n);
    }

    int solve(vector<int>& cost,int n){
       
        int prev1 = cost[0];
        int prev2 = cost[1];

        for(int i=2;i<n;i++){
            int curr=cost[i] + min(prev1,prev2);
            prev1=prev2;
            prev2=curr;
        }
        return  min(prev1,prev2);
    }
};


