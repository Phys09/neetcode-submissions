class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set_nums = set(nums)
        if len(nums) == len(set_nums):
           return False
        return True