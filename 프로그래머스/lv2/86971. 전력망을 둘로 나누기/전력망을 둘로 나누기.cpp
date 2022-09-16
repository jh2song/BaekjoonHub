#include <bits/stdc++.h>
using namespace std;

int global_n;
int adj[101][101];
bool visited[101];

int DFS(int node) {
    int ret = 1;
    
    for (int i = 1; i <= global_n; i++) {
        if (adj[node][i] == 1 && visited[i] == false) {
            visited[i] = true;
            ret += DFS(i);
        }
    }
    
    return ret;
}

int DiffCalculate() {
    // n:1부터 탐색
    // 탐색할 수 있는 모든 노드의 개수를 계산
    // global_n과 비교
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    int path1 = DFS(1);
    int path2 = global_n - path1;
    return abs(path1 - path2);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999;
    
    global_n = n;
    // 전선을 2차원 행렬로 변환
    for (int i = 0; i < wires.size(); i++) {
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }
    
    for (int i = 0; i < wires.size(); i++) {
        adj[wires[i][0]][wires[i][1]] = 0;
        adj[wires[i][1]][wires[i][0]] = 0;
        
        answer = min(answer, DiffCalculate());
        
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }
    
    return answer;
}