class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		nums1.push_back(INT_MAX);
		nums2.push_back(INT_MAX);
		int n = (size - 1) / 2;
		int i = 0, j = 0;
		while (n-- != 0) {
			if (nums1[i] < nums2[j]) i++;
			else j++;
		}
		if (size % 2) {
			return min(nums1[i], nums2[j]);
		}
		else {
			int median1;
			if (nums1[i] < nums2[j]) {
				median1 = nums1[i++];
			}
			else {
				median1 = nums2[j++];
			}
			int median2 = min(nums1[i], nums2[j]);
			return (median1 + median2) / 2.0;
		}
	}
};