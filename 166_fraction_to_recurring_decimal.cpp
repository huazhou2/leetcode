class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
                string result="";
            
            bool sign=numerator<0 != denominator<0;
            if (numerator==0) sign=false;
            long numer=abs(static_cast<long> (numerator));
            long denom=abs(static_cast<long> (denominator));
        if (numer%denom) { 

            result+=to_string(numer/denom);
            result=sign?("-"+result):result;
            result+=".";
            numer=numer%denom;
            long rcb=getrcb(numer,denom);
            numer=numer/rcb;
            denom=denom/rcb;
            result+=getDecimal(numer,denom);
        }
        else {
            result+=to_string(numer/denom);
            result=sign?("-"+result):result;
        }
        return result;
        }
    string getDecimal(long num,long den) {
        vector<long> result;
        unordered_map<long,long> mark;
        long repeat=0;
        long count=0;
        while (num) {
            long rem=num*10/den;
            if (!mark[num]) {
                mark[num]=++count;
                result.push_back(rem);
            }
            else 
            {repeat=num;break;}
            num=num*10%den;
        }
        string s("");
        for (int i=0;i<result.size();i++) {
            s+=(result[i]+'0');
        }
        if (repeat) {
            s.insert(mark[repeat]-1,"(");
            s+=")";
                    }
        return s;}
    long getrcb(long n1,long n2) {
        if (n1%n2==0) return n2;
        else return getrcb(n2,n1%n2);
    }
        
};
