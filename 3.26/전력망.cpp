#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int minval = n;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n + 1);
        
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue; 
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }
        
        vector<bool> visited(n + 1, false);
        int cnt1 = bfs(1, graph, visited);
        int cnt2 = n - cnt1; 
        
        minval = min(minval, abs(cnt1 - cnt2));
    }
    
    return minval;
}