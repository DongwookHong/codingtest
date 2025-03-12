

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
