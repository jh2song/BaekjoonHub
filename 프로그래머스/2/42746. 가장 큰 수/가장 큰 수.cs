using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public string solution(int[] numbers) 
    {
        Array.Sort(numbers, (x, y) => {
            string XY = x.ToString() + y.ToString();
            string YX = y.ToString() + x.ToString();
            // Greater than zero:	This instance follows strB.
            return YX.CompareTo(XY);
        });
        
        if (numbers.Where(x => x == 0).Count() == numbers.Length)
            return "0";
        
        return string.Join("", numbers);
    }
}