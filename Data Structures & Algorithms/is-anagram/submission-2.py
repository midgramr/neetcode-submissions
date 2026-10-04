from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        seen, seen2 = defaultdict(int), defaultdict(int)
        for c in s:
            seen[c] += 1
        
        for c in t:
            seen2[c] += 1

        return seen == seen2

