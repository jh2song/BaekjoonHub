using System;
using System.Collections.Generic;

public class Solution 
{
    private int _answer = 0;
    private int len;
    
    public int solution(int[] numbers, int target) 
    {
        // 초기화
        len = numbers.Length;
        // 로직
        Backtracking(0, 0, numbers, target);
        
        return _answer;
    }
    
    public void Backtracking(int nextIdx, int sum, int[] numbers, int target)
    {
        if (nextIdx >= len)
        {
            if (sum == target)
                _answer++;
            return;
        }
        
        Backtracking(nextIdx + 1, sum - numbers[nextIdx], numbers, target);
        Backtracking(nextIdx + 1, sum + numbers[nextIdx], numbers, target);
    }
}