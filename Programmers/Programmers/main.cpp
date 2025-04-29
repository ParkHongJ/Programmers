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
#include <string>
#include <unordered_map>
#pragma warning(disable :4996)
using namespace std;

void BackJoon()
{
	freopen("input.txt", "r", stdin);
	
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int input;
	cin >> input;

	//다음 노드까지의 거리
	vector<unsigned long long> toNextlength;

	for (int i = 0; i < input - 1; ++i)
	{
		int length;
		cin >> length;
		toNextlength.push_back(length);
	}

	//각 주유소의 1리터당 기름
	vector<unsigned long long> gasPrice;

	for (int i = 0; i < input; i++)
	{
		int gas;
		cin >> gas;
		gasPrice.push_back(gas);
	}

	//현재 연료 L
	unsigned long long currentFuel = 0;
	unsigned long long currentNode = 0;

	unsigned long long totalCost = 0;
	//연료 값이 현재보다 작은걸 만날때까지 앞으로 가야한다.
	while (currentNode + 1 < gasPrice.size())
	{
		//다음 노드 연료가 더 작으면
		if (gasPrice[currentNode] > gasPrice[currentNode + 1])
		{
			totalCost += gasPrice[currentNode] * toNextlength[currentNode];
		}
		else
		{
			//다음 노드 연료가 더 크면

			int length = 0;
			int toNext = 0;
			for (int i = currentNode; i < gasPrice.size(); ++i)
			{
				//작은 노드를 만날때까지 길이 계산
				if (gasPrice[currentNode] > gasPrice[i])
				{
					//다음 노드가 더 작으면 끝
					break;
				}
				else
				{
					if (i < toNextlength.size())
					{
						length += toNextlength[i];
					}
					++toNext;
				}
			}
			totalCost += length* gasPrice[currentNode];
			currentNode += toNext;
			continue;
		}
		++currentNode;
	}
	cout << totalCost;
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}