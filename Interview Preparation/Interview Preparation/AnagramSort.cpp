#include "All.h"


int anagramSort(string a ,string b)
{
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	if(a<b)
		return 1;
	if(a<b)
		return -1;
	return 0;
}


int main()
{

string arr[] = {"dog", "ogd" , "paul" , "ooo" , "a" , "k" , "god", "gdo" , "hell" , "c" , "lelh" , "laup"};
sort(arr,arr+12,anagramSort);
for(int i=0;i<12 ; i++)
	cout<<arr[i] << " ";
cout<<endl;


return 0;
}



