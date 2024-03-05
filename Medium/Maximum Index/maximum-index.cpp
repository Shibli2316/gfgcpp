//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        std::vector<int> maxRight(n);
    maxRight[n - 1] = n - 1;

    // Pre-compute the index of the maximum element to the right of each element
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[maxRight[i + 1]]) {
            maxRight[i] = i;
        } else {
            maxRight[i] = maxRight[i + 1];
        }
    }

    int maxDiff = 0;

    // Iterate through the array and find the maximum difference
    for (int i = 0, j = 0; j < n;) {
        if (a[i] <= a[maxRight[j]]) {
            maxDiff = std::max(maxDiff, j - i);
            ++j;
        } else {
            ++i;
        }
    }

    return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends