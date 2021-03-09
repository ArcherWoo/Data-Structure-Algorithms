#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define UNDER 1
#define FULL 2

/**
 * 循环队列
 */

typedef struct{
    int length;
    int * a;
    int r;//队尾,入队数据向队尾添加
    int f;//队头,出队从队头出队
    int isFlag;//标记这个队列是否已满,0表示为空队列,1表示未满,2表示已满
}LoopQueue,*PLoopQueue;

/**
 * 创建一个循环队列,默认大小是5
 * @param  length [description]
 * @return        [description]
 */
LoopQueue createLoopQueue(int length){
    LoopQueue l;

    if (length<5){
        length=5;
    }
    
    l.length=length;
    l.a=(int *)malloc(length*sizeof(int));
    l.r=0;
    l.f=0;
    l.isFlag=EMPTY;
    return l;
}

/**
 * 入队,入队成功返回1,失败返回0
 * @param  pL  [description]
 * @param  val [description]
 * @return     [description]
 */
int enqueue(PLoopQueue pL,int val){
    if (pL->isFlag == FULL){
        //队列已满,无法再添加数据
        return 0;
    }else{
        //否则的话就将当前a数组的r所对应的位置用来存储值
        (pL->a)[pL->r]=val;
        //r的位置向前移动一次
        //被坑的最惨的一次,后加加,使用之后加,在这儿必须使用前 pL->r + 1 
        pL->r = (pL->r + 1 ) % (pL->length);

        //判断当前这个循环队列的状态,因为是如队,所以接下来添加一个元素的可能状态是,UNDER(未满),或者是FULL(满)
        if (pL->r==pL->f){
            //说明此时的队列已经装满了
            pL->isFlag = FULL;
        }else{
            //说明此时的队列还没有装满
            pL->isFlag = UNDER;
        }
        return 1;
    }
}

/**
 * 出队
 * @param  pL  [description]
 * @param  val [description]
 * @return     [description]
 */
int dequeue(PLoopQueue pL,int * val){
    if (pL->isFlag==EMPTY){
        //队列为空,无法再出队
        return 0;
    }else{
        //取值
        *val=pL->a[pL->f];
        //将值清除
        pL->a[pL->f]=0;
        //f向前移动
        pL->f =( pL->f + 1 ) % pL->length;

        //判断当前这个循环队列的状态,因为是出队,所以接下来移除一个元素的可能状态是,UNDER(未满),或者是EMPTY(空)
        if (pL->f == pL->r){
            //此时全部出队了,当前的队列为空
            pL->isFlag = EMPTY;
        }else{
            pL->isFlag = UNDER;
        }
        return 1;
    }
}

int main(){
    LoopQueue loopQueue=createLoopQueue(50);

    int i,flag;
    int temp;

    for(i=0;i<60;i++){
        flag=enqueue(&loopQueue,i);
        if(flag){
            printf("入队%d\n", i);
        }else{
            printf("队列已满\n");
        }
    }

    while(dequeue(&loopQueue,&temp)){
        printf("出队%d\n", temp);
    }

    return 0;
}
