class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")    return 0;
        int h = haystack.size();
        int n = needle.size();
        for(int j = 0; j < h; j++) {
            if(haystack[j] == needle[0]) {
                bool match = true;
                for(int i = 1; i < n; i++){
                    if(haystack[j+i] != needle[i]){
                        match = false;
                        break;
                    }
                }
                if(match)   return j;
            }
        }
        
        return -1;
    }
};