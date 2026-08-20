class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left =0;
        int right =n-1;
        while(right-left>=k)
        {
            if(abs(x-arr[left])<=abs(x-arr[right]))
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return vector<int>(arr.begin()+left, arr.begin()+right+1);

        
    }
};