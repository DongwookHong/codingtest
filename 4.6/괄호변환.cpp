#include <string>
#include <vector>
#include <stack>

using namespace std;


bool check(string input) {
    stack<char> st;
    for (char c : input) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}


string solution(string p) {
    if (p.empty()) return "";

    string u, v;
    int left = 0, right = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') left++;
        else right++;

        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u)) {
        return u + solution(v);
    } 
    
    else {
        string answer = "(";             
        answer += solution(v);           
        answer += ")";                   

        
        u = u.substr(1, u.length() - 2);
        for (char c : u) {
            answer += (c == '(') ? ')' : '(';
        }

        return answer;
    }
}
