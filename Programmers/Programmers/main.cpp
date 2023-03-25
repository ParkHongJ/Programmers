#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;

	int iMaxSize = 3;
	{
		double x1 = abs(dots[0][0] - dots[1][0]);
		double y1 = abs(dots[0][1] - dots[1][1]);

		if (x1 == 0)
		{
			x1 = 0;
		}

		double x2 = abs(dots[2][0] - dots[3][0]);
		double y2 = abs(dots[2][1] - dots[3][1]);

		if (x2 == 0)
		{
			x2 = 0;
		}

		double iResult1 = y1 / x1;
		double iResult2 = y2 / x2;

		if (iResult1 == iResult2)
		{
			return 1;
		}
	}
	{
		double x1 = abs(dots[0][0] - dots[2][0]);
		double y1 = abs(dots[0][1] - dots[2][1]);

		if (x1 == 0)
		{
			x1 = 0;
		}

		double x2 = abs(dots[1][0] - dots[3][0]);
		double y2 = abs(dots[1][1] - dots[3][1]);

		if (x2 == 0)
		{
			x2 = 0;
		}

		double iResult1 = y1 / x1;
		double iResult2 = y2 / x2;

		if (iResult1 == iResult2)
		{
			return 1;
		}
	}
	{
		double x1 = abs(dots[0][0] - dots[3][0]);
		int y1 = abs(dots[0][1] - dots[3][1]);

		if (x1 == 0)
		{
			x1 = 0;
		}

		double x2 = abs(dots[1][0] - dots[2][0]);
		double y2 = abs(dots[1][1] - dots[2][1]);

		if (x2 == 0)
		{
			x2 = 0;
		}

		double iResult1 = y1 / x1;
		double iResult2 = y2 / x2;

		if (iResult1 == iResult2)
		{
			return 1;
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
	vector<vector<int>> test = { {1, 1} ,{4, 2},{5, 5}
	,{7, 7} };
	cout << solution(test) << endl;
    return 0;
}