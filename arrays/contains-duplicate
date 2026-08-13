// Problem: Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/
// Approach: Unordered Set for easy checking of duplicacy
// Time: O(n) | Space: O(n)

#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};
