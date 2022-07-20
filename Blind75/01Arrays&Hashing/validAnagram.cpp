/*
Leet Code Link: https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Ex:
Input1: s = "anagram", t = "nagaram" ==> true
Input2: s = "rat", t = "car" ==> false

Solution:
Count chars, strings should have same # of chars if anagram
Time: O(n)
Space: O(26)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Checking s & t size same or not, if not we can return false
        if (s.size() != t.size()) {
            return false;
        }
        // creating vector<int> to count the characters
        vector<int> charsCount(26);
        // counting input "s" character counts
        for (int i = 0; i < s.size(); i++) {
            charsCount[s[i] - 'a']++;
        }
        // validating input "t" character's count with "s"
        for (int j = 0; j < t.size(); j++) {
            charsCount[t[j] - 'a']--;
            if (charsCount[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
