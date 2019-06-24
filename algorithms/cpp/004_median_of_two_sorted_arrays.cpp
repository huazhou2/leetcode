class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if (total%2) return helper(nums1,nums2,0,nums1.size()-1,0,nums2.size()-1,(total+1)/2);
        else return (helper(nums1,nums2,0,nums1.size()-1,0,nums2.size()-1,total/2)+helper(nums1,nums2,0,nums1.size()-1,0,nums2.size()-1,total/2+1))/2;
    }
    double helper(vector<int>& nums1, vector<int>& nums2,int l1, int r1, int l2, int r2, int k) {
        if (l1>r1) return nums2[l2+k-1];
        else if (l2>r2) return nums1[l1+k-1];
        if (k==1) return nums1[l1]<nums2[l2]? nums1[l1]:nums2[l2];
        int med1=(l1+r1)/2, med2=(l2+r2)/2;
        int total=med1-l1+1+med2-l2+1;  //total left sum, calculated as
        if (total<=k) {
            if (nums1[med1]<=nums2[med2]) return helper(nums1,nums2,med1+1,r1,l2,r2,k-(med1-l1+1));
            else return helper(nums1,nums2,l1,r1,med2+1,r2,k-(med2-l2+1));
        }
        else {
            if (nums1[med1]<=nums2[med2]) return helper(nums1,nums2,l1,r1,l2,med2-1,k);
            else return helper(nums1,nums2,l1,med1-1,l2,r2,k);
        }
    }
};
