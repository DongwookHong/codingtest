#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int column;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if (v1[column] == v2[column])
        return v1[0] > v2[0];
    return v1[column] < v2[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    column = col - 1;
    sort(data.begin(), data.end(), cmp);

    int answer = 0;
    int numCols = data[0].size();

    for (int i = row_begin; i <= row_end; ++i) {
        int total = 0;
        for (int j = 0; j < numCols; ++j) {
            total += data[i - 1][j] % i;
        }
        answer ^=total;
    }

    return answer;
}

//문제가 간단한거같은데 xor연산을 공부하는데 시간이좀걸렸다 .