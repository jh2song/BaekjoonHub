// https://www.acmicpc.net/problem/1063

#include <iostream>
#include <string>
using namespace std;

string a, b;
int n;
int ky, kx;
int sy, sx;
int tky, tkx;
int tsy, tsx;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> n;
    kx = a[0] - 'A' + 1;
    ky = a[1] - '1' + 1;
    
    sx = b[0] - 'A' + 1;
    sy = b[1] - '1' + 1;
    
    for (int i = 0; i < n; ++i)
    {
        string ins;
        cin >> ins;

        tky = ky;
        tkx = kx;
        for (char c : ins)
        {
            if (c == 'R')
                ++tkx;
            else if (c == 'L')
                --tkx;
            else if (c == 'B')
                --tky;
            else if (c == 'T')
                ++tky;
        }
        
        // 1. 킹이 체스판 벗어 났는지 확인
        if (tky < 1 || tky > 8 || tkx < 1 || tkx > 8)
            continue;
        // 2. 돌과 t가 위치가 같다면 돌을 움직여 보고 돌이 체스판에 벗어 났는지 확인
        tsy = sy;
        tsx = sx;
        if (sy == tky && sx == tkx)
        {
            if (ins == "R")
            {
                ++tsx;
            }
            else if (ins == "L")
            {
                --tsx;
            }
            else if (ins == "B")
            {
                --tsy;
            }
            else if (ins == "T")
            {
                ++tsy;
            }
            else if (ins == "RT")
            {
                ++tsx;
                ++tsy;
            }
            else if (ins == "LT")
            {
                --tsx;
                ++tsy;
            }
            else if (ins == "RB")
            {
                ++tsx;
                --tsy;
            }
            else if (ins == "LB")
            {
                --tsx;
                --tsy;
            }
        }
        
        if (tsy < 1 || tsy > 8 || tsx < 1 || tsx > 8)
            continue;
        
        // 갱신
        ky = tky;
        kx = tkx;
        sy = tsy;
        sx = tsx;
    }
    
    char okx = kx + 'A' - 1;
    char osx = sx + 'A' - 1;
    
    cout << okx << ky << "\n";
    cout << osx << sy << "\n";
}