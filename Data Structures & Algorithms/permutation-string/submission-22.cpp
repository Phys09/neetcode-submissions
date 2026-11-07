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
    return checkInclusion_multiset(s1, s2);  // Even worse than a vector!
    // return checkInclusion_vectors(s1,s2); // inefficient
  }

  bool checkInclusion_2array(const string s1, const string s2) {
    // Degen case
    if (s1.size() > s2.size()) {
      return false;
    }
    /**
      0. Hold 2 arrays that count the number of characters for s1, and the windows of s2
        Also hold the a variable that counts [0-26] how many of those entries match
          - eg: [1,2,0,0,...,0] and [1,0,0,0,...,0] => match_count = 25;
          - When 26, they are the same array, which means the window has the same characters (and
      charcount) as s1 Each time the window slides over, increment window array with new r while
      updating charcount, and decrement l while updating charcount return false if 26 is never
      achieved
    */

    // Initialize variables to store
    auto s1CountArray = std::array<int, 26>{};
    auto s2CountArray = std::array<int, 26>{};

    // Initialize arrays
    for (const char c : s1) {
      s1CountArray[c - 'a']++;
      s2CountArray[c - 'a']++;
    }
    // Correctly set match_count before running main algorithm
    int match_count = 0;
    for (int i = 0; i < 26; ++i) {
      if (s1CountArray[i] == s2CountArray[i]) {
        match_count++;
      }
    }
    int l=0;
    // Inch forward r, do stuff above, then increment l
    // First window has already been processed, move to next window
    for (int r = s1.size(); r < s2.size(); ++r) {
      if (match_count == 26) {return true;}
      // Need to increment l and r, then update arrays

      // Handle l case:

      ++l;
    }
  }

  bool checkInclusion_multiset(const string s1, const string s2) {
    namespace rv = std::views;
    namespace rg = std::ranges;

    auto ms1 = std::multiset(s1.begin(), s1.end());
    for (const auto window : s2 | rv::slide(s1.size())) {
      auto ms2 = std::multiset(window.begin(), window.end());
      if (ms1 == ms2) {
        return true;
      }
    }
    return false;
  }
  bool checkInclusion_vectors(const string s1, const string s2) {
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
