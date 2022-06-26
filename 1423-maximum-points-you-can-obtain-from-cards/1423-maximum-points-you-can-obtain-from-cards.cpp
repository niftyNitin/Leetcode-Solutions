class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long n = cardPoints.size();
        long long win_size = n - k;
        long long i = 0, j = 0;
        long long sum = 0;
        int mini= INT_MAX;
        sum = accumulate(cardPoints.begin(), cardPoints.end(), sum);
        int winsum = 0;
        while(j < n) {
			winsum += cardPoints[j++];
			while(j-i > win_size) {
				winsum -= cardPoints[i++];
			}
			if(j-i == win_size) {
				mini = min(mini, winsum);
			}
		}
        return sum-mini;
    }
};