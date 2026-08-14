class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result=0;
        int currentSum=0;
        unordered_map<int,int>sumCount{{0,1}};
        for (int num : nums)
        {
            currentSum+=num;

            result+= sumCount[currentSum-k];

            ++sumCount[currentSum];

        }
        return result;
    }
};