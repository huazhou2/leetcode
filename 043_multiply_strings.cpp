class Solution {
public:
    string multiply(string num1, string num2) {
      if (num1.empty() || num2.empty()) return "";
      std::reverse(num1.begin(),num1.end());
      std::reverse(num2.begin(),num2.end());
      string result(num1.size()+num2.size(),'0');
      for (int i=0;i<num1.size();i++) {
          int carry=0;
          int t1=num1[i]-'0';
          for (int j=0;j<num2.size();j++) {
              int t2=(num2[j]-'0')*t1+carry+result[i+j]-'0';
              carry=t2/10;
              result[i+j]=static_cast<char>(t2%10+'0');
          }
          result[i+num2.size()]=static_cast<char>(carry+result[i+num2.size()]);
      }
      std::reverse(result.begin(),result.end());
      int rem_zero=0;
      for (;rem_zero<result.size();rem_zero++) 
        if (result[rem_zero]!='0') break;
       if (rem_zero==result.size()) return "0";
       else return result.substr(rem_zero);
}
    };
