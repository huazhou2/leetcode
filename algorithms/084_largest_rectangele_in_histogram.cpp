class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int result=0;
        if (height.empty()) return 0;
        stack<int> sta;
        height.push_back(0);
        sta.push(0);
        for (int i=1;i<height.size();i++)  {
            if (height[i]<height[sta.top()]) {
                while (!sta.empty()) {
                    int cur=height[sta.top()];
                    if (cur>height[i]) {
                        int max;
                        sta.pop();
                        if (sta.empty()) max=cur*i;
                        else max=cur*(i-sta.top()-1);
                        result=result>max?result:max;
                    }
                    else break;}
                }
            sta.push(i);
                    }
        return result;
    }
};
