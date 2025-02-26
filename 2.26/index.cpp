#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cit) {
    sort(cit.rbegin(), cit.rend()); 
    int h = 0;
    for (int i = 0; i < cit.size(); i++) {
        if (cit[i] >= i + 1) 
            h = i + 1;
        else 
            break;
    }
    
    return h;
}