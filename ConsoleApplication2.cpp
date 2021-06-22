#include <iostream>
#include <Windows.h>
#include <ctime> 
#include <cstdlib>
#include <typeinfo>
#include <locale>

using namespace std;

template <class T>
class Array {
private:
    int size; // размер исходного массива
    T* data; // исходный массив
public:
    Array(int n) {
        cout << "Введите размер массива" << endl;
        cin >> size;
        data = new T[size + 3];
    }
    void init() {
        if (strcmp(typeid(data).name(), "double *") == 0) {
            for (int i = 0; i < size; i++) {
                data[i] = 0.1 * rand(); // рандомное дробное число
            }
        }
        if (strcmp(typeid(data).name(), "int *") == 0) {
            for (int i = 0; i < size; i++) {
                data[i] = rand(); // рандомное целое число
            }
        }
        if (strcmp(typeid(data).name(), "char *") == 0) {
            for (int i = 0; i < size; i++) {
                data[i] = char('a' + rand() % ('z' - 'a'));   //Рандом char
            }
        }
    }
    void print_data() {
        cout << "Исходный массив: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void selection() { // функция, добавления элемента
        T x;
        int indx;
        size++;
        cout << "Введите добавляемый элемент" << endl;
        cin >> x;
        if (strcmp(typeid(x).name(), "char") == 0) {
            for (int i = size; i > 0; --i) {
                data[i] = data[i - 1];
            }
            data[0] = x;
        }
        else {
        cout << "Введите номер элемента после которого будет добавлен элемент" << endl;
        cin >> indx;
            for (int i = size; i > indx; --i) {
                data[i] = data[i - 1];
            }
            data[indx] = x;
        }
        
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    /////
    cout << "Работа шаблона с double:" << endl;
    Array<double> data1(7);
    data1.init();
    data1.print_data();
    data1.selection();
    cout << "===========================================" << endl;
    /////
    cout << "Работа шаблона с int:" << endl;
    Array<int> data2(7);
    data2.init();
    data2.print_data();
    data2.selection();
    cout << "===========================================" << endl;
    /////
    cout << "Работа шаблона с char:" << endl;
    Array<char> data3(7);
    data3.init();
    data3.print_data();
    data3.selection();
}


