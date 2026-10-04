class Solution:
    def isPalindrome(self, s: str) -> bool:
        builder = []
        for c in s:
            if c.isalnum():
                builder += c.lower()

        cleaned = "".join(builder)
        return cleaned == "".join(reversed(cleaned))