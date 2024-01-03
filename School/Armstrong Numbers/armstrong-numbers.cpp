//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int answer = 0;
        int num = n;
        for(int i = 0; i < 3; i++){
            int remainder = num%10;
            answer = answer+(remainder*remainder*remainder);
            num = num/10;
        }
        if(answer == n){
            return "Yes";
        }else{
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends