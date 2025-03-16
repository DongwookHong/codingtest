#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (string a, string b)
{
     return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> arr;
    
     for (int num : numbers) {
        arr.push_back(to_string(num));
    }
    
    sort(arr.begin(), arr.end(), compare);

    for (string s : arr) {
        answer += s;
    } 
    
    if (answer[0] =='0')
        return "0";
    
    return answer;
}