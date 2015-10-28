class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
       int rev=0, temp=x;
       while (temp) {
           
           rev=rev* 10 + temp%10;
           temp=temp/10;
       }
       if (rev==x) return true;
       else return false;
       
        
    }
};
