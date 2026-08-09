class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int>seen;
        int n = nums.size();
        for(int i =0 ; i<n ; i++)
        {
            if(seen.count(nums[i])>0)
            {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};