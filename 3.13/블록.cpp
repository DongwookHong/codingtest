
//못풀겠는데요 ?? .... 다른사람꺼 참고함 ..
#include <string>
#include <vector>
#include <set>

using namespace std;

int row, col;
vector<string> kakao;

void changebox() {
    for (int j = 0; j < col; j++) {  
        string newcol = "";
        for (int i = 0; i < row; i++) {
            if (kakao[i][j] != '.') {
                newcol += kakao[i][j];
            }
        }

        while (newcol.size() < row) {
            newcol = "." + newcol;
        }

        for (int i = 0; i < row; i++) {
            kakao[i][j] = newcol[i];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    row = m;
    col = n;
    kakao = board;
    int answer = 0;

    while (true) {
        set<pair<int, int>> rmsquare;
        
        for (int i = 0; i < row - 1; i++) {
            for (int j = 0; j < col - 1; j++) {
                char block = kakao[i][j];
                if (block != '.' && block == kakao[i][j+1] && block == kakao[i+1][j] && block == kakao[i+1][j+1]) {
                    rmsquare.insert({i, j});
                    rmsquare.insert({i, j+1});
                    rmsquare.insert({i+1, j});
                    rmsquare.insert({i+1, j+1});
                }
            }
        }

        if (rmsquare.empty()) break; 
        for (auto [x, y] : rmsquare) {
            kakao[x][y] = '.';
        }

        answer += rmsquare.size();
        changebox();
    }

    return answer;
}