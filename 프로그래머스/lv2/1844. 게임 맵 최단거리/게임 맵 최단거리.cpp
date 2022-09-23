#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
bool visited[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int sy = 0;
    int sx = 0;
    int ey = maps.size() - 1;
    int ex = maps[0].size() - 1;
    
    deque<pii> dq;
    dq.push_back({sy, sx});
    visited[sy][sx] = true;
    
    bool flag = false;
    while(!dq.empty()) {
        int dqSize = dq.size();
        for (int i = 0; i < dqSize; i++) {
            int py = dq[i].first;
            int px = dq[i].second;
            
            if (py == ey && px == ex) {
                flag = true;
                break;
            }
            
            for (int j = 0; j < 4; j++) {
                int ny = py + dy[j];
                int nx = px + dx[j];
                
                if (ny < sy || ny > ey) continue;
                if (nx < sx || nx > ex) continue;
                if (maps[ny][nx] == 0) continue;
                if (visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                dq.push_back({ny, nx});
            }
        }
        
        answer++;
        
        if (flag)
            break;
        else {
            for (int i = 0; i < dqSize; i++)
                dq.pop_front();
        }
    }
    if (visited[ey][ex] == false)
        answer = -1;
    return answer;
}