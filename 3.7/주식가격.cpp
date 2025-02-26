#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int k = 0;
    for (int i = 0; i < prices.size();i++)
    {
        k=0;
        for (int j = i+1;j<prices.size();j++)
        {
            k++;
            if (prices[j]<prices[i])
                break;
        
        }
        answer.push_back(k);
    }
    return answer;

}