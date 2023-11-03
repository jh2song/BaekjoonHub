#include <bits/stdc++.h>
using namespace std;

int n;
bool SKWin[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SKWin[0] = false;
    SKWin[1] = true;
    SKWin[2] = false;
    SKWin[3] = true;
    SKWin[4] = true;

    cin >> n;
    
    for (int i = 5; i <= n; ++i)
    {
        SKWin[i] = !SKWin[i - 4] || !SKWin[i - 3] || !SKWin[i - 1];
    }

    if (SKWin[n])
        cout << "SK";
    else
        cout << "CY";

    return 0;
}