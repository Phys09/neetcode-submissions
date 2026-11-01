class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 2:
            return False
        nums = sorted(nums)

        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True

        # otherwise nothing
        return False