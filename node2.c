#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node*next,*prev;
}Node;

Node*initNode(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->prev=NULL;
    head->next=NULL;
    return head;
}
//头插
int insertHead(Node*L,ElemType e){

    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    p->prev=L;
    if(L->next!=NULL){
        L->next->prev=p;

    }
    L->next=p;
    return 1;

}

//尾插法
Node* getTail(Node*L){
    Node*p=L;
    
    while(p->next!=NULL){
        p=p->next;
        

    }
    return p;
}
int insertTail(Node*tail,ElemType e){

    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=NULL;
    q->prev=tail;
    tail->next=q;
    return 1;
}


//任意位置插入

int insertNode(Node*L,ElemType e,int pos){

    Node*p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        while(p==NULL){
            return 0;
        }
        

    }
    Node*q=(Node*)malloc(sizeof(Node));
        q->data=e;
        q->next=p->next;
        q->prev=p;
        while(q->next!=NULL){
            p->next->prev=q;

        }
        p->next=q;
        return 1;
}

//删除节点
int deleteNode(Node*L,ElemType e,int pos){

    Node*p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p->next==NULL){
            return 0;
        }
    }
    Node*q=p->next;
    e=q->data;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return 1;
}


