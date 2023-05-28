class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector <int> temp;
        int prev = nums[0];
        temp.push_back(prev);
        int i = 1;
        int count = 1;
        while (i < nums.size())
        {
            if (nums[i] != prev)
            {
                temp.push_back(nums[i]);
                prev = nums[i];
                count++;
            }
            i++;
        }
        for (int i = 0; i < count; i++)
            nums[i] = temp[i];
        return (count);
    }
};