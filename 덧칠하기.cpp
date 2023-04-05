#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    auto curIdx = -m;
    auto cnt = 0;
    for (auto idx : section)
    {
        if (idx > curIdx + m)
        {
            curIdx = idx;
            ++cnt;
        }
    }
    return answer;
}