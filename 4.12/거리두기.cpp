#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

bool checkRoom(vector<string>& room) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (room[i][j] != 'P') continue;

            queue<pair<pair<int, int>, int>> q;
            q.push(make_pair(make_pair(i, j), 0));

            vector<vector<bool>> visited(5, vector<bool>(5, false));
            visited[i][j] = true;

            while (!q.empty()) {
                pair<pair<int, int>, int> front = q.front();
                q.pop();

                int x = front.first.first;
                int y = front.first.second;
                int dist = front.second;

                if (dist >= 1 && room[x][y] == 'P') {
                    return false;
                }
                if (dist == 2) continue;

                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (!isValid(nx, ny) || visited[nx][ny]) continue;
                    if (room[nx][ny] == 'X') continue;

                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), dist + 1));
                }
            }
        }
    }
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& room : places) {
        if (checkRoom(room)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}
