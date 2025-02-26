#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<pair<string, int>> style; 

    
    for (size_t i = 0; i < clothes.size(); i++) {
        string product = clothes[i][1];
        bool found = false;
        for (size_t j = 0; j < style.size(); j++) {
            if (style[j].first == product) {
                style[j].second++;
                found = true;
                break;
            }
        }

        if (!found) {
            style.push_back(make_pair(product, 1));
        }
    }

    int answer = 1;
    for (size_t i = 0; i < style.size(); i++) {
        answer *= (style[i].second + 1);
    }

    return answer - 1;
}

