#include "MyList.h"
#include <iostream>
#include <assert.h>

MyNode::MyNode(int val)
{
    this->val = val;
}

MyNode::MyNode(MyNode* prev, int val, MyNode* next)
{
}

void MyList::MergeSort()
{
    if (head == tail)
        return;

    int arraySize = size();
    std::vector<int> array;
    array.resize(size());
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = front();
        pop_front();
    }

    //todo

    std::vector<int> tempArray;
    tempArray.resize(arraySize);

    MergeSort(array, 0, arraySize, tempArray);

    for (int i = 0; i < arraySize; i++)
    {
        push_back(array[i]);
    }

    //print();
}
void MyList::QuickSort()
{
    if (head == tail)
        return;

    int arraySize = size();
    /*int* array = new int[arraySize];*/
    std::vector<int> array;
    array.resize(size());
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = front();
        pop_front();
    }

    QuickSort(array, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i++)
    {
        push_back(array[i]);
    }
}
// arr[st:en]을 정렬하고 싶다.
void MyList::MergeSort(std::vector<int>& array, int start, int end, std::vector<int>& temp)
{
    if (end - start <= 1) return; // 길이 1인 경우
    int mid = (start + end) / 2;
    MergeSort(array, start, mid, temp); // arr[st:mid]을 정렬한다.
    MergeSort(array, mid, end, temp); // arr[mid:en]을 정렬한다.

    Merge(array, start, end, temp); // arr[st:mid]와 arr[mid:en]을 합친다.

}
// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void MyList::Merge(std::vector<int>& array, int start, int end, std::vector<int>& temp)
{
    int mid = (start + end) / 2;

	int lidx = start; // arr[st:mid]에서 값을 보기 위해 사용하는 index
	int ridx = mid; // arr[mid:en]에서 값을 보기 위해 사용하는 index

	for (int i = start; i < end; i++) {
        if (ridx == end)
        {
            temp[i] = array[lidx];
            lidx++;
        }
        else if (lidx == mid)
        {
            temp[i] = array[ridx];
            ridx++;
        }
        else if (array[lidx] <= array[ridx])
        {
            temp[i] = array[lidx];
            lidx++;
        }
        else
        {
            temp[i] = array[ridx];
            ridx++;
        }
	}

	for (int i = start; i < end; i++)
    {
        array[i] = temp[i]; // tmp에 임시저장해둔 값을 a로 다시 옮김
    }

    //cout << "temp Array : ";
    //for (int i = 0; i < end; i++)
    //{
    //    cout << temp[i] << " ";
    //}
    //cout << endl;
    ///*for (int i = 0; i < array.size(); i++)
    //{
    //    std::cout << array[i] << " ";
    //}*/
}

void MyList::QuickSort(std::vector<int>& array, int left, int right)
{
    if (left < right)
    {
        //pivot을 첫번째로 잡고 pivot보다 작은것은 왼쪽에, 큰것은 오른쪽에 오도록한다.
        int index = Partition(array, left, right);

        QuickSort(array, left, index - 1);
        QuickSort(array, index + 1, right);
    }
}

