class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp,value);
        
    }
    
    string get(string key, int timestamp) {
        auto& values = map[key];
        int left = 0;
        int right = values.size()-1;

        string res="";
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(values[mid].first <=timestamp)
            {
                res=values[mid].second;
                left=mid+1;
            }
            else

            {
                right=mid-1;
            }
        }
        return res;

        
    }
};
