// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/
// Approach: Using boyer-moore algorithm 
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate= nums[i];
            }
            if(candidate == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};
