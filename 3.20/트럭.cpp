#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0; 
    int cur = 0; 
    queue<pair<int, int>> bridge; 

    int index = 0;

    while (index < truck_weights.size() || !bridge.empty()) {
        time++;

        if (!bridge.empty() && bridge.front().second == time) {
            cur -= bridge.front().first;
            bridge.pop();
        }


        if (index < truck_weights.size() && cur + truck_weights[index] <= weight && bridge.size() < bridge_length) {
            bridge.push({truck_weights[index], time + bridge_length});
            cur += truck_weights[index];
            index++;
        }
    }

    return time;
}

