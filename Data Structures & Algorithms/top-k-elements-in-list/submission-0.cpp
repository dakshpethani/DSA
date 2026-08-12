class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>freqNummap;

        for(int num : nums)
        {
            freqNummap[num]++;
        }
        using freqNumPair = pair<int,int>;
        priority_queue<freqNumPair,vector<freqNumPair>,greater<freqNumPair>>minHeap;
        for(const auto&[number, frequency] : freqNummap)
        {
            minHeap.push({frequency,number});

            if(minHeap.size()>k)
            {
                minHeap.pop();
            }
            
        }
        vector<int> result;
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
