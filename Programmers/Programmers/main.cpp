#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	vector<string> myBabbling = { "aya", "ye", "woo", "ma" };

	
	for (auto& iter : babbling)
	{
		int iOffset = 0;
		int iCorrectLength = 0;
		int iBeforeBabb = -1;
		for (int i = 0; i < myBabbling.size(); ++i)
		{
			string myBabb = myBabbling[i];
			int iLength = myBabb.length();
			string str = iter.substr(iOffset, iLength);
			if (str == myBabb)
			{
				if (iBeforeBabb == i)
				{
					break;
				}
				iBeforeBabb = i;
				iOffset += iLength;
				if (iOffset == iter.length())
				{
					answer++;
					break;
				}
				i = -1;
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
	vector<string> test = { "aya", "yee", "u", "maa" };
	cout << solution(test) << endl;

    return 0;
}