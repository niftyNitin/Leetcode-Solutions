//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        string res = "";
        string count = "", decode = "";
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i]))  res += s[i];
            else if(isdigit(s[i]))   count += s[i];
            else if(s[i] == '[') {
                int open = 1;
                while(open != 0 and i < s.size()-1) {
                    i++;
                    if(s[i] == '[') open++;
                    else if(s[i] == ']')    open--;
                    decode += s[i];
                }
                decode = decodedString(decode);
                int c = stoi(count);
                while(c--)  res += decode;
                count = "", decode = "";
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends