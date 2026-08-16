// Problem: Continuous Subarray Sum
// Link: https://leetcode.com/problems/continuous-subarray-sum/
// Approach: Use the map to store the remainder of prefix sum and index and if the remainder is found again in the map than subtract the index of current element
// that matched the remainder index in the map
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder;
        remainder[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remain = sum%k;
            if(remainder.find(remain) == remainder.end()){
                remainder[remain]= i;
            }
            else{
                if(i- remainder[remain]>= 2){
                    return true;
                }
            }
        }
        return false;
    }
};
