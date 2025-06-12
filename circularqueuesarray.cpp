#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max = 5;
    int front, rear;
    int queue_array[5];

public:
    Queues()
    {
        front = -1;
        rear = -1;
    }

    void insert()
    {
        int num;
        cout << "enter a number :";
        cin >> num;
        cout << endl;

        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout << "\nQueue overvlow\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == max - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
        queue_array[rear] = num;
    }

    void remove()
    {
        if (front == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is :" << queue_array[front] << "\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }

    void display()
    {
        int front_position = front;
        int rear_position = rear;

        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElelments in the queue are....\n";

        if (front_position <= rear_position)
        {
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            cout << endl;
        }
        else
        {
            while (front_position <= max - 1)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }

            front_position = 0;

            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }

            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1. implement insert opration" << endl;
            cout << "2. implement delete opration" << endl;
            cout << "3. display values" << endl;
            cout << "4. exit" << endl;
            cout << "enter your choise (1-4) : ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {

                q.insert();
                break;
            }
            case '2':
            {

                q.remove();
                break;
            }
            case '3':
            {

                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }

            default:
            {
                cout << "invalid option !!" << endl;
                break;
            }
        
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered" << endl;
        }
    }
    return 0;
}