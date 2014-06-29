#include "All.h"



__inline int left(int i)
{return i*2+1;}
__inline int right(int i)
{return i*2+2;}

void heapify(int arr[] , const int & n , int i)
{
	int cur = i;
	while(true)
	{
		int largest = cur;
		int l = left(cur);
		int r = right(cur);
		if(l<n && arr[largest]<arr[l])
			largest = l;
		if(r<n && arr[largest]<arr[r])
			largest = r;
		if(largest!=cur)
		{
			swap(arr[largest] , arr[cur]);
			cur = largest;
			continue;
		}
		else
			break;	
	}

}

void buildHeap(int arr[] , const int &n)
{
	for(int i = n/2 ; i>=0 ; i--)
		heapify(arr,n,i);
}

void heapSort(int arr[]  , const int &n)
{
	buildHeap(arr,n);
	int heapLen = n;
	for(int i = n-1 ; i>=1 ; i--)
	{
		swap(arr[0] , arr[i]);
		heapLen--;
		heapify(arr,heapLen ,0);
	}
}

int Random()
{

	return  rand(); 

}

int main()
{
	srand(time(NULL)); 
	int* arr;
	int n = 100;
	arr = new int[n];

	for(int i = 0 ; i< n ; i++)
		arr[i] = Random();
	heapSort(arr,n);
	for(int i = 0 ; i< n ; i++)
		cout<< arr[i] << " ";
	cout<<endl;


	delete [] arr;
}