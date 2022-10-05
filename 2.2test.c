#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef int ElemType;

/*存储结构*/
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;

/*初始化链表

1.生成新结点作头结点，用头指针 L 指向头结点；
2.头结点的指针域置空。

*/
void InitList(LinkList* L)
{
    *L=(LinkLlist)malloc(sizeof(LNode));
    if(!L)
    {
        exit(OVERFLOW);
    }
    (*L)->next=NULL;
}

void DestroyList(LinkList* L)
{
    LinkList temp;
    while(*L)
    {
        temp=(*L)->next;
        free(*L)
        *L=temp;
    }
}

Status InsertElem(LinkList L,int i, ElemType e){
    int j=0;
    LinkList s,p=L;
    while(p&&j<i-1)
    {
        j++;
        p=p->next;
    }
    if(!p||j>i-1)
    {
        return ERROR;
    }
    //将后面的元素后移
    s=(LinkList)malloc (sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

/*删除元素并返回值*/
Status DeleteElem(LinkList L,int i, ElemType *e)
{
    int j=0;
    LinkList q,p=L;
    while(p->next && j<i-1)
    {
        j++;
        p=p->next;
    }
    if(!p->next ||j>i-1)
    {
        return ERROR;
    }
    //删除元素并将后面的元素前移
    q=p->next;
    p->next=q->next;
    free(q);
    return OK;
}

/*根据位置查找元素*/
Status GetElem(LinkList L,int i,ElemType* e)
{
    int j=1;
    LinkList p=L->next;
    while(p && j<i)
    {
        j++;
        p=p->next;
    }
    if(!p||j>i)
    {
        return ERROR;
    }
    *e=p->data;
    return OK;
}