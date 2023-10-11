/*Intersection of 2 sorted arrays*/

#include <bits/stdc++.h> 

/*Brute force approach

TC-O(n*m)  &  SC-O(m)
vector<int> findArrayIntersection(vector<int> &a1, int n, vector<int> &a2, int m)
{
	// Write your code here.

    vector<int>ans;
	int vis[m]={0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a1[i]==a2[j] && vis[j]==0){
				ans.push_back(a1[i]);
				vis[j]=1;
				break;
			}
			if(a2[j]>a1[i]){
				break;
			}
		}
	}
	return ans;
}

Optimal Approach
TC-O(n+m) & SC-O(1)
*/

vector<int> findArrayIntersection(vector<int> &a1, int n, vector<int> &a2, int m)
{
	int i=0,j=0;
	vector<int>ans;

    while(i<n && j<m){
		if(a1[i]==a2[j]){
			ans.push_back(a1[i]);
			i++;
			j++;
		}
		else if(a1[i]<a2[j]){
			i++;
		}
		else if(a1[i]>a2[j]){
			j++;
		}
	}
	return ans;
}