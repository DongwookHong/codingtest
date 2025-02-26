#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(vector<int> scov, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq(scov.begin(), scov.end());
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }
    if (pq.top() < K)    return -1;
    return answer;
}

//풀기 실패  priorty queue를 공부하라 


//시간초과 ..



// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int solution(vector<int> scov, int K) {
    
//     int cnt =0;
    
//     sort(scov.begin(),scov.end());
    
//     while(scov.size()>1)
//     {
//         int first = scov[0];
//         int second = scov[1];
        
//         int  ex = first + (second * 2);
        
//         scov[0] = ex;
//         scov.erase(scov.begin() + 1); 
//         sort(scov.begin(), scov.end());

//         cnt ++;
//         if (scov[0] >= K) {
//             return cnt;
//         }
//     }
//     return -1;
// }

