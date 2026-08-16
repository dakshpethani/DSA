class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i =0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                swap(nums[j],nums[n-1]);
            }
        }
        
        
    }
};