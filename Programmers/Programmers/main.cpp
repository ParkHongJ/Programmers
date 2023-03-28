#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < lost.size(); j++)
        {
            //도난당했다면
            if (lost[j] == i)
            {
                answer--;
                for (int k = 0; k < reserve.size(); k++)
                {
                    if ((reserve[k] -1 == lost[j]) || (reserve[k] + 1 == lost[j]) || (reserve[k] == lost[j]))
                    {
                        answer++;
                        lost.erase(lost.begin() + j);
                        reserve.erase(reserve.begin() + k);
                        break;
                    }
                }
                break;
            }
        }
        answer++;
    }

    return answer;
}

int main()
{
	vector<int> lost = { 2,3 };
	vector<int> reserve = { 3,4 };
    //13[13, 6, 1][11, 9, 8, 7] 11
    cout << solution(4, lost, reserve) << endl;
    return 0;
}