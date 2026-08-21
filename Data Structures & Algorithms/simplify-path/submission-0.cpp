class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;

        stringstream pathstream(path);
        string token;
        while(getline(pathstream,token,'/'))
        {
            if(token ==""   || token==".")
            {
                continue;
            }
            else if (token =="..")
            {
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else
            {
                s.push(token);
            }
        }
        if(s.empty())
        {
            return "/";
        }
        string formatedstring;
        
        stack<string>s2;
        while(!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty())
        {
            string dir = s2.top();
            formatedstring+="/"+ dir;
            s2.pop();
        }
        return formatedstring;
        
    }
};