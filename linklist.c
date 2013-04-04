/* link list without head node and its operation */
#include<stdio.h>
#include<stdlib.h>
#define DT char
typedef struct node
{
  DT data;
	struct node *next;
}LinkList;

//测试尾结点 
int LinkList_IsLast(LinkList *List,LinkList *p)
{
	if(p->next==NULL)
		return 1;
	else return 0;
}

//头插入初始化 
LinkList *LinkListInsert_top()
{
	LinkList *t=NULL,*head;
	char ch;
	while((ch=getchar())!='$')
	{
		t=malloc(sizeof(LinkList));
		t->data=ch;
		t->next=head;
		head=t;
	}
	return head;
}

//尾插入初始化 
LinkList *LinkListInsert_Tail_EvenEmpty()
{
	LinkList *t,*tail;
	char ch;
	{
		while((ch=getchar())!='$')
		{
			t=malloc(sizeof(LinkList));
			tail->next=t;
			tail=t;
		}
	}
	
/* if(head==tail)	
	{
		while((ch=getchar)!='$')
		{
			head=t;
			tail=t;
		}
	}
*/
	return tail; //where is head
}


//以下是查找运算 
//查找数据x所在结点的地址 
LinkList* LinkListLocate(LinkList *list,DT x)
{
	/* return the address of node with DT x */
	LinkList *p;
	p=list;
	while(p!=NULL&&p->data!=x)
			p=p->next;
	return p;
}

//查找第number个结点的地址 
LinkList* LinkListGet(LinkList *list,unsigned int number)
{
	/* input the ordinal number and return the node address from list;*/
	unsigned int vernier=0;
	LinkList *p=list;
	while((vernier<number)&&(p->next!=NULL))
		{p=p->next;vernier++;}
	if(vernier==number)
		return p;
	else
		return NULL;
}

//查找结点p的前继结点地址
LinkList* LinkList_FindPrevious(LinkList *List,LinkList *p)
{
	/*To found the previous node,then return its address*/
	LinkList *pre;
	pre=List;
	while(pre!=NULL&&pre->next!=p)
		pre=pre->next;
	return pre;
}


//以下是删除运算 
//通过数据来删除结点 
void LinkListDelete_byData(LinkList *list,DT x)
{
	LinkList *p,*TmpCell; 
	
	TmpCell=LinkListLocate(list,x);//x的结点地址 
	p=LinkList_FindPrevious(list,TmpCell);//x前继结点的地址 

	if(LinkList_IsLast(list,p))
	{
		free(TmpCell);
		p->next=NULL;
	}
	else
	{
		TmpCell=p->next;
		p->next=TmpCell->next;
		free(TmpCell);
	}
	 
}

//通过序数来删除结点 
void LinkListDelete_byNumber(LinkList *list,unsigned int number)
{
	LinkList *p,*TmpCell; 
	
	TmpCell=LinkListGet(list,number);//x的结点地址 
	p=LinkList_FindPrevious(list,TmpCell);//x前继结点的地址 

	if(LinkList_IsLast(list,p))
	{
		free(TmpCell);
		p->next=NULL;
	}
	else
	{
		TmpCell=p->next;
		p->next=TmpCell->next;
		free(TmpCell);
	}
}
