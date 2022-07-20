/*
Leetcode Link:
https://leetcode.com/problems/group-anagrams/

Description:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example:
Input1: strs = ["eat","tea","tan","ate","nat","bat"]
Output1: [["bat"],["nat","tan"],["ate","eat","tea"]]

Input2: strs = [""]
Output2: [[""]]

Input3: strs = ["a"]
Output3: [["a"]]

Sol:
 Count chars, for each string use total char counts (naturally sorted) as key
 Time: O(n x l) -> n = length of strs, l = max length of a string in strs
 Space: O(n x l)
 
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // creating map to store values, key->value pairs
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        // result data structure to store the results
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    // getting the key for each "string"
    string getKey(string str) {
        // counting the characters
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        // getting key as "count values of each character and converts to string"
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};
