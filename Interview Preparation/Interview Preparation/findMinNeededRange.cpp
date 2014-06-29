#include "All.h"

// 1,2,4,7,10,11,7,12,6,7,16,18,19

pair<int,int> detectMiddle(int arr[] , const int &n)
{
	int start = 0;
	int end = n-1;
	while(start<n-1 && arr[start]<arr[start+1])
	++start;
	while(end>0 && arr[end]>arr[end-1])
	--end;
	return make_pair(start,end);	

}


pair<int,int> findLeastRange(int arr[] , const int &n)
{
	pair<int,int>middle = detectMiddle(arr,n);
	
	int minMid = middle.first;
	int maxMid = middle.second;

	for(int i=middle.first ; i<=middle.second ; i++)
	{
		if(arr[i]<arr[minMid])
			minMid = i;
		if(arr[i]>arr[maxMid])
			maxMid = i;
	}

	int lowerBound = middle.first-1;
	int upperBound = middle.second+1;

	while(lowerBound>=0 && arr[lowerBound]>arr[minMid])
		lowerBound--;
	while(upperBound<n && arr[upperBound]<arr[maxMid])
		upperBound++;
	return make_pair(lowerBound+1, upperBound-1);
}

int main()
{

	int arr[] = {7,12,6,7,16,18,19};
	int n = 7;
	pair<int,int> range = findLeastRange(arr,n);
	cout<< "The Range is :" << range.first << " " << range.second << endl;
}