class Solution {
public:
    string addStrings(string nums1, string nums2) {
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        
        int c = 0;
        string ans = "";
        int l = max(nums1.size(), nums2.size());
        for(int i = 0; i < l; i++) {
            int a, b;
            if(i < nums1.size())    a = nums1[i] - '0';
            else    a = 0;
            
            if(i < nums2.size())    b = nums2[i] - '0';
            else    b = 0;
            
            int x = a + b + c;
            ans += (x % 10) + '0';
            c = x / 10;
        }
        if(c)   ans += c + '0';
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};