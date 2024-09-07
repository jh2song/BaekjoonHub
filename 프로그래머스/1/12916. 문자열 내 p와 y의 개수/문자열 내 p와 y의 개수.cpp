#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    
    int pCount = 0;
    int yCount = 0;
    
    for (auto c : s)
    {
        if (c == 'P')
            pCount++;
        else if (c == 'Y')
            yCount++;
    }
    
    if (pCount == 0 && yCount == 0)
        return true;
    
    if (pCount == yCount)
        return true;
    else
        return false;
    
    return false;
}