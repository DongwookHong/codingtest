#include <string>
#include <vector>
#include <ctype.h> 

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();    
    if (isalpha(s[0]))
            answer +=toupper(s[0]);
    else
        answer+=s[0];
    for (int i =1; i < len ; i++)
    {
        if (s[i-1] == ' ' && isalpha(s[i]))
            answer += toupper(s[i]) ;
        else if (isalpha(s[i]))
            answer+=tolower(s[i]);
        else
            answer+=s[i];
    }
    
    return answer;
}