// Problem: Matrix Block Sum
// Link: https://leetcode.com/problems/matrix-block-sum/
// Approach: Used the function 
// Time: O(m.n.k^2) | Space: O(1)

#include <iostream>
#include <vector>
class Solution {
public:
    int value(vector<vector<int>> &mat,int k, int i, int j){
        int sum=0;
        for(int r=i-k;r<=i+k;r++){
            for(int c=j-k;c<=j+k;c++){
                if(r>=0 && r<mat.size() && c>=0 && c<mat[0].size()){
                    sum+= mat[r][c];
                }
            }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rowsize= mat.size();
        int colsize= mat[0].size();
        vector<vector<int>> result(rowsize, vector<int>(colsize, 0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int newval= value(mat, k,i,j );
                result[i][j] = newval;
            }
        }
        return result;
    }
};


//Optimized Approach
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // 1. Build a 2D prefix sum array (size: (m+1) x (n+1))
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        
        // 2. Calculate the block sum for each cell in O(1) time
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Define the bounding box indices with boundary clamping
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);
                
                // Use the inclusion-exclusion formula on prefix sum
                result[i][j] = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            }
        }
        
        return result;
    }
};
