class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lo, ans = prices[0], 0
        for price in prices:
            lo = min(lo, price)
            ans = max(ans, price - lo)
        return ans
