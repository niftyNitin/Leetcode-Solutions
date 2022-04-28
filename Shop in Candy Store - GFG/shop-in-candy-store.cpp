// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        // Write Your Code here
        int ca[n];
        int cd[n];
        
        for(int i = 0; i < n; i++) {
            ca[i] = candies[i];
            cd[i] = candies[i];
        }
        sort(ca, ca+n);
        sort(cd, cd+n, greater<int>());
        
        int min = 0, max = 0;
        int i = 0, j = n-1;
        while(i <= j) {
            min += ca[i];
            max += cd[i];
            j -= K;
            i++;
        }
        
        return {min, max};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends