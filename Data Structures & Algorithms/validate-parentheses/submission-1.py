class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for c in s:
            if c in {'(', '[', '{'}:
                stk.append(c)
            else:
                if len(stk) == 0:
                    return False
                if c == ')' and stk[-1] != '(':
                    return False
                if c == ']' and stk[-1] != '[':
                    return False
                if c == '}' and stk[-1] != '{':
                    return False
                stk.pop()
        return len(stk) == 0