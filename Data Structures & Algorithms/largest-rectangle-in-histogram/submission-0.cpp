class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea=0;
        stack<int>s;

        vector<int>leftboundry(n,-1);
        vector<int>rightboundry(n,n);

        for(int i =0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                rightboundry[s.top()]=i;
                s.pop();
            }
            if(!s.empty())
            {
                leftboundry[i]=s.top();

            }
            s.push(i);
        }
        for(int i =0;i<n;i++)
        {
            int width = rightboundry[i]-leftboundry[i]-1;
            int area = heights[i]*width;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};
