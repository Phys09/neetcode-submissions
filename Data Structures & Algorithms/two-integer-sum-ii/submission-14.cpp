#include <print>
#include <ranges>
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    /**
      1. Initialize sum, and if too large, reduce sum (take from the right side)
        - If giving more to the left (instead of taking from right), we run out of numbers to choose
      from Also problem is simplified due to having EXACTLY 1 solution
      2. otherwise it's too small, increase sum by giving more to the left
        - Similar response for taking from the right
    */
    int left_index = 0;
    int right_index = numbers.size() - 1;
    while (left_index < right_index) {
      int sum = numbers[left_index] + numbers[right_index];
      if (sum > target) {
        right_index--;
      } else if (sum < target) {
        left_index++;
      } else {
        break;
      }
    }

    return {left_index + 1, right_index + 1};
  }

  vector<int> twoSumIterator(vector<int>& numbers, int target) {
    namespace rg = std::ranges;

    /**
    1. go through each element by iterator
    2. binary search the right side for the value adding up to target
    3. return their true indices shifted over 1 positively
    */

    int left_index{-1};
    int right_index{-1};
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
      int value_sum_to_target = target - (*it);
      auto needle = rg::lower_bound(it + 1, numbers.end(), value_sum_to_target);
      if (needle != numbers.end() and *needle == value_sum_to_target) {
        std::println("{} {} {}", value_sum_to_target, *needle, *it);
        // early return because we found it
        left_index = 1 + std::distance(numbers.begin(), it);
        right_index = 1 + std::distance(numbers.begin(), needle);
        break;
      }
    }

    return {left_index, right_index};
  }
};
