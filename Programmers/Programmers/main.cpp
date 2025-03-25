#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#pragma warning(disable :4996)
using namespace std;

void BackJoon()
{
	freopen("input.txt", "r", stdin);


	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int M, N;
	cin >> N >> M;

	//나온 단어의 수

	unordered_map<string, int> wordNum;

	//map<int, string> wordLength;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		//M 이상인 단어들만
		if (str.length() >= M)
		{
			unordered_map<string, int>::iterator iter = wordNum.find(str);

			//이미 단어목록에 들어갔다면
			if (iter != wordNum.end())
			{
				iter->second++;
			}
			else
			{
				wordNum.emplace(str, 1);
			}
		}
	}

	priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> pq; //부른횟수
	for (auto& iter : wordNum)
	{
		pq.push(make_pair(iter.second, iter.first));
	}

	while (!pq.empty())
	{
		//가장 많이불린 단어.
		pair<int, string> temp = pq.top();

		pq.pop();

		//다음 단어와 겹치는지 확인해야함.

		//겹치는 단어 목록
		set<string> collaps;		
		//priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> lengthpq;
		while (!pq.empty())
		{
			pair<int, string> temp2 = pq.top();

			//겹친다
			if (temp2.first == temp.first)
			{
				collaps.insert(temp2.second);
				pq.pop();
			}
			else
			{
				break;
			}
		}

		//겹치는 단어가 없다면.
		if (collaps.empty())
		{
			cout << temp.second << "\n";
		}
		else
		{
			//todo
			//길이순
			
			//사전순
		}
	}

	/*int prevNum = 0;
	while (!pq.empty())
	{
		pair<int, string> temp = pq.top();

		pq.pop();

		vector<pair<int, string>> tempVec;
		while (!pq.empty())
		{
			pair<int, string> next = pq.top();

			if (temp.first == next.first)
			{
				tempVec.push_back(next);
				pq.pop();
			}
			else
			{
				break;
			}
		}

		if (tempVec.empty())
		{
			cout << temp.second << "\n";
		}
		else
		{
			
		}

	}*/
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}