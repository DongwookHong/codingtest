#include <string>
#include <vector>
#include <iostream>
#include <queue>
int n,m;

using namespace std;
vector<string> bd;
vector <vector<int> > visit;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int cnt ;
int st,sy,lx,ly,ex,ey;

int bfs(int x,int y, int destx, int desty) 
{
    queue<pair <int ,int> > q;
    q.push(make_pair(x,y));
    visit[x][y] = 0;
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        
        q.pop();
        
        for (int i =0; i < 4; i++)
        {
            int mx = curx+ dx[i];
            int my = cury+ dy[i];
            
            if (mx <0 || mx >= n || my <0 || my >=m || bd[mx][my] =='X')
                continue;
            if (visit[mx][my] == -1)
            {  
                visit[mx][my] = visit[curx][cury] +1;
                q.push(make_pair(mx,my));
            }
        }
        
    }

    cnt = visit[destx][desty];
   return  cnt;
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0]. size();
   
  
    bd = maps;
    visit.resize(n,vector<int>(m,-1));
    for (int i =0; i< n ; i++)
    {
        for (int j =0; j < m ;j++)
        {
            if (maps[i][j] == 'S')
            {
                st = i;
                sy= j;
            }
            
            else if (maps[i][j] == 'L')
            {
                lx = i;
                ly= j;
            }
             else if (maps[i][j] == 'E')
            {
                ex = i;
                ey= j;
            }
        }
    }
    
    int lenl=0;
    lenl= bfs(st,sy,lx,ly);
    if (lenl == -1) return -1;
    int lene=0;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visit[i][j] = -1;
        }
    }
    
    lene= bfs(lx,ly,ex,ey);
    if (lene == -1) return -1;
    answer = lenl+lene;
    return answer;
        
    
}

