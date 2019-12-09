class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        num=sum([item==0 for item in arr])
        ind=len(arr)-1
        n=len(arr)
        while num>0 and ind>=0:
            if arr[ind]==0:
                num-=1
            newind=ind+num
            if newind<n:
                arr[newind]=arr[ind]
                if arr[ind]==0 and newind+1<n:
                    newind+=1
                    arr[newind]=arr[ind]
            ind-=1





a=Solution()
arr=[1,0,2,3,0,4,5,0]
a.duplicateZeros(arr)
