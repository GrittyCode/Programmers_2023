#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) 
{
    int answer = 0;
    
    if (M > 1 || N > 1)
    {
        if (M > N)
        {
            answer = M - 1;
            answer += M * (N - 1);
        }
        else
        {
            answer = N - 1;
            answer +=  (M - 1) * N;
        }
    }
    
    return answer;
}