using System;

public class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        long minN = Math.Min(a, b);
        long maxN = Math.Max(a, b);
        answer = maxN * (maxN + 1) - minN * (minN - 1);
        answer /= 2;
        return answer;
    }
}