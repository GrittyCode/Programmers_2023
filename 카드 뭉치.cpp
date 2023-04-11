#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";

    int idx1 = 0, idx2 = 0, idx3 = 0;
    bool isCan = true;

    while (isCan && idx3 < goal.size())
    {
        isCan = false;

        if (cards1[idx1] == goal[idx3])
        {
            ++idx1;
            ++idx3;
            isCan = true;
        }

        if (cards2[idx2] == goal[idx3])
        {
            ++idx2;
            ++idx3;
            isCan = true;
        }
    }


    if (idx3 == goal.size())
        answer = "Yes";
    else
        answer = "No";

    return answer;
}