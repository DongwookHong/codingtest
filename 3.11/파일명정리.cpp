#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;


bool compare(const tuple<int, string, int>& f1, const tuple<int, string, int>& f2) {
    if (get<1>(f1) == get<1>(f2)) {
        if (get<2>(f1) == get<2>(f2)) {
            return get<0>(f1) < get<0>(f2);  
        } else {
            return get<2>(f1) < get<2>(f2);  
        }
    } else {
        return get<1>(f1) < get<1>(f2);  
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<int, string, int>> v;  

    for (int i = 0; i < files.size(); i++) {
        string fileString = files[i];
        string HEAD = "";
        string NUMBER = "";
        int index = 0;

        
        for (int j = 0; j < fileString.length(); j++) {
            fileString[j] = tolower(fileString[j]);
        }

        
        while (index < fileString.length() && !isdigit(fileString[index])) {
            HEAD += fileString[index];
            index++;
        }

        
        while (index < fileString.length() && isdigit(fileString[index])) {
            NUMBER += fileString[index];
            index++;
        }

        
        v.push_back(make_tuple(i, HEAD, stoi(NUMBER)));
    }

    
    sort(v.begin(), v.end(), compare);  

    
    for (auto& file_tuple : v) {
        answer.push_back(files[get<0>(file_tuple)]);
    }

    return answer;
}
