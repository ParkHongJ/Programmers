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

	int charge = 1000 - input;
	int result = 0;
	if (charge / 500 > 0)
	{
		result += charge / 500;
		charge -= charge / 500 * 500;
	}

	if (charge / 100 > 0)
	{
		result += charge / 100;
		charge -= charge / 100 * 100;
	}

	if (charge / 50 > 0)
	{
		result += charge / 50;
		charge -= charge / 50 * 50;
	}

	if (charge / 10 > 0)
	{
		result += charge / 10;
		charge -= charge / 10 * 10;
	}

	if (charge / 5 > 0)
	{
		result += charge / 5;
		charge -= charge / 5 * 5;
	}

	result += charge;

	cout << result << endl;
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}