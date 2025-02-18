#include <string>
#include <vector>
#include <iostream>
using namespace std;

void toBinary(int num, string &str) {
    while (num > 0) {
        str = to_string(num % 2) + str; 
        num /= 2;  
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0; 
    int trcnt = 0;  

    while (s != "1") {
        int rmzero = 0;
        string temp = "";  

        
        for (auto ch : s) {
            if (ch == '0') 
                cnt++;  
            else 
                temp += ch;  
        }
        string str= "";
        toBinary(temp.size(), str);  
        s = str;  
        trcnt++;  
    }

    answer.push_back(trcnt);  
    answer.push_back(cnt);  
    return answer;
}

// auto 함수 사용 해보보기 함수 기존 c, c++ 에서는 타입을  선언하여 사용한 한반면에 auto를 사용하면 컴파일동안에 타입을 추론하여 쓸 수있다고한다 ,
// 컴파일동안에 추론 과정이 있기 때문에 사실상 실행 시간 영향 x 
