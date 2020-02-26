
#include<stdio.h>
#include<math.h>
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == k)
			return mid;
		else if (arr[mid] > k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	int key;
	scanf("%d", &key);
	int arr[10] = { 1, 3, 5, 6, 7, 9, 10, 13, 16, 88 };

	int sz = sizeof(arr) / sizeof(arr[0]);


	int ret = binary_search(arr, key, sz);

	if (ret == -1)
		printf("找不到\n");
	else
		printf("找到了：%d\n", ret + 1);

	return 0;
}
