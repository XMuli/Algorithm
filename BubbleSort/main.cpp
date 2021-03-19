#include <iostream>
using namespace std;

//原理:
//比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
//针对所有的元素重复以上的步骤，除了最后一个。
//持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

/*!
 * 冒泡排序
 * @param arr 数组地址
 * @param len 数组长度
 */
void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    cout << "Hello, World!" << endl;

    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = sizeof(arr) / sizeof(int);

    bubbleSort(arr, len);
    for (int i = 0; i < len; ++i)
        cout<<arr[i]<<"   ";

    return 0;
}
