# Leetcode #15: https://leetcode.com/problems/3sum/description/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort() # Sort the numbers
        
        # Traverse the list and search for unique triplets (x, y, z) that sum to 0
        for x in range(len(nums) - 2):
            # Skip duplicates
            if x > 0 and nums[x] == nums[x - 1]:
                continue

            # Initialize indices for the 2nd and 3rd value
            y = x + 1
            z = len(nums) - 1

            # Traverse the list, starting from y and calculate the sum of the triplets
            while y < z:
                sum = nums[x] + nums[y] + nums[z]

                # If the sum is 0, add the triplet to the list of answers and skip duplicates
                if sum == 0:
                    ans.append([nums[x], nums[y], nums[z]])

                    while y < z and nums[y] == nums[y + 1]:
                        y += 1
                    while y < z and nums[z] == nums[z - 1]:
                        z -= 1

                    y += 1
                    z -= 1
                elif sum < 0:
                    y += 1  # Sum is too small, increment second index
                else:
                    z -= 1  # Sum is too large, decrement third index
            
        return ans
