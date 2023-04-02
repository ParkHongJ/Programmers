#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <conio.h>
#pragma warning(disable :4996)
using namespace std;

int T, M;
void BackJoon()
{
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

int solution(vector<int> picks, vector<string> minerals) {
    
    vector< Fatigue> fatigue;

    int iCount = 0;
	Fatigue _fatigue;
	for (int i = 0; i < minerals.size() - minerals.size() % 5; i++)
	{
		if (minerals[i] == "diamond") { _fatigue.dia++; }
		if (minerals[i] == "iron") { _fatigue.iron++; }
		if (minerals[i] == "stone") { _fatigue.stone++; }

		iCount++;
		if (iCount >= 5)
		{
            fatigue.push_back(_fatigue);
            _fatigue.dia = 0;
            _fatigue.iron = 0;
            _fatigue.stone = 0;
		}
    }
	sort(fatigue.begin(), fatigue.end(), [](int dia, int iron) -> bool {
		return dia > iron;
		});
    int answer = 0;
    return answer;
}

void Programmers()
{
    vector<int> picks = { 1, 3, 2 };
    vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    cout << solution(picks, minerals) << endl;
}

int main()
{
    Programmers();
    getch();
    return 0;
}