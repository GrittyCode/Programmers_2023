#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    // name 변수 -> 사람의 이름을 담고 있다
    // vector<int> -> 사람 별로 점수를 담고 있다
    // unordered_map의 자료구조를 생성해 키 값 -> value 값 조회를 통해 O(1)의 속도로 result를 뱉어내는 알고리즘 작성
    
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