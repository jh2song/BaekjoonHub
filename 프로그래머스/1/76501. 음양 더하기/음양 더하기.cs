using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] absolutes, bool[] signs) 
    {
        int answer = 0;
        
        for (int i = 0; i < signs.Length; i++)
        {
            if (signs[i])
                answer += absolutes[i];
            else
                answer -= absolutes[i];
        }
        
        return answer;
    }
}