class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        total=len(nums1)+len(nums2)
        if total %2:
            return self.helper(nums1,0,len(nums1)-1,nums2,0,len(nums2)-1,(total+1)//2)
        else:
            return (self.helper(nums1,0,len(nums1)-1,nums2,0,len(nums2)-1,total//2)+self.helper(nums1,0,len(nums1)-1,nums2,0,len(nums2)-1,total//2+1))/2
    def helper(self,nums1,l1,r1,nums2,l2,r2,k):
        if l1>r1:
            return nums2[l2+k-1]
        if l2>r2:
            return nums1[l1+k-1]
        total=(r1-l1)//2+(r2-l2)//2+2
        med1=(r1+l1)//2
        med2=(r2+l2)//2
        if (total<=k):
            if nums1[med1]<nums2[med2]:
                return self.helper(nums1,med1+1,r1,nums2,l2,r2,k-(med1-l1+1))
            else:
                return self.helper(nums1,l1,r1,nums2,med2+1,r2,k-(med2-l2+1))
        else:
            if (nums1[med1]<nums2[med2]):
                return self.helper(nums1,l1,r1,nums2,l2,med2-1,k)
            else:
                return self.helper(nums1,l1,med1-1,nums2,l2,r2,k)