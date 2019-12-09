class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        ans=[0]*len(T)
        stack=[]
        for i in range(len(T)):
            while stack and T[stack[-1]]<T[i]:
                ans[stack[-1]]=i-stack[-1]
                stack.pop()
            stack.append(i)
        return ans


a=Solution()

print(a.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))