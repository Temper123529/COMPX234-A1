#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct stack{
    ElemType data[MAXSIZE];
    int top;

}Stack;

void initStack(Stack*s){
    
    s->top=-1;
    
}



//进栈
int push(Stack*s,ElemType e){

    if(s->top>=MAXSIZE-1){
        printf("已满\n");
        return 0;
    }
    else{
        s->top++;
        s->data[s->top]=e;
        return 1;
    }
}

int pop(Stack*s,ElemType *e){

    if(s->top==-1){

        printf("空\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;


}

//顺序结构初始化
