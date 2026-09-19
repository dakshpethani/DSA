class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int left = 0;
        int right = 0;
        for (auto& num : nums)
        {
            left = max(left,num);
            right +=num;
        }
        auto fessible = [&](int maxsum)
        {
            int currentsum = 0;
            int count=1;

            for(int& num : nums)
            {
                if(currentsum+num > maxsum)
                {
                    currentsum=num;
                    count++;
                }
                else
                {
                    currentsum+=num;
                }
            }
            return count<=k;

        };
        int first_true_index =-1;
        while(left<=right)
        {
            int mid = left+ (right-left)/2;

            if(fessible(mid))
            {
                right = mid-1;
                first_true_index=mid;
            }
            else
            {
                left = mid+1;
            }

        }
        return first_true_index;
    }
};