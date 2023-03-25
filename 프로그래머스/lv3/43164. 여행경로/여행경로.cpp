#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> g_tickets;
vector<vector<string>> cand;
bool visited[10001];

void backtracking(vector<string> path, string target) {
    if (path.size() == g_tickets.size())
    {
        path.push_back(target);
        cand.push_back(path);
        return;
    }
    
    for (int i = 0; i < g_tickets.size(); ++i) {
        if (visited[i])
            continue;
        string start = g_tickets[i][0];
        string end = g_tickets[i][1];
        if (start == target) {
            visited[i] = true;
            path.push_back(start);
            backtracking(path, end);
            path.pop_back();
            visited[i] = false;
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    g_tickets = tickets;
    backtracking({}, "ICN");
    sort(cand.begin(), cand.end());
    return cand[0];
}