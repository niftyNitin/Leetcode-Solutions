//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0;
    long long total = N*M - 1;
    int mod = 1e9+7;
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {-2,-1,1,2,-2,-1,1,2};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int count = 0;
            for(int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 or y < 0 or x >= N or y >= M)  continue;
                count++;
            }
            ans += (total - count);
            ans %= mod;
        }
    }
    return ans;
}