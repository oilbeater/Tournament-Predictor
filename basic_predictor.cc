#include  <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <stdio.h>
using namespace std;
class entry
{
	public:
		bitset<10> history;
		int taken;
		entry()
		{
			history.reset();
			taken=2;
		}
};
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
	return ret;
}
entry predicttab[4096];
int main()
{
	unsigned long miss=0;
	unsigned long total=0;
	string str;
	while(getline(cin,str))
	{
		total++;
		char curpc[20],nexpc[20];
		int instyp;
		sscanf(str.c_str(),"%s %s %d",curpc,nexpc,&instyp);
		int index=strtoint(curpc);
		if((strtoint(nexpc)-index)%4096!=4)
		{
			predicttab[index].history=predicttab[index].history<<1;
			predicttab[index].history.set(0,1);
			if(predicttab[index].taken<2)
				miss++;
			if(predicttab[index].taken<3)
				predicttab[index].taken++;
		}
		else
		{
			predicttab[index].history=predicttab[index].history<<1;
			predicttab[index].history.set(0,0);
			if(predicttab[index].taken>1)
				miss++;
			if(predicttab[index].taken>0)
				predicttab[index].taken--;
		}
	}
	cout<<float(miss)/total<<endl;
	return 0;
}
