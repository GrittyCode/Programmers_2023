#include <string>
#include <vector>
#include <map>
using namespace std;


void SkipAlphabet(string skip, map<char, int>& skipDic)
{
    for (auto& alpha : skip)
    {
        skipDic[alpha] = 0;
    }
}

bool IsExceed(char c)
{
    if (c >= 'a' && c <= 'z') return false;

    return true;
}

string solution(string s, string skip, int index)
{
    map<char, int> skipDic;
    SkipAlphabet(skip, skipDic);

    string answer = "";
    for (auto alpha : s)
    {
        for (int i = 0; i < index; ++i)
        {      
            ++alpha;

            if (IsExceed(alpha))
                alpha = 'a';

            if (skipDic.find(alpha) != skipDic.end())
                --i;
        }

        answer += alpha;
    }

    return answer;
}