#include "All.h"

#define MAX 1000


__inline void quickSort_aux(int *arr , int n , int left , int right)
{
	if(left<right)
	{
		int pivotIndex = left; // to be improved
		int i=left+1 , j = right;
		while(i<j)
		{
			while(arr[i]<=arr[pivotIndex])++i;
			while(arr[j]>arr[pivotIndex])--j;
			if(i<j)
				swap(arr[i],arr[j]);
		}
		swap(arr[j] ,arr[pivotIndex]);
		quickSort_aux(arr, n , left , j-1);
		quickSort_aux(arr, n , j+1, right);
	}
}

__inline void quickSort(int *arr , int n)
{
	quickSort_aux(arr, n , 0 , n-1);
}

// test
int main()
{
	srand((unsigned)time(NULL));
	int arr[] = { 3,5,1,5,7,8,10,22,6,8,4,5,-2,9,0};
	quickSort(arr, 15);
	FOR(i,0,15)
		cout<< arr[i] << " ";
	cout<<endl;

	return 0;
}
