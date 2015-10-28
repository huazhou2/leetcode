class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        ratings.push_back(ratings.back());
        int prev_peak=0;
        int peak_value=1;
        int total=1;
        int cur=1;
        for (int i=1;i<ratings.size();i++) {
            if (ratings[i]>=ratings[i-1]) {
                for (int j=0;j<i-prev_peak-1;j++) total+=j+1;
                if (i-1-prev_peak>=peak_value) total+=i-prev_peak-peak_value;
                prev_peak=i;
                if (ratings[i]==ratings[i-1]) cur=1;
                else cur+=1;
                peak_value=cur;
            total+=cur;
            }
            else cur=1;
        }
        return total-1;
    }
};
