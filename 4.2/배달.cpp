#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    
    vector<vector<pair<int,int>>> graph(N+1);  
    
    
    for(auto& edge : road) {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});  
    }
    
    
    vector<int> dist(N+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    dist[1] = 0; 
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cur_dist) continue;
        
        for(auto& next : graph[cur]) {
            int next_node = next.first;
            int next_dist = next.second + cur_dist;
            
            if(next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K) answer++;
    }
    
    return answer;
}

//전에푼거가져옴