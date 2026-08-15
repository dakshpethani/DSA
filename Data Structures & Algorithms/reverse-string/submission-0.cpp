class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        int left =0;
        int right=n-1;
        int iteration = n/2;
        for(int i =0;i<iteration ;i++)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
        
    }
};