#include "All.h"

#define MAX 1000

__inline void mergeArray(int *arr  , int *aux , int n , int left , int right)
{
	int mid = (left+right)>>1;
	int il = left ,ir = mid+1 , it =0;
	while(il<=mid && ir<=right)
		if(arr[il]>arr[ir])
			aux[it++] = arr[ir++];
		else aux[it++] = arr[il++];
		while(il<=mid)
			aux[it++] = arr[il++];
		while(ir<=right)
			aux[it++] = arr[ir++];
		for(int i = left ; i<=right ; i++)
			arr[i] = aux[i-left];
}


void mergeSort_aux(int *arr  ,int *aux, int n ,  int left , int right)
{
	if(left<right)
	{
		int mid = (left+right)>>1;
		mergeSort_aux(arr, aux , n , left , mid);
		mergeSort_aux(arr, aux , n , mid+1 , right);
		mergeArray(arr , aux , n , left , right);
	}
}

void mergeSort(int *arr , int n)
{
	int *aux = new int[n];
	mergeSort_aux(arr, aux , n , 0 ,n-1);
	delete[] aux;
	aux = NULL;
}



// test
int main()
{
	int arr[] = { 3,5,1,5,7,8,10,22,6,8,4,5,-2,9,0};	
	mergeSort(arr,15);
	FOR(i,0,15)
		cout<< arr[i] << " ";
	cout<<endl;

	return 0;
}
