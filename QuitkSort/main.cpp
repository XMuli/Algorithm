#include <iostream>
using namespace std;

/*!
 * 快速排序
 * @param arr 数组地址
 * @param left 数组的左侧序号
 * @param right 数组的右侧序号
 * \see 参考：https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html
 * \note 默认左侧的是小于基准数，右侧的是大于基准数
 */
void QuickSort(int arr[], int left, int right) {
    if (left > right)
        return;

    int i = left;
    int j = right;
    int temp = arr[left];  // 基准数

    while (i != j) {
        while (i < j && arr[j] >= temp)  // 右边哨兵先行
            --j;

        while (i < j && arr[i] <= temp)
            ++i;

        if (i < j) {            // 交换序号为 i 和 j 的
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    arr[left] = arr[i];    // 将基准数和左右哨兵相遇的序号互换
    arr[i] = temp;

    QuickSort(arr, left, i - 1);   // 递归，处理小于基准数的左侧的一堆
    QuickSort(arr,  i + 1, right);  // 递归，处理大于基准数的右侧的一堆
}

int main() {
    int arr[] = { 1, 2, 7, 9, 3, 4, 5, 10, 8};
    const int nSize = sizeof (arr) / sizeof (int);

    QuickSort(arr, 0, nSize);

    for (int i = 0; i < 9; ++i)
        cout << arr[i] << "  ";

    return 0;
}
