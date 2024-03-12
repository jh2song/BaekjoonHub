using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    
    private Dictionary<string, List<string>> _giving = new Dictionary<string, List<string>>();
    private Dictionary<string, List<string>> _taking = new Dictionary<string, List<string>>();
    private Dictionary<string, int> _getCount = new Dictionary<string, int>();
    
    public int solution(string[] friends, string[] gifts) {
        int answer = 0;
        // 친구 숫자
        int fCount = friends.Length;
        // 초기화
        foreach (var friend in friends)
        {
            _giving[friend] = new List<string>();
            _taking[friend] = new List<string>();
            _getCount[friend] = 0;
        }
        foreach (var gift in gifts)
        {
            string[] gInput = gift.Split(' ');
            string giver = gInput[0];
            string taker = gInput[1];
            _giving[giver].Add(taker);
            _taking[taker].Add(giver);
        }
        // 프로세싱
        for (int i = 0; i < fCount; i++)
        {
            for (int j = i + 1; j < fCount; j++)
            {
                string friendA = friends[i];
                string friendB = friends[j];
                // 첫번째 조건
                int aToB = _giving[friendA].Where(x => x.Equals(friendB)).Count();
                int bToA = _giving[friendB].Where(x => x.Equals(friendA)).Count();
                if (aToB > bToA)
                {
                    _getCount[friendA]++;
                    continue;
                }
                else if (aToB < bToA)
                {
                    _getCount[friendB]++;
                    continue;
                }
                // 두번째 조건 (gp: 선물(gift) 지수(point))
                int gpA = _giving[friendA].Count() - _taking[friendA].Count();
                int gpB = _giving[friendB].Count() - _taking[friendB].Count();
                if (gpA > gpB)
                {
                    _getCount[friendA]++;
                }
                else if (gpA < gpB)
                {
                    _getCount[friendB]++;
                }
            }
        }
        // 결과 계산
        foreach (var friend in friends)
        {
            answer = Math.Max(answer, _getCount[friend]);
        }
        
        return answer;
    }
}