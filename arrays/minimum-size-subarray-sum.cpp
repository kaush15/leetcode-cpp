// Problem: Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Approach: Use sliding window concept to find the min length of subarray
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        long long sum=0;
        int minlength=INT_MAX;
        while(right < nums.size()){
            sum= sum+nums[right];
            while(sum >= target){
                minlength= min(minlength, right-left+1);
                sum=sum-nums[left];
                left++;
            }
            right++;
        }
        return (minlength == INT_MAX)? 0: minlength;
    }
};
