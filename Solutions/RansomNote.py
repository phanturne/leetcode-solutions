# Leetcode #383: https://leetcode.com/problems/ransom-note/
# Source: https://leetcode.com/problems/ransom-note/discuss/85837/O(m%2Bn)-one-liner-Python

# Solution 1 (Counter) | O(m + n) time, O(1) space
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return Counter(ransomNote) <= Counter(magazine)
      
# Solution 2 (Dictionary) | O(m + n) time, O(1) space
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict = [0] * 26
            
        # Stores the count of each letter in the magazine
        for letter in magazine:
            dict[ord(letter) - ord('a')] += 1
        
        # For each letter in the ransomNote, subtract 1 from the magazine
        for letter in ransomNote:
            # If the count of any letter in the dict becomes < 0, the note can't be constructed
            dict[ord(letter) - ord('a')] -= 1
            if dict[ord(letter) - ord('a')] < 0:
                return False
            
        return True
