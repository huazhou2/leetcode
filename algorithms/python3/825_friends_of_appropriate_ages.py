class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        count=[0]*121
        for age in ages:
            count[age]+=1

        ans=0
        for age_a in range(121):
            for age_b in range(121):
                if age_b>age_a or age_b<=0.5*age_a+7 or age_b>100 and age_a<100:
                    continue
                ans += count[age_a] * count[age_b]
                if age_a == age_b:
                    ans -= count[age_a]
        return ans

a=Solution()

ages=[16,17,18]
print(a.numFriendRequests(ages))

