class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>anagramGroup;

        for(const auto &str : strs)
        {
            string sortedkey= str;
            sort(sortedkey.begin(), sortedkey.end());
            anagramGroup[sortedkey].emplace_back(str);



        }
        vector<vector<string>>result;
        for(auto &[key,group] : anagramGroup)
        {
            result.emplace_back(group);   
        }
        return result;
    }
};
