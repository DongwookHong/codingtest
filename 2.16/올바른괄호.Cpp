#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt = 0; 
    
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == '(') 
            cnt++; 
        else if (s[i] == ')') 
            cnt--; 
        if (cnt < 0) { 
            return false;
        }
    }
    if (cnt == 0)
        return true;
    return false; 
}

//스택
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> pare;
     
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            pare.push(s[i]); 
        } else if (s[i] == ')') {
            if (pare.empty()) {
                return false;
            }
            pare.pop();  
        }
    }
    if  (pare.empty())
        return answer;
    return false;
}

