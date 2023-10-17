class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        a = s.split()
        a.reverse()
        ans = " ".join(a)
        return ans