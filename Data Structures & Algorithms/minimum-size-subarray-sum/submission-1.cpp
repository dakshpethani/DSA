class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int total = 0;
    int result = INT_MAX;

    for (int right = 0; right < n ; right++) {
      total += nums[right];
      while (total >= target) {
        result = min(right - left + 1, result);
        total -= nums[left];
        left++;
        
      }
    }
    return result ==INT_MAX?0:result;
  }
};