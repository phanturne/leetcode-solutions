# Leetcode #242:
# Source:

# Solution 1 (2 Dictionaries) | O(n) time, O(n) space
# Note: Can use 2 array initialized to [0] * 26 instead
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Create 2 dictionaries to store the count of each letter in each string
        dict1, dict2 = {}, {}

        # Iterate over the strings and update the dicts. 
        # If the char is not in the dict, set it to 0 + 1 = 1. Else just increment it.
        for char in s:
            dict1[char] = dict1.get(char, 0) + 1
        for char in t:
            dict2[char] = dict2.get(char, 0) + 1

        # The strings are anagrams if the dicts are equal
        return dict1 == dict2
      
# Solution 2 (1 Array) | O(n) time, O(n) space
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Create an array to store the "net count" of each letter
        netCount = [0] * 26

        # Iterate over the 1st string and increment the count of each letter
        # ord(char) - ord('a') gives a unique value between 0 and 25, which is its index in the array
        for char in s:
            netCount[ord(char) - ord('a')] += 1

        # Iterate over the 2nd string and decrement the count of each letter
        for char in t:
            netCount[ord(char) - ord('a')] -= 1

        # Check if the net count of each letter is 0. Return false if its not
        for count in netCount:
            if count != 0:
                return False

        # All letters from s were used in t exactly once and t doesn't use extra letters
        return True

# Solution 3 (Sorted() Function) | O(nlogn) time, O(n) space
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # If the 2 strings are anagrams, they must be the same string after sorting
        return sorted(s) == sorted(t)
