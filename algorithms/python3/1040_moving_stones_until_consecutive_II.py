class Solution(object):
    def numMovesStonesII(self, stones):
        """
        :type stones: List[int]
        :rtype: List[int]
        """
        stones.sort()

        dis=[]
        for i in range(1,len(stones)):
            dis.append(stones[i]-stones[i-1]-1)

        step2=sum(dis)-min(dis[0],dis[-1])
        n=len(stones)
        l,step1=0,n

        for r in range(n):
            while stones[r]-stones[l]+1>n:
                l+=1
            if stones[r]-stones[l]==r-l and stones[r]-stones[l]+1==n-1:
                step1=min(step1,2)
            else:
                step1=min(step1,n-(r-l+1))
        return [step1,step2]

a=Solution()

print(a.numMovesStonesII([6,5,4,3,10]))

