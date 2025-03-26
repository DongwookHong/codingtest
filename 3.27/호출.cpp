#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timetomin(string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    
    for (auto& booking : book_time) {
        int sttime = timetomin(booking[0]);
        int endtime = timetomin(booking[1]) + 10; 
        times.push_back({sttime, endtime});
    }
    

    sort(times.begin(), times.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto& time : times) {
        int st = time.first;
        int end = time.second;
        
        
        if (!pq.empty() && pq.top() <= st) {
            pq.pop(); 
        }
        
        pq.push(end); 
    }
    
    return pq.size(); 
}