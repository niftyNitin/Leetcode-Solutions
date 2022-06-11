// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    double helper(double m[], int n, double start, double end) {
        double ans = -1;
        while(start <= end) {
            double mid = (start + end) / 2;
            double tf = 0.00;
            for(int i = 0; i < n; i++) {
                tf += 1.0 / (mid - m[i]);
            }
            
            if(abs(tf) < 0.0000001) {
                ans = mid; 
                break;
            }
            else if(tf >= 0) {
                ans = mid;
                start = mid + 0.0000001;
            }
            else {
                end= mid - 0.0000001;
            }
        }
        
        return ans;
    }
    
    void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here
        for(int i = 0; i < n; i++) {
            getAnswer[i] = helper(magnets, n, magnets[i], magnets[i+1]);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends