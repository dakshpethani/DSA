class Solution {
public:
    int mySqrt(int x) {
        int half = x/2;

        int left = 0;
        int right = x;
        int result=0;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if((long long)mid*mid <x)
            {
                left = mid+1;
                result= mid;
            }
            else if ((long long)mid*mid > x)
            {
                right=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return result;

        
    }
};