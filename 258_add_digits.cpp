class Solution {
public:
    int addDigits(int num) {
        if (num<10) return num;
        else return num%9? (num%9):9;
    }
};
