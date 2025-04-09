#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int x, y, tx, ty;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
            } else if (board[i][j] == 'G') {
                tx = i;
                ty = j;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1};

    queue<tuple<int, int, int>> q; 
    q.push(make_tuple(x, y, 0));
    visited[x][y] = true;

    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        if (x == tx && y == ty) return cnt;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x;
            int ny = y;

            while (true) {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];

                if (tx < 0 || ty < 0 || tx >= n || ty >= m || board[tx][ty] == 'D') break;
                nx = tx;
                ny = ty;
            }

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, cnt + 1));
            }
        }
    }

    return -1; 
}
