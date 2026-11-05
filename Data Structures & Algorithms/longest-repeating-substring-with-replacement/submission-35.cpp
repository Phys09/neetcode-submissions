class Solution {
 public:
  int characterReplacement(string s, int k) {
    if (s.size() == 0) {
      return 0;
    }

    /**
      0. Two pointers, start both at left, store and update frequent_char for the current window,
      and calculate current_window_size - frequent_char <= k On failure, must increment l until it
      holds again, while updating map
      1. Optimized solution takes advantage of the fact that you only replace characters with the
      character that shows up the most
        - "ABBABADB" most_freq = {'B', 4} max_size = 5
    */

    return regular(s, k);
    // return optimized(s, k);
  }

  int regular(std::string_view s, int k) {
    namespace rg = std::ranges;
    int max_size = 0;
    int l = 0;
    std::unordered_map<unsigned char, int> window_charfreq{};

    for (int r = 0; r < s.size(); ++r) {
      window_charfreq[s[r]] += 1;

      const auto projection_frequency = [](const auto pair) {
        const auto [k, v] = pair;
        return v;
      };
      const auto [k_, count] = *(rg::max_element(window_charfreq, {}, projection_frequency));

      int window_size = r - l + 1;
      bool valid_window = window_size - count <= k;
      while (not valid_window) {
        window_charfreq[s[l]]--;
        l++;

        window_size = r - l + 1;
        valid_window = window_size - count <= k;
      }
      max_size = std::max(max_size, window_size);
    }

    return max_size;
  }

  int optimized(std::string s, int k) {
    /**
      0. Same as above, but storing max_freq as a number (we only care about size, not what the
      character is) then using it in the calculation of max count
    */
    namespace rg = std::ranges;
    int max_size = 0;
    int l = 0;
    int max_freq = 0;
    std::unordered_map<unsigned char, int> window_charfreq{};

    for (int r = 0; r < s.size(); ++r) {
      window_charfreq[s[r]] += 1;
      max_freq = std::max(max_freq, window_charfreq[s[r]]);

      int window_size = r - l + 1;
      bool valid_window = window_size - max_freq <= k;
      while (not valid_window) {
        window_charfreq[s[l]]--;
        l++;

        window_size = r - l + 1;
        valid_window = window_size - max_freq <= k;
      }
      max_size = std::max(max_size, window_size);
    }

    return max_size;
  }
};
