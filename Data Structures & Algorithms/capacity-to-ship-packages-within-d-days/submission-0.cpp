class Solution {
private:
    int findDays(vector<int>&weights, int cap)
    {
        int day= 1;
        int load =0;

        for(int i =0;i<weights.size();i++)
        {
            if(load+weights[i] > cap)
            {
                day+=1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            int numberOFDays = findDays(weights,mid);

            if(numberOFDays <= days)
            {
                right = mid-1;
            }

            else
            {
                left = mid+1;
            }
        }
        return left;
        
    }
};