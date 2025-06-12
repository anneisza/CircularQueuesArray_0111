#include <iostream>
using namespace std;

class Queues{
    private:
    static const int max = 5;
    int FRONT, REAR;
    int queue_array[5];

    public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert(){
        int num;
        cout<< "Enter a number : ";
        cin >> num;
        cout << endl;

        //1.Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n" ; //1.a
            return;//1.b
        }

        //2.Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; //2.a
            REAR = 0; //2.b
        }
        else
        {
            //jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;  
        }
        queue_array[REAR] = num;  
    }

    void remove(){
        //Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout<< "Queue underflow\n";
            return;
        }
        cout<< "\nThe element deleted from the queue is : "<<queue_array[FRONT]<< "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {

        }       
    }

};