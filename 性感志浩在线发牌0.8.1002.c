/*
�ִ�����������������
Q1.��Ϸֻ�ܽ���һ��
Q2.J,Q,K�����ƴ������Ӧ��Ϊ10������11,12,13
Q3.A��ʾ�ĵ���Ӧ����1��11֮��ѡ��
Q4.�����ׯ�ҵ�������Ϣ���浫��δʹ��

���˼·��������
A1.������Χѭ��ʹ��Ϸ�ܶ�ν��� 
A2.�Ƚ��������������10�Ĵ�С(�ѽ����
A3&A4.ÿ�μ��ƺ���ʾ������Ϣ��ȷ����Ҳ�Ҫ�ƺ��������ŵ��� ���ѽ�������д��Ż��� 
*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
char a[110];         //������������ 
int deck[15][5];     //�����˿����� 
int player[15][5],dealer[15][5];    //�������������ׯ������ 
int sum1=0,sum2=0,cont=1;    //��¼ׯ�����ƴ�С&&�Ƿ����Ҫ�� 
int s1=0,s2=0;
void yp()             //���Ҫ�� 
{
	srand((unsigned)(time(NULL)));     //ʱ�亯����������� 
	int m,n;
	for(;;)
	{
		m=rand()%12;n=rand()%3;       //���ȷ��һ���� 
	    if(deck[m][n])                //�жϸ����Ƿ����� 
		{
		    deck[m][n]=0;             //���Ʊ��Ϊ��ʹ�� 
			player[s1][1]=m+1;        //��������������Ƶ��� 
			player[s1][2]=n;          //��������������ƻ�ɫ 
			s1++;
			break;
		}
	    else continue;                //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ
	}
}




void zj()             //ׯ��Ҫ�� 
{
	if(sum2>=17) {cont=0;return;}      //ׯ�ҵ�������18ʱ����Ҫ�� 
	srand((unsigned)(time(NULL)));       //ʱ�亯����������� 
	int m,n;
	for(;;)
	{
		m=rand()%12;n=rand()%3;          //���ȷ��һ���� 
	    if(deck[m][n])                   //�жϸ����Ƿ����� 
		{
		    deck[m][n]=0;                //���Ʊ��Ϊ��ʹ�� 
			dealer[s2][1]=m+1;           //����ׯ���������Ƶ��� 
			dealer[s2][2]=n;             //����ׯ���������ƻ�ɫ
			sum2=sum2+m+1;
			js(2);
			break;
		}
	    else continue;                   //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ 
	}	
} 




void sp()
{
	printf("����ǰ��������:\n");
	int i;
	for(i=0;i<s1;i++)
	{
		if(player[i][1]!=0&&player[i][1]<10)        //��Ϊ2~10 
		{
			if(player[i][2]==0) printf("����%d ",player[i][1]+1); 
			else if(player[i][2]==1) printf("����%d ",player[i][1]+1); 
			else if(player[i][2]==2) printf("÷��%d ",player[i][1]+1);
			else printf("����%d ",player[i][1]+1);
			
		}
		else if(player[i][1]==0)        //��ΪA 
		{
			if(player[i][2]==0) printf("����A "); 
			else if(player[i][2]==1) printf("����A "); 
			else if(player[i][2]==2) printf("÷��A ");
			else printf("����A ");	
		}
		else if(player[i][1]==10)        //��ΪJ 
		{
			if(player[i][2]==0) printf("����J "); 
			else if(player[i][2]==1) printf("����J "); 
			else if(player[i][2]==2) printf("÷��J ");
			else printf("����J ");		
		}
		else if(player[i][1]==11)        //��ΪQ 
		{
			if(player[i][2]==0) printf("����Q "); 
			else if(player[i][2]==1) printf("����Q "); 
			else if(player[i][2]==2) printf("÷��Q ");
			else printf("����Q ");		
		}
		else         //��ΪK 
		{
			if(player[i][2]==0) printf("����K "); 
			else if(player[i][2]==1) printf("����K "); 
			else if(player[i][2]==2) printf("÷��K ");
			else printf("����K ");	
			
			
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
	for(i=0;i<=14;i++)                             //��Һ�ׯ��������� 
	{
		memset(player[i],0,sizeof(player[i]));
	    memset(dealer[i],0,sizeof(dealer[i]));
	}
	for(i=0;i<=12;i++)                              //��ʼ���˿��� 
	  for(j=0;j<=3;j++)
	  deck[i][j]=1;
	printf("����ǰ����Ϊ��,������yҪ��\n"); 
	for(;;)
	{  
		memset(a,0,sizeof(a));             //�����������  
		scanf("%s",a);                     //��������
	    if(strlen(a)!=1)                   //���ѡ���Ĭ��������Ҫ��һ���� 
	    {
	    	yp();sp();
	    	if(cont) zj();                 //ׯ��ѡ���Ƿ�Ҫ�� 
	    	continue;
	    }
	    else if(a[0]=='y')                //���jio��OK��������Ҫ��һ����   
	    {
		    printf("OK\n");
		    yp();sp();
		    if(cont) zj();                //ׯ��ѡ���Ƿ�Ҫ��
		    continue;
	    }
	    else if(a[0]=='n')               //���jio�ú��ǣ�������Ҫ��һ���� 
	    {
		    printf("Not bad\n");
		    yp();sp();
		    if(cont) zj();               //ׯ��ѡ���Ƿ�Ҫ��
		    continue;
	    }
	    else                           //��Ҳ�����������㶪��һ��ծ�� 
	    {
		    printf("Bye\n");
		    sp();
		    while(cont) zj();           //ׯ��ѡ���Ƿ�Ҫ�� 
		    break;
	    }
    }
    printf("��һ���Ѿ�����\n");
    js(1);
    if(sum1<=21) printf("���ĵ���Ϊ��%d\n\n",sum1);
    else printf("������˼����������QAQ\n\n");
	if(sum2<=21) printf("ׯ�ҵĵ���Ϊ��%d\n\n",sum2);
	else printf("��ϲ����ׯ�ұ�����hhh\n\n"); 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("��ϲ��սʤ�˺��ĵ�X־��ͬѧ");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("��ͺ���X־��ͬѧƽ�֣��ɰ͵���");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("а���X־��ͬѧ��ȻӮ�ˣ�����������");
	return 0;
}
