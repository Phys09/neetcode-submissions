#include <print>
#include <ranges>

template <typename T>
  requires std::formattable<T, char>
struct std::formatter<std::vector<T>> {
  constexpr auto parse(const auto& format_context) { return format_context.begin(); }
  constexpr auto format(const std::vector<T>& vec, auto& ctx) const {
    auto out = ctx.out();
    std::format_to(out, "[");
    for (const auto& e : vec) {
      std::format_to(out, "{},", e);
    }
    std::format_to(out, "]");
    return out;
  }
};

class Solution {
 public:
  int trap(std::vector<int>& height) {
    /**
      1. At each position height[i], the amount of water able to be contained in that column is
        - Smallest of: (greatest left and greatest right) with 0 at least
        - Water at that point is thus:
          -> int water_column = min(max_left[i], max_right[i]) - height[i]; if water_column >= 0
             OR 0 ; otherwise
      2. Can store an array for each position holding this max_left value and max_right value
        - eg: height = [0,2,0,3,1,0,1,3,2,1]
            max_left = [0,0,2,2,3,3,3,3,3,3]
           max_right = [3,3,3,3,3,3,3,2,1,0]
        - This gives an O(n) memory solution
      3. Notice in (2.) that these are monotonic arrays
        - This gives a 2 pointer solution, shifting the pointer with the smaller max_*, while l < r
        - Keeping track of total water, and max_*
        - Shifting the pointer with the smaller max_* to make sure that the calculation of the
          minimum(max_left, max_right) at that position is correct (short answer)

        The algorithm is as follows:
        1. Initialize l and r pointers at start, end
        2. Shift the pointer corresponding with the smaller max_*, then calculate the water at that

    */

    return trap_linear_memory(height);  // 2
    // return trap_constant_memory(height); // 3
  }

  // 2.
  int trap_linear_memory(std::vector<int> height) {
    namespace rv = std::ranges::views;
    namespace rg = std::ranges;

    std::vector<int> max_left(height.size());
    std::vector<int> max_right(height.size());
    std::vector<int> minimums_of_maximums(height.size());
    int total_rainwater = 0;

    // Populate max_left

    for (int current_max = 0;
         auto [current_height, current_max_left_height] : rv::zip(height, max_left)) {
      current_max = std::max(current_height, current_max);
      current_max_left_height = current_max;
    }
    // Populate max_right
    for (int current_max = 0; auto [current_height, current_max_right_height] :
                              rv::zip(rv::reverse(height), rv::reverse(max_right))) {
      current_max = std::max(current_height, current_max);
      current_max_right_height = current_max;
    }

    // Populate minimums_of_maximums
    for (auto [max_l, max_r, min_of_max] : rv::zip(max_left, max_right, minimums_of_maximums)) {
      min_of_max = std::min(max_l, max_r);
    }

    std::vector<int> water_at_col{};
    // Each column can hold water equal to: minimums_of_maximums[i] - height[i]
    for (const auto& [mins_of_max, height] : rv::zip(minimums_of_maximums, height)) {
      int water = std::max(0, mins_of_max - height);
      water_at_col.emplace_back(water);
      total_rainwater += water;
    }
    return total_rainwater;
  }

  // 3. Two pointer approach
  template <typename T>
  int trap_constant_memory(std::span<T> height) {
    int total_rainwater;
    int l = 0;
    int r = height.size() - 1;

    int max_left = height[l];
    int max_right = height[r];
    while (l < r) {
      

      if (max_left < max_right) {
        l++;
      } else {
        r--;
      }
    }

    return total_rainwater;
  }
};
