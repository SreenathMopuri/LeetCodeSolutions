/*
    Given int array, return true if any value appears at least twice
    Ex. nums = [1,2,3,1] -> true, nums = [1,2,3,4] -> false
    If seen num previously then has dupe, else insert into hash set
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // creating Hash set to store the values
        unordered_set<int> uniqueNumbers;
        // Loop until it exit
        for (int i = 0; i < nums.size(); i++) {
            // checking whether the number exists in Hash set or not, If exists will return True.
            if (uniqueNumbers.find(nums[i]) != uniqueNumbers.end()) {
                return true;
            }
            uniqueNumbers.insert(nums[i]); // Inserting num into hash set
        }
        return false;
    }
};
