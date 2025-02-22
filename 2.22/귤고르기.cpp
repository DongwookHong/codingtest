#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int cnt =0;;
    int n = *max_element(tangerine.begin(), tangerine.end());
   
    vector <int> tan(n+1, 0);
    
    for(int i = 0; i < tangerine.size(); i++)
        tan[tangerine[i]]+=1; 
    sort(tan.begin(), tan.end(), greater<int>()); 

    for(int i = 0 ; i<n;i++)
    {        
        if ( k <=0)
            break;
        k-= tan[i];
        cnt +=1;
    }
    return cnt;
}