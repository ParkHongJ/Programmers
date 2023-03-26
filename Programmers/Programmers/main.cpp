#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string s, string skip, int index) {

    string answer = "";

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j < index; ++j)
        {
            char temp;
            if (s[i] + 1 > 'z')
            {
                temp = 'a';
            }
            else
            {
                temp = s[i] + 1;
            }

            int iOffset = skip.find(temp);
            if (iOffset >= 0)
            {
                j--;
            }
            s[i] = temp;
        }
        answer += s[i];
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
    return 0;
}