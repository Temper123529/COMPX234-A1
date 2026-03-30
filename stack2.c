#include<stdio.h>    
#include<stdlib.h>

typedef int ElemType;
typedef struct stack{

    ElemType data;
    struct stack*next;

}Stack;

Stack*initStack(){
    Stack*s=(Stack*)malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}

//判断是否空
int isEmpty(Stack*s){
    if(s->next==NULL){
        printf("空\n");
        return 1;
    }
}


//进栈
int push(Stack*s,ElemType e){
    Stack*p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}

