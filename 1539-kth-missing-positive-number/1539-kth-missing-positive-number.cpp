class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = 1;
        int c = 1;
        for(int i = 0; i < arr.size();) {
            if(arr[i] == x) x++, i++;
            else {
                if(c == k)  return x;
                c++;
                x++;
            }
        }
        
        while(c != k)   c++, x++;
        return x;
    }
};