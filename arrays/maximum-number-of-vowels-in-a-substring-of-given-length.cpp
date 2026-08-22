// Problem: Maximum Number of Vowels in a Substring of Given Length
// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Approach: Used fixed sliding window concept
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(s[i] == 'a'|| s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'){
                count++;
            }
        }
        int maxcount=0;
        maxcount = max(maxcount, count);
        for(int right= k;right<s.length();right++){
            if(s[right] == 'a'|| s[right] == 'e'|| s[right] == 'i'|| s[right] == 'o'|| s[right] == 'u'){
                count++;
            }
            int left = right-k;
            if(s[left] == 'a'|| s[left] == 'e'|| s[left] == 'i'|| s[left] == 'o'|| s[left] == 'u'){
                count--;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
