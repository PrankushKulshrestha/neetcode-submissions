class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        auto kth = [&](int k) {
            int i = 0, j = 0;
            while (true) {
                if (i == nums1.size())
                    return nums2[j + k - 1];
                if (j == nums2.size())
                    return nums1[i + k - 1];
                if (k == 1)
                    return min(nums1[i], nums2[j]);
                int half = k / 2;
                int ni = min(i + half, (int)nums1.size()) - 1;
                int nj = min(j + half, (int)nums2.size()) - 1;
                if (nums1[ni] <= nums2[nj]) {
                    k -= ni - i + 1;
                    i = ni + 1;
                } else {
                    k -= nj - j + 1;
                    j = nj + 1;
                }
            }
        };
        if (total % 2 == 1) {
            return kth(total / 2 + 1);
        }
        int left = kth(total / 2);
        int right = kth(total / 2 + 1);
        return (left + right) / 2.0;
    }
};