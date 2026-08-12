class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
        
        
    }
    void mergeSort(vector<int>&nums, int start, int end)
    {
        if(start >= end)
            return;
        int mid = start + (end-start)/2;
        mergeSort(nums, start,mid);
        mergeSort(nums, mid+1,end);
        merge(nums, start,mid,end);
    }
    void merge(vector<int>&nums, int start, int mid, int end)
    {
        vector<int>result;
        int i=start,j=mid+1,k=0;
        while(i<=mid && j<=end)
        {
            if(nums[i]<nums[j])
            {
                result.push_back(nums[i]);
                i++;
            }
            else
            {
                result.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            result.push_back(nums[i]);
            i++;
        }
        while(j<=end)
        {
            result.push_back(nums[j]);
            j++;
        }
        for(int k =0;k<result.size();k++)
        {
            nums[start+ k]=result[k];
        }
        
    }
};