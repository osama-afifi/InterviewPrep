#include "All.h"

class Heap
{
private:
	int* arr;
	int size;
	int elements;

	__inline int left(int i)
	{
		return i*2;
	}
	__inline int right(int i)
	{
		return i*2+1;
	}
	void expand()
	{
		size<<=1;
		int* newArr = new int[size];
		for(int i = 1 ; i<=elements ; i++)
			newArr[i] = arr[i];
		delete []arr;
		arr = newArr;		
	}
	void heapify( int cur)
	{
		while(true)
		{
			int largest = cur;
			int l = left(cur);
			int r = right(cur);
			if(l<=elements && arr[l]>arr[largest])
				largest = l;
			if(r<=elements && arr[r]>arr[largest])
				largest = r;
			if(cur!=largest)
			{
				swap(arr[cur],arr[largest]);
				cur = largest;
				continue;
			}
			else 
				break;
		}
	}
	void updateVal(int i , int val)
	{
		assert(i<=elements);
		arr[i] = val;
		while(i>1 && arr[i/2]<arr[i])
		{
			swap(arr[i],arr[i/2]);
			i/=2;
		}
	}
public:
	Heap()
	{
		size = 10;
		arr = new int[10];
		elements = 0;
	}

	~Heap()
	{
		delete [] arr;
	}
	void insert(int val)
	{
		if(elements+2==size)
			expand();
		elements++;
		updateVal(elements,val);
	}

	int peek()
	{
		assert(elements>0);
		return arr[1];
	}
	int pop()
	{
		assert(elements>0);
		int returnedVal = arr[1];
		arr[1] = arr[elements];
		heapify(1);
		elements--;
		return returnedVal;
	}
	int length()
	{
		return elements;
	}
};


