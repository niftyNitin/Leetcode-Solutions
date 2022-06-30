class Solution {
public:
    bool check(vector<int> position, int n, int m, long long target){
        long long pos = position[0];
        long long count = 1;
        for(int i = 0; i < n; i++){
            if(position[i] - pos >= target){
                count++;
                pos = position[i];
            }
            if(count == m)  return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        long long low = 1;
        long long high = position[n-1] - position[0];
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high) >> 1;
            if(check(position, n, m, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};