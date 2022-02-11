class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1=len(s1)
        l2=len(s2)
        if l2<l1:
            return 0
        s1=str(sorted(s1))
        # print(s1)
        for i in range(l2-l1+1):
            # print(i,i+l1)
            s=s2[i:i+l1]
            if str(sorted(s))==s1:
                return 1
            # print(str(sorted(s)))
        # print(s)
        return 0