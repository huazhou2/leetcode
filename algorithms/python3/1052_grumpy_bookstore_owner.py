class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type X: int
        :rtype: int
        """
        num_unhappy,max_num_unhappy=0,0
        for i in range(len(customers)):
            num_unhappy+=grumpy[i]*customers[i]
            if i>=X:
                num_unhappy-=grumpy[i-X]*customers[i-X]
            if num_unhappy>max_num_unhappy:
                max_num_unhappy=num_unhappy

        res=sum((1-grumpy[i])*customers[i] for i in range(len(customers)))+max_num_unhappy
        return res

a=Solution()
customers = [1,0,1,2,1,1,7,5]
grumpy = [0,1,0,1,0,1,0,1]
X = 3
print(a.maxSatisfied(customers,grumpy,X))