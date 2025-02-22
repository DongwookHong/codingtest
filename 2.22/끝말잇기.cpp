#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> dup; 
    
    dup.insert(words[0]);  

  for (int i = 1; i < words.size(); i++) {
    int k = words[i - 1].size(); 
    if (words[i - 1][k - 1] != words[i][0] || dup.count(words[i])) {
        int wrong = (i / n) + 1;  
        int ppl = (i % n) + 1;    
        return {ppl, wrong}; 
    }

    dup.insert(words[i]);  
}

    return {0, 0}; 
}

//unordered_set 사용하기 , set  의 속도는 (O(log N)	) 정렬이되고 , unordered 정렬 x(최악일 경우 o(N))