/*读取想要的数量，把最后10个存入元素个数为10的数组（其一）*/
#include<stdio.h>

#define MAX 10

int main(void){
    int i;
    int a[MAX];
    int cnt=0;
    int retry;

    printf("请输入整数。\n");

    do{
        if(cnt>=MAX){
            for(i=0;i<MAX-1;i++)
            a[i]=a[i+1];
        }

        printf("第%d个整数:",cnt+1);
        scanf("%d",&a[cnt<MAX?cnt:MAX-1]);
        cnt++;

        printf("是否继续？(Yes···1/No···0):");
        scanf("%d",&retry);
    }while(retry==1);

    if(cnt<=MAX)
    for(i=0;i<cnt;i++)
    printf("第%d个:%d\n",i+1,a[i]);
    else
    for(i=0;i<MAX;i++)
    printf("第%d个:%d\n",cnt-MAX+i+1,a[i]);

    return 0;
}