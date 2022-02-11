class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1=len(s1)
        l2=len(s2)
        if l2<l1:
            return 0
        x=[int(0)]*26
        y=[int(0)]*26
        # print(x)
        for i in range(l1):
            x[ord(s1[i])-ord('a')]+=1
        # print(x)
        for i in range(l2-l1+1):
            f=1
            if i==0:
                for j in range(l1):
                    y[ord(s2[j])-ord('a')]+=1
                if x==y:
                    return 1
                continue
            y[ord(s2[i-1])-ord('a')]-=1
            y[ord(s2[i+l1-1])-ord('a')]+=1
            
            if x==y:
                return 1
        # print(s)
        return 0