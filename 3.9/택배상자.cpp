#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    deque<int> main;
    for(int i = 1; i <= order.size(); i++) {
        main.push_back(i);
    }
    deque<int> temp;    
    deque<int> dq;      
    int num = 0;       
    
    while(!main.empty() || !temp.empty()) {
        int k = -1;
        int j = -1;
        
        if(!main.empty())
            k = main.front();
        if(!temp.empty())
            j = temp.back();
            
        if(k == order[num]) {
            main.pop_front();
            dq.push_back(k);
            num++;
            answer++;
        }
        else if(j == order[num]) {
            temp.pop_back();
            dq.push_back(j);
            num++;
            answer++;
        }
        else if(!main.empty()) {
            temp.push_back(main.front());
            main.pop_front();
        }
        else {
            break; 
        }
    }
    return answer;
}