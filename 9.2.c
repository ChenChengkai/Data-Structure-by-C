#include <stdio.h>
#include <stdlib.h>

int n;

/*
 * 分割使枢轴记录的左边元素比右边元素小
 */
int Partition(int *array, int low, int high){
	int pivotkey = array[low];
	array[0] = array[low];
	while (low < high){
		while (low < high && array[high] >= pivotkey){
			high--;
		}
		array[low] = array[high];
		while (low < high && array[low] <= pivotkey){
			low++;
		}
		array[high] = array[low];
	}
	array[low] = array[0];
	return low;
}

/*
 * 快速排序递归实现
 */
void QuickSort(int *array, int low, int high){
	if (low < high){
		int pivotloc = Partition(array, low, high);
		QuickSort(array, low, pivotloc - 1);
		QuickSort(array, pivotloc + 1, high);
	}
}

int main(){
	int i;
	int *array;
	printf("请输入数组的大小：");
	scanf("%d", &n);
	array = (int*) malloc(sizeof(int) * (n + 1));
	printf("请输入数据（用空格分隔）：");
	for (i = 1; i <= n; i++){
		scanf("%d", &array[i]);
	}
	QuickSort(array, 1, n);
	printf("排序后为：");
	for (i = 1; i <= n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}