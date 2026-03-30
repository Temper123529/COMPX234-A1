// #include <stdlib.h>
// #include <stdio.h>

// typedef int ElemType;
// typedef struct node{
//     ElemType data;
//     struct node*next;

// }Node;

// Node*initList(){
//     Node*head=(Node*)malloc(sizeof(Node));
//     head->data=0;
//     head->next=NULL;
//     return head;

// }

// int insertHead(Node*L,ElemType e){
//     Node*p=L;
//     Node*q=(Node*)malloc(sizeof(Node));
//     q->data=e;
//     q->next=p->next;
//     p->next=q;
//     return 1;
// }

// int findNode(Node*L,int k){
//     Node*slow=L;
//     Node*fast=L;
//     int i=0;
//     while(i<k){
//         fast=fast->next;
//         i++;
//         if(fast->next==NULL){
//             return 0;
//         }

//     }
//     while(fast->next!=NULL){
//         fast=fast->next;
//         slow=slow->next;
//     }
//     return slow->next->data;
// }

// int main(){
//     Node*node=initList();
//     insertHead(node,10);
//     insertHead(node,20);
//     insertHead(node,30);
//     insertHead(node,40);
//     insertHead(node,50);
//     insertHead(node,60);
//     printf("%d\n",findNode(node,3));
//     }