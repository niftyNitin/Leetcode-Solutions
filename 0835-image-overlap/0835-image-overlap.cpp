class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>, int> mp;
        for(int i = 0; i < img1.size(); i++) {
            for(int j = 0; j < img1[0].size(); j++) {
                if(img1[i][j] == 1) {
                    for(int m = 0; m < img2.size(); m++) {
                        for(int n = 0; n < img2[0].size(); n++) {
                            if(img2[m][n] == 1) {
                                mp[{m-i,n-j}]++;
                            }
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(auto i : mp) {
            res = max(res, i.second);
        }
        
        return res;
    }
};