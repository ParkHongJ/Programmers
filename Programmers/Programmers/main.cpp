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

	int N;
	cin >> N;

	map<int, int> HasCards;
	for (int i = 0; i < N; i++)
	{
		int Input;
		cin >> Input;
		map<int, int>::iterator iter = HasCards.find(Input);
		if (iter != HasCards.end())
		{
			++(iter->second);
		}
		else
		{
			HasCards.emplace(Input, 1);
		}
		
	}
	
	int M;
	cin >> M;

	vector<int> TargetCards;
	TargetCards.reserve(M);

	vector<int> Result;
	Result.resize(M, 0);

	for (int i = 0; i < M; i++)
	{
		int Input;
		cin >> Input;

		map<int, int>::iterator iter = HasCards.find(Input);

		//소유하고있다면
		if (iter != HasCards.end())
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 <<" ";
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}