#include "Stack.h"

template<typename T>
CStack<T>::CStack()
	: m_iSize(0),
	m_pNode(nullptr)
{
	
}

template<typename T>
CStack<T>::~CStack()
{
}

template<typename T>
void CStack<T>::Pop()
{
}

template<typename T>
void CStack<T>::Push(T data)
{
	Node* pNode = new Node;
	

}

template<typename T>
void CStack<T>::Push(T&& data)
{
}

template<typename T>
T CStack<T>::top()
{
	return T();
}

template<typename T>
int CStack<T>::Size()
{
	return m_iSize;
}
