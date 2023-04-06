#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;

    //선수 위치
    map<string, int> p_idx_map;
    
    //위치 선수
    map<int, string> idx_p_map;
    
    auto rank = 0;
    
    for (auto player : players)
    {
        p_idx_map.insert({ player, rank });
        idx_p_map.insert({ rank++, player });
    }

    for (auto& name : callings)
    {
        auto curIdx = p_idx_map[name];
        auto preIdx = curIdx - 1;
        auto curPlayer = name;
        auto prePlayer = idx_p_map[preIdx];

        p_idx_map[curPlayer] = preIdx;
        p_idx_map[prePlayer] = curIdx;

        idx_p_map[preIdx] = curPlayer;
        idx_p_map[curIdx] = prePlayer;

    }

    for (auto tmp : idx_p_map)
    {
        answer.push_back(tmp.second);
    }

    return answer;
}


int main(void)
{
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });
    return 0;
}