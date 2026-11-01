#include <set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return not (nums.size() == std::set<int>(nums.begin(), nums.end()).size());
    }
};