/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * projek ini merupakan struktur data 
 * menggunakan struktur data quues dengan pendekatan circular arrays .
 * 
 * @section Oprations
 * projek memiliki bebrapa oprasi antara lain:
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan
 * berikut beberapa menu yang digunakan: 
 * 1. en quue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama : Bima Eka Setiawan
 * - nim  : 20240140089
 * - kelas : B
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright bimaeka@umy.ac.id (c) 2025
 * 
 * 
 */

 #include <iostream>
 using namespace std;
 /**
  * @class Queues
  * @brief class ini untuk oprasi lengkap queues
  * 
  * 
  */
 
 class Queues
 {
 private:
      
     int front; ///< variable private front untuk menyimpan posisi depan antrian
     int rear; ///< variable private rear untuk menyimpan posisi belakang antrian
     int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
     int queue_array[5]; ///< variable private quue_array untuk menyimpan elemen antrian
 
 public:
 /**
  * @brief Construct a new Queues object
  * set default queues null
  * with front = -1 and rear = -1
  */
     Queues()
     {
         front = -1;
         rear = -1;
     }
 
     /**
      * @brief method untuk masukan data dalam antrian
      * data dimasukan dalam variable queue_array
      */
 
     void insert()
     {
         int num; ///< variable num menyimpan nilai
         cout << "enter a number :";
         cin >> num;
         cout << endl;
 
         // cek antrian penuh
         if ((front == 0 && rear == max - 1) || (front == rear + 1))
         {
             cout << "\nQueue overvlow\n";
             return;
         }
         // cek apakah antrian kosong
         if (front == -1)
         {
             front = 0;
             rear = 0;
         }
         else
         {
             // jika REAR berada di posisiterakhir array, kembali ke awal array
             if (rear == max - 1)
                 rear = 0;
             else
                 rear = rear + 1;
         }
         queue_array[rear] = num;
     }
 
     /**
      * @brief method untuk menghapus data dalam antrian
      * data dihapuskan dari dalam variable queue_array
      */
 
     void remove()
     {
         //cek antrian kosong
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
 
     /**
      * @brief method untuk menampilkan data dalam antrian
      * data ditampilkan yang berada dalam variable quue_array
      */
 
     void display()
     {
         int front_position = front; ///< variable front_position untuk menandakan posisi element pertama pada variable front
         int rear_position = rear; ///< variable raer_position untuk menandakan posisi element terakhir variable rear
 
         // cek apakah antrian kosong
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
 /**
  * @brief method utama untuk menjalakan progam
  * 
  * @return int
  */
 
 int main()
 {
     Queues q; ///< objek menggunakan member yang ada pada class queues
     char ch; ///< variable ch untuk menyimpan pilihan pada menu yang diharapkan
 
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