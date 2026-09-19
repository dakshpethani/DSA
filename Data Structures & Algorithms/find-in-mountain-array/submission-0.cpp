/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        int left = 1;
        int right = length-2;
        int peak =0;

        while(left<=right)
        {
            int mid =(left+right)/2;
            int prev = mountainArr.get(mid-1);
            int center = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);

            if(prev<center && center<next)
            {
                left=mid+1;
            }
            else if (prev> center && center > next)
            {
                right = mid-1;
            }
            else
            {
                peak = mid;
                break;
            }
        }
        left = 0;
        right = peak-1;

        while(left<=right)
        {
            int mid = (left+right)/2;
            int val =mountainArr.get(mid);
            if(val<target)
            {
                left  =mid+1;

            }
            else if (val> target)
            {
                right=mid-1;
            }
            else
            {
                return mid;
            }
        }
        left = peak;
        right = length-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            int val =mountainArr.get(mid);
            if(val>target)
            {
                left = mid+1;
            }
            else if (val < target)
            {
                right = mid-1;
            }
            else
            {
                return mid ;
            }
        }
        return -1;
        
    }
};