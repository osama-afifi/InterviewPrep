#include "All.h"

int binarySearch(int arr[] , int n)
{
	//15,16,19,25,7
	int begin = 0  , end = n-1;
	int maxi = INT_MIN;
	int returnedIndex = 0;
	while(begin<=end)
	{
		int mid = (begin+end)/2;
		if(arr[mid]>arr[end])
			begin = mid+1;	
		else
		{
			end = mid-1;
			returnedIndex = mid;
		}
	}
	return returnedIndex;
}


int main()
{

	int arr[] = { 15,16,19,25,1,3,4,5,7,10,14};
	int n = 11;
	int index;
	index = binarySearch(arr,n);
	cout<< "The Index is : " << index << " and the Value is " << arr[index] <<endl; 

	int arr2[] = { 1,3,4,5,7,10,14,15,16,19,25};
	index = binarySearch(arr2,n);
	cout<< "The Index is : " << index << " and the Value is " << arr2[index] <<endl; 

	int arr3[] = { 15,16,19,25,7};
	index = binarySearch(arr3,5);
	cout<< "The Index is : " << index << " and the Value is " << arr3[index] <<endl; 

		int arr4[] = {9, 2,2,2,3,4};
	index = binarySearch(arr4,5);
	cout<< "The Index is : " << index << " and the Value is " << arr4[index] <<endl; 

	return 0;
}
