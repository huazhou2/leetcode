class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        dict={}
        diff=[]
        for item in arr1:
            if item in arr2:
                if item in dict:
                    dict[item] += 1
                else:
                    dict[item] = 1
            else:
                diff.append(item)
        diff.sort()
        cnt=0
        res=[]
        for item in arr2:
            res.extend([item]*dict[item])
        res.extend(diff)
        return res

s=Solution()

arr1 = [2,3,1,3,2,4,6,7,9,2,19]
arr2 = [2,1,4,3,9,6]

print(s.relativeSortArray(arr1,arr2))



