class Solution {
public:
    string addBinary(string a, string b) {
    int size=max(a.size(),b.size());
    int carry=0, pa,pb;
    string result;
    for (int i=0;i<size;i++) {
        pa=i>=a.size()? 0:a[a.size()-i-1]=='1';
        pb=i>=b.size()? 0:b[b.size()-i-1]=='1';
        result=(pa+pb+carry)%2?"1"+result:"0"+result;
        carry=(pa+pb+carry)>=2?1:0;
    }
    if (carry) result="1"+result;
    return result;
    }
};
