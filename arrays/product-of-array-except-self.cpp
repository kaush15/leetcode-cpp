// Problem: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/description/
// Approach: First calculate the prefix product then using the result and the original array calculate the product of array except self using the prefix and suffix variables
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        vector<int> result(nums.size(),1);
        
        for(int i=0;i<nums.size();i++){
            result[i]= prefix;
            prefix= prefix * nums[i];
        }
        int suffix=1;
        for(int i=nums.size()-1;i>=0;i--){
            result[i]= result[i] * suffix;
            suffix= suffix * nums[i];
        }
        return result;
    }
};
