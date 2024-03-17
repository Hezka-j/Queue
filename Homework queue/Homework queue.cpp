#include <iostream>
using namespace std;

class Deque {
    struct Node {
        Node* next = nullptr;
        Node* prev = nullptr;
        int data = 0;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
public:
    ~Deque(){
        while (!IsEmpty())
        {
            PopFront();
        }
    }
    bool IsEmpty()
    {
        return count == 0;
    }

    void PushBack(int elem)
    {
        auto newElem = new Node;
        newElem->data = elem;

        if (IsEmpty())
        {
            head = newElem;
        }
        else
        {
            newElem->prev = tail;
            tail->next = newElem;
        }
        tail = newElem;
        count++;
    }

    void PushFront(int elem)
    {
        auto newElem = new Node;
        newElem->data = elem;

        if (IsEmpty())
        {
            tail = newElem;
        }
        else
        {
            head->prev = newElem;
            newElem->next = head;
        }
            
        head = newElem;
        count++;
    }

    int PopBack()
    {
        if (IsEmpty())
            return 0;
        auto temp = tail;
        int number = tail->data;
        tail = tail->prev;
        delete temp;
        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
        count--;
        return number;
    }

    int PopFront()
    {
        if (IsEmpty())
            return 0;
        auto temp = head;
        int number = head->data;
        head = head->next;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;
        count--;
        return number;
    }

    void Print()
    {
        if (IsEmpty())
            return;
        auto current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

class PriorityQueue {
    int* data = nullptr;
    int* priority = nullptr;
    int max_count = 0;
    int count = 0;
public:
    PriorityQueue(int max_count){
        this->max_count = max_count;
        data = new int[max_count];
        priority = new int[max_count];
    }

    ~PriorityQueue()
    {
        if (data != nullptr) delete[] data;
        if (priority != nullptr) delete[] priority;
    }

    void Clear()
    {
        count = 0;
    }

    bool IsEmpty()
    {
        return count == 0;
    }

    bool IsFull()
    {
        return count == max_count;
    }

    int GetCount()
    {
        return count;
    }

    void Sort()
    {
        if (IsEmpty() || IsFull())
            return;
        int* temp = new int[max_count];
        int max = priority[0];
        for (int i = 1; i < count; i++)
        {
            if (priority[i] > max)
            {
                max = priority[i];
            }
        }
        for (int i = 0; i < count;i++)
        {
            for (int j = 0; j < count; j++)
            {     
                if (max  == priority[j])
                {
                    temp[i] = data[j];
                    i++;
                }                
            }
            if (temp[i] < 0)
                i--;
            if (max == 0)
                return;
            max -= 1;
        }
        delete[] data;
        data = temp;
        for (int i = 1; i < count; i++)
        {
            for (int j = 0; j < count - i; j++)
            {
                if (priority[j] < priority[j + 1])
                {
                    int temp1 = priority[j];
                    priority[j] = priority[j + 1];
                    priority[j + 1] = temp1;
                }
            }
        }
    }

    void Enqueue(int elem, int priority)
    {
        this->data[count++] = elem;
        this->priority[count - 1] = priority;  
        Sort();
    }

    int Dequeue()
    {           
        if (IsEmpty())
            return 0;
        int* first = data;
        int number = data[0];
        int* firstPrir = priority;
        for (int i = 0; i < count; i++)
        {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }
        /*delete first;
        delete firstPrir;*/
        count--;
        return number;
    }

    void Print()
    {
        if(!IsEmpty())
        {
            for (int i = 0; i < count; i++)
            {
                cout << "Data: " << data[i] << " priority: " << priority[i] << "\n";
            }
        }
    }
};
int main()
{
    /*Deque deq;
    deq.PushFront(3);
    deq.PushFront(7);
    deq.PushFront(5);

    deq.PushBack(10);
    deq.PushBack(8);
    deq.PushBack(9);

    deq.PopFront();
    deq.Print();*/

    PriorityQueue q(10);
    q.Enqueue(1, 2);
    //q.Print();

    q.Enqueue(3, 5);
    q.Enqueue(4, 1);
    q.Enqueue(10, 10);
    q.Enqueue(4, 10);
    
    q.Print();

    cout << q.Dequeue() << "\n";
    q.Print();
}
