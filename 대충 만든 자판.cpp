#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> alphaHash(26, -1);
    
    for (auto str : keymap)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            auto alphaIdx = str[i] - 'A';

            if (alphaHash[alphaIdx] > i + 1 || alphaHash[alphaIdx] == -1)
            {
                alphaHash[alphaIdx] = i + 1;
            }
        }
    }

    vector<int> answer;

    for (auto target : targets)
    {
        auto temp = 0;

        for (auto character : target)
        {
            auto count = alphaHash[character - 'A'];
            
            if (count == -1)
            {
                temp = -1;
                break;
            }

            temp += count;
            
        }
        answer.push_back(temp);
    }

    return answer;
}