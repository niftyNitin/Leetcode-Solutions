class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i : tasks)  mp[i]++;
        
        int count = 0;
        for(auto i : mp) {
            int fr = i.second;
            if(fr < 2)    return -1;
            else {
                if(fr % 3 == 0)
                    count += (fr/3);
                else if(fr % 3 == 1) {
                    count += 2;
                    fr -= 4;
                    count += (fr/3);
                }
                else {
                    count += 1;
                    fr -= 2;
                    count += (fr/3);
                }
            }
        }
        
        return count;        
    }
};

/*
3 - 1-three
4 - 2-two
5 - 1-three, 1-two
6 - 2-three
7 - 1-three, 2-two
8 - 2-three, 1-two
9 - 3-three
10- 2-three, 2-two
*/