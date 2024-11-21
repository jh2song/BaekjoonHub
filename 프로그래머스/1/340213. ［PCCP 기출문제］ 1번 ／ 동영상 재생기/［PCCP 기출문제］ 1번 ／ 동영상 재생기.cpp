#include <bits/stdc++.h>
using namespace std;

int parseTime(const string& timeStr) {
    size_t colonPos = timeStr.find(':');
    if (colonPos == string::npos) return -1;
    
    int minutes = stoi(timeStr.substr(0, colonPos));
    int seconds = stoi(timeStr.substr(colonPos + 1));
    
    return (minutes * 60) + seconds;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 단축어는 오직 초만 의미함
    int vl = parseTime(video_len);
    int p = parseTime(pos);
    int os = parseTime(op_start);
    int oe = parseTime(op_end);
    
    // 먼저 오프닝 스킵 확인
    if (p >= os && p <= oe)
        p = oe;
    
    
    for (const auto& cmd : commands) {
        if (cmd == "prev") {
            p = p - 10;
        } else if (cmd == "next") {
            p = p + 10;
        }
        
        if (p < 0)
            p = 0;
        else if (p > vl)
            p = vl;
        
        // 오프닝 스킵 확인
        if (p >= os && p <= oe)
            p = oe;
    }
    
    int minutes = p / 60;
    int seconds = p % 60;
    
    return (minutes < 10 ? "0" : "") + to_string(minutes) +
        ":"
        + (seconds < 10 ? "0" : "") + to_string(seconds);
}