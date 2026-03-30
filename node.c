#include <stdlib.h>
#include <stdio.h>
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

//判断是否有环
int isCycle(Node*head){
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;


}
Node* posCycle(Node*head){

    Node*fast=head;
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            int count=0;
            while(fast->next!=slow){
                count++;
                fast=fast->next;
            }

            fast=head;
            slow=head;
            for(int i=0;i<count;i++){
                fast=fast->next;

            }
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }

    }
    return NULL;
    

}
int main(){
    Node*node=initList();
    insertHead(node,10);
    insertHead(node,20);
    insertHead(node,30);
    insertTail(node,40);
    insertpos(node,2,50);
   
    listLength(node);
    ListNode(node);
    freeList(node);
}