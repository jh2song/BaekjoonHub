#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int j = y1; j <= y2; j++)
            for (int k = x1; k <= x2; k++)
                board[j][k] = 1;
    }
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int j = y1 + 1; j < y2; j++)
            for (int k = x1 + 1; k < x2; k++)
                board[j][k] = 0;
    }
    
    queue<pair<int, int>> q;
    q.push({characterY, characterX});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == itemY && x == itemX)
            break;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (board[ny][nx] == 1) {
                board[ny][nx] = board[y][x] + 1;
                q.push({ny, nx});   
            }
        }
    }
    
    answer = (board[itemY][itemX] - 1) / 2;
    return answer;
}