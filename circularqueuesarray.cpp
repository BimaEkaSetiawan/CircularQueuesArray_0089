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

            if ((front == 0 && rear == max -1) || (front == rear +1))
            {
                cout << "\nQueue overvlow\n";
                return;
            }
            
        }
};