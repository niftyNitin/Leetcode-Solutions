// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        
        int n1 = A.length(), n2 = B.length();
        
        if(n1 != n2)    return -1;
        unordered_map<char, int> m1, m2;
        for(auto i : A) {
            m1[i]++;
        }
        
        for(auto i : B) {
            m2[i]++;
        }
        
        for(auto i : A) {
            if(m2[i] <= 0)   return -1;
            else    m2[i]--;
        }
        
        int i, j = n1-1, c = 0;
        for(i = n1-1; i >= 0; i--) {
            if(A[i] == B[j])    j--;
            else    c++;
        }
        
        return c;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends