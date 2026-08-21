class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>pair;
        for(int i = 0;i<n;i++)
        {
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());

        int fleet =1;
        double prev = (double)(target-pair[0].first)/pair[0].second;
        for(int i =1; i<n;i++)
        {
            double current = (double)(target-pair[i].first)/pair[i].second;
            if(current>prev)
            {
                fleet++;
                prev= current;
            }
        }
        return fleet;
        
        
    }
};
