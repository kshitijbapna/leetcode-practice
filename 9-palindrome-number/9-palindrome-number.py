class Solution:
    def isPalindrome(self, x: int) -> bool:
        a=str(x)
        b=a[::-1]
        if a==b:
            return 1
        else:
            return 0