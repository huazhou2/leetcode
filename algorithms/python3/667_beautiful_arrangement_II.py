class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        ans = []
        arr = list(range(1, k + 2))
        i, j = 0, k
        while i <= j:
            ans.append(arr[i])
            if j > i:
                ans.append(arr[j])
            i += 1
            j -= 1
        return ans + list(range(k + 2, n + 1))

a=Solution()

print(a.constructArray(4,2))

