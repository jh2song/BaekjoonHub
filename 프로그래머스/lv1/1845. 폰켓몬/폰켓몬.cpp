#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    for (auto& e : nums)
        m[e]++;
    
    if (m.size() >= nums.size() / 2)
        return nums.size() / 2;
    else
        return m.size();
}