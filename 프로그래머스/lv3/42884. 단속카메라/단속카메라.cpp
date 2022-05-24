#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1] ? true : false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    for (int i = 0; i < routes.size(); i++) {
        answer++;
        int ti = i;
        for (int j = i + 1; j < routes.size(); j++) {
            if (routes[j][0] <= routes[i][1] && routes[i][1] <= routes[j][1]) {
                ++ti;
            }
            else
                break;
        }
        i = ti;
    }
    
    return answer;
}