#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // 예외처리
    if (arr.size() == 0)
        return answer;
    
    int top = arr[0];
    answer.push_back(top);
    for (int i = 1; i < arr.size(); i++)
    {
        if (top == arr[i])
            continue;
        top = arr[i];
        answer.push_back(top);
    }

    return answer;
}