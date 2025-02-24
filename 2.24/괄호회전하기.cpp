#include <string>
#include <stack>
#include <queue>

using namespace std;

bool check(queue<char> q) {
    stack<char> st;
    while (!q.empty()) {
        char c = q.front();
        q.pop();

        if (c == '(' || c == '{' || c == '[') {
            st.push(c); 
        } else {
            if (st.empty()) return false;  
            char top = st.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                st.pop();  
            } else {
                return false;  
            }
        }
    }
    return st.empty(); 
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    queue<char> q;
    for (int i =0; i<s.size(); i++) q.push(s[i]);

    
    for (int i = 0; i < n; i++) {
        if (check(q)) 
            answer++;
       
        char front = q.front();
        q.pop();
        q.push(front);
    }

    return answer;
}
