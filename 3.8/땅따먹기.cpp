#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp; 

int back(vector<vector<int>>& land, int row, int prev_col) {
    int n = land.size();
    int m = land[0].size();

    if (row == n) return 0;
    if (prev_col != -1 && dp[row][prev_col] != -1) return dp[row][prev_col];

    int max_value = 0;

    for (int col = 0; col < m; col++) {
        if (col != prev_col) {
            max_value = max(max_value, land[row][col] + back(land, row + 1, col));
        }
    }

    if (prev_col != -1) dp[row][prev_col] = max_value;

    return max_value;
}

int solution(vector<vector<int>> land) {
    int row = land.size();
    int col = land[0].size();

    dp.resize(row, vector<int>(col, -1)); 
    int cnt =back(land, 0, -1);  
    return cnt;
}
// 내가푼거아님 포기 .. 나중에 다시보겠음 ..너무어렵 