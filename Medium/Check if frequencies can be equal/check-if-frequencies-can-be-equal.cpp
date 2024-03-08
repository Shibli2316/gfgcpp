//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    // Count the frequency distribution
    unordered_map<int, int> countFreq;
    for (auto& entry : freq) {
        countFreq[entry.second]++;
    }

    // If there is only one frequency, the string already satisfies the condition
    if (countFreq.size() == 1) {
        return true;
    }

    // If there are exactly two frequencies and one of them has a count of 1,
    // it is possible to remove a character to make the frequencies equal
    if (countFreq.size() == 2) {
        auto it = countFreq.begin();
        int freq1 = it->first;
        int countFreq1 = it->second;
        it++;
        int freq2 = it->first;
        int countFreq2 = it->second;

        if ((countFreq1 == 1 && (freq1 == 1 || freq1 - freq2 == 1)) ||
            (countFreq2 == 1 && (freq2 == 1 || freq2 - freq1 == 1))) {
            return true;
        }
    }

    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends