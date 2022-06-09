class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin=0,end=0,sum=0,len=INT_MAX;
        while(end<nums.size())
        {
            sum+=nums[end]; //increase window
            end++;
            while(sum>=target) //valid window
            {
                if(end-begin<len) //minimize window length
                {
                    len=end-begin;
                }
                sum-=nums[begin]; //decrease window from the left (beginning)
                begin++;
            }
        }
        return len==INT_MAX? 0:len;
    }
};

