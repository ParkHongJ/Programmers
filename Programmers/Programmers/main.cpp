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
	
	string input;
	cin >> input;
	
	int result = 0;
	string str;
	string strAdd;
	bool bMinus = false;
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '-' || input[i] == '+')
		{
			//일단 킵
			if (input[i] == '-' && bMinus)
			{
				result += stoi(strAdd) * -1;
				strAdd = "0";
				continue;
			}
			else if (input[i] == '-' && !bMinus)
			{
				bMinus = true;

				result += stoi(str);
				str = "0";
				continue;
			}
			else
			{
				if (bMinus)
				{
					str = to_string(stoi(str) + stoi(strAdd));
					strAdd = "0";
					continue;
				}
				bMinus = false;
			}

			if (!bMinus)
			{
				result += stoi(str);
				str = "0";
			}
			else
			{
				//이전에 -를 만났고, 이번에 + 라면
				//다음 연산자까지 킵해야한다.
				str = to_string(stoi(str) + stoi(strAdd));
				strAdd = "0";
			}
		}
		else
		{
			if (!bMinus)
			{
				str += input[i];
			}
			else
			{
				strAdd += input[i];
			}
			
		}
	}

	if (bMinus)
	{
		str = to_string(stoi(str) + stoi(strAdd));
		strAdd = "0";
		result += stoi(str) * -1;
	}
	else
	{
		result += stoi(str);
		str = "0";
	}

	cout << result << endl;
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}