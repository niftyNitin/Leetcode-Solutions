class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> vali, valj;
        for(int i = 0; i < values.size(); i++)      vali.push_back(values[i] + i);
        for(int j = 0; j < values.size(); j++)      valj.push_back(values[j] - j);
        for(int j = values.size()-2; j >= 0; j--)   valj[j] = max(valj[j], valj[j+1]);
        
        int res = 0;
        for(int i = 0; i <= vali.size()-2; i++)     res = max(res, vali[i]+valj[i+1]);
        return res;        
    }
};