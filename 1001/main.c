#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fun.c>

int main(int argc,char** argv)
{
	char Bot[1000][10];
	int Pow[1000];
	size_t i =0;
	//printf("input !");
	while(scanf("%s%d",&Bot[i][0],&Pow[i]) == 2)
	{
		//printf("input %d",i);
		if(i >=1000)
			break;
		i++;
	}
	testPrint(Bot,Pow,i);
	//printf("input finish!");
	for(size_t j = 0;j<i;++j)
	{
		char* sresult= ExpoRealDec(Bot[j],Pow[j]);
		myStripZeros(sresult);
		//sresult = fcvt(result,100,&dec,&sign);
		printf("%s\n",sresult);
		if(sresult!=NULL)
		{
			delete sresult;
			sresult = NULL;
		}
	}

	return 0;
}

