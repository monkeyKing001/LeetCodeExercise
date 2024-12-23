class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr;
    arr.reserve(nums1.size() + nums2.size());
    int i1 = 0, i2 = 0;
    int num = 0;
    while (i1 < nums1.size() && i2 < nums2.size()){
      if (nums1[i1] < nums2[i2])
        arr.push_back(nums1[i1++]);
      else
        arr.push_back(nums2[i2++]);
    }
    while (i1 < nums1.size()){
      arr.push_back(nums1[i1++]);
    }
    while (i2 < nums2.size()){
      arr.push_back(nums2[i2++]);
    }
    double ans;
    if (arr.size() % 2 != 0)
      ans = arr[arr.size() / 2];
    else
      ans = (double)(arr[(arr.size() / 2) - 1] + arr[arr.size() / 2]) / 2;
    return (ans);
  }
};