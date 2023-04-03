#include <string>
#include <vector>
#include <utility>

using namespace std;

bool CheckCanMove(vector<string>& park, pair<int, int>& curIdx);

vector<int> solution(vector<string> park, vector<string> routes) 
{
    // 2���� �迭 -> 2���� �������� ��ȯ (�࿭) �����̴�.
    // [���� �Ÿ�] �� ���� �ڷᱸ���� �̷���� ����� �κ� ���������� �־�����. 
    // ���ع�, ������ ������ ����ٸ� ���� ����� ���� -> ������ ��� ���� ���� ��ǥ�� ����ϴ°� ����
    // park -> ������ ������ ���� routes -> ����� ����
    // ���� �� �� : ����
    vector<int> answer;
    pair<int, int> curIdx;

    for (int i = 0; i < park.size(); ++i)
    {
        auto colmn = park[i].find('S');

        if (colmn != string::npos)
        {
            curIdx = { i, colmn };
            break;
        }
    }

    for (auto& command : routes)
    {
        auto nextIdx = curIdx;
        auto steps = command[2];
        pair<int, int> dir = {0, 0};

        switch (command[0])
        {
        case 'N' : 
            dir = { -1, 0 };
            break;
        case 'S':
            dir = { 1, 0 };
            break;
        case 'W':
            dir = { 0, -1 };
            break;
        case 'E':
            dir = { 0, 1 };
            break;
        }

        for (int i = 0; i < steps - '0'; ++i)
        {
            nextIdx.first += dir.first;
            nextIdx.second += dir.second;

            if (!CheckCanMove(park, nextIdx))
            {
                nextIdx = curIdx;
                break;
            }
        
        }

        curIdx = nextIdx;
    }

    answer.push_back(curIdx.first);
    answer.push_back(curIdx.second);

    return answer;
}



bool CheckCanMove(vector<string>& park, pair<int,int>& curIdx)
{
    auto row = curIdx.first;
    auto column = curIdx.second;

    if ((row < 0 || column < 0) || (row >= park.size() || column >= park[0].size()))
        return false;

    if (park[row][column] == 'X')
        return false;

    return true;
}