class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int i = 0;
       int j = i + 1;
       int find = 0;
        vector <int> ret;
       while (i < nums.size() - 1 && !find)
       {
           j = i + 1;
           while (j < nums.size() && !find)
           {
               if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    break;
                }
                j++;
           }
           i++;
       } 
        return (ret);
    }
};