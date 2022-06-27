class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for(auto c : n) {
            int x = c - '0';
            if(x > max) max = x;
        }
        return max;
    }
};