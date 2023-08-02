/*记忆训练（记忆多个数值并输入这些数值加一后的值）*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

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
    int level;
    int success;
    int score[MAX_STAGE];
    clock_t start,end;

    srand(time(NULL));

    printf("加一训练开始！！\n");
    printf("来记忆两位的数值。\n");
    printf("请输入原数值加一后的值。\n");

    do{
        printf("要挑战的等级(%d~%d):",LEVEL_MIN,LEVEL_MAX);
        scanf("%d",&level);
    }while(level<LEVEL_MIN||level>LEVEL_MAX);

    success=0;
    start=clock();
    for(stage=0;stage<MAX_STAGE;stage++){
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
        score[stage]=seikai;
        success+=seikai;
    }
    end=clock();

    printf("%d次中答对了%d次。\n",level*MAX_STAGE,success);

    printf("\n■□ 成绩 □■\n");
    printf("--------------------\n");
    for(i=level;i>=1;i--){
        for(stage=0;stage<MAX_STAGE;stage++)
            if(score[stage]>=i)
            printf(" ★ ");
            else
            printf("   ");
        putchar('\n');
    }
    printf("--------------------\n");

    for(stage=1;stage<=MAX_STAGE;stage++)
    printf(" %02d",stage);
    putchar('\n');

    printf("用时%.1f秒。\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}