#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct node{
    ElemType data;
    struct node*next;
}Node;

Node*initList(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=NULL;
    head->next=NULL;
    return head;

}
int insertHead(Node*L,ElemType e){
    Node*p=L;
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}

int find_same_ing(Node*str1,Node*str2){
    Node*p=str1;
    Node*q=str2;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
        i++;

    }
    int j=0;
    while(q->next!=NULL){
        q=q->next;
        j++;
    }
    if(i>j){
        Node*fast=str1->next;
        Node*slow=str2->next;
        for(int k=0;k<i-j;k++){
            fast=fast->next;
        }
        int pos=i-j;
        while(fast!=NULL){
            if(fast->data==slow->data){
                return pos;
            }
            pos++;

        }
        

    }
    else{
        Node*fast=str2->next;
        Node*slow=str1->next;
        for(int k=0;k<j-i;k++){
            fast=fast->next;
        }
        int pos=j-i;
        while(fast!=NULL){
            if(fast->data==slow->data){
                return pos;

            }
            pos++;
        }
      

    }
    return 0;
    
}

int main(){
    Node*node1=initList();
    Node*node2=initList();
    insertHead(node1,"g");
    insertHead(node1,"n");
    insertHead(node1,"i");
    insertHead(node1,"o");
    insertHead(node1,"g");
    insertHead(node2,"g");
    insertHead(node2,"n");
    insertHead(node2,"i");
    insertHead(node2,"s");
    printf("%d\n",find_same_ing(node1,node2));



}