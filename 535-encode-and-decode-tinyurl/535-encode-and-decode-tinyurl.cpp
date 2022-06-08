class Solution {
public:
    string str{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    random_device rd;
    mt19937 generator{rd()};
    unordered_map<string, string> mp;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        shuffle(str.begin(), str.end(), generator);
        string s = str.substr(0, 16);
        s = "http://tinyurl.com/" + s;
        if(mp.find(s) != mp.end())
            s = encode(longUrl);
        
        mp[s] = longUrl;
        return s;    
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));