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
			taken=4;
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
entry predicttab[1024];
bitset<2> globpredict[4096];
bitset<2> choicepredict[4096];
int main()
{
	unsigned long miss=0;
	unsigned long total=0;
	string str;
	int history=0;
	int choice_num;
	while(getline(cin,str))
	{
		total++;
		char curpc[20],nexpc[20];
		int instyp;
		sscanf(str.c_str(),"%s %s %d",curpc,nexpc,&instyp);
		int index=strtoint(curpc)%1024;
		int choiceindex=strtoint(curpc);
		if(choicepredict[choiceindex].to_ulong()>1)
			choice_num=1;
		else
			choice_num=0;
		if((strtoint(nexpc)-index)%1024!=4)
		{
			predicttab[index].history=predicttab[index].history<<1;
			predicttab[index].history.set(0,1);
			if(predicttab[index].taken<4&&choice_num==0)
			{
				miss++;
				choicepredict[choiceindex]=(choicepredict[choiceindex].to_ulong()+1)%4;
			}
			if(globpredict[history].to_ulong()<2&&choice_num==1)
			{
				miss++;
				if(choicepredict[choiceindex].to_ulong()!=0)
					choicepredict[choiceindex]=(choicepredict[choiceindex].to_ulong()-1)%4;
			}
			if(predicttab[index].taken<7)
				predicttab[index].taken++;
			globpredict[history]=(globpredict[history].to_ulong()+1)%4;
			history=(history*2+1)%4096;
		}
		else
		{
			predicttab[index].history=predicttab[index].history<<1;
			predicttab[index].history.set(0,0);
			if(predicttab[index].taken>3&&choice_num==0)
			{
				miss++;
				choicepredict[choiceindex]=(choicepredict[choiceindex].to_ulong()+1)%4;
			}
			if(globpredict[history].to_ulong()<2&&choice_num==1)
			{
				miss++;
				if(choicepredict[choiceindex].to_ulong()!=0)
					choicepredict[choiceindex]=(choicepredict[choiceindex].to_ulong()-1)%4;
			}

			if(predicttab[index].taken>0)
				predicttab[index].taken--;
			if(globpredict[history].to_ulong()!=0)
				globpredict[history]=(globpredict[history].to_ulong()-1)%4;
			history=(history*2+1)%4096;
		}
	}
	cout<<float(miss)/total<<endl;
	return 0;
}
