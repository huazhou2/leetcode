class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        c1=c2=0
        a1=a2=0
        for num in nums:
            if num==a1:
                c1+=1
            elif num==a2:
                c2+=1
            elif c1==0:
                a1=num
                c1=1
            elif c2==0:
                a2=num
                c2=1
            else:
                c1-=1
                c2-=1
        c1=c2=0
        for num in nums:
            if num==a1:
                c1+=1
            elif num==a2:
                c2+=1
        ans=[]
        if c1>len(nums)//3:
            ans.append(a1)
        if c2>len(nums)//3:
            ans.append(a2)
        return ans


a=Solution()

print(a.majorityElement([1,1,1,3,3,2,2,2]))