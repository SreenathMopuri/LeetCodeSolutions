/*
Leetcode Link:
https://leetcode.com/problems/product-of-array-except-self/

Description:
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i]
 
 Example1:
 Input: nums = [1,2,3,4]
 Output: [24,12,8,6]
 Example2:
 Input: nums = [-1,1,0,-3,3] 
 Output: [0,0,9,0,0]
    
Solution:
    Calculate prefix products forward, then postfix backwards in a 2nd pass
    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        // Initialize prefix with 1 
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix; // skipping i'th position
            prefix = prefix * nums[i];
        }
        // Initialize postfix with 1
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }    
        return result;
    }
};
