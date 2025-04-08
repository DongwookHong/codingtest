#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MAP[110][110]; 

int Turning(int x, int y, int xx, int yy)
{
    int temp = MAP[x][y];
    int min_num = temp;

    for (int i = x; i < xx; ++i) {
        MAP[i][y] = MAP[i + 1][y];
        min_num = min(min_num, MAP[i][y]);
    }
    for (int i = y; i < yy; ++i) {
        MAP[xx][i] = MAP[xx][i + 1];
        min_num = min(min_num, MAP[xx][i]);
    }
    for (int i = xx; i > x; --i) {
        MAP[i][yy] = MAP[i - 1][yy];
        min_num = min(min_num, MAP[i][yy]);
    }
    for (int i = yy; i > y + 1; --i) {
        MAP[x][i] = MAP[x][i - 1];
        min_num = min(min_num, MAP[x][i]);
    }
    MAP[x][y + 1] = temp;

    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    int num=1;
   for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            MAP[i][j] = num++;

    for (const auto& q : queries) {
        int x = q[0] - 1;
        int y = q[1] - 1;
        int xx = q[2] - 1;
        int yy = q[3] - 1;

        answer.push_back(Turning(x, y, xx, yy));
    }

    return answer;
}
