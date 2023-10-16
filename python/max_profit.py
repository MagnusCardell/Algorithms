from typing import List
def maxProfit(prices: List[int]) -> int:
    p1 = 0
    p2 = 1
    mProfit = 0
    while(p1 < len(prices) and p2< len(prices)):
        profit = prices[p2] - prices[p1]
        mProfit = max(mProfit, profit)

        if prices[p2] < prices[p1]:
            p1 = p2
        p2 += 1
    return mProfit

assert maxProfit([1,2,3,1]) == 2, "example"