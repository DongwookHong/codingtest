#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int a, int b, int c, vector<vector<int>>& result) {
    if (n == 1) {
        result.push_back({a, c});
        return;
    }
    hanoi(n - 1, a, c, b, result);
    result.push_back({a, c});
    hanoi(n - 1, b, a, c, result);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> result;
    hanoi(n, 1, 2, 3, result); 
    return result;
}