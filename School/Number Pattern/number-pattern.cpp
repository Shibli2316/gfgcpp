//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<string> numberPattern(int N)
    {
        vector<string> answer;
        string temp;
        for(int i = 0; i <N; i++){
            for(int j = 1; j <=i+1; j++){
                temp+=to_string(j);
            }
            for(int k = i; k > 0; k--){
                temp+=to_string(k);
            }
            answer.push_back(temp);
            temp = "";
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
       
        Solution ob;
        vector<string> res = ob.numberPattern(N);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    
    }
    return 0;
}
// } Driver Code Ends