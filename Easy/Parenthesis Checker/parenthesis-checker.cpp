//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        vector<char> answer;
        for(int i = 0; i< x.length(); i++){
            if((x[i] == '[') || (x[i] == '(') || (x[i] == '{')){
                if(x[i] == '[') answer.push_back(']');
                else if(x[i] == '(') answer.push_back(')');
                else if(x[i] == '{') answer.push_back('}');
            }else {
                if(answer.empty() || answer.back() != x[i]) {
                return false;
            }
            answer.pop_back();
            }
        }
        return answer.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends