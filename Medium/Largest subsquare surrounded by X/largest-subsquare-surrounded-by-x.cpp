//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find the largest subsquare with 'X'
    int largestSubsquare(int n, vector<vector<char>> a) {
        int by_rows[n][n];
        int by_cols[n][n];

        // Calculate the number of 'X' horizontally for each row
        for (int i = 0; i < n; i++) {
            by_rows[i][0] = (a[i][0] == 'X' ? 1 : 0);
            for (int j = 1; j < n; j++) {
                if (a[i][j] == 'X') {
                    by_rows[i][j] = by_rows[i][j - 1] + 1;
                } else {
                    by_rows[i][j] = 0;
                }
            }
        }

        // Calculate the number of 'X' vertically for each column
        for (int j = 0; j < n; j++) {
            by_cols[0][j] = (a[0][j] == 'X' ? 1 : 0);
            for (int i = 1; i < n; i++) {
                if (a[i][j] == 'X') {
                    by_cols[i][j] = by_cols[i - 1][j] + 1;
                } else {
                    by_cols[i][j] = 0;
                }
            }
        }

        int res = 0;
        
        // Iterate over each cell from bottom right to top left
        for (int i = n - 1; i >= res; i--) {
            for (int j = n - 1; j >= res; j--) {
                int side = min(by_rows[i][j], by_cols[i][j]);
                while (side > res) {
                    // Check if a subsquare of size 'side' can be formed
                    if (by_rows[i - side + 1][j] >= side &&
                        by_cols[i][j - side + 1] >= side) {
                        res = side;
                    } else {
                        side--;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends