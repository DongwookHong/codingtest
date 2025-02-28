#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;  
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> m;  
    
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {  
            int num = 0;
            while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');  
                i++;
            }
            m[num]++;  
        }
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].first);
    }

    return answer;
}
