class Solution {
public:
  bool isPalindrome(string s) {
    // Point to each character left and right
    // compare each tolower character until l < r is false
    // cases: it's not alphanumeric

    if (s.size() <= 1) {
      return true;
    }

    size_t l = 0;
    size_t r = s.size() - 1;
    while (l < r) {
      auto left = std::tolower(s[l]);
      auto right = std::tolower(s[r]);
      if (not std::isalnum(left)) {
        l++;
      } else if (not std::isalnum(right)) {
        r--;
      } else if (left != right) {
        return false;
      } else {
        l++;
        r--;
      }
    }
    return true;
  }
};