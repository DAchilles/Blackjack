//ԭʼ�汾
//ֻ�ܽ���һ�֣�ֻ��PvE��������ʾ������Ϣ������ֻ�ܴ���A ��JQKδ����Ϊ10 
//�������� 
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
			sum1=sum1+m+1;            //����������Ƶ��� 
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
			sum2=sum2+m+1;               //����������Ƶ���
			s2++;
			break;
		}
	    else continue;                   //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ 
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
	for(;;)
	{  
	    printf("��ǰ�������Ƶ���Ϊ��%d���Ƿ����Ҫ��\n",sum1); 
		memset(a,0,sizeof(a));             //�����������  
		scanf("%s",a);                     //��������
	    if(strlen(a)!=1)                   //���ѡ���Ĭ��������Ҫ��һ���� 
	    {
	    	yp();
	    	if(cont) zj();                 //ׯ��ѡ���Ƿ�Ҫ�� 
	    	continue;
	    }
	    else if(a[0]=='y')                //���jio��OK��������Ҫ��һ����   
	    {
		    printf("OK\n");
		    yp();
		    if(cont) zj();                //ׯ��ѡ���Ƿ�Ҫ��
		    continue;
	    }
	    else if(a[0]=='n')               //���jio�ú��ǣ�������Ҫ��һ���� 
	    {
		    printf("Not bad\n");
		    yp();
		    if(cont) zj();               //ׯ��ѡ���Ƿ�Ҫ��
		    continue;
	    }
	    else                            //��Ҳ�����������㶪��һ��ծ�� 
	    {
		    printf("Bye\n\n");
		    while(cont) zj();           //ׯ��ѡ���Ƿ�Ҫ�� 
		    break;
	    }
    }
    printf("��һ���Ѿ�����\n");
    if(sum1<=21) printf("���ĵ���Ϊ��%d\n\n",sum1);
    else printf("������˼����������QAQ\n\n");
	if(sum2<=21) printf("ׯ�ҵĵ���Ϊ��%d\n\n",sum2);
	else printf("��ϲ����ׯ�ұ�����hhh\n\n"); 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("��ϲ��սʤ�˺��ĵ�X־��ͬѧ");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("��ͺ���X־��ͬѧƽ�֣��ӰѾ���");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("а���X־��ͬѧ��ȻӮ�ˣ�����������");
	return 0;
}
