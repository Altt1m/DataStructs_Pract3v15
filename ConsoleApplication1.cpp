#include <iostream>

using namespace std;

struct StackItem
{
    int data;
    StackItem* next = nullptr;
};

struct queue
{
    int data;
    queue* next;
};

StackItem* pushSTACK(StackItem*& head, int x)
{
    StackItem* new_top = new StackItem;
    new_top->data = x;
    new_top->next = head;
    head = new_top;
    return head;
}

void pushQUEUE(queue*& head, queue*& tail, int x)
{
    queue* element = new queue;
    element->data = x;
    element->next = NULL;
    if (head == NULL) head = element;
    else tail->next = element;
    tail = element;
}

void popQUEUE(queue*& head) // modified
{
    if (head == nullptr) return;
    queue* temp = head;
    head = head->next;
    delete temp;
}


StackItem* popSTACK(StackItem*& head)
{
    if (head == nullptr) return 0;
    StackItem* old_top = head;
    head = old_top->next;
    delete old_top;
    return head;
}

void printSTACK(StackItem* head)
{
    cout << "\nStack:" << endl;
    StackItem* element = head;
    while (element != nullptr)
    {
        cout << element->data << " ";
        element = element->next;
    }
    cout << endl;
}

void printQUEUE(queue* head)
{
    queue* element = new queue;
    element = head;
    if (head == NULL) cout << "Queue is empty\n";
    else
    {
        cout << "\nQueue:" << endl;
        while (element != nullptr)
        {
            cout << element->data << " ";
            element = element->next;
        }
        cout << endl;
    }
}

void Task()
{
    // Ввести з клавіатури число X.
    // Записати в стек кратні 3 числа з діапазону  від 1 до 2 * X + 7.
    // Числа зі стека виймати по одному і записувати в чергу.
    // Числа з черги виймати і виводити на екран ті з них, які менше 12.

    StackItem* top = nullptr;
    int x; cin >> x;
    for (int i = 3; i <= 2 * x + 7; i += 3) top = pushSTACK(top, i);
    printSTACK(top);

    queue* head = NULL, * end = NULL;
    StackItem* element = top;
    while (element != nullptr)
    {
        pushQUEUE(head, end, element->data);
        element = element->next;
    }
    printQUEUE(head);

    element = top;
    cout << "\nQueue:" << endl;
    while (element != nullptr)
    {
        if (element->data < 12)
            cout << element->data << " ";
        element = element->next;
    }
    cout << endl;
}

int main()
{
    Task();

    return 0;
}
