/*1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
You should build the array arr which has the following properties:

maximum_value = -1
maximum_index = -1
search_cost = 0
n = arr.length
for (i = 0; i < n; i++) {
    if (maximum value < arr[i]) {
          maximum_value = arr[i] maximum_index = i search_cost = search_cost + 1
    }
}
return maximum_index;


arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

Example 1:
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.

Example 3:
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
 
Constraints:
1 <= n <= 50
1 <= m <= 100
0 <= k <= n*/

/*Intuition
The problem requires counting the number of arrays of length n, where each element in the array is in the range [1, m], and the array has exactly k distinct elements. We need to find a dynamic programming solution to calculate the count of such arrays.

Approach
Initialize a 3D DP array dp to store the count of valid arrays.
For len = 1 (arrays of length 1), set dp[1][i][1] = 1 for i in [1, m] since there's only one way to create a single-element array with any number from 1 to m.
Use dynamic programming to fill in the dp array for len from 2 to n.
For each len, maxVal, and cost, calculate dp[len][maxVal][cost] by summing up the values of dp[len-1][i][cost-1] for i less than maxVal, and then add dp[len-1][maxVal][cost] * maxVal.
Take modulo MOD after each computation to avoid integer overflow.
Sum up the possibilities for the final state dp[n][1..m][k] to get the answer.
Complexity
Time complexity:
The time complexity of this solution is O(n * m * k), where n, m, and k are the input parameters.

Space complexity:
The space complexity is O(n * m * k) as well, due to the 3D dp array.
*/

class Solution {
public:
    const int MOD = 1000000007;

   int numOfArrays(int n, int m, int k) {
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

    // Initialize base case
    for (int i = 1; i <= m; i++) {
        dp[1][i][1] = 1;
    }

    // DP
    for (int len = 2; len <= n; len++) {
        for (int maxVal = 1; maxVal <= m; maxVal++) {
            for (int cost = 1; cost <= k; cost++) {
                long long ways = dp[len - 1][maxVal][cost];
                ways = (ways * maxVal) % MOD;

                for (int prevMax = 1; prevMax < maxVal; prevMax++) {
                    ways = (ways + dp[len - 1][prevMax][cost - 1]) % MOD;
                }

                dp[len][maxVal][cost] = ways;
            }
        }
    }

    long long result = 0;
    for (int maxVal = 1; maxVal <= m; maxVal++) {
        result = (result + dp[n][maxVal][k]) % MOD;
    }

    return result;
   }
};
