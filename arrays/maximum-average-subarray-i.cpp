// Problem: Maximum Average Subarray I
// Link: https://leetcode.com/problems/maximum-average-subarray-i/
// Approach: Sliding Window Concept
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <numeric>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n= nums.size();
        double windowsum= accumulate(nums.begin(), nums.begin()+k,0.0);
        double windowaverage= windowsum/k;
        double maxaverage=windowaverage;
        for(int i=k;i<n;i++){
            windowsum=windowsum+ nums[i] - nums[i-k];
            windowaverage= windowsum/k;
            maxaverage= max(windowaverage, maxaverage);
        }
        return maxaverage;
    }
};
