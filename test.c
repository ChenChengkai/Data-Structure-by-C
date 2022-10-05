#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    // 定义这个序列
    int arr[] = {0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5};

    // 存储最大值，初始化为 arr[0]
    int max = arr[0];

    // 遍历使用的变量
    int i, j;

    // 临时变量，存储子序列之和
    int tempSum = 0;

    // 数组的大小
    int sizeOfArr = sizeof(arr) / sizeof(int);

    // 子序列分别从每个元素开始
    for(int i = 0; i < sizeOfArr; ++i){
        tempSum = 0;
        // 不同结尾的子序列
        for(int j = i; j < sizeOfArr; ++j){
            tempSum += arr[j];
            // 判断和是否大于 max
            if(tempSum > max){
                max = tempSum;
            }
        }
    }

    printf("%d\n", max);

    return 0;
}