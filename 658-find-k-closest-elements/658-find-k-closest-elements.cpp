class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0, end = arr.size()-1;
        while(start < end and end-start+1 != k) {
            int diff1 = abs(x - arr[start]);
            int diff2 = abs(x - arr[end]);
            
            if(diff1 > diff2)  start++;
            else end--;
        }
        
        vector<int> ans;
        for(int i = start; i <= end; i++)
            ans.push_back(arr[i]);
        
        return ans;
    }
};