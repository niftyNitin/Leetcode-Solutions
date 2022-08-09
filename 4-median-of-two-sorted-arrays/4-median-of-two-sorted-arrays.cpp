class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 == 0) {
            double a = nums1[nums1.size()/2];
            double b = nums1[nums1.size()/2 - 1];
            return (a+b)/2;
        }
        return nums1[nums1.size()/2];
    }
};