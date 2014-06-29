#include "All.h"

#define MAX 1000


void insertion_sort( int *arr , int n )
{
	for(int i = 1 ; i<n ; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(arr[j]>key)
			swap(arr[j+1] , arr[j]), --j;
		//arr[j+1] = key;
	}
}

// test
int main()
{
	int arr[] = { 3,5,1,5,7,8,10,22,6,8,4,5,-2,9,0};	
	insertion_sort(arr,15);
	FOR(i,0,15)
		cout<< arr[i] << " ";
	cout<<endl;

	return 0;
}
