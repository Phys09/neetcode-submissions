#include <print>
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }

    /**
      Two Pointers approach
      1. Initialize 2 pointers to first and second
      2. Increment the right pointer while updating max_profit
      3. If there's a lower price that exists on right, update left to be that new price to potentially buy
      2. Every time left > right, reset left and right to be beside each other, to the newer smaller left
      3. Store max profit
    */

    auto buy = prices.begin();
    auto sell = std::next(prices.begin());
    int max_profit = 0;
    for (;sell != prices.end(); ++sell) {
      if (*buy > *sell) {
        buy = sell;
      } else {
        int profit = *sell - *buy;
        max_profit = std::max(max_profit, profit);
        std::println("{}", *buy);
      }
    }
    return max_profit;
  }
};
