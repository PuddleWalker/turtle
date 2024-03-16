
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

template<typename T>
T MAX(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;

}

template<typename T>
T MAX(const T* arr)
{
    T b = arr[0];
    for (int i = 0; i < strlen(arr); i++)
    {
        if (b < arr[i]) b = arr[i];
    }
    return b;
}

template<typename T>
T MIN(T a, T b)
{
    if (a < b)
    {
        return a;
    }
    else
        return b;
}

template<typename T>
T MIN(const T* arr)
{
    T b = arr[0];
    for (int i = 0; i < strlen(arr); i++)
    {
        if (b > arr[i]) b = arr[i];
    }
    return b;
}


template<typename T, size_t n>
void sort(T(&arr)[n]) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T, size_t n>
void print(const T(&arr)[n]) {
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template<typename T, size_t n>
void replace(T(&arr)[n], T(&arr2)[n]) {
    for (size_t i = 0; i < n; ++i) {
        arr[i] = arr2[i];
    }
    cout << endl;
}

template<typename T, size_t n>
void binsearch(T(&arr)[n])
{
    int numb;
    sort(arr);
    cout << endl;
    cout << "Введите число которок хотите найти: ";
    cin >> numb;
    bool flag = false;
    int l = 0;
    int r = 9;
    int mid;
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr[mid] == numb) flag = true;
        if (arr[mid] > numb) r = mid - 1;
        else l = mid + 1;
    }
    if (flag) cout << "Индекс элемента " << numb << " в массиве равен: " << mid;
    else cout << "Извините, но такого элемента в массиве нет";
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int inpA{};
    int inpB{};
    int array[10];

    for (int i = 0; i < 10; i++)
        array[i] = rand() % 30 - 15;

    cout << "A: "; cin >> inpA;
    cout << "B: "; cin >> inpB;

    cout << endl;

    cout << "Большое число из A и B: " << MAX(inpA, inpB) << endl;
    cout << "Меньше число из A и B: " << MIN(inpA, inpB) << endl;

    cout << endl;

    for (size_t i = 0; i < 10; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;

    sort(array);
    cout << array;
    int array2[10];
    for (int i = 0; i < 10; i++)
        array2[i] = rand() % 30 - 15;
    replace(array, array2);
    cout << array;
    cout << endl;
    cout << "----------Двоичный поиск----------\n\n";
    cout << array;
    binsearch(array);

}