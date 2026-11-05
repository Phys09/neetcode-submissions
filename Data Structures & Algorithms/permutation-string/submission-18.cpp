#include <ranges>
#include <print>
template <typename T>
struct std::formatter<std::vector<T>> : std::formatter<std::string_view> {
  constexpr auto parse(const auto& ctx) const { return ctx.begin(); }

  constexpr auto format(const std::vector<T>& vec, auto& ctx) const {
    auto out = ctx.out();
    out = std::format_to(out, "[");
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
  bool checkInclusion(const string s1, const string s2) {
    namespace rv = std::views;
    namespace rg = std::ranges;

    std::vector<char> v1(s1.begin(), s1.end());
    rg::sort(v1);
    int window_size = s1.size();

    for (const auto window : s2 | rv::slide(window_size)) {
      std::vector<char> v2(window.begin(), window.end());
      rg::sort(v2);
      if (v1 == v2) {
        return true;
      }
    }
    return false;
  }
};
