//模块化，加入PvP设计（testing) 
//加入多局模式与退出选项
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
char a[110];         //储存输入数据 
int deck[15][5];     //构建扑克牌组 
int player[15][5],dealer[15][5];    //构建玩家手牌与庄家手牌 
int sum1=0,sum2=0,cont=1;    //记录庄家手牌大小&&是否继续要牌 
int s1=0,s2=0;
void js(int p)
{
	int i,k=0;
	if(p==1)
	{
		for(i=0;i<s1;i++)
	    {
		    if(player[i][1]>0&&player[i][1]<10) sum1=sum1+player[i][1]+1;
		    else if(player[i][1]!=0&&player[i][1]<13) sum1=sum1+10;
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
		sum2=0;
		for(i=0;i<s2;i++)
	    {
	    	if(dealer[i][1]>0&&dealer[i][1]<10) sum2=sum2+dealer[i][1]+1;
	    	else if(dealer[i][1]!=0&&dealer[i][1]<13) sum2=sum2+10;
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
	return;
} 



void yp()             //玩家要牌 
{
	srand((unsigned)(time(NULL)));     //时间函数生成随机数 
	int m,n;
	for(;;)
	{
		m=rand()%13;n=rand()%4;       //随机确定一张牌 
	    if(deck[m][n])                //判断该牌是否已用 
		{
		    deck[m][n]=0;             //将牌标记为已使用 
			player[s1][1]=m;        //保存玩家新增手牌点数 
			player[s1][2]=n;          //保存玩家新增手牌花色 
			s1++;
			break;
		}
	    else continue;                //如果确定的牌已使用，重新确定下一张直到可用为止
	}
	return;
}




void zj()             //庄家要牌 
{
	if(sum2>=17) {cont=0;return;}      //庄家点数大于18时不再要牌 
	srand((unsigned)(time(NULL)));       //时间函数生成随机数 
	int m,n;
	for(;;)
	{
		m=rand()%13;n=rand()%4;          //随机确定一张牌 
	    if(deck[m][n])                   //判断该牌是否已用 
		{
		    deck[m][n]=0;                //将牌标记为已使用 
			dealer[s2][1]=m;           //保存庄家新增手牌点数 
			dealer[s2][2]=n;             //保存庄家新增手牌花色
			s2++;
			js(2); 
			break;
		}
	    else continue;                   //如果确定的牌已使用，重新确定下一张直到可用为止 
	}
} 




void sp(int p)
{
	if(p==1)
	{
		printf("您的手牌如下:\n");
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
	}
	else
		{
		printf("庄家手牌如下:\n");
	    int i;
	    for(i=0;i<s2;i++)
	    {
		    if(dealer[i][1]>0&&dealer[i][1]<10)        //牌为2~10 
		    {
			    if(dealer[i][2]==0) printf("黑桃%d ",dealer[i][1]+1); 
			    else if(dealer[i][2]==1) printf("红桃%d ",dealer[i][1]+1); 
		    	else if(dealer[i][2]==2) printf("梅花%d ",dealer[i][1]+1);
		    	else printf("方块%d ",dealer[i][1]+1);
			
	    	}
	    	else if(dealer[i][1]==0)        //牌为A 
	    	{
	    		if(dealer[i][2]==0) printf("黑桃A "); 
	    		else if(dealer[i][2]==1) printf("红桃A "); 
		    	else if(dealer[i][2]==2) printf("梅花A ");
	    		else printf("方块A ");	
	    	}
	    	else if(dealer[i][1]==10)        //牌为J 
	    	{
	     		if(dealer[i][2]==0) printf("黑桃J "); 
	    		else if(dealer[i][2]==1) printf("红桃J "); 
	    		else if(dealer[i][2]==2) printf("梅花J ");
		    	else printf("方块J ");		
		    }
	    	else if(dealer[i][1]==11)        //牌为Q 
	    	{
	    		if(dealer[i][2]==0) printf("黑桃Q "); 
	    		else if(dealer[i][2]==1) printf("红桃Q "); 
	    		else if(dealer[i][2]==2) printf("梅花Q ");
	    		else printf("方块Q ");		
	        }
	    	else         //牌为K 
	    	{
		    	if(dealer[i][2]==0) printf("黑桃K "); 
		    	else if(dealer[i][2]==1) printf("红桃K "); 
		    	else if(dealer[i][2]==2) printf("梅花K ");
		    	else printf("方块K ");	
			
			
		    }
	    }
	} 
	printf("\n\n");	
}



void PvE()
{
	system("cls");
	int i,j;
	    sum1=0;sum2=0;cont=1;
        s1=0,s2=0;
		    for(i=0;i<=14;i++)                             //玩家和庄家手牌清空 
    	{
	    	memset(player[i],0,sizeof(player[i]));
	        memset(dealer[i],0,sizeof(dealer[i]));
	    }
	    for(i=0;i<=12;i++)                              //初始化扑克牌 
	      for(j=0;j<=3;j++)
	      deck[i][j]=1;
	    printf("游戏开始！\n\n\n");
        printf("提示：\n");
        printf("y:如果你觉得手牌不错，并还想再要下一张牌，请输入y\n"); 
        printf("n:如果你觉得手牌一般，但还想再要下一张牌搏一搏，请输入n\n");
        printf("q:如果你不想继续要牌，请输入q\n");
        printf("请输入相应字母继续\n\n");
	    for(;;)
	    {  
	    	memset(a,0,sizeof(a));             //清空输入数据  
    		scanf("%s",a);                     //输入数据
	        if(a[0]=='y')                //玩家jio得OK，并且再要了一张牌   
	        {
		        printf("OK，");
    		    yp();sp(1);
	    	    if(cont) zj();                //庄家选择是否要牌
		        continue;
	        }
    	    else if(a[0]=='n')               //玩家jio得海星，并且再要了一张牌 
    	    {
    		    printf("Not bad，");
    		    yp();sp(1);
    		    if(cont) zj();               //庄家选择是否要牌
    		    continue;
    	    }
    	    else                         //玩家不想继续并向你丢了一句债见 
    	    {
    		    printf("Bye");
    		    while(cont) zj();           //庄家选择是否要牌 
    		    break;
    	    }
        }
        system("cls");
        printf("本局已经结束\n\n\n");
        sp(1);        //显示玩家手牌 
        js(1);        //结算玩家手牌 
        sp(2);        //显示庄家手牌 
        printf("本局结果如下：\n"); 
        if(sum1<=21) printf("您的点数为：%d\n",sum1);        //结算玩家点数 
        else printf("玩家爆牌\n");              //同上 
        if(sum2<=21) printf("庄家的点数为：%d\n\n",sum2);      //结算庄家点数 
	    else printf("庄家爆牌\n\n");              //同上 
        if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("玩家胜\n");
        else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("平局\n");
        else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("庄家胜\n");
        system("pause");
        system("cls");
	    }
	
int main ()
{
	
	for(;;)
	{
		int x;
		printf("欢迎进入志浩同学的澳门线上赌场\n");
	    printf("请选择以下模式\n"); 
	    printf("1：玩家vs玩家\n");
	    printf("2：玩家vs电脑\n");
	    printf("3：退出程序\n");
	    printf("请输入数字1~3选择相应模式，按回车键确定\n"); 
	    scanf("%d",&x);
	    if (x==1);
	    else if(x==2) PvE();
	    else if(x==3) break; 
    }
	return 0;
}
