#include <bits/stdc++.h>
using namespace std;

string g_target;
vector<string> g_words;
map<string, bool> visited;

int BFS(string begin, int count) {
    int ret = INT_MAX;
    
    if (begin == g_target) {
        return count;
    }
    
    for (string word : g_words) {
        // Need to validate if begin is changable to word
        // And change for begin to word
        int matchlessCount = 0;
        for (int i = 0; i < begin.length(); i++) {
            if (begin[i] != word[i]) {
                matchlessCount++;
            }
        }
        
        if (matchlessCount <= 1 && visited[word] == false) {
            visited[word] = true;
            ret = min(ret, BFS(word, count + 1));
            visited[word] = false;
        }
    }
    
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    g_target = target;
    g_words = words;
    
    answer = BFS(begin, 0);
    if (answer == INT_MAX)
        answer = 0;
    
    return answer;
}