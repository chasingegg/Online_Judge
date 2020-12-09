/*
Date: 2017.8.21
Author: Chao Gao
Lang: C++
*/

// 二分啊大爷。。

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthElement(vector<int>& nums1, int nums1_start, vector<int>& nums2, int nums2_start, int k)
    {
        if(nums1_start > int(nums1.size()) - 1) return nums2[nums2_start+k-1];
        if(nums2_start > int(nums2.size()) - 1) return nums1[nums1_start+k-1];
        if(k == 1) return min(nums1[nums1_start], nums2[nums2_start]);

        int nums1_mid = 2147400000, nums2_mid = 2147400000;
        if(nums1_start+k/2-1 < nums1.size()) nums1_mid = nums1[nums1_start+k/2-1];
        if(nums2_start+k/2-1 < nums2.size()) nums2_mid = nums2[nums2_start+k/2-1];
        if(nums1_mid < nums2_mid) {
            return findKthElement(nums1, nums1_start+k/2, nums2, nums2_start, k-k/2);
        } else {
            return findKthElement(nums1, nums1_start, nums2, nums2_start+k/2, k-k/2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (findKthElement(nums1, 0, nums2, 0, l) + findKthElement(nums1, 0, nums2, 0, r)) / 2.0;
    }
};