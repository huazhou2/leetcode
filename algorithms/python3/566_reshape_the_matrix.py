class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if not nums or not nums[0]:
            return nums
        r1,c1=len(nums),len(nums[0])
        if r1*c1 != r*c:
            return nums
        newmat=[[0]*c for i in range(r)]
        cnt=-1
        for i in range(r1):
            for j in range(c1):
                cnt+=1
                newr,newc=cnt//c,cnt%c
                newmat[newr][newc]=nums[i][j]

        return newmat

a1=Solution()

nums=[[1,2,3],[4,5,6]]

a1.matrixReshape(nums,3,2)


