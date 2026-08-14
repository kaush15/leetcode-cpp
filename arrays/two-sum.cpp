// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Approach: Unordered map to track the value of the target-first value
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int size=nums.size();
        vector<int> result;
        for(int i=0;i<size;i++){
            int first=nums[i];
            int sec=target-first;
            if(m.find(sec)!=m.end()){
                result.push_back(i);
                result.push_back(m[sec]);
                break;
            }
            m[first]=i;
        }
        return result;
    }
};
