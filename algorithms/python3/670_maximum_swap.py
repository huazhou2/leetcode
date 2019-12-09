class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        arr=[int(i) for i in list(str(num))]
        tmp=sorted(arr,reverse=True)
        for i in range(len(arr)):
            if tmp[i] != arr[i]:
                ind=len(arr)-1-arr[::-1].index(tmp[i])
                arr[i],arr[ind]=arr[ind],arr[i]
                break
        arr=[str(i) for i in arr]
        return int(''.join(arr))

a=Solution()

print(a.maximumSwap(2736))

