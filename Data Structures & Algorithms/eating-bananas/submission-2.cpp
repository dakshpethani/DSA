class Solution {
private:
    int calculate_total_time(vector<int>piles, int h)
    {
        int total =0;
        int n = piles.size();
        for(int i =0;i<n;i++)
        {
            total += ceil((double)piles[i] / (double)h);
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        
        int right = *max_element(piles.begin(),piles.end());
        int res= 0;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            long long totalTime=calculate_total_time(piles,mid);
        

            if(totalTime<=h)
            {
                res=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return res;
        
    }
};
