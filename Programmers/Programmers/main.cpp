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


    //���� Ȯ������ �������� ��ȣ
    int CurrentNum = 0;

	//���� Ȯ��
	int col = 0, row = 0;

	while (CurrentNum < 10)
	{
		int widthTemp = 0;
		//���� �˻����� ��ȣ �������� lt�� ���Ѵ�
		if (CurrentNum == rect[col][row])
		{
			//�ں��� rt�� �˻��Ѵ�.
			for (int i = M - 1; i >= 0; i--)
			{
				//��ġ�� ���κ��� ���ٸ� �ǹ̰�����
				if (i == row)
				{
					break;
				}

				//�ӽ� rt�� ���Ѵ���
				if (CurrentNum == rect[col][i])
				{
					//�ӽ� ���� ũ�⸦ ���Ѵ�. lb�� ����
					widthTemp = i - row;

					//���簢���� ���κ��� ũ�� �ǹ̰� ����.
					if (col + widthTemp >= N)
					{
						continue;
					}

					//lb �˻�
					if (CurrentNum == rect[col + widthTemp][row])
					{
						//rb�˻� 
						if (CurrentNum == rect[col + widthTemp][i])
						{
							width = max(widthTemp + 1, width);
						}
					}
				}
			}
		}
		//�ٸ��ٸ� ���� ���κ��� �˻��Ѵ�.
		row++;
		//���θ� �� ���Ҵٸ� ���θ� �������� �˻�
		if (row >= M)
		{
			col++;
			row = 0;
		}

		//���� ���θ� �� ���Ҵٸ�
		if (col >= N)
		{
			CurrentNum++; //���� �������� ��ȣ�� �˻�

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