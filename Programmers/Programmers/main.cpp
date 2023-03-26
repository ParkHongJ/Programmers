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
    return 0;
}