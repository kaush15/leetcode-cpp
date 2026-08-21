// Problem: Intersection of Two Arrays II
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Approach: Sort the both arrays then run a loop in both the arrays at same time
// Time: O(m.n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0;
        int j=0;
        vector<int> result;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]< nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }
        return result;
    }
};
