class Solution {
public:
    bool isMatch(string s1, string p1) {
        const char * s=s1.c_str(), *p=p1.c_str();
        bool flag=false;
        const char* curi=s, *curj=p;
        while (*s) {
        switch (*p) {
            case '*':
                flag=true;
                curi=s;
                p++;
                curj=p;
                break;
            case '?':
                s++;
                p++;
                break;
            case '\0':
                if (flag) {
                curi++;
                s=curi;
                p=curj;
                break;}
                else return false;
            default:
                if (*s==*p) {s++;p++;}
                else if (flag) 
                {curi++;s=curi;p=curj;}
                else return false;
            
        }
    }
    if (*p=='\0') return true;
    while (*p) { 
        if (*p=='*') p++;
        else return false;}        
    return true;
    }
};
