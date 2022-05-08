//подсчет перестановок
#include <iostream>


void printArray(int*, int); //прототип функции для вывода массива на печать
void bubbleSort(int*, int); //прототип
using namespace std;
int main()
{
    const int size = 25;
    int array[size] = {10,56,15,100,78,
                       45,91,12,1,4,
                       7,8,533,47,2,
                       21,3,67,68,79,
                       73,27,93,22,0};

    cout << " No sorted a array" << "\n\n";
    printArray(array, size);
    bubbleSort (array, size);
    cout << " The sorted a array" <<"\n\n";
    printArray(array, size);
    return 0;
}
void printArray(int *arr, int sizeOfArray) //печать массива
{
    for (int k = 0; k < sizeOfArray; k++)

        cout << arr[k]<<" ";

    cout <<"\n\n";
}
void bubbleSort(int* arr, int sizeOfArray)
{
    int countswap=0; //счетчик обменов
    int countcompare=0; //счетчик сравнений
    for(int i = 1; i < sizeOfArray; i++) // i - номер прохода
        for(int j = 0; j < sizeOfArray - 1;j++) // внутренний цикл прохода
        {
            countcompare++;
            if (arr[j ] < arr[j +1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                countswap++;
            }
        }
    cout<<"countcompare:  "<<countcompare <<"\n";
    cout<<"countswap:  "<<countswap <<"\n";
    cout <<"\n\n";
}