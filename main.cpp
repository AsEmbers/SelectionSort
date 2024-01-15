#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//定义动态数组数据结构
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SequenceTable;

//初始化随机数组
void init_rand_seq_table(SequenceTable &seq_table,int len)
{
    seq_table.len=len;
    seq_table.elem=(ElemType*)malloc(sizeof(ElemType)*seq_table.len);
    srand(time(NULL));
    for(int i=0;i<seq_table.len;i++)
    {
        seq_table.elem[i]=rand()%100;
    }
}

//初始化数组
void init_seq_table(SequenceTable &seq_table,int len)
{
    seq_table.len=len;
    seq_table.elem=(ElemType*)malloc(sizeof(ElemType)*seq_table.len);
    ElemType element;
    for(int i=0;i<seq_table.len;i++)
    {
        scanf("%d",&element);
        seq_table.elem[i]=element;
    }
}

//打印数组
void print_seq_table(SequenceTable seq_table)
{
    for(int i=0;i<seq_table.len;i++)
    {
        printf("%3d",seq_table.elem[i]);
    }
    printf("\n");
}

//交换元素
void swap(ElemType &a,ElemType &b)
{
    ElemType temp=a;
    a=b;
    b=temp;
}

//选择排序
void selection_sort(ElemType *arr,int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(arr[i],arr[min]);
        }
    }
}

int main() {
    SequenceTable seq_table;
    int len=10;
    init_rand_seq_table(seq_table,len);
//    ElemType arr[10]={12,63,58,95,41,35,65,0,38,44};
//    memcpy(seq_table.elem,arr,sizeof(arr));//使用前提：动态数组的内存空间已经初始化，即已获得一片连续的内存空间
    print_seq_table(seq_table);
    selection_sort(seq_table.elem,seq_table.len);
    print_seq_table(seq_table);
    return 0;
}
