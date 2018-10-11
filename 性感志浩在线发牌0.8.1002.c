/*
现存在以下问题待解决：
Q1.游戏只能进行一局
Q2.J,Q,K三张牌代表点数应均为10，而非11,12,13
Q3.A表示的点数应可在1或11之间选择
Q4.玩家与庄家的手牌信息储存但并未使用

解决思路及方案：
A1.加入外围循环使游戏能多次进行 
A2.比较生成牌面点数与10的大小(已解决）
A3&A4.每次加牌后显示手牌信息，确定玩家不要牌后再求最优点数 （已解决，但有待优化） 
*/ 
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
			sum2=sum2+m+1;
			js(2);
			break;
		}
	    else continue;                   //如果确定的牌已使用，重新确定下一张直到可用为止 
	}	
} 




void sp()
{
	printf("您当前手牌如下:\n");
	int i;
	for(i=0;i<s1;i++)
	{
		if(player[i][1]!=0&&player[i][1]<10)        //牌为2~10 
		{
			if(player[i][2]==0) printf("黑桃%d ",player[i][1]+1); 
			else if(player[i][2]==1) printf("红桃%d ",player[i][1]+1); 
			else if(player[i][2]==2) printf("梅花%d ",player[i][1]+1);
			else printf("方块%d ",player[i][1]+1);
			
		}
		else if(player[i][1]==0)        //牌为A 
		{
			if(player[i][2]==0) printf("黑桃A "); 
			else if(player[i][2]==1) printf("红桃A "); 
			else if(player[i][2]==2) printf("梅花A ");
			else printf("方块A ");	
		}
		else if(player[i][1]==10)        //牌为J 
		{
			if(player[i][2]==0) printf("黑桃J "); 
			else if(player[i][2]==1) printf("红桃J "); 
			else if(player[i][2]==2) printf("梅花J ");
			else printf("方块J ");		
		}
		else if(player[i][1]==11)        //牌为Q 
		{
			if(player[i][2]==0) printf("黑桃Q "); 
			else if(player[i][2]==1) printf("红桃Q "); 
			else if(player[i][2]==2) printf("梅花Q ");
			else printf("方块Q ");		
		}
		else         //牌为K 
		{
			if(player[i][2]==0) printf("黑桃K "); 
			else if(player[i][2]==1) printf("红桃K "); 
			else if(player[i][2]==2) printf("梅花K ");
			else printf("方块K ");	
			
			
		}
	}
	printf("\n");	
}



void js(int p)
{
	int i,k=0;
	if(p==1)
	{
		for(i=0;i<s1;i++)
	{
		if(player[i][1]>0&&player[i][1]<10) sum1=sum1+player[i][1]+1;
		else if(player[i][1]<13) sum1=sum1+10;
		else k++;
	}
	if(k==1)
	{
		if(sum1+11<22) sum1=sum1+11;
		else sum1=sum1+1;
	}
	else if(k==2)
	{
		if(sum1+12<22) sum1=sum1+12;
		else sum1=sum1+2;
	}
	else sum1=sum1+k;
	}
	else
	{
		for(i=0;i<s2;i++)
	{
		if(dealer[i][1]>0&&dealer[i][1]<10) sum2=sum2+dealer[i][1]+1;
		else if(dealer[i][1]<13) sum2=sum2+10;
		else k++;
	}
	if(k==1)
	{
		if(sum2+11<22) sum2=sum2+11;
		else sum2=sum2+1;
	}
	else if(k==2)
	{
		if(sum2+12<22) sum2=sum2+12;
		else sum2=sum2+2;
	}
	else sum2=sum2+k;
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
	printf("您当前手牌为空,请输入y要牌\n"); 
	for(;;)
	{  
		memset(a,0,sizeof(a));             //清空输入数据  
		scanf("%s",a);                     //输入数据
	    if(strlen(a)!=1)                   //玩家选择沉默，并且再要了一张牌 
	    {
	    	yp();sp();
	    	if(cont) zj();                 //庄家选择是否要牌 
	    	continue;
	    }
	    else if(a[0]=='y')                //玩家jio得OK，并且再要了一张牌   
	    {
		    printf("OK\n");
		    yp();sp();
		    if(cont) zj();                //庄家选择是否要牌
		    continue;
	    }
	    else if(a[0]=='n')               //玩家jio得海星，并且再要了一张牌 
	    {
		    printf("Not bad\n");
		    yp();sp();
		    if(cont) zj();               //庄家选择是否要牌
		    continue;
	    }
	    else                           //玩家不想继续并向你丢了一句债见 
	    {
		    printf("Bye\n");
		    sp();
		    while(cont) zj();           //庄家选择是否要牌 
		    break;
	    }
    }
    printf("这一局已经结束\n");
    js(1);
    if(sum1<=21) printf("您的点数为：%d\n\n",sum1);
    else printf("不好意思，您爆牌了QAQ\n\n");
	if(sum2<=21) printf("庄家的点数为：%d\n\n",sum2);
	else printf("恭喜您，庄家爆牌了hhh\n\n"); 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("恭喜你战胜了黑心的X志浩同学");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("你和黑心X志浩同学平局，干巴爹！");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("邪恶的X志浩同学居然赢了，不服！！！");
	return 0;
}
