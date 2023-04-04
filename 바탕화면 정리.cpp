#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    // wallpaper -> ���ϵ��� ��ġ�� ��� �ִ� string �迭
    // for���� ���� �࿭ �� ���� ���� �Ͱ� ���� ū ���� ��ƾ��Ѵ�.
    // ���� minIdx, maxIdx�� ���� ���� �ϸ� �� ��

    pair<int, int> minIdx = { wallpaper.size() , wallpaper[0].length()  }, maxIdx = { 0, 0 };

    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for (int j = 0; j < wallpaper[i].size(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                minIdx.first = minIdx.first > i ? i : minIdx.first;
                minIdx.second = minIdx.second > j ? j : minIdx.second;
                maxIdx.first = maxIdx.first < i + 1 ? i + 1 : maxIdx.first;
                maxIdx.second = maxIdx.second < j + 1 ? j + 1: maxIdx.second;
            }
       }
    }

    vector<int> answer;

    answer.push_back(minIdx.first);
    answer.push_back(minIdx.second);
    answer.push_back(maxIdx.first);
    answer.push_back(maxIdx.second);

    return answer;
}