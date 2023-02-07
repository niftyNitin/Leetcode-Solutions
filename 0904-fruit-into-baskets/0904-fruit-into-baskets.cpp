class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, sum = 0;
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        while(j < fruits.size()) {
            mp[fruits[j]]++;
            sum++;
            j++; 
            if(mp.size() > 2) {
                while(mp.size() > 2 ) {
                    mp[fruits[i]]--;
                    sum--;
                    if(mp[fruits[i]] == 0)  mp.erase(fruits[i]);
                    i++;   
                }
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};