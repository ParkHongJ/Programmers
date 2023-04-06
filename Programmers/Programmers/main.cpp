#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <queue>

#include <stack>
#pragma warning(disable :4996)
using namespace std;

int T, M;
void BackJoon()
{

    priority_queue<int> iQueue;
    freopen("input.txt", "r", stdin);

    cin >> T;

    int A = 300;
    int B = 60;
    int C = 10;

    int iCountA = 0;
    int iCountB = 0;
    int iCountC = 0;
    while (T != 0)
    {
        if (T / A > 0)
        {
            T -= A;
            iCountA++;
            continue;
        }

        if (T / B > 0)
        {
            T -= B;
            iCountB++;
            continue;
        }

        if (T / C > 0)
        {
            T -= C;
            iCountC++;
            continue;
        }

        cout << -1 << endl;
        return;
        break;
    }

    cout << iCountA << " " << iCountB << " " << iCountC << endl;
    //getch();
}

typedef struct tagMineralsFatigue {
    int dia = 0;
    int iron = 0;
    int stone = 0;
}Fatigue;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

	vector<int> temp;
	int j = 1;
    int i = 0;
	while (i <= progresses.size())
	{
		if (progresses[i] + speeds[i] * j >= 100)
		{
			temp.push_back(j);
            i++;

            if (i == progresses.size())
            {
                answer.push_back(temp.size());
                break;
            }
            continue;
		}
		else
		{
			if (!temp.empty())
			{
				answer.push_back(temp.size());

				temp.clear();
			}
		}
        j++;
	}
	return answer;
}

void Programmers()
{
    vector<int> progresses = { 95, 95, 95, 95 };
    vector<int> speeds = { 4,3,2,1 };
    //vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    solution(progresses, speeds);
    //cout << solution(progresses, speeds) << endl;
}

int main()
{
    Programmers();
    getch();
    return 0;
}