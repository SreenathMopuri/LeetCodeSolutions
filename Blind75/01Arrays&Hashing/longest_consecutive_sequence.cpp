/*
Leetcode Link: 
https://leetcode.com/problems/longest-consecutive-sequence/

Description:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Store in hash set, only check for longer seq if it's the beginning
Time: O(n)
Space: O(n)
*/
 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       // inserting all elements into hashset
        unordered_set<int> s(begin(nums), end(nums)); 
        int longest = 0;
        for (auto& num : s)
        {
            int curr_largest = 1;
            // find consecutive elements in the backwrd and forward direction
            for (int j = 1; s.count(num-j);j++) s.erase(num-j), curr_largest++;
            for (int j = 1; s.count(num+j); j++) s.erase(num+j), curr_largest++;
            longest = max(curr_largest, longest);
        }
        return longest;
    }
};
