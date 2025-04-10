#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq; 
    int answer = 0;

    for (int i = 0; i < enemy.size(); ++i) {
        pq.push(enemy[i]);
        n -= enemy[i];

        if (n < 0) {
            if (k > 0) {
                n += pq.top(); 
                pq.pop(); 
                k--;
            } else {
                break;
            }
        }
        answer++;
    }

    return answer;
}
