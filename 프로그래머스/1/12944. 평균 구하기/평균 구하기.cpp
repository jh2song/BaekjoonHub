#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int ele : arr) {
        answer += ele;
    }
    answer /= arr.size();
    return answer;
}