#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        if (citations.size()==1) return citations[0]?1:0;
        std::sort(citations.begin(),citations.end());
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

int main() {
	int a[]={4,4,4,4,4};
	vector<int> num(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<m.hIndex(num)<<endl;
	}
