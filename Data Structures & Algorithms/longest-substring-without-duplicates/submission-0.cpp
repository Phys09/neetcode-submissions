class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) {
      return s.size();
    }

    /**
      1. Create a window, and check if characters are unique over that view, increasing right if so,
      or repeatedly decreasing left until it is
      2. If characters are all unique, window is a view over a substring without duplicate
      characters
          - Record update max size, and potentially capture more characters from the right
      3. If character are not all unique, shrink the view by shifting the left until it is
    */

    /**
      0. Goal is to check increasingly larger substrings, starting from the left, until a repeating
      character happens, where left is shifted until the view no longer has repeating characters
      1. Create a window with bounds l,r
          - This view has no repeats, or it does
          - If it has no repeats, continue loop ()
          - If it has repeating characters, this repeating character is s[r], introduced in the current loop iteration
            - Need to update window and set in this case
            - So shift l until this character is no longer repeating in the view <=> in set
    */

    int l = 0;
    int max_size = 0;
    std::unordered_set<char> char_set{};
    char_set.reserve(s.size());

    for (int r = 0; r < s.size(); ++r) {
      // If not entering while loop, then no duplicates
      while (char_set.contains(s[r])) {
        char_set.erase(s[l]);
        ++l;
      }
      char_set.insert(s[r]);
      const int current_size = r - l + 1;
      max_size = std::max(max_size, current_size);
    }
    return max_size;
  }
};
