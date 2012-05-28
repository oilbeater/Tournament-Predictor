#include  <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int strtoint(char* pc)
{
	int ret=0;
	for(int i=7;i!=10;i++)
	{
		char tmp=pc[i];
		if('0'<=tmp&&tmp<='9')
			ret=ret*16+tmp-'0';
		else
		{
			ret=ret*16+tmp-'a'+10;
		}
	}
	return ret%4096;
}
int predicttab[4096][1024];
int main()
{
	memset(predicttab,0,1024*1024);
	unsigned long miss=0;
	unsigned long total=0;
	string str;
	int history=0;
	while(getline(cin,str))
	{
		total++;
		char curpc[20],nexpc[20];
		int instyp;
		sscanf(str.c_str(),"%s %s %d",curpc,nexpc,&instyp);
		int index=strtoint(curpc);
		if((strtoint(nexpc)-index)%4096!=4)
		{
			if(predicttab[index][history]<2)
				miss++;
			if(predicttab[index][history]<3)
				predicttab[index][history]++;
			history=(history*2+1)%1024;
		}
		else
		{
			if(predicttab[index][history]>1)
				miss++;
			if(predicttab[index][history]>0)
				predicttab[index][history]--;
			history=history*2%1024;
		}
	}
	cout<<float(miss)/total<<endl;
	return 0;
}
