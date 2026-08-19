// Problem: Maximum Points You Can Obtain from Cards
// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Approach: Calculated the total sum then the sum of k size window and each time added one element from the rear and removed one element from the front
// Time: O(n) | Space: O(1)

#include <iostrem>
#include <vector>
#include <numeric>
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total_sum=accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k==n) return total_sum;
        int windowsize= n-k;
        int currwinsum= accumulate(cardPoints.begin(), cardPoints.begin()+windowsize,0);
        int minwinsum=currwinsum;
        for(int i=windowsize;i<cardPoints.size();i++){
            currwinsum= currwinsum+cardPoints[i] - cardPoints[i-windowsize];
            minwinsum= min(minwinsum, currwinsum);
        }
        return total_sum- minwinsum;
    }
};
