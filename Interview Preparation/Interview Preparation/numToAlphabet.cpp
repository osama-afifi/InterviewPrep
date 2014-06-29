#include "All.h"

#include "All.h"

string digit[] = { "" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
string tens[] = { "" ,"ten" , "twenty", "thirty" , "forty" , "fifty" , "sixty" , "seventy" , "eighty" , "ninety"};
string xteens[] = { "", "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"};
string big[] = { "" , "thousand" , "million" , "Billion" , "Trillion"};


string parseBlock(int num)
{
	string res = "";
	if(num==0)return res;
	int hundred = num/100;
	if(hundred!=0)
		res+= digit[hundred] + " hundred ";		
	int dig2 = num%100;
	if(dig2 >=11 && dig2<=19)
		res+= " " + xteens[num%10];
	else
	{
		if(dig2/10)
		res += " " + tens[dig2/10] + " " + digit[num%10];
		else res+= " " + digit[num%10];
	}

	return res;
}

string intToAlpha(int num)
{
	if(num==0)
		return "Zero";
	if(num<0)
		return "Negative " + intToAlpha(-num);
	string res = "";
	int count = 0;
	while(num>0)
	{
		int curBlock = num%1000;
		if(curBlock!=0)
		res =  parseBlock(curBlock) + " " + big[count] +  " " + res + " ";
		count++;
		num/=1000;
	}
	return res;
}


int main()
{
	//for(int i  = 0 ; i< 100 ; i++)
	cout<< intToAlpha(1234567) <<endl;

}