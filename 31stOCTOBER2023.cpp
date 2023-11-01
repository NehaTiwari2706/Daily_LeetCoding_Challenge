/*2433. Find The Original Array of Prefix Xor

You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.

 

Example 1:

Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
Example 2:

Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.
 

Constraints:

1 <= pref.length <= 105
0 <= pref[i] <= 106

Intuition
The intuition behind this code is to perform a sequence of XOR operations on the input vector pref to generate the output vector ans. Each element of the output vector is formed by XORing the corresponding element in the input vector with the previous element in the input vector.

Approach
The loop starts from i = 1 and continues until i is less than the size of pref.
In each iteration, it calculates the XOR of the current element pref[i-1] and the previous element pref[i-1], and appends the result to ans.
Finally, it returns the ans vector as the result.
Complexity
Time complexity: O(n), where n is the size of the pref vector,
Space complexity: The space complexity is O(n) as well because it creates a new vector ans of the same size as pref
Code
class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n = pref.size() ;
        vector<int> ans ;
        
        ans.push_back(pref[0]) ;

        for(int i = 1 ; i < n ; i++)
           ans.push_back(pref[i-1]^pref[i]) ;

        return ans ;   
    }
};

Method: Time and Space Optimization(accepted)
Intuition
It initializes n as the size of the input vector pref.
The code then iterates through the elements of pref in reverse order (from the last element to the second element).
In each iteration, it calculates the XOR of the current element pref[i] with the previous element pref[i-1] and updates
the current element with the result.
The code returns the modified pref vector after all iterations.
Complexity
Time complexity: O(n)
Space complexity: O(1)
Code*/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n = pref.size() ;
        
        for(int i = n-1 ; i > 0 ; i--)
           pref[i] = pref[i]^pref[i-1] ;

        return pref ;   
    }
};
