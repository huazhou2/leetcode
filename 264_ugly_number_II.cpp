class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> result;
        result.insert(1);
        int num;
        int count=0;
        int limit2=numeric_limits<int>::max()/2;
        int limit3=numeric_limits<int>::max()/3;
        int limit5=numeric_limits<int>::max()/5;
        while (count<n) {
            set<int>::iterator it=result.begin();
            num=*it;
            result.erase(it);
            if (num<=limit2) result.insert(num*2);
            if (num<=limit3) result.insert(num*3);
            if (num<=limit5) result.insert(num*5);
            count++;}
        return num;
        }
};
