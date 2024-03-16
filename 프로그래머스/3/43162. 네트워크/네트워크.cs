using System;

public class Solution 
{
    private bool[] _visited;
    private int _answer = 0;
    
    public int solution(int n, int[,] computers) 
    {
        // 초기화
        _visited = new bool[n];
        for (int i = 0; i < n; i++)
            _visited[i] = false;
        ////
        
        for (int start = 0; start < n; start++)
        {
            if (DFS(start, n, computers) == true)
                _answer++;
        }
        
        return _answer;
    }
    
    // true: DFS 할 수 있음
    // false: DFS 할 수 없음
    public bool DFS(int now, int n, int[,] computers)
    {
        if (_visited[now] == true)
            return false;
        
        _visited[now] = true;
        
        for (int next = 0; next < n; next++)
        {
            if (now == next)
                continue;
            if (computers[now, next] == 0)
                continue;
            if (_visited[next] == true)
                continue;
            
            DFS(next, n, computers);
        }
        return true;
    }
}