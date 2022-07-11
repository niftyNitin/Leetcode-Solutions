// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a, a+n);
    if(a[0] == a[n-1] and n%2 == 0)  return {-1};
    vector<int> res;
    int b = 0, e = n-1;
    while(b < e) {
        res.push_back(a[e]);
        res.push_back(a[b]);
        b++;
        e--;
    }
    if(n&1) res.push_back(a[b]);
    return res;
}
