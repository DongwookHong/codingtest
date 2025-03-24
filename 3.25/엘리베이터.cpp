#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> pow_vec(10);
    pow_vec[0] = 1;

    for(int i = 1; i < 10; i++) {
        pow_vec[i] = pow_vec[i - 1] * 10;
    }
    sort(pow_vec.rbegin(), pow_vec.rend()); 

    int k = 0;
    int cnt = 0;
    
    for (int i = 0; i < pow_vec.size(); i++) {
        if (storey == 0) break; 
        k = storey % 10;  
        
        if (k > 5 || (k == 5 && (storey / 10) % 10 >= 5)) {
            cnt += (10 - k);
            storey += (10 - k);
        } else {

            cnt += k;
        }
        
        storey /= 10; 
    }
    
    return cnt;
}

