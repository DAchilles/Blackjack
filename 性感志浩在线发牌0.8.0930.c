//原始版本
//只能进行一局，只有PvE，不能显示牌面信息，不能只能处理A ，JQK未处理为10 
//界面贼丑 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
char a[110];         //储存输入数据 
int deck[15][5];     //构建扑克牌组 
int player[15][5],dealer[15][5];    //构建玩家手牌与庄家手牌 
int sum1=0,sum2=0,cont=1;    //记录庄家手牌大小&&是否继续要牌 
int s1=0,s2=0;
void yp()             //玩家要牌 
{
	srand((unsigned)(time(NULL)));     //时间函数生成随机数 
	int m,n;
	for(;;)
	{
		m=rand()%12;n=rand()%3;       //随机确定一张牌 
	    if(deck[m][n])                //判断该牌是否已用 
		{
		    deck[m][n]=0;             //将牌标记为已使用 
			player[s1][1]=m+1;        //保存玩家新增手牌点数 
			player[s1][2]=n;          //保存玩家新增手牌花色 
			sum1=sum1+m+1;            //增加玩家手牌点数 
			s1++;
			break;
		}
	    else continue;                //如果确定的牌已使用，重新确定下一张直到可用为止
	}
}




void zj()             //庄家要牌 
{
	if(sum2>=17) {cont=0;return;}      //庄家点数大于18时不再要牌 
	srand((unsigned)(time(NULL)));       //时间函数生成随机数 
	int m,n;
	for(;;)
	{
		m=rand()%12;n=rand()%3;          //随机确定一张牌 
	    if(deck[m][n])                   //判断该牌是否已用 
		{
		    deck[m][n]=0;                //将牌标记为已使用 
			dealer[s2][1]=m+1;           //保存庄家新增手牌点数 
			dealer[s2][2]=n;             //保存庄家新增手牌花色
			sum2=sum2+m+1;               //增加玩家手牌点数
			s2++;
			break;
		}
	    else continue;                   //如果确定的牌已使用，重新确定下一张直到可用为止 
	}	
} 




int main ()
{
	int i,j;
	for(i=0;i<=14;i++)                             //玩家和庄家手牌清空 
	{
		memset(player[i],0,sizeof(player[i]));
	    memset(dealer[i],0,sizeof(dealer[i]));
	}
	for(i=0;i<=12;i++)                              //初始化扑克牌 
	  for(j=0;j<=3;j++)
	  deck[i][j]=1;
	for(;;)
	{  
	    printf("当前您的手牌点数为：%d，是否继续要牌\n",sum1); 
		memset(a,0,sizeof(a));             //清空输入数据  
		scanf("%s",a);                     //输入数据
	    if(strlen(a)!=1)                   //玩家选择沉默，并且再要了一张牌 
	    {
	    	yp();
	    	if(cont) zj();                 //庄家选择是否要牌 
	    	continue;
	    }
	    else if(a[0]=='y')                //玩家jio得OK，并且再要了一张牌   
	    {
		    printf("OK\n");
		    yp();
		    if(cont) zj();                //庄家选择是否要牌
		    continue;
	    }
	    else if(a[0]=='n')               //玩家jio得海星，并且再要了一张牌 
	    {
		    printf("Not bad\n");
		    yp();
		    if(cont) zj();               //庄家选择是否要牌
		    continue;
	    }
	    else                            //玩家不想继续并向你丢了一句债见 
	    {
		    printf("Bye\n\n");
		    while(cont) zj();           //庄家选择是否要牌 
		    break;
	    }
    }
    printf("这一局已经结束\n");
    if(sum1<=21) printf("您的点数为：%d\n\n",sum1);
    else printf("不好意思，您爆牌了QAQ\n\n");
	if(sum2<=21) printf("庄家的点数为：%d\n\n",sum2);
	else printf("恭喜您，庄家爆牌了hhh\n\n"); 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("恭喜你战胜了黑心的X志浩同学");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("你和黑心X志浩同学平局，加把劲！");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("邪恶的X志浩同学居然赢了，不服！！！");
	return 0;
}
