#include "All.h"

#define MAX 1000

__inline void bubbleSort(int *arr , int n)
{
	for(int i = 0 ; i<n-1 ; i++)
	{
		bool sorted = true;
		for(int j = 1 ; j<n ; j++)
			if(arr[j]<arr[j-1])
				swap(arr[j] , arr[j-1]) , sorted = false;
		if(sorted)break;
	}
}

// test
int main()
{
	int arr[] = { 3,5,1,5,7,8,10,22,6,8,4,5,-2,9,0};	
	bubbleSort(arr,15);
	FOR(i,0,15)
		cout<< arr[i] << " ";
	cout<<endl;

	return 0;
}
