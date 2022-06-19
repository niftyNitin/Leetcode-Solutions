// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long long C(int n, int r) {
        if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
        long long ans = 1;
        int i;
    
        for(i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
    
        return ans;
    }
    long posIntSol(string s)
    {
        int i = 0;
        int count = 0;
        while(i < s.size() && s[i] != '='){
            if(s[i] == '+'){
                count++;
            }
            i++;
        }
        i++;
        long long value = 0;
        long long pr = 1;
        while(i < s.size()){
            value = pr*value + (s[i] - '0');
            pr *= 10;
            i++;
        }
        count++;
        value -= count;
        if(value < 0){
            return 0;
        }
        if(value == 0){
            return 1;
        }
        return C(value + count - 1, count - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends