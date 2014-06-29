#include "All.h"

#define COLUMNS 5
#define ROWS 3

__inline pair<int,int> _1D_2D(int i)
{
	return make_pair(i/COLUMNS , i%COLUMNS);
}
__inline int _2D_1D(int i , int j)
{	
	return i*COLUMNS+j;
}

int findInMatrix(int mat[ROWS][COLUMNS] , const int &target , int tl , int br) //2D->1D
{
	if(mat[tl/COLUMNS][tl%COLUMNS]==target)
		return tl;
	if(br<=tl)return -1;	
	if(mat[tl/COLUMNS][tl%COLUMNS] > target ||  mat[br/COLUMNS][br%COLUMNS] < target)
		return -1;

	int begRow = _1D_2D(tl).first;
	int endRow = _1D_2D(br).first;

	int begColumn = _1D_2D(tl).second;
	int endColumn = _1D_2D(br).second;

	int midRow = (begRow+endRow)/2;
	int midColumn = (begColumn+endColumn)/2;

	int quarter= -1;
	// upper left quarter
	quarter=findInMatrix(mat ,target , _2D_1D(begRow,begColumn) , _2D_1D(midRow,midColumn));
	if(quarter!=-1)
		return quarter;
	//lower left
	quarter= findInMatrix(mat ,target , _2D_1D(midRow+1,begColumn) , _2D_1D(endRow,midColumn));
	if(quarter!=-1)
		return quarter;
	// upper right
	quarter = findInMatrix(mat ,target, _2D_1D(begRow,midColumn+1) , _2D_1D(midRow,endColumn));
	if(quarter!=-1)
		return quarter;
	// lower right
	quarter = findInMatrix(mat ,target,_2D_1D(midRow+1,midColumn+1),_2D_1D(endRow,endColumn));
		return quarter;

}

pair<int,int> findValInMatrix(int mat[ROWS][COLUMNS] , const int &target)
{
	int result = findInMatrix(mat,target , _2D_1D(0,0) , _2D_1D(ROWS-1 , COLUMNS-1) );
	if(result==-1)
		return make_pair(-1,-1);
	return _1D_2D(result);

}


int main()
{

	int arr[ROWS][COLUMNS] =
	{   {  1,4,5,6,7} ,
    	{  2,6,7,7,9 },
	    {  4,8,9,9,10 } };

	int target = 10;
	pair<int,int> index = findValInMatrix(arr,target);
	if(index.first==-1)
		cout<< "Not Found" << endl;
	else
		cout<< "Found at Row: " << index.first << " and Column: " << index.second << endl;


}