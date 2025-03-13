

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> nic;
    vector<pair<string, string>> msg;  

    for (string& entry : record) {
        stringstream ss(entry);
        string command, uid, user;
        ss >> command >> uid; 
        
        if (command == "Enter" || command == "Change") {
            ss >> user;
            nic[uid] = user; 
        }
        
        if (command == "Enter" || command == "Leave") {
            msg.push_back(make_pair(uid, command));
        }
    }

    vector<string> result;
    for (auto& [uid, action] : msg) {
        string user = nic[uid];
        if (action == "Enter") {
            result.push_back(user + "님이 들어왔습니다.");
        } else { 
            result.push_back(user + "님이 나갔습니다.");
        }
    }

    return result;
}




// 시간 초과 탐색을 하는데 시간이 오래걸 려서 코드 수정이 필요했음 ,
// vector 에서 탐색으로해서 user를 찾고 하는시간이 O(N)으로 너무오래걸려서 시간초과가 나옴 그래서 gpt 물어보니까
// map을 활용해서 풀어줬다 . ..  너무 속도 차이가많이나고 가독성도 뛰어나게 바꿔줬다 .. 반성해야겠다 

// #include <string>
// #include <vector>
// #include <sstream>

// using namespace std;

// vector<string> solution(vector<string> record) {
//     vector<pair<string, string>> nic; 
//     vector<pair<string, string>> msg; 

//     for (string& entry : record) {
//         stringstream ss(entry);
//         string command, uid, user;
//         ss >> command >> uid; 
        
//         if (command == "Enter" || command == "Change") {
//             ss >> user;
//             bool found = false;

//             for (auto& p : nic) {
//                 if (p.first == uid) {
//                     p.second = user;
//                     found = true;
//                     break;
//                 }
//             }

//             if (!found) {
//                 nic.push_back({uid, user});
//             }
//         }
        
//         if (command == "Enter" || command == "Leave") {
//             msg.push_back({uid, command});
//         }
//     }

//     vector<string> result;
//     for (auto& [uid, action] : msg) {
//         string user = "";
    
//         for (auto& p : nic) {
//             if (p.first == uid) {
//                 user = p.second;
//                 break;
//             }
//         }

//         if (action == "Enter") {
//             result.push_back(user + "님이 들어왔습니다.");
//         } else {
//             result.push_back(user + "님이 나갔습니다.");
//         }
//     }

//     return result;
// }
