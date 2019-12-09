class Solution(object):
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

        res = 0
        n = len(A)
        next = 0
        cur = 0
        if n < 2:
            return n
        for i in range(n - 1):
            if not next:
                if A[i] < A[i + 1]:
                    next = -1
                elif A[i] > A[i + 1]:
                    next = 1
                if A[i] != A[i + 1]:
                    cur = 2
                else:
                    cur = 1
                    next = 0
            else:
                if A[i] < A[i + 1]:
                    if next == 1:
                        cur += 1
                        next = -1
                    else:
                        next = -1
                        cur = 2
                elif A[i] > A[i + 1]:
                    if next == -1:
                        cur += 1
                        next = 1
                    else:
                        next = 1
                        cur = 2
                else:
                    next = 0
                    cur = 1

            res = max(res, cur)

        return res


a=Solution()

print(a.maxTurbulenceSize([9,1,2,10,7,8,8,1,9]))





