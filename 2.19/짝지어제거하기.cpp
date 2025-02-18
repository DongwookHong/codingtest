#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stck;

    for (int i = 0; i < s.size(); i++) {
        if (!stck.empty() && stck.top() == s[i]) 
            stck.pop();
        else 
            stck.push(s[i]); 
    }
    return stck.empty(); 
}
