/* LARGEST ELEMENT IS AN ARRAY 


arr[]={3,2,1,5,2}
o/p= 5

Brute soln-

sort the array and return the arr[n-1] element.
TC- O(nlogn) SC- O(1)

no better soltion for this question

optimal solution- 
TC- O(n) SC- O(1)
 */


//Brute force approach

#include <bits/stdc++.h> 
int largestElement(vector<int>&arr, int n) {
    // Write your code here.
    sort(arr,arr+n);
    cout<<arr[n-1];
}

//Optimal Solution

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest= arr[i];
        }
    }
    return largest;
}
