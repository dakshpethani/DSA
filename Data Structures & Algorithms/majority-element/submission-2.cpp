class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int candidate =0;
        for(int i =0;i<nums.size() ; i++)
        {
            if(count==0)
            {
                count=1;
                candidate=nums[i];
            }
            else
            {
                if(candidate==nums[i])
                {
                    count+=1;
                }
                else
                {
                    count-=1;
                }
            }
        }
        return candidate;

        
        
    }
};