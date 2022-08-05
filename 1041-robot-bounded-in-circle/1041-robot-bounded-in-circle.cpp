class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        char dir[] = {'N', 'E', 'S', 'W'};
        int curr = 0;
        int z = 360;
        while(z--) {
            for(char c : instructions) {
                if(c == 'L') {
                    curr = curr-1;
                    if(curr == -1)  curr = 3;
                }
                
                else if(c == 'R') {
                    curr++;
                    if(curr == 4)   curr = 0;
                }
                else if(c == 'G') {
                    if(curr == 0)   x++;
                    else if(curr == 1)  y++;
                    else if(curr == 2)  x--;
                    else if(curr == 3)  y--;
                }
            }
            if(x == 0 and y == 0)  return true; 
        }
        return false;
    }
};