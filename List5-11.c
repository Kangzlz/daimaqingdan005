/*加一训练（其四）-显示最后的MAX_RECORD关卡的答对数量-*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEVEL_MIN 2
#define LEVEL_MAX 5
#define MAX_RECORD 10

int sleep(unsigned long x){
    clock_t c1=clock(),c2;
    do{
        if((c2=clock())==(clock_t)-1)
        return 0;
    }while(1000.0*(c2-c1)/CLOCKS_PER_SEC<x);
    return 1;
}
int main(void){
    int i,j,stage,stage2;
    int level;
    int success;
    int point[MAX_RECORD];
    int retry;
    clock_t start,end;

    srand(time(NULL));

    printf("记忆数值并输入这些数值加一后的值。\n");

    do{
        printf("要挑战的等级(%d~%d):",LEVEL_MIN,LEVEL_MAX);
        scanf("%d",&level);
    }while(level<LEVEL_MIN||level>LEVEL_MAX);

    success=stage=0;
    start=clock();
    do{
        int no[LEVEL_MAX];
        int x[LEVEL_MAX];
        int seikai=0;

        printf("\n第%d关卡开始!!\n",stage+1);

        for(i=0;i<level;i++){
            no[i]=rand()%90+10;
            printf("%d ",no[i]);
        }
        fflush(stdout);
        sleep(300*level);
        printf("\r%*s\r",3*level,"");
        fflush(stdout);

        for(i=0;i<level;i++){
            printf("第%d个数:",i+1);
            scanf("%d",&x[i]);
        }

        for(i=0;i<level;i++){
            if(x[i]!=no[i]+1)
            printf("X  ");
            else{
                printf("O  ");
                seikai++;
            }
        }
        putchar('\n');

        for(i=0;i<level;i++)
        printf("%2d ",no[i]);

        printf("···答对了%d个。\n",seikai);

        point[stage++%MAX_RECORD]=seikai;
        success+=seikai;

        printf("是否继续？(Yes···1/No···0):");
        scanf("%d",&retry);
    }while(retry==1);
    end=clock();

    printf("\n■□  成绩  □■\n");

    stage2=stage-MAX_RECORD;
    if(stage2<0) stage2=0;
    for(i=level;i>=1;i--){
        for(j=stage2;j<stage;j++)
        if(point[j%MAX_RECORD]>=i)
        printf(" ★ ");
        else
        printf("   ");
        putchar('\n');
    }
    printf("--------------------\n");

    for(j=stage2;j<stage;j++)
    printf("%02d ",j+1);
    putchar('\n');

    printf("%d个中答对了%d个。\n",level*stage,success);
    printf("用时%.1f秒。\n",(double)(end-start)/CLOCKS_PER_SEC);
     
    return 0;

}