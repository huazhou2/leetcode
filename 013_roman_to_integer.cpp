class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romanMap;
        romanMap['M']=1000;
        romanMap['D']=500;
        romanMap['C']=100;
        romanMap['L']=50;
        romanMap['X']=10;
        romanMap['V']=5;
        romanMap['I']=1;
        int result=0;
        int count=1;
        for (int i=0; i<s.size()-1;i++){
            if (romanMap[s[i]]<romanMap[s[i+1]]){
                result-= count*romanMap[s[i]];
                count=1;
            }
            else if (romanMap[s[i]]>romanMap[s[i+1]]){
                result+= count*romanMap[s[i]];
                count=1;
            }
            else count++;}
        return result+count*romanMap[s[s.size()-1]];
    }
};