int MyList::Partition(std::vector<int>& array, int left, int right)
{
    int first = left;
    int Pivot = array[first];
    ++left;

    while (left <= right)
    {
        //pivot보다 작다면 left로 모은다.
        while (array[left] <= Pivot && left < right)
        {
            ++left;
        }

        while (array[right] > Pivot && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
        else
        {
            break;
        }
    }

    std::cout << "기준점 : " << array[first] << std::endl;
    
    //첫번째원소가 기준점이었고 기준점을 보다 작은것은 왼쪽, 
    //큰것은 오른쪽 분할이 끝난 상태
    //이후에 다시 재귀로들어와 first부터 검사

    //
    int temp = array[first];
    array[first] = array[right];
    array[right] = temp;
    
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl << std::endl;
    return right;
}

void MyList::BubbleSort()
{
    if (head == tail)
        return;

    int arraySize = size();
    int* array = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = front();
        pop_front();
    }
    
    int index = 0;

    for (int i = 0; i < arraySize-1; i++)
    {
        while (index + 1 < arraySize)
        {
            if (array[index] >= array[index + 1])
            {
                int temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
            }
            index++;
        }

        //print
        std::cout << i + 1 << "회전" << std::endl;
        for (int j = 0; j < arraySize; j++)
        {
            std::cout << array[j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        index = 0;
    }

    for (int i = 0; i < arraySize; i++)
    {
        push_back(array[i]);
    }

    delete[] array;

    //print();
}

void MyList::push_front(int val)
{
    MyNode* newNode = new MyNode(val);
    if (head == nullptr)
    {
        head = tail = newNode;
        _size++;
        return;
    }
    MyNode* temp = head;

    head = newNode;
    head->prev = nullptr;
    head->next = temp;

    temp->prev = head;
    _size++;
}

void MyList::push_back(int val)
{
    MyNode* newNode = new MyNode(val);

    MyNode* temp = tail;

    tail = newNode;
    tail->next = nullptr;
    tail->prev = temp;

    if (head == nullptr)
    {
        head = tail;
    }
    else
    {
        temp->next = tail;
    }

    _size++;
}

void MyList::pop_back()
{
    if (size() <= 0)
    {
        assert(0);
        return;
    }

    MyNode* temp = tail;

    tail = tail->prev;

    _size--;

    if (tail == nullptr)
        return;

    tail->next = nullptr;

    delete temp;
}

void MyList::pop_front()
{
    if (size() <= 0)
    {
        assert(0);
        return;
    }

    MyNode* temp = head;
    
    head = head->next;//헤드 갱신

    _size--;

    if (head == nullptr)
        return;

    head->prev = nullptr;

    delete temp;
}

int MyList::front()
{
    if (size() <= 0)
    {
        assert(0);
        return 0;
    }
    // TODO: 여기에 return 문을 삽입합니다.
    return head->val;
}

int MyList::back()
{
    if (size() <= 0)
    {
        assert(0);
        return 0;
    }
    // TODO: 여기에 return 문을 삽입합니다.

    return tail->val;
}

int MyList::at(int index)
{
    if (size() < index)
    {
        assert(0);
        return 0;
    }

    int tempIndex = 0;

    MyNode* tempNode = head;
    while (tempIndex != index)
    {
        if (tempNode == nullptr)
            break;
        tempNode = tempNode->next;
        tempIndex++;
    }

    return tempNode->val;
}

int MyList::insert(int index, int value)
{
    if (size() < index)
    {
        assert(0);
        return 0;
    }
    int tempIndex = 0;

    MyNode* newNode = new MyNode(value);

    MyNode* tempNode = head;

    if (tempIndex == index)
    {
        head->prev = newNode;
        newNode->next = tempNode;
        newNode->prev = nullptr;

        head = newNode;
        _size++;
        return 0;
    }

    while (tempIndex != index)
    {
        if (tempNode == nullptr)
            break;
        tempNode = tempNode->next;
        tempIndex++;
    }
    
    //tail이라면
    if (tempNode == nullptr)
    {
        tail->next = newNode;

        newNode->prev = tail;
        newNode->next = nullptr;

        tail = newNode;

        /*tempNode->next = newNode;
        newNode->prev = tempNode;
        tail = newNode;*/
    }
    else
    {
        MyNode* tt = tempNode->prev;
        tempNode->prev = newNode;
        newNode->next = tempNode;
        newNode->prev = tt;

        tt->next = newNode;

    }
    _size++;
    
    return 0;
}

int MyList::erase(int index, int value)
{
    if (size() < index)
    {
        assert(0);
        return 0;
    }

    int tempIndex = 0;

    MyNode* eraseNode = head;
    while (tempIndex != index)
    {
        if (eraseNode == nullptr)
            break;
        eraseNode = eraseNode->next;
        tempIndex++;
    }

    eraseNode->prev == nullptr;
    eraseNode->prev->next = eraseNode->next;

    if (eraseNode == tail)
    {
        tail = eraseNode->prev;
        tail->next = nullptr;
    }
    else
    {
        eraseNode->next->prev = eraseNode->prev;
    }
    delete eraseNode;
    
    _size--;

    return tempIndex;
}

void MyList::clear()
{
    while (head != tail)
    {
        if (head != nullptr)
        {
            MyNode* deleteNode = head;

            head = head->next;
            delete deleteNode;

            _size--;
        }        
    }
    _size--;
    delete head;
    head = tail = nullptr;
}

void MyList::print()
{
    if (size() <= 0)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    MyNode* temp = head;

    while (true)
    {
        std::cout << temp->val << " ";

        if (temp->next == nullptr)
            break;
        else
            temp = temp->next;
    }
    std::cout << std::endl;
}

size_t MyList::size()
{
    return _size;
}
