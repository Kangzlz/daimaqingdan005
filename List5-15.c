/*加一训练（其五：记忆多个数值并输入这些数值加一后的值）*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x){
    clock_t c1=clock(),c2;
    do{
        if((c2=clock())==(clock_t)-1)
        return 0;
    }while(1000.0*(c2-c1)/CLOCKS_PER_SEC<x);
    return 1;
}
int main(void){
    int i,stage;
    int max_stage;
    int level;
    int success;
    int *score;
    clock_t start,end;

    srand(time(NULL));

    printf("加一训练开始！！\n");
    printf("记忆2位的数值。\n");
    printf("请输入原数值加1后的值。\n");

    do{
        printf("要挑战的等级(%d~%d):",LEVEL_MIN,LEVEL_MAX);
        scanf("%d",&level);
    }while(level<LEVEL_MIN||level>LEVEL_MAX);
    do{
        printf("训练次数：");
        scanf("%d",&max_stage);
    }while(max_stage<=0);

    score=calloc(max_stage,sizeof(int));

    success=0;
    start=clock();
    for(stage=0;stage<max_stage;stage++){
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
        printf("\r%*s\r",level*max_stage);
        fflush(stdout);

        for(i=0;i<level;i++){
            printf("第%d个数:",i+1);
            scanf("%d",&x[i]);
        }
        for(i=0;i<level;i++){
            if(x[i]!=no[i]+1)
            printf(" X ");
            else{
                printf(" O ");
                seikai++;
            }
        }
        putchar('\n');

        for(i=0;i<level;i++)
        printf("%2d ",no[i]);

        printf("···答对了%d个。\n",seikai);
        score[stage]=seikai;
        success+=seikai;
    }
    end=clock();

    printf("%d个中答对了%d个。\n",level*max_stage,success);

    for(stage=0;stage<max_stage;stage++)
    printf("第%d关卡:%d\n",stage+1,score[stage]);

    printf("用时%.1f秒。\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}