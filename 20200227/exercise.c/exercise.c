#include <stdio.h>
#include <string.h>

int global = 2019;//全局变量

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 7;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) >> 1;
	}

	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 7;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > key) {
			right = mid - 1;
		}
		else if(arr[mid]  < key){
			left = mid + 1;
		}
		else {
			break;
		}
		
	}
	if (left <= right) {
		printf("找到了，下标是%d\n", mid);
	}
	else {
		printf("找不到\n");
	}*/

	/*char psw[10] = "";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; ++i) {
		printf("please input:");
		scanf("%s", psw);
		if (strcmp(psw, "password") == 0) {
			break;
		}
		if (i == 3) {
			printf("exit\n");
		}
		else {
			printf("login\n");
		}
	}
	*/
	/*char arr1[] = "welcome to zhinengban";
	char arr2[] = "#####################";
	int left = 0;
	int right = strlen(arr1) - 1;

	printf("%s\n", arr2);
	while (left <= right) {
		
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	
	for (left = 0, right = strlen(arr2) - 1;
		left <= right;
		left++, right--) {
		
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
	}*/
/*int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		k++;
	return 0;

	printf("%d\n", strlen("abcdef"));
	// \32被解析成一个转义字符
	printf("%d\n", strlen("c:\test\328\test.c"));


	printf("%c\n", '\'');
	printf("%s\n", "\"");

	char arr1[] = "bit";
	char arr2[] = { 'b', 'i', 't' };
	char arr3[] = { 'b', 'i', 't', '\0' };
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);

	int local = 2018;//局部变量
	int global = 2020;//局部变量

	printf("global = %d\n", global);*/

	return 0;
}