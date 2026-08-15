// Problem: Contains Duplicate II
// Link: https://leetcode.com/problems/contains-duplicate-ii/
// Approach: Unordered map to track the index of the i and j whose value are same and less than k
// Time: O(n) | Space: O(1)

#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(nums[i])) {
                if (i - visited[nums[i]] <= k) {
                    return true;
                }
            }
            visited[nums[i]] = i;
        }
        return false;
    }
};
