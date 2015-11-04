class Solution {
public:
    string countAndSay(int n) {
        string result="1";
        for (int i=1; i < n; i++) {
            result=read(result);
        }
        return result;
    }
    string read(string number) {
        char current=number[0];
        int count=1;
        string result="";
        for (int i=1;i<number.size();i++) {
            if (number[i] != current)
            {
                result =result + to_string(count) + current;
                count=1;
                current=number[i];}
                
            else
                count++;
        }
        result =result + to_string(count) + current;
        return result;
    }
};
