#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> sta;
    
    sta.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        char newChar = s[i];
        if (newChar == '(')
        {
            sta.push(newChar);
        }
        
        if (newChar == ')')
        {
            if (sta.empty())
            {
                sta.push(newChar);
                continue;
            }
            
            if (sta.top() == '(')
            {
                sta.pop();
            }
            else
            {
                sta.push(newChar);
            }
        }
    }

    if (sta.size() == 0)
        return true;
    else
        return false;
}