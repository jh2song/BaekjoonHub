using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    private Stack<char> sta = new Stack<char>();
    
    public bool solution(string s) 
    {
        foreach (char c in s)
        {
            if (c == '(')
            {
                sta.Push(c);
            }
            else
            {
                if (sta.Count() == 0)
                    return false;
                else
                    sta.Pop();
            }
        }
        
        if (sta.Count() == 0)
            return true;
        else
            return false;
    }
}