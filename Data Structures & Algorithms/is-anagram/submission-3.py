class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        seen = [0] * 26
        for c in s:
            seen[ord(c) - ord('a')] += 1

        for c in t:
            seen[ord(c) - ord('a')] -= 1

        for i in range(26):
            if seen[i] != 0:
                return False
        return True