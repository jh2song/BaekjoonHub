using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int[] citations) 
    {
        int maxCit = citations.Max();
        for (int answer = maxCit; answer >= 0; answer-- )
        {
            int uppCount = 0;
            int leftCount = 0;
            for (int i = 0; i < citations.Length; i++)
            {
                int val = citations[i];
                if (val >= answer)
                    uppCount++;
                else
                    leftCount++;
            }
            if (uppCount >= answer && leftCount <= answer)
                return answer;
        }
        
        return -1;
    }
}