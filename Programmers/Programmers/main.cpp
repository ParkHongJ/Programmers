#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<int>> lines) {
	int answer = 0;

	set<vector<int>> test;//중첩된 점들을 보관
	
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines.size(); j++)
		{
			if (lines[i] == lines[j])
			{
				continue;
			}

			//선분이 겹쳤다
			if (lines[i][0] <= lines[j][0] &&
				lines[i][1] > lines[j][0])
			{
				int x = lines[j][0];
				int y = 0;

				if (lines[i][1] <= lines[j][1])
				{
					y = lines[i][1];
				}
				else
				{
					y = lines[j][1];
				}
				vector<int> Points = { x,y };
				test.insert(Points);
			}
		}
	}

	int iX = 0;
	int iY = 0;
	for (auto& iter : test)
	{
		for (auto& iter2 : test)
		{
			if (iter == iter2)
			{
				continue;
			}

			//또걸렸다
			if (iter[0] <= iter2[0] &&
				iter[1] > iter2[0])
			{
				int x = iter2[0];
				int y = 0;

				if (iter[1] <= iter2[1])
				{
					y = iter[1];
				}
				else
				{
					y = iter2[1];
				}
			}
		}
	}

	return answer;
}

//typedef char ElementType;
//typedef struct tagLCRSNode
//{
//	struct tagLCRSNode* LeftChild;
//	struct tagLCRSNode* RightSibling;
//	
//	ElementType Data;
//}LCRSNode;
//
//LCRSNode* LCRS_CreateNode(ElementType NewData)
//{
//	LCRSNode* NewNode = new LCRSNode;
//	NewNode->LeftChild = nullptr;
//	NewNode->RightSibling = nullptr;
//	NewNode->Data = NewData;
//
//	return NewNode;
//}
//void LCRS_DestroyNode(LCRSNode* Node)
//{
//	delete Node;
//}
//void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
//{
//	//부모의 왼쪽자식이 없다면 바로 자식으로 등록한다.
//	if (Parent->LeftChild == nullptr)
//	{
//		Parent->LeftChild = Child;
//	}
//	else
//	{
//		//왼쪽 자식이 있다면
//		LCRSNode* TempNode = Parent->LeftChild;
//
//		//오른쪽 자식을 계속탐색
//		while (TempNode->RightSibling != nullptr)
//		{
//			TempNode = TempNode->RightSibling;
//		}
//		TempNode->RightSibling = Child;
//	}
//}
//
//void LCRS_PrintTree(LCRSNode* Node, int Depth)
//{
//	// 들여쓰기
//	int i = 0;
//	for (i = 0; i < Depth - 1; i++)
//	{
//		cout << "   ";
//	}
//	if (Depth > 0)  // 자식노드 여부 표시
//	{
//		cout << "+--";
//	}
//
//	cout << Node->Data << endl;
//
//	if (Node->LeftChild != nullptr)
//	{
//		LCRS_PrintTree(Node->LeftChild, Depth + 1);
//	}
//	if (Node->RightSibling != nullptr)
//	{
//		LCRS_PrintTree(Node->RightSibling, Depth);
//	}
//}
//class Person {
//public:
//	static int a;
//	int m_identity = 0;
//public:
//	Person(int identity) {
//		this->m_identity = identity;
//		cout << m_identity << "생성" << endl; 
//	}
//	Person(const Person& p) { 
//		m_identity = p.m_identity; 
//		cout << m_identity << "복사생성" << endl;
//	}
//	~Person() { cout << m_identity << "소멸" << endl; }
//	Person& operator=(const Person& pp)
//	{
//		cout << "대입" << endl;
//		return *this;
//	}
//};
//int Person::a = 0;
int main()
{
	vector<vector<int>> test = { {0, 5} ,{3, 9},{1, 10}};
	cout << solution(test) << endl;
    return 0;
}