# LeetCode 06
# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
# Notice that the solution set must not contain duplicate triplets.
from typing import List


from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sort the array to facilitate the two-pointer approach and avoid repeated calculation
        result = []
        n = len(nums)

        for i in range(n - 2):  # Fix the first number nums[i]
            # same continual elements in a loop lead to duplication, the latter solution is a subset of the former
            if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicate elements to avoid hash
                continue

            left, right = i + 1, n - 1  # Define two pointers
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total == 0:
                    result.append([nums[i], nums[left], nums[right]])  # Store the valid triplet
                    left += 1
                    right -= 1

                    # Skip duplicate elements
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1

                elif total < 0:
                    left += 1  # Increase the sum
                else:
                    right -= 1  # Decrease the sum

        return result
