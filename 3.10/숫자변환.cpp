#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
        if (x == y) return 0; 
    queue<pair<int, int>> q;  
    unordered_set<int> visited;
    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        vector<int> next = {cur + n, cur * 2, cur * 3};  

        for (int num : next) {
            if (num == y) return cnt + 1; 
            if (num < y && visited.find(num) == visited.end()) {
                q.push({num, cnt + 1});
                visited.insert(num);
            }
        }
    }

    return -1;  
}
