#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    // name ���� -> ����� �̸��� ��� �ִ�
    // vector<int> -> ��� ���� ������ ��� �ִ�
    // unordered_map�� �ڷᱸ���� ������ Ű �� -> value �� ��ȸ�� ���� O(1)�� �ӵ��� result�� ���� �˰��� �ۼ�
    
    unordered_map<string, int> dic;

    for (int i = 0; i < name.size(); ++i)
        dic.insert({ name[i], yearning[i]});

    for (vector<string> array : photo)
    {
        answer.push_back(0);

        for (string name : array)
        {
            auto iter = dic.find(name);
            
            if (iter != dic.end())
            {
                answer[answer.size() - 1] += (*iter).second;
            }
        }
    }
    
    return answer;
}