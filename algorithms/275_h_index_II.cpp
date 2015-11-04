class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int size=citations.size();
        int h=0;
        for (int i=0;i<size;i++) {
            if (size-i==citations[i]) return citations[i];
            else if (citations[i]>size-i) {
                h=size-i;
                break;
            }
        }
        return h>size?size:h;
    }
};
