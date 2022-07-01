class Solution {
public:
    vector<long long> dp;
    int costClimb(int n, vector<int> cost) {
        if(n >= cost.size())     return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = min(costClimb(n+1, cost), costClimb(n+2, cost)) + cost[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(1001, -1);
        return min(costClimb(0, cost), costClimb(1, cost));
    }
};