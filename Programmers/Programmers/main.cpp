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


typedef struct Node
{
	int left;
	int right;

	char data;
}NODE;

void Preorder(vector<Node>& tree, int Index)
{
	cout << tree[Index].data;

	if (tree[Index].left >= 0)
	{
		Preorder(tree, tree[Index].left);
	}
	if (tree[Index].right >= 0)
	{
		Preorder(tree, tree[Index].right);
	}
}

void Inorder(vector<Node>& tree, int Index)
{
	if (tree[Index].left >= 0)
	{
		Inorder(tree, tree[Index].left);
	}

	cout << tree[Index].data;

	if (tree[Index].right >= 0)
	{
		Inorder(tree, tree[Index].right);
	}
}

void Postorder(vector<Node>& tree, int Index)
{
	if (tree[Index].left >= 0)
	{
		Postorder(tree, tree[Index].left);
	}

	if (tree[Index].right >= 0)
	{
		Postorder(tree, tree[Index].right);
	}

	cout << tree[Index].data;
}
void BackJoon()
{
    freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<Node> tree;
	tree.resize(N);
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		
		Node node;
		node.data = root;
		
		if (left == '.')
			left = -1;
		else
			left = left - 'A';

		if (right == '.')
			right = -1;
		else
			right = right - 'A';


		node.left = left;
		node.right = right;
		tree[root - 'A'] = node;
	}

	//preorder
	
	Preorder(tree, 0);
	cout << endl;
	Inorder(tree, 0);
	cout << endl;
	Postorder(tree, 0);
	
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