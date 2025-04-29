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

	//���� �������� �Ÿ�
	vector<unsigned long long> toNextlength;

	for (int i = 0; i < input - 1; ++i)
	{
		int length;
		cin >> length;
		toNextlength.push_back(length);
	}

	//�� �������� 1���ʹ� �⸧
	vector<unsigned long long> gasPrice;

	for (int i = 0; i < input; i++)
	{
		int gas;
		cin >> gas;
		gasPrice.push_back(gas);
	}

	//���� ���� L
	unsigned long long currentFuel = 0;
	unsigned long long currentNode = 0;

	unsigned long long totalCost = 0;
	//���� ���� ���纸�� ������ ���������� ������ �����Ѵ�.
	while (currentNode + 1 < gasPrice.size())
	{
		//���� ��� ���ᰡ �� ������
		if (gasPrice[currentNode] > gasPrice[currentNode + 1])
		{
			totalCost += gasPrice[currentNode] * toNextlength[currentNode];
		}
		else
		{
			//���� ��� ���ᰡ �� ũ��

			int length = 0;
			int toNext = 0;
			for (int i = currentNode; i < gasPrice.size(); ++i)
			{
				//���� ��带 ���������� ���� ���
				if (gasPrice[currentNode] > gasPrice[i])
				{
					//���� ��尡 �� ������ ��
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