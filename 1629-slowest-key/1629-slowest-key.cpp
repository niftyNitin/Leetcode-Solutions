class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxx = 0;
        char slowest = keysPressed[0];
        for(int i = 0; i < releaseTimes.size(); i++) {
            int rtime;
            if(i == 0)
                rtime = releaseTimes[0];
            else
                rtime = releaseTimes[i] - releaseTimes[i-1];
            
            if(rtime > maxx) {
                maxx = rtime;
                slowest = keysPressed[i];
            }
            
            if(rtime == maxx and keysPressed[i] > slowest)
                slowest = keysPressed[i];
        }
        return slowest;
    }
};