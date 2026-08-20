class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(),0);
        stack<pair<int,int>>s;

        for(int i =0;i<temperatures.size();i++)
        {
            int t = temperatures[i];
            while(!s.empty() && t>s.top().first)
            {
                auto pair = s.top();
                s.pop();
                result[pair.second]=i-pair.second;
            }
            s.push({t,i});
        }
        return result;
        
    }
};
