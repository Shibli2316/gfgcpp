//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int clockSum(int num1, int num2){
        // code here
        int answer = num1+num2;
        if(answer<12){
            return answer;
        }
        return answer%12;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int num1, num2;
        cin>>num1>>num2;
        
        Solution ob;
        cout<<ob.clockSum(num1, num2)<<endl;
    }
    return 0;
}
// } Driver Code Ends