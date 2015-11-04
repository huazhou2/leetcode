class Solution {
public:
    string simplifyPath(string path) {
        string result;
        if (path.empty()) return result;
        string temp;
        stack<string> final;
        path=path+"/";
        for (int i=0;i<path.size();i++) {
            if (path[i]=='/') {
                if (!temp.empty()) {
                    if (temp=="..") 
                        {if (!final.empty())
                            final.pop();}
                    else if (temp !=".")
                        final.push(temp);
                }
            temp="";}
            else temp+=path[i];
        }
        if (final.empty()) return "/";
        while (!final.empty()) {
            result='/'+final.top()+result;
            final.pop();
        }
        return result;
    }
};
