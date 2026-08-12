class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();

        for (int i =0;i<size-1;i++)
        {
            int minColor =i;
            for(int j =i+1;j<size;j++)
            {
                if(nums[j]<nums[minColor])
                {
                    minColor = j;
                }
            }
            swap(nums[i],nums[minColor]);

        }
        

    }
};