#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <queue>
#include <list>
#include <stack>
#pragma warning(disable :4996)
using namespace std;


void BackJoon()
{
    freopen("input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;
    vector<vector<int>> rect;
    
    rect.resize(N);

    for (int i = 0; i < N; i++)
    {
        rect[i].resize(M);

		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			rect[i][j] = str[j] - '0';
		}
        /*for (int j = 0; j < M; j++)
        {
            cin >> rect[i][j];
        }*/
    }

    int width = 0, height = 0;


    //현재 확인중인 꼭짓점의 번호
    int CurrentNum = 0;

	//윗변 확인
	int col = 0, row = 0;

	while (CurrentNum < 10)
	{
		int widthTemp = 0;
		//현재 검사중인 번호 기준으로 lt를 구한다
		if (CurrentNum == rect[col][row])
		{
			//뒤부터 rt를 검사한다.
			for (int i = M - 1; i >= 0; i--)
			{
				//겹치는 가로변이 없다면 의미가없다
				if (i == row)
				{
					break;
				}

				//임시 rt를 구한다음
				if (CurrentNum == rect[col][i])
				{
					//임시 가로 크기를 구한다. lb를 위해
					widthTemp = i - row;

					//직사각형의 세로보다 크면 의미가 없다.
					if (col + widthTemp >= N)
					{
						continue;
					}

					//lb 검사
					if (CurrentNum == rect[col + widthTemp][row])
					{
						//rb검사 
						if (CurrentNum == rect[col + widthTemp][i])
						{
							width = max(widthTemp + 1, width);
						}
					}
				}
			}
		}
		//다르다면 다음 가로변을 검사한다.
		row++;
		//가로를 다 돌았다면 세로를 증가시켜 검사
		if (row >= M)
		{
			col++;
			row = 0;
		}

		//가로 세로를 다 돌았다면
		if (col >= N)
		{
			CurrentNum++; //다음 꼭짓점의 번호를 검사

			row = 0; col = 0;
		}
	}

	if (width == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << width * width << endl;
	}
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
    //Programmers();
    BackJoon();
    getch();
    return 0;
}