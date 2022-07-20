/*
Leetcode Link:
https://leetcode.com/problems/top-k-frequent-elements/

Description:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Sol:
Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // creating map data structure for counting the each number in array
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        // Initializing MaxHeap for getting max count value
        priority_queue<pair<int, int>>pq;
        
        for(auto it: mp)
            pq.push({it.second, it.first});
        
        vector<int> ans;
        int cnt = 0;
        // We are retrieving upto k elements from Heap
        while (cnt < k)
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            cnt++;
        }
        return ans;
    }
};
