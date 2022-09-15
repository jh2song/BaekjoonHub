#include <bits/stdc++.h>
using namespace std;

bool visited[8];
int answer = -1;

void Backtracking(int k, vector<vector<int>> dungeons, int ret) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i])
            continue;
        
        // 해당 던전을 돌았을때 조건에 충족되지 않다면 continue 해줘야됨
        if (k < dungeons[i][0]) // 최소피로도보다 현재 k가 더 작다면 continue
            continue;
        
        visited[i] = true;
        Backtracking(k - dungeons[i][1], dungeons, ret + 1);
        visited[i] = false;
    }
    
    answer = max(answer, ret);
}

int solution(int k, vector<vector<int>> dungeons) {
    Backtracking(k, dungeons, 0);
    return answer;
}