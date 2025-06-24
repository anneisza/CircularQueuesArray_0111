/** 
* @mainpage Documentation Circular Queues
*
* @section Intruduction
* Projeck ini merupakan project struktur data
* menggunakan struktur data queues dengan pendekatan circular arrays.
*

* @section Operations
* Project ini memiliki beberapa operasi antara lain:
* 1. Insert
* 2. Delete
* 3. Display
*
* @section Cara Penggunaan
* Berikut beberapa menu yang bisa digunakan:
* 1. en queue
* 2. de queue
* 3. display
* 4. exit
*
* @author Profil
* - nama    : Riza Fitria Istiqomah Zaitunah
* - nim     : 20240140111
* - kelas   : C

* @brief
* @version 1.0
* @date 2025-06-24
*
* @copyright riza.fitria.ft24@mail.umy.ac.id (c) 2025
*/

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini digunakan untuk operasi lengkap queues
 * 
 * 
 */

class Queues
{
private:
    int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
    int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1; // tanda antrian kosong
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */

    void insert()
    {
        int num; ///< variable num untuk menyimpan nilai
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        // 1.Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; // 1.a
            return;                       // 1.b
        }

        // 2.Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a //Kalau front dan rear si indeks 0, maka cuma ada 1
            REAR = 0;  // 2.b
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0; //Ini yang buat array nya circular
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num; //masukkan data ke array rear
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam variable queue_array
     */

    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;//biar kehapus semua, karena tadi cuma sisa satu elemen saja
            REAR = -1;
        }
        else
        {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variable queue_array
     */

    void display()
    {
        int FRONT_position = FRONT; ///< variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_position = REAR; ///< variable rear_position untuk menandakan posisi element terakhir pada variable rear

        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main()
{
    Queues q; ///< objek untuk menggunakan member yang ada pada class queues
    char ch; ///< variable ch untuk menyimpan pilihan pada menu yang diberikan
    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
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
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}