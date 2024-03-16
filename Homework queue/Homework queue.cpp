#include <iostream>
using namespace std;
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
        return data[--count];
    }

    void Print()
    {
        for (int i = 0; i < count; i++)
        {
            cout <<"Data: " << data[i] << " priority: " << priority[i] << "\n";
        }
    }
};
int main()
{
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
