#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int k, int cnt, vector<vector<int>>& dungeons, vector<bool>& visited, int& max_cnt) {
    max_cnt = max(max_cnt, cnt);  
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) { 
            visited[i] = true;
            dfs(k - dungeons[i][1], cnt + 1, dungeons, visited, max_cnt);  
            visited[i] = false;  
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    vector<bool> visited(n, 0); 
    int max_cnt = 0;
    dfs(k, 0, dungeons, visited, max_cnt);

    return max_cnt;
}