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
//	//�θ��� �����ڽ��� ���ٸ� �ٷ� �ڽ����� ����Ѵ�.
//	if (Parent->LeftChild == nullptr)
//	{
//		Parent->LeftChild = Child;
//	}
//	else
//	{
//		//���� �ڽ��� �ִٸ�
//		LCRSNode* TempNode = Parent->LeftChild;
//
//		//������ �ڽ��� ���Ž��
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
//	// �鿩����
//	int i = 0;
//	for (i = 0; i < Depth - 1; i++)
//	{
//		cout << "   ";
//	}
//	if (Depth > 0)  // �ڽĳ�� ���� ǥ��
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
//		cout << m_identity << "����" << endl; 
//	}
//	Person(const Person& p) { 
//		m_identity = p.m_identity; 
//		cout << m_identity << "�������" << endl;
//	}
//	~Person() { cout << m_identity << "�Ҹ�" << endl; }
//	Person& operator=(const Person& pp)
//	{
//		cout << "����" << endl;
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