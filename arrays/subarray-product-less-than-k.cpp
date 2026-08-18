// Problem: Subarray Product Less Than K
// Link: https://leetcode.com/problems/subarray-product-less-than-k/
// Approach: Used the sliding window concept 
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count=0;
        int left=0;
        int right=0;
        long long product=1;
        while(right< nums.size()){
            product= product* nums[right];
            while(product >= k && left<=right){
                product=product/nums[left];
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};
