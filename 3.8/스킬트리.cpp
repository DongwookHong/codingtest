#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0; 
    vector<char> v;   
    vector<char> temp;
    for (int i = 0; i < skill.size(); i++)
        v.push_back(skill[i]);
    
    for(int j = 0; j < skill_trees.size(); j++) {
        temp = v;
        bool is_valid = true;  
        for(int k = 0; k < skill_trees[j].size(); k++) {
            if (skill.find(skill_trees[j][k]) != string::npos)
                if (!temp.empty() && skill_trees[j][k] == temp.front()) {
                    temp.erase(temp.begin());
                }
                else {
               is_valid = false;
                break; 
            }
            
        }
        if (is_valid)
            answer++;  
    }
    
    return answer; 
}