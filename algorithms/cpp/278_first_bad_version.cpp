// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return divide(1,n);
    }
    int divide(int left, int right) {
        if (left>right) return left; 
        int mid=left/2+right/2+(left%2+right%2)/2;
        if (isBadVersion(mid)) return divide(left,mid-1);
        else return divide(mid+1,right);
    }
};
