#include <cmath>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    
    vector<int> com(n);
    for (int i = 0; i < n; i++) {
        // ceil을 사용하여 올림 처리
        com[i] = ceil((100.0 - progresses[i]) / speeds[i]); 
    }

    int today = com[0]; 
    int cnt = 1; 

    for (int i = 1; i < n; i++) {
        if (com[i] <= today) {
            cnt++;
        } else {
            answer.push_back(cnt);
            today = com[i]; 
            cnt = 1;
        }
    }

    answer.push_back(cnt);
    
    return answer;
}



//마지막 테스트 케이스에서 계속 통과를 못함 
// 그래서원인을 찾아보니 계산할때 올림이 되지않아서 계속 틀렸던거같음 .//  
//사실 계속 해도 못찾았을거같음...

// #include <vector>
// #include <cmath>

// using namespace std;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     int n = progresses.size();
    
//     vector<int> com(n);
//     for (int i = 0; i < n; i++) {
//         com[i] = (100 - progresses[i] ) / speeds[i]; 
//     }
//     //5,10,1,1,20,1
//     int today = com[0]; 
//     int cnt = 1; 

//     for (int i = 1; i < n; i++) {
//         if (com[i] <= today) {
//             cnt++;
//         } else {
//             answer.push_back(cnt);
//             today = com[i]; 
//             cnt = 1;
//         }
//     }

//     answer.push_back(cnt);
    
//     return answer;
// }


// 원래코드 