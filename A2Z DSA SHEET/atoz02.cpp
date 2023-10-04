/*
Find Second Smallest and Second Largest Element in an array

Problem Statement:
 Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.
*/

/*BRUTE FORCE APPROACH

Sort the array in ascending order
The element present at the second index is the second smallest element
The element present at the second index from the end is the second largest element

TC- O(nlogn) SC-O(1)

Better Approach:

Find the smallest and largest element in the array in a single traversal
After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
Similarly, we would find the largest element which is just smaller than the largest element we just found
Indeed, this is our second smallest and second largest element.

Optimal Approach

Second Smallest Algo:
If the current element is smaller than ‘small’, then we update second_small and small variables
Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
Once we traverse the entire array, we would find the second smallest element in the variable second_small.

Second Largest Algo:
If the current element is larger than ‘large’ then update second_large and large variables
Else if the current element is larger than ‘second_large’ then we update the variable second_large.
Once we traverse the entire array, we would find the second largest element in the variable second_large.
*/


//Brute Force Approach
// TC- O(nlogn + n) SC- O(n)

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    sort(a.begin(),a.end());
    int largest=a[n-1];
    
    vector<int> secondlargest={-1};
    for(int j=n-2;j>=0;j--){
        if(a[j]!= largest){
            secondlargest=a[j];
            break;
        }
    }
    return secondlargest;
}

//Better Approach
// TC- O(2n) SC- O(1)

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.

    int largest=a[0];

    for(int i=0;i<n;i++){
        if(a[i]>largest){
            largest=a[i];
        }
    }
    
    vector<int>slargest={-1};
    for(int j=0;j<n;j++){
        if(a[j]>slargest && a[j]!=largest){
            slargest=a[j];
        }
    }
    return slargest;
}

//Optimal Solution
// TC - O(n) SC- O(1)


vector<int>getSecondOrderElements(int n, vector<int>a) {
    
    int small = INT_MAX;
    int second_small = INT_MAX;

    int i;
    for(i = 0; i < n; i++) 
    {
       if(a[i] < small)
       {
          second_small = small;
          small = a[i];
       }
       else if(a[i] < second_small && a[i] != small)
       {
          second_small = a[i];
       }
    }

    int large=INT_MIN,second_large=INT_MIN;
    int j;
    for (j = 0; j < n; j++) 
    {
        if (a[j] > large) 
        {
            second_large = large;
            large = a[j];
        }
 
        else if (a[j] > second_large && a[j] != large) 
        {
            second_large = a[j];
        }
    }
    return { second_large, second_small };
}












