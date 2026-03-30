#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int length;

}SeqList;
void initList(SeqList *L){
    L->length=0;
    
}

//在尾部添加元素

int appendElem(SeqList *L,ElemType e){

    if(L->length>=MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    else{
        L->data[L->length]=e;
        L->length++;
        return 1;
    }
}

//遍历
void listElem(SeqList *L){
    for(int i=0;i<L->length;i++){
        pintf("%d\n",L->data[i]);
    }
    printf("\n");
}

//插入元素
int insertElem(SeqList *L,ElemType e,int pos){
    if(pos<1||pos>L->length){
        return 0;
    }
    else{
        for(int i=pos-1;i<L->length;i++){
            L->data[i]=L->data[i+1];

        }
        L->data[pos-1]=e;
        L->length++;
        return 1;
    }


}

//删除元素
int deleteElem(ElemType e,SeqList *L,int pos){
    if(pos>=1&&pos<=L->length){
        for(int i=pos;i<L->length;i++){
            L->data[i]=L->data[i-1];

        }
        L->length--;
        return 1;
    }

}

//查找
int findElem(SeqList *L,ElemType e){
    if(L->length>0){
        int i=0;
        while(i<L->length){
            if(L->data[i]==e){
                return i+1;
            }
            i++;
        }
        return 0;
    }
}

//动态分配内存地址初始化

