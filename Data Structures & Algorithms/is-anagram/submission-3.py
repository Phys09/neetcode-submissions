class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_char_frequency = {}
        t_char_frequency = {}

        # Populate s_char_frequency
        for s_i in s:
            if not s_i in s_char_frequency:
                s_char_frequency[s_i] = 0
            else:
                s_char_frequency[s_i] += 1

        # Populate t_char_frequency
        for t_i in t:
            if not t_i in t_char_frequency:
                t_char_frequency[t_i] = 0
            else:
                t_char_frequency[t_i] += 1
                
        return t_char_frequency == s_char_frequency