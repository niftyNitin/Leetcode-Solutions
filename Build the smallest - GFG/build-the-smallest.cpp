//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    int n = num.size();
    if(k == n)  return "0";
    string ans = "";
    for(char c : num) {
        while(k and !ans.empty() and c < ans.back()) {
            ans.pop_back();
            k--;
        }
        ans.push_back(c);
    }
    while(k-- and !ans.empty())  ans.pop_back();
    int count = 0;
    for(char c : ans) {
        if(c != '0')
            break;
        else    count++;
    }
    string res = ans.substr(count);
    if(res == "")   return "0";
    return res;
}