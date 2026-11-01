#include <ranges>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans{};
        // blind attempt at brute force

        size_t N = nums.size();
        for (size_t i{}; i < N; ++i) {
            for (size_t j{}; j < N; ++j) {
                for (size_t k{}; k < N; ++k) {
                    const bool indices_all_different = (i != j and i != k and j != k);
                    const bool indices_order_correct = (i < j and j < k);
                    const bool valid_index_combination = (indices_order_correct and indices_all_different);
                    if (valid_index_combination) {
                        if (bool sum_to_zero = (nums[i] + nums[j] + nums[k] == 0)) {
                            print_indices(i,j,k);
                            auto v = std::vector<int>({nums[i], nums[j], nums[k]});
                            std::ranges::sort(v);
                            if (std::ranges::find(ans, v) == ans.end()) {
                                ans.emplace_back(v.begin(), v.end());
                            }
                        }
                    }
                }
            }
        }
        return ans;
        // 1,2,0 or 1,2,1
    }
private:
static void print_indices(size_t i, size_t j, size_t k) {
    std::cout << "[" << i << "," << j << "," << k << "]\n";
}
};
