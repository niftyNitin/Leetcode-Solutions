// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        // code here
        for(int i = 1; i < s.length(); i++) {
            string part1 = s.substr(0, i);
            int num1 = stoi(part1);
            if(num1 % a != 0)
                continue;
            
            string part2 = s.substr(i);
            int num2 = stoi(part2);
            if(num2 % b == 0)
                return part1 + " " + part2;
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends