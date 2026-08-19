class Solution {
 public:
  int characterReplacement(string s, int k) {
    int result = 0;
    int n = s.size();
    unordered_set<char> charSet(s.begin(),s.end());
    
    for (auto c : charSet) {
      int count = 0;
      int left = 0;
      for (int right = 0; right < n; right++) {
        if (s[right] == c) {
          count++;
        }
        while ((right - left + 1) - count > k) {
          if (s[left] == c) {
            count--;
          }
          left++;
        }

        result = std::max(result, right - left + 1);
      }
    }
    return result;
  }
};
