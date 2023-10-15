/*
1269. Number of Ways to Stay in the Same Place After Some Steps

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8
 

Constraints:

1 <= steps <= 500
1 <= arrLen <= 106*/


//Recursion ........TC-O(3^steps) & SC-O(steps!)
/*class Solution {
public:
    const int MOD = 1e9+7;
    int f(int index,int remstep,int arrLen){
        
        //base case
        if(remstep==0){
            if(index==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(index<0 || index>=arrLen || index > remstep){
            return 0;
        }

        int right = f(index+1,remstep-1,arrLen)%MOD;
        int left = f(index-1,remstep-1,arrLen)%MOD;
        int stay = f(index,remstep-1,arrLen)%MOD;

        int ways = ((right + left)+stay)%MOD;

        return ways;
    }

    int numWays(int steps, int arrLen) {
        
        return f(0,steps,arrLen);
    }
};*/

//Recursion + Memoization 
/* Appraoch 2 : Recursion + Memo 
1. Try all possibilities
2. Memoize repeating subproblems
Time : O(n^2)       
Space :O(n^2)       // n = steps
*/
class Solution {
public:
    const int MOD = 1e9+7;
    int f(int index,int remstep,int arrLen,vector<vector<int>>&dp){
        
        //base case
        // 1. No steps remaining
        if(remstep==0){
            if(index==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        // 2. Outside boundary or index > remSteps (we can't reach 0 with remSteps)
        if(index<0 || index>=arrLen || index > remstep){
            return 0;
        }
        // already calcualted
        if(dp[index][remstep]!=-1){
            return dp[index][remstep];
        }

        // try all moves
        int right = f(index+1,remstep-1,arrLen,dp)%MOD;
        int left = f(index-1,remstep-1,arrLen,dp)%MOD;
        int stay = f(index,remstep-1,arrLen,dp)%MOD;

        int ways = ((right + left)%MOD+stay)%MOD;

        return dp[index][remstep]=ways;
    }

    int numWays(int steps, int arrLen) {

        vector<vector<int>>dp(steps+1,vector<int>(steps+1,-1));
        // index, remaining Steps, arrLen
        return f(0,steps,arrLen,dp);
    }
};

