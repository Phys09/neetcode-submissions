#include <format>
#include <print>

template <typename T>
struct std::formatter<std::vector<T>> : std::formatter<std::string_view> {
  constexpr auto parse(const auto& ctx) const { return ctx.begin(); }

  constexpr auto format(const std::vector<T>& vec, auto& ctx) const {
    auto out = ctx.out();
    std::format_to(out, "[");
    for (int i = 0; i < vec.size(); ++i) {
      if (i < vec.size() - 1) {
        out = std::format_to(out, "{},", vec[i]);
      } else {
        out = std::format_to(out, "{}", vec[i]);
      }
    }
    out = std::format_to(out, "]");
    return out;
  }
};

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::vector<std::vector<int>> triplets;
    int initial = 0;
    std::ranges::sort(nums);
    std::println("{}", nums);

    for (initial = 0; initial < nums.size() - 2; ++initial) {
      /**
      1. go through each element in the sorted list
        - When index is greater than 0, and previous element is the same as current, skip iteration
        - Prevents duplicates, and the sorted-ness helps in this regard
      2. for subrange right-side of initial, find the next 2 elements that sum to 0 with
      nums[initial]
        - Do so by shifting the left index right when too small, and right index left when too large
        - If we find one, shift the left (w.l.o.g) repetedly until it's a different number and
      continue
      */

      // 1
      if (initial > 0 and nums[initial] == nums[initial - 1]) {
        continue;
      }

      // 2
      int left = initial + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int sum = nums[initial] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          // Meets target
          triplets.emplace_back(std::initializer_list<int>{nums[initial], nums[left], nums[right]});
          left++;
          // Shift aforementioned left pointer until different
          while (bool must_increment_left_pointer = left < right and nums[left] == nums[left - 1]) {
            left++;
          }
        }
      }
    }
    return triplets;
  }
};
