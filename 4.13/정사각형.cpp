#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dp = board;
    int max_value = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1) {
                max_value = 1; 
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                max_value = max(max_value, dp[i][j]);
            }
        }
    }

    return max_value * max_value;
}

//옛날에푼게있었네요 ㅎㅎ