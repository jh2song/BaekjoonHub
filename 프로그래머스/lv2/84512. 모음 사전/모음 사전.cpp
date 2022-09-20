#include <bits/stdc++.h>
using namespace std;

int answer = 0;
bool solved = false;
string global_word;

void Backtracking(string now_word) {
    if (now_word == global_word) {
        solved = true;
        return;
    }    
    
    if (!solved && now_word.length() < 5) {
        answer++;
        Backtracking(now_word + "A");
    }
    if (!solved && now_word.length() < 5) {
        answer++;
        Backtracking(now_word + "E");
    }
    if (!solved && now_word.length() < 5) {
        answer++;
        Backtracking(now_word + "I");
    }
    if (!solved && now_word.length() < 5) {
        answer++;
        Backtracking(now_word + "O");
    }
    if (!solved && now_word.length() < 5) {
        answer++;
        Backtracking(now_word + "U");
    }
    
    return;
}

int solution(string word) {
    global_word = word;
    
    Backtracking("");
    
    return answer;
}