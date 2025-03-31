#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> comcnt;
vector<string> answer;

void gencom(string order, string comb, int index, int targetSize) {
    if (comb.size() == targetSize) {
        comcnt[comb]++;
        return;
    }
    for (int i = index; i < order.size(); i++) {
        gencom(order, comb + order[i], i + 1, targetSize);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (auto& order : orders) {
        sort(order.begin(), order.end()); 
    }
    
    for (int courseSize : course) {
        comcnt.clear();
        for (auto& order : orders) {
            if (order.size() >= courseSize) {
                gencom(order, "", 0, courseSize);
            }
        }
        
        int maxCount = 0;
        for (auto& pair : comcnt) {
            if (pair.second >= 2) {
                maxCount = max(maxCount, pair.second);
            }
        }
        
        for (auto& pair : comcnt) {
            if (pair.second == maxCount && maxCount >= 2) {
                answer.push_back(pair.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}