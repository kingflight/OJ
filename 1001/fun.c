#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char i2cnum(int i)
{
	return (char)(i+0x30);
}

// 字符转化成整形
int cnum2i(char c)
{
	return (int)((int)c-0x30);
}

void deleteindex(char *s,int index )
{
	int i = index+1;
	while(s[i]!='\0')
	{
	   //printf("deleteindex\n");
	   s[i-1]=s[i];
	   i++;
	}
	s[i-1]=s[i];
}

bool isAllZero(const char* s)
{
   int i =0 ;
   while(s[i]!=0)
   {
	   //printf("isAllZero\n");
       if(s[i] != '0')
           return false;
	   i++;
   
   }
   return true;
}

bool HasDecPoint(char* s)
{
	for(int i =0 ;i<strlen(s);++i)
	{
		if(s[i]=='.')
			return true;
	}
	return false;
}

void myStripZeros(char* s)
{
	if(isAllZero(s))
	{
		s[0]='0';
		s[1]=0;
	}
	//删除前面的0
	int i =0 ;
	while (s[i]=='0')
	{
		deleteindex(s,i);	
	}

	if(HasDecPoint(s))
	{
		//printf("%s\n",s);
		//删除后面的0
		//int j =i-1 ;
		int j=strlen(s)-1;
		while (s[j]=='0')
		{
			deleteindex(s,j);	
			j--;
		}
	}
	// if all left is a dec point 
	if(s[0]=='.'&&s[1]=='\0')
	{
		s[0]='0';
		s[1]=0;
	}
}

void testPrint(char a[1000][10],int* b,int num)
{
	for(int i=0;i<num;i++)
	{
		printf("%s %d\n",&a[i][0],b[i]);
	}
}


// n1乘以n2的补weight个0存入r 中
// 注字符要先转成数值
void mulRealDigit(char *n1,int n2,int weight,char *r)
{
	int carry = 0;
	int value = 0;
	int sum[1000];
	int i = 0;
	for(i = strlen(n1) -1;i != 0; --i)
	{
		int digit = cnum2i(n1[i]);
		int product = n2 * digit + carry;
		value = product % 10;
		sum[i]=value;
		carry = product /10;
	}
	int digit = cnum2i(n1[i]);
	int product = n2 * digit + carry;
	value = (product) % 10;
	carry = product /10;
	sum[i]=value;
	//输出结果
	int j = 0;
	if(carry != 0)
	{
		r[0]=i2cnum(carry);
		j = 1;
	}
	else
	{
		j = 0;
	}
	for( int count=0;count < strlen(n1) ;++j ,++count)
	{
		r[j]= i2cnum(sum[count]);
	}
	// 补0
	int k =0;
	for(;k<weight;++k)
	{
		r[j+k]='0';
	}
	r[j+k]='\0';
		
}

// n1+n2的结果存入r中
void addRealReal(char *n1,char* n2,char* r)
{
	int value = 0;
	int carry = 0;
	int i2 = strlen(n2);
	int i1 = strlen(n1);
	int i = i1>i2?i2:i1;
	//int i3 = i1<i2?i2:i1;
	int i3 = 0;
	int sum[1000];
	do
	{
		--i;--i1;--i2;
		int isum = cnum2i(n1[i1])+cnum2i(n2[i2])+ carry;
		value = isum%10 ;
		sum[i3] = value;
		carry = isum/10;
		++i3;
	}while(i!=0);

	if(i1!=i2)
	{
		char *n = strlen(n1)>strlen(n2)?n1:n2;
		int ibig = n==n1?i1:i2;
		do{
			--ibig;
			int isum=cnum2i(n[ibig])+carry;
			value = isum%10;
			sum[i3] = value;
			carry = isum/10;
			++i3;
		}while(ibig!=0);
	}
	// output result
	int ir = 0;
	if(carry!=0)
	{
		r[ir]=i2cnum(carry);
		++ir;
	}
	do
	{
		i3--;
		r[ir]=i2cnum(sum[i3]);
		ir++;
	}while(i3!=0);
	r[ir]='\0';
	
}

// 返回n中小数点后有几个数字
int countAfterPointNum(const char* n)
{
	int i=0;
	bool bfound = false;
	for(;i<strlen(n);++i)
	{
		if(n[i]=='.')
		{
			bfound = true;
			break;
		}
	}
	if(!bfound)
		return 0;
	
	return (strlen(n)-i-1);

}

// 删除n中的小数点
void removeDecPoint(char * s)
{
	for(int i=0;i<strlen(s);++i)
	{
		if(s[i]=='.')
		{
			deleteindex(s,i);
		}
	}
}

// 在某个索引之前插入字符
void insertBeforeIndex(char* s,int i)
{
	int j=strlen(s);
	for(;j>=i;--j)
	{
		s[j+1]=s[j];
	}
	s[j+1]='.';
}

void insertMultiCharAtBegin(char* s,int n ,char c)
{
	int i = strlen(s);
	for(;i!=0;--i)
	{
		s[i+n]=s[i];
	}
	s[i+n]=s[i];
	for(int j =0;j<n;++j)
	{
		s[j] = c;
	}
}
void mulRealReal(char *pn1,char* pn2,char *r)
{
	char n1[1000]= {0};
	char n2[1000]= {0};
	strcpy(n1,pn1);
	strcpy(n2,pn2);
	int AfterPointNum = countAfterPointNum(n1)+countAfterPointNum(n2);
	//memcpy(n1,pn1,strlen(pn1)+1);
	//memcpy(n2,pn2,strlen(pn2)+1);

	removeDecPoint(n1);
	removeDecPoint(n2);
	char sum[1000]= {0};
	sum[0] = '0';
	sum[1] = '\0';
	char r1[1000] = "0"; //保存中间结果
	int digitWeight = 0; //表示数字后面需要加几个零
	int digitIndex = strlen(n2)-1;
	for(;digitIndex!=0;digitIndex--,digitWeight++)
	{
		mulRealDigit(n1,cnum2i(n2[digitIndex]),digitWeight,r1);
		addRealReal(sum,r1,sum);
	}
	mulRealDigit(n1,cnum2i(n2[digitIndex]),digitWeight,r1);
	addRealReal(sum,r1,sum);
	// 下面恢复小数点
	if(AfterPointNum ==0)
	{
		memcpy(r,sum,1000);
		return ;
	}
	int insertIndex = strlen(sum)-AfterPointNum;
	if(insertIndex<0)
	{
		insertMultiCharAtBegin(sum,1-insertIndex,'0');
	}
	insertBeforeIndex(sum,insertIndex);
	memcpy(r,sum,1000);
	return ;
}

char* ExpoRealDec(char* bot,int pow)
{
	char * sum = new char[1000];
	memcpy(sum,bot,1000);
	for(int i = 0; i< pow-1;i++)
	{
		mulRealReal(sum,bot,sum);
	}
	return sum;
}


