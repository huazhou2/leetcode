class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:

        nums=sorted(arr)

        left=right=cnt=0
        i=0
        while i<len(arr):
            if arr[i]==nums[right]:
                i+=1
            else:
                right=nums.index(arr[i])
                while i<right:
                    i+=1
                    if (nums[right]==arr[i]):
                        right+=1
                    else:
                        right=max(right,nums.index(arr[i]))
                i+=1
                right+=1
            cnt+=1

        return cnt