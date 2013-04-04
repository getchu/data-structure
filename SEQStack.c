#include<stdio.h>
#define MaxSize 520
#define DT char
#define PrintControl "%c"

typedef struct SEQ_Stack
{
	DT data[MaxSize];
	long int vernier; /* long long int vernier=-1;*/ //TO COUNT THE ELEMENT NUMBER
	// DT *Array; //For My another algorithm
}StackArray;

//ALGORITHM 1 from our textbook

//(1)
StackArray* StackInit(StackArray *s)
{
	DT ch;
	s->vernier=-1;
	while((ch=getchar())!='$')
		s->data[++(s->vernier)]=ch;
	return s;
}

//(2)
void StackPush(StackArray *s,DT x)
{
	if((s->vernier)+1<MaxSize)
		s->data[++(s->vernier)]=x;
	else
		printf("Error:Stack has been full of data!");
}

//(3)
int IsEmpty(StackArray *s)
{if(s->vernier==-1) return 1;return 0;}
DT StackPop(StackArray *s)
{
	DT x;
	if(IsEmpty(s))
	{
		printf("Error:Could not Pop Empty stack!");
		return 0;
	}
	else
	{
		x=s->data[(s->vernier)];
		s->data[(s->vernier)]=0; /*此句可以省略，关键在下句的自减*/
		(s->vernier)--;
		return x;
	}
}

//(4)输出stack中的元素
void StackArrayOutput(StackArray *s)
{
	long int i=0;
	printf("输出栈中元素:");
	for(;i<=(s->vernier);i++)
		printf(PrintControl,s->data[i]);
	printf("\n");
}


//(5)计算stack中元素个数
long int StackCountArray(StackArray *s)
{
	return (s->vernier)+1;
}

//split all functions
int main()
{
	StackArray tmp,*test;
	
	//begin to test Init function;
	test=StackInit(&tmp);
	StackArrayOutput(test);
	printf("初始化后，元素个数是%ld\n",StackCountArray(test));
	printf("\n");

	//begin to test PUSH function;
	StackPush(test,'Q');
	printf("入栈后，元素个数是%ld\n",StackCountArray(test));
	StackArrayOutput(test);
	printf("\n");
	
	//begin to test POP function;
	printf("出栈的元素是");printf(PrintControl,StackPop(test));
	printf("\n出栈后，元素个数是%ld\n",StackCountArray(test));
	StackArrayOutput(test);
	printf("\n");

	return 0;
}ents here
