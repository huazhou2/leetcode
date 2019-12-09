class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        cnt = m + n - 1
        p1, p2 = m - 1, n - 1
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] >= nums2[p2]:
                nums1[cnt] = nums1[p1]
                p1 -= 1
            else:
                nums1[cnt] = nums2[p2]
                p2 -= 1
            cnt -= 1
        if p1 < 0:
            nums1[0:p2 + 1] = nums2[0:p2 + 1]



a=Solution()


nums1=[1,2,3,0,0,0]
nums2=[2,5,6]

a.merge(nums1,3,nums2,3)