#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxLength = 0;
    for (int i = 0; i < sizes.size(); i++) {
        maxLength = max(max(sizes[i][0], sizes[i][1]), maxLength);
    }
    int matchedMaxLength = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int shortLength = sizes[i][0];
        int longLength = sizes[i][1];
        if (shortLength > longLength)
            swap(shortLength, longLength);
        
        matchedMaxLength = max(matchedMaxLength, shortLength);
    }
    
    return maxLength * matchedMaxLength;
}