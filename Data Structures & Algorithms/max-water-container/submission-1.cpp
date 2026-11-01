class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_volume = 0;
        int l{0}, r{heights.size() - 1};
        while (l < r) {
            int base = r-l;
            int volume = (base * std::min(heights[l], heights[r]));
            max_volume = volume > max_volume ? volume : max_volume;
            (heights[l] < heights[r]) ? l++ : r--;
        }

        return max_volume;
    }
};
