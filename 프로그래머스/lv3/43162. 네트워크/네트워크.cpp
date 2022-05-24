#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
bool visited[200];

void DFS(int i, int n) {
    visited[i] = true;
    for (int j = 0; j < n; j++) {
        if (visited[j])
            continue;
        
        if (adj[i][j] == 1 || adj[j][i] == 1)
            DFS(j, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    adj = computers;
    
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        DFS(i, n);
        answer++;
    }
    
    return answer;
}