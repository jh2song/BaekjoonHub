public class Solution {
    public bool solution(int x) {
        bool answer = true;
        
        int sum = 0;
        int tempX = x;
        while (tempX > 0)
        {
            sum += tempX % 10;
            tempX /= 10;
        }
        
        answer = (x % sum == 0);
        
        return answer;
    }
}