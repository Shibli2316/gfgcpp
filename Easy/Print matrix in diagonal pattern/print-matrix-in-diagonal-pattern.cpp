//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        // 00 - 01 - 10 - 20 - 11 - 02 - 12 - 21 - 22
    vector<int> result;
    int n = mat.size();

    // Traverse the diagonals
    for (int i = 0; i < 2 * n - 1; ++i) {
        int start_col = max(0, i - n + 1);
        int count = min(i + 1, 2 * n - 1 - i);

        if (i % 2 == 0) {
            for (int j = 0; j < count; ++j) {
                result.push_back(mat[min(n - 1, i) - j][start_col + j]);
            }
        } else {
            for (int j = 0; j < count; ++j) {
                result.push_back(mat[start_col + j][min(n - 1, i) - j]);
            }
        }
    }

    return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends