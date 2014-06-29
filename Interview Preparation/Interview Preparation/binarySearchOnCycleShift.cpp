#include "All.h"

int binarySearchInCycleShift(int arr[] , int n, int target)
{
	//15,16,19,25,7
	int begin = 0  , end = n-1;
	int beginIndex = 0;
	while(begin<=end)
	{
		int mid = (begin+end)/2;
		if(arr[mid]>arr[end])
			begin = mid+1;	
		else
		{
			end = mid-1;
			beginIndex = mid;
		}
	}

	begin = beginIndex , end = n+beginIndex-1;
	while(begin<=end)
	{
		int mid = (begin+end)/2;
		if(arr[mid%n]<target)
			begin = mid+1;	
		else if(arr[mid%n]>target)
			end = mid-1;
		else return mid%n;	
	}
	return -1;

}


int main()
{

	int arr[] = { 15,16,19,25,1,3,4,5,7,10,14};
	int n = 11;
	int index;
	index = binarySearchInCycleShift(arr,n,7);
	if(index==-1)
		cout<<"Not Found" <<endl;
	else
		cout<< "The Index is : " << index << " and the Value is " << arr[index] <<endl; 


	return 0;
}
