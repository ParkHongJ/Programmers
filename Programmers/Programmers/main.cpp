#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    for (auto& iter : skill_trees)
    {
        int iOffset = 0;
        int iOldOffset = -1;
        for (int i = 0; i < iter.length(); i++)
        {
            //������ �Է��� ù��° ��ų
            iOffset = skill.find(iter[i]);
            
            if (iOffset < 0)
                continue;
            
            //ó�� �Է��� ��
            if (iOldOffset < 0)
            {
                if (iOffset > 0)
                {
                    answer--;
                    break;
                }
                iOldOffset = iOffset;
                continue;
            }

            if ((iOffset > iOldOffset) && ((iOffset - iOldOffset) == 1))
            {
                iOldOffset = iOffset;
                continue;
            }
            else
            {
                answer--;
                break;
            }

            iOldOffset = iOffset;
        }
    }

    return answer;
}

int main()
{
    vector<string> people = { "CED", "CBADF", "AECB","BDA" };
    string str = "CBD";
    cout << solution(str, people) << endl;
    return 0;
}