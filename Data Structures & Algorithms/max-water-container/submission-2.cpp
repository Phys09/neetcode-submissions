#include <print>
#include <format>
class Solution {
 public:
  int maxArea(vector<int>& heights) {
    /**
      1. Initialize pointers to leftmost, and rightmost and max area
      2. Move towards center, the smallest height one continuously until all is done
      Return maximum
    */

    int max_area = -1;
    int left = 0;
    int right = heights.size() - 1;
    while (left < right) {
      int left_height = heights[left];
      int right_height = heights[right];
      int current_area = (right - left) * (std::min(left_height, right_height));
      max_area = (current_area > max_area) ? current_area : max_area;

      if (left_height > right_height) {
        right--;
      } else {
        left++;
      }
    }
    return max_area;
  }
};
