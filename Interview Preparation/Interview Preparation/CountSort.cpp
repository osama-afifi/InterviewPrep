#include "All.h"

#define MAX 1000

__inline void countSort(int *arr , int n)
{
	int mx = (~0) ; int mn = (~0)>>1;
	for(int i = 0 ; i< n ; i++)
		mx = max(mx , arr[i]) , mn = min(mn , arr[i]);
	int shiftFactor = (mn<0) ? -mn : 0;
	int totalBucket = shiftFactor + mx;
	int *cnt = new int[totalBucket + 1];
	for(int i = 0 ; i<= totalBucket ; i++) cnt[i]=0;
	for(int i = 0 ; i< n ; i++)
		++cnt[shiftFactor + arr[i]];
	int it = 0;
	for(int c = 0 ; c<= totalBucket ; c++)
		while(cnt[c]>0)
			arr[it++] = c-shiftFactor , cnt[c]--;
}


// test
int main()
{
	int arr[] = { 3,5,1,5,7,8,10,22,6,8,4,5,-2,9,0};	
	countSort(arr,15);
	FOR(i,0,15)
		cout<< arr[i] << " ";
	cout<<endl;

	return 0;
}
