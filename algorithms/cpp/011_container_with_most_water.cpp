class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int min_height;
        auto left=height.begin(), right=height.end()-1;
        while (left<right) {
            min_height=min(*left,*right);
            if ((right-left) * min_height > max) max=(right-left)*min_height;
            
            if (*left<=*right) left++;
            else right--;
        }
       
        return max;
    }
};
