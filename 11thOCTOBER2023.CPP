/*

2251. Number of Flowers in Full Bloom

You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). 
You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

 

Example 1:
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
Example 2:
Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
 

Constraints:
1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= people.length <= 5 * 104
1 <= people[i] <= 109


Binary Seach
Intuition: Blooming flowers = started flowers - ended flowers

Explanation:
Collect start bloom time point array, then sort it.
Collect end bloom time point array, then sort it.

For each time point t in persons:

Binary search the upper bound of t in start, then we find the started flowers.
Binary search the lower bound of t in end, then we find the ended flowers.
Blooming flowers = started flowers - ended flowers


Complexity
Time O(n + nlogn + mlogn + p)
Space O(p)*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int>start;
        vector<int>end;

       for (auto& t : flowers)
            start.push_back(t[0]), end.push_back(t[1]);

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        vector<int>ans;

        for(int i=0;i<people.size();i++){
            int started = upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int ended = lower_bound(end.begin(),end.end(),people[i])-end.begin();
            ans.push_back(started-ended);
        }

        return ans;
    }
};
