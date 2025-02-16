#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(string s) {
    vector<int> num;
    string temp = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {  
            num.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i]; 
        }
    }
    
    num.push_back(stoi(temp));  
    

    int min= *min_element(num.begin(), num.end());
    int max= *max_element(num.begin(), num.end());
    
    temp = "";
    temp = to_string(min) + " "+ to_string(max);
    
    
    return temp; 
}
