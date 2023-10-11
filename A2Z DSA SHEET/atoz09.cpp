/*Union of Two Sorted Arrays / Merge 2 Sorted Array
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.*/


//Brute force approach
/*
TC-O(2(n+m)   SC-O(n+m)
#include<bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n = a.size();
    int m = b.size();

    set<int> st;

    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(b[i]);
    }
    
    vector < int >ans;

    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
}*/

//Optimal solution      TC-O(n+m) SC-O(n+m)
#include<bits/stdc++.h>

vector < int > sortedArray(vector < int > arr1, vector < int > arr2) {

    int n = arr1.size();
    int m = arr2.size();
    
    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector

    while (i < n && j < m) {
       if (arr1[i] <= arr2[j]) // Case 1 and 2
      {
        if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
        i++;
       } else // case 3
       {
        if (Union.size() == 0 || Union.back() != arr2[j])
                 Union.push_back(arr2[j]);
        j++;
       }
    }
    while (i < n) // IF any element left in arr1
    {
       if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
     i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
             Union.push_back(arr2[j]);
    j++;
    }
    return Union;
}