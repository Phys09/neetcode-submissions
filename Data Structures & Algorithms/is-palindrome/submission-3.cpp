#include <ranges>
class Solution {
public:
  bool isPalindrome(string s) {
    auto cleaned =
        s | std::views::transform([](auto c) { return std::tolower(c); }) |
        std::views::filter([](auto c) { return std::isalnum(c); });
    return std::ranges::equal(cleaned, cleaned | std::views::reverse);
  }
};

