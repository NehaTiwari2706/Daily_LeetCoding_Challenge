/*Remove Duplicates in-place from Sorted Array
Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.
Example 1: 

Input: arr[1,1,2,2,2,3,3]

Output: arr[1,2,3,_,_,_,_]

Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2: 

Input: arr[1,1,1,2,2,3,3,3,3,4,4]

Output: arr[1,2,3,4,_,_,_,_,_,_,_]

Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.

Solution 1: Brute Force

Approach: 

Declare a HashSet.
Run a for loop from starting to the end.
Put every element of the array in the set.
Store size of the set in a variable K.
Now put all elements of the set in the array from the starting of the array.
Return K.

Time complexity: O(n*log(n))+O(n)
Space Complexity: O(n) 
*/

#include <bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

    set < int > set;
	for(int i=0;i<n;i++){
		set.insert(arr[i]);
	}

    /*
    int index=0;

	for(auto it:set){
		arr[index++]=it;
	}
    */  
    int index=set.size();
	return index;
}

/*Solution 2: (Optimal Approach) Two pointers
Take a variable i as 0;
Use a for loop by using a variable ‘j’ from 1 to length of the array.
If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
 After completion of the loop return i+1, i.e size of the array of unique elements.

Time Complexity: O(N)
Space Complexity: O(1)
*/

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

    int i=0;
	for(int j=1;j<n;j++){
		if(arr[j]!=arr[i]){
			arr[i+1]=arr[j];
			i++;
		}
	}
	return (i+1);
}