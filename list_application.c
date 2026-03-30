#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node*next;

}Node;

Node*initList(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;

}

//头插法

int insertHead(Node*L,ElemType e){
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=L->next;
    L->next=q;
    return 1;


}

//遍历
void ListNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}

//尾插
Node*getTail(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        p=p->next;
    }
    return p;
}

int insertTail(Node*tail,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    return 1;


}

//尾插法，插入节点
Node*insertTailWithNode(Node*tail,Node*node){
    tail->next=node;
    node->next=NULL;
    return node;
}

//指定位置插入
int insertpos(Node*L,int pos,ElemType e){
    Node*p=L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }

    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;

}
//删除节点

//获取链表长度

int listLength(Node*L){
    Node*p=L;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
        i++;
    }
    return i;
}

//释放列表
void freeList(Node*L){
    Node*p=L->next;
    Node*q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;

    }
    L->next=NULL;
}

//查找倒数第k个节点
int findNode(Node*L,int k){
    Node*fast=L->next;
    Node*slow=L->next;
    for(int i=0;i<k;i++){
        fast=fast->next;
      
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;


    }
    printf("倒数第%d个节点数：%d\n",k,slow->data);
    return 1;

}

//查找两个节点共同后缀的起始位置
Node*findPos(Node*headA,Node*headB){
    if(headA==NULL||headB==NULL){
        return NULL;
    }
    Node*p=headA;
    int lenA=0;
    int lenB=0;
    while(p!=NULL){
        p=p->next;
        lenA++;
    }
    p=headB;
    while(p!=NULL){
        p=p->next;
        lenB++;
    }
    Node*fast;
    Node* slow;
    int step;
    if(lenA>lenB){
        step=lenA-lenB;
        fast=headA;
        slow=headB;

    }
    else{
        step=lenB-lenA;
        fast=headA;
        slow=headB;
    }
    for(int i=0;i<step;i++){
        fast=fast->next;
    }
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;

    }
    return fast;
}

int main(){

    Node*list1=initList();
    Node*list2=initList();
    Node*tail1=getTail(list1);
    Node*tail2=getTail(list2);
    insertTail(tail1,'l');
    insertTail(tail1,'o');
    insertTail(tail1,'a');
    insertTail(tail1,'d');
    insertTail(tail2,'b');
    insertTail(tail2,'e');

}