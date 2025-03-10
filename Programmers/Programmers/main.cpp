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
#include <set>
#pragma warning(disable :4996)
using namespace std;


typedef struct Node
{
	vector<int> child;

	int data;
}NODE;

void BackJoon()
{
    freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<Node> tree;
	tree.resize(N);

	vector<int> visited;
	visited.resize(N);


	int NumTown = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> visited[i];

		NumTown = max(NumTown, visited[i] + 1);
	}

	//N번 노드의 부모 인덱스 없다면 -1
	vector<int> result;
	result.resize(NumTown, -1);

	int root = visited[0];
	//다음 방문노드
	int NextVisited = 1;

	
	stack<int> rootNum;
	rootNum.push(root);
	while (NextVisited < visited.size())
	{
		//부모도시의 번호
		//int rootNum = root;

		/*if (rootNum < visited[NextVisited])
		{
			result[visited[NextVisited]] = rootNum;
			root = visited[NextVisited++];
		}
		else
		{
			root = visited[NextVisited++];
		}*/

		//int rootNum = root;

		if (rootNum.size() > 1)
		{
			int current = rootNum.top();
			rootNum.pop();

			//다시 돌아간다면
			if (rootNum.top() == visited[NextVisited])
			{
				root = visited[NextVisited++];
			}
			else
			{
				rootNum.push(current);

				result[visited[NextVisited]] = root;
				root = visited[NextVisited++];

				rootNum.push(root);
			}
		}
		else
		{
			result[visited[NextVisited]] = root;
			root = visited[NextVisited++];

			rootNum.push(root);
		}

		/*if (rootNum < visited[NextVisited])
		{
			result[visited[NextVisited]] = rootNum;
			root = visited[NextVisited++];
		}
		else
		{
			root = visited[NextVisited++];
		}*/
	}

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
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