#include "All.h"

int main()
{


	unordered_map<string,int>M;
	typedef unordered_map<string,int> Hash;
	M["Osama"]= 76;
	M["MGSY"]= 27;
	Hash::iterator it;
	for(it = M.begin() ; it!=M.end() ; it++)
		cout << it->first << " " << it->second <<endl;

	pair<int*,int*>p;
	cout << p.first <<endl;
	




return 0;
}