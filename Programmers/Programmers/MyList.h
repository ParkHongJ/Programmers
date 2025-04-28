#pragma once
#include <vector>
#include <memory>
using namespace std;
class MyNode
{
public:
    MyNode* prev;
    int val;
    MyNode* next;

    MyNode(int val);
    MyNode(MyNode* prev, int val, MyNode* next);
};

/*
    만들어 놓은 연결리스트는. 추후 정렬 구현에도 사용 할 예정.

*/
class temp;
class MyList
{
private:
    MyNode* head = nullptr;
    MyNode* tail = nullptr;

    int _size = 0;
    unique_ptr< temp> tt;
public:
    ~MyList();
    void MergeSort();
    void QuickSort();
    void BubbleSort();

    void push_front(int val);
    void push_back(int val);

    void pop_back();
    void pop_front();

    int front();    // 맨 앞의 값 반환.
    int back();        // 맨 뒤의 값 반환.
    int at(int index);
    int insert(int index, int value);
    int erase(int index, int value);
    void clear();    // 리스트 내부의 모든 노드 삭제

    void print();    // 리스트 값들을 cout으로 출력(연습용 함수)
    size_t size();    // 리스트에 들어있는 데이터의 수 반환.
private:
    void MergeSort(std::vector<int>& array, int start, int end, std::vector<int>& temp);
    void Merge(std::vector<int>& array, int start, int end, std::vector<int>& temp);
    void QuickSort(std::vector<int>& array, int left, int right);
    int Partition(std::vector<int>& array, int left, int right);

};