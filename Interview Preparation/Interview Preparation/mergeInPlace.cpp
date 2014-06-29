#include"All.h"


int* mergeInPlace(int A[], int B[] , int lenA , int lenB)
{

	int iterA = lenA-1;
	int iterB = lenB-1;
	int iterBoth = lenA+lenB-1;	

	while(iterBoth>=0)
	{
		if(A[iterA]>=B[iterB])
			A[iterBoth--] = A[iterA--];
		else
			A[iterBoth--] = B[iterB--];
	}
	return A;
}


int main()
{

	int A[8] = {3,6,8};
	int B[] = {2,4,8,9};

	int* result = mergeInPlace(A,B,3,4);
	for(int i=0 ; i<7 ; i++)
		cout<< *(result++) << " ";
	cout<<endl;

}