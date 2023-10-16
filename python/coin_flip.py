from typing import List

def coin_flip(coins: List[int], amount: int) -> int:
    dp = [amount + 1] * (amount + 1)
    dp[0] = 0

    for a in range(1, amount+1):
        for c in coins:
            if(a -c >= 0):
                dp[a] = dp[a-c] + 1
    return dp[amount] if dp[amount] != amount+1 else -1


assert coin_flip([1,2,5], 11) == 3