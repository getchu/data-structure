/* 用 带表头的单链表 实现 栈ADT */
#include<stdio.h>
#include<stdlib.h>
#define DT char
#define PrintControl "%c"

//----------------------------
/*Maybe write then in the header file*/
typedef struct StackNode
{
  DT data;
	struct StackNode *next;
}Stack;

int StackIsEmpty(Stack *s);
Stack* CreatStack(void);
void MakeEmpty(Stack *s);
DT StackTop(Stack *s);
void Pop(Stack *s);
void Push(Stack *s,DT x);
//-----------------------------


int StackIsEmpty(Stack *s)
{
	return s->next==0;
}

Stack* CreatStack(void)/* 创建栈的表头;*/
{
	Stack *s;
	s=(Stack *)malloc(sizeof(Stack));
	if(s==NULL)
		printf("Error:Out of space!\n");
	s->next=NULL;
	MakeEmpty(s);/*保险起见,先清空栈;*/
	return s;
}

void MakeEmpty(Stack *s)/*清空栈中所有元素;*/
{
	if(s==NULL)
		printf("Errot:Must use CreatStack first!\n");
	else
		while(!StackIsEmpty(s))
			Pop(s);
} /*当栈不为空，loop出栈，直至剩下单链表的表头;*/


DT StackTop(Stack *s)
{
	if(!StackIsEmpty)
		return s->next->data;
	printf("\nError:Empty Stack!\n");
	return 0;
}

void Pop(Stack *s)
{
	Stack *FirstCell;
	if(StackIsEmpty(s))
		printf("\nError:Empty Stack\n");
	else
	{
		FirstCell=s->next;
		s->next=s->next->next;
		free(FirstCell);
	}
}

void Push(Stack *s,DT x)
{
	Stack *TmpCell;
	TmpCell=(Stack*)malloc(sizeof(Stack));
	if(TmpCell==NULL)
		printf("\nError:Out of space!\n");
	else
	{
		TmpCell->data=x;
		TmpCell->next=s->next;
		s->next=TmpCell;
	}
}


//----------------------
/*Just For Test*/
int main()
{

//test Init function;
//test Push function;
//test Pop function;
//test Top function;
//test Make function;

return 0;}
