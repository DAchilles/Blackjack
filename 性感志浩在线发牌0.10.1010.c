//UI����  
//PvP�������� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
char a[110];         //������������ 
int deck[15][5];     //�����˿����� 
int player[15][5],player2[15][5],dealer[15][5];    //�������������ׯ������ 
int sum1=0,sum2=0,sum3=0,cont=1;    //��¼ׯ�����ƴ�С&&�Ƿ����Ҫ�� 
int s1=0,s2=0,s3=0;
void js(int p)        //����׶Σ�������� 
{
	int i,k=0;
	if(p==1)          //����player-1 
	{
		k=0;
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
	else if(p==2)
	{
		k=0;
		for(i=0;i<s2;i++)
	    {
		    if(player2[i][1]>0&&player2[i][1]<10) sum2=sum2+player2[i][1]+1;
		    else if(player2[i][1]!=0&&player2[i][1]<13) sum2=sum2+10;
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
	else
	{
		k=0;
		sum3=0;
		for(i=0;i<s3;i++)
	    {
	    	if(dealer[i][1]>0&&dealer[i][1]<10) sum3=sum3+dealer[i][1]+1;
	    	else if(dealer[i][1]!=0&&dealer[i][1]<13) sum3=sum3+10;
    		else k++;
    	}
    	if(k==1)
    	{
    		if(sum3+11<22) sum3=sum3+11;
    		else sum3=sum3+1;
     	}
    	else if(k==2)
    	{
    		if(sum3+12<22) sum3=sum3+12;
    		else sum3=sum3+2;
    	}
    	else sum3=sum3+k;
	}
	return;
} 



void yp(int p)             //Ҫ�� 
{
	int m,n;
	srand((unsigned)(time(NULL)));     //ʱ�亯����������� 
	if(p==1)
	{
	    for(;;)
    	{
	    	m=rand()%13;n=rand()%4;       //���ȷ��һ���� 
	        if(deck[m][n])                //�жϸ����Ƿ����� 
	    	{
    		    deck[m][n]=0;             //���Ʊ��Ϊ��ʹ�� 
    			player[s1][1]=m;        //��������������Ƶ��� 
    			player[s1][2]=n;          //��������������ƻ�ɫ 
    			s1++;
    			break;
    		}
    	    else continue;                //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ
    	}
	}
	else if(p==2)
	{
    	for(;;)
    	{
    		m=rand()%13;n=rand()%4;       //���ȷ��һ���� 
    	    if(deck[m][n])                //�жϸ����Ƿ����� 
    		{
    		    deck[m][n]=0;             //���Ʊ��Ϊ��ʹ�� 
    			player2[s2][1]=m;        //��������������Ƶ��� 
    			player2[s2][2]=n;          //��������������ƻ�ɫ 
    			s2++;
    			break;
    		}
    	    else continue;                //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ
    	}
	}
	else
	{
		if(sum3>=17) {cont=0;return;}      //ׯ�ҵ�������18ʱ����Ҫ�� 
    	for(;;)
    	{
    		m=rand()%13;n=rand()%4;          //���ȷ��һ���� 
    	    if(deck[m][n])                   //�жϸ����Ƿ����� 
    		{
    		    deck[m][n]=0;                //���Ʊ��Ϊ��ʹ�� 
    			dealer[s3][1]=m;           //����ׯ���������Ƶ��� 
    			dealer[s3][2]=n;             //����ׯ���������ƻ�ɫ
    			s3++;
    			js(3); 
    			break;
    		}
    	    else continue;                   //���ȷ��������ʹ�ã�����ȷ����һ��ֱ������Ϊֹ 
    	}	
	}
	return;
}




void sp(int p)        //���� 
{
	if(p==1)
	{
		printf("player-1������Ϊ:\n");
	    int i;
		if(s1!=0) 
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
	    else printf("��");
	}
	else if(p==2)
	{
		printf("player-2������Ϊ:\n");
	    int i;
	    if(s2!=0) 
	    for(i=0;i<s2;i++)
	    {
		    if(player2[i][1]!=0&&player2[i][1]<10)        //��Ϊ2~10 
		    {
			    if(player2[i][2]==0) printf("����%d ",player2[i][1]+1); 
			    else if(player2[i][2]==1) printf("����%d ",player2[i][1]+1); 
		    	else if(player2[i][2]==2) printf("÷��%d ",player2[i][1]+1);
		    	else printf("����%d ",player2[i][1]+1);
			
	    	}
	    	else if(player2[i][1]==0)        //��ΪA 
	    	{
	    		if(player2[i][2]==0) printf("����A "); 
	    		else if(player2[i][2]==1) printf("����A "); 
		    	else if(player2[i][2]==2) printf("÷��A ");
	    		else printf("����A ");	
	    	}
	    	else if(player2[i][1]==10)        //��ΪJ 
	    	{
	     		if(player2[i][2]==0) printf("����J "); 
	    		else if(player2[i][2]==1) printf("����J "); 
	    		else if(player2[i][2]==2) printf("÷��J ");
		    	else printf("����J ");		
		    }
	    	else if(player2[i][1]==11)        //��ΪQ 
	    	{
	    		if(player2[i][2]==0) printf("����Q "); 
	    		else if(player2[i][2]==1) printf("����Q "); 
	    		else if(player2[i][2]==2) printf("÷��Q ");
	    		else printf("����Q ");		
	        }
	    	else         //��ΪK 
	    	{
		    	if(player2[i][2]==0) printf("����K "); 
		    	else if(player2[i][2]==1) printf("����K "); 
		    	else if(player2[i][2]==2) printf("÷��K ");
		    	else printf("����K ");	
		    }
	    }
	    else printf("��"); 
	}
	else
	{
		printf("ׯ����������:\n");
	    int i;
	    for(i=0;i<s3;i++)
	    {
		    if(dealer[i][1]>0&&dealer[i][1]<10)        //��Ϊ2~10 
		    {
			    if(dealer[i][2]==0) printf("����%d ",dealer[i][1]+1); 
			    else if(dealer[i][2]==1) printf("����%d ",dealer[i][1]+1); 
		    	else if(dealer[i][2]==2) printf("÷��%d ",dealer[i][1]+1);
		    	else printf("����%d ",dealer[i][1]+1);
			
	    	}
	    	else if(dealer[i][1]==0)        //��ΪA 
	    	{
	    		if(dealer[i][2]==0) printf("����A "); 
	    		else if(dealer[i][2]==1) printf("����A "); 
		    	else if(dealer[i][2]==2) printf("÷��A ");
	    		else printf("����A ");	
	    	}
	    	else if(dealer[i][1]==10)        //��ΪJ 
	    	{
	     		if(dealer[i][2]==0) printf("����J "); 
	    		else if(dealer[i][2]==1) printf("����J "); 
	    		else if(dealer[i][2]==2) printf("÷��J ");
		    	else printf("����J ");		
		    }
	    	else if(dealer[i][1]==11)        //��ΪQ 
	    	{
	    		if(dealer[i][2]==0) printf("����Q "); 
	    		else if(dealer[i][2]==1) printf("����Q "); 
	    		else if(dealer[i][2]==2) printf("÷��Q ");
	    		else printf("����Q ");		
	        }
	    	else         //��ΪK 
	    	{
		    	if(dealer[i][2]==0) printf("����K "); 
		    	else if(dealer[i][2]==1) printf("����K "); 
		    	else if(dealer[i][2]==2) printf("÷��K ");
		    	else printf("����K ");	
		    }
	    }
	}  
	printf("\n\n");	
}



void PvE()
{
	system("cls");
	int i,j;
	sum1=0;sum3=0;cont=1;
    s1=0;s3=0;
	for(i=0;i<=14;i++)                             //��Һ�ׯ��������� 
    {
	   	memset(player[i],0,sizeof(player[i]));
	    memset(dealer[i],0,sizeof(dealer[i]));
	}
	for(i=0;i<=12;i++)                              //��ʼ���˿��� 
	  for(j=0;j<=3;j++)
	      deck[i][j]=1;
	printf("��Ϸ��ʼ��\n\n\n");
    printf("��ʾ��\n");
    printf("y:�����������Ʋ�����������Ҫ��һ���ƣ�������y\n"); 
    printf("n:������������һ�㣬��������Ҫ��һ���Ʋ�һ����������n\n");
    printf("q:����㲻�����Ҫ�ƣ�������q\n");
    printf("��������Ӧ��ĸ����\n\n");
	for(;;)
	{  
	    memset(a,0,sizeof(a));             //�����������  
    	scanf("%s",a);                     //��������
	    if(a[0]=='y')                //���jio��OK��������Ҫ��һ����   
	    {
		    printf("OK��");
    	    yp(1);sp(1);
	        if(cont) yp(3);                //ׯ��ѡ���Ƿ�Ҫ��
		    continue;
	    }
    	else if(a[0]=='n')               //���jio�ú��ǣ�������Ҫ��һ���� 
    	{
    	    printf("Not bad��");
    	    yp(1);sp(1);
    	    if(cont) yp(3);               //ׯ��ѡ���Ƿ�Ҫ��
    	    continue;
    	}
    	else                         //��Ҳ�����������㶪��һ��ծ�� 
    	{
    	    printf("Bye");
    	    while(cont) yp(3);           //ׯ��ѡ���Ƿ�Ҫ�� 
    	    break;
    	}
    }
    system("cls");
    printf("�����Ѿ�����\n\n\n");
    sp(1);        //��ʾ������� 
    js(1);        //����������� 
    sp(3);        //��ʾׯ������ 
    printf("���ֽ�����£�\n"); 
    if(sum1<=21) printf("���ĵ���Ϊ��%d\n",sum1);        //������ҵ��� 
    else printf("��ұ���\n");              //ͬ�� 
    if(sum3<=21) printf("ׯ�ҵĵ���Ϊ��%d\n\n",sum3);      //����ׯ�ҵ��� 
	else printf("ׯ�ұ���\n\n");              //ͬ�� 
    if((sum1<=21&&sum3<=21&&sum1>sum3)||(sum1<=21&&sum3>21)) printf("���ʤ\n\n");
    else if((sum1<=21&&sum3<=21&&sum1==sum3)||(sum1>21&&sum3>21)) printf("ƽ��\n\n");
    else if((sum1<=21&&sum3<=21&&sum1<sum3)||(sum1>21&&sum3<=21)) printf("ׯ��ʤ\n\n");
    system("pause");
    system("cls");
}




void PvP()
{
	system("cls");
	int i,j,k1=1,k2=1;
	sum1=0;sum2=0;
    s1=0,s2=0;
	    for(i=0;i<=14;i++)                             //��Һ�ׯ��������� 
    {
	  	memset(player[i],0,sizeof(player[i]));
	    memset(player2[i],0,sizeof(player2[i]));
	}
	for(i=0;i<=12;i++)                              //��ʼ���˿��� 
	    for(j=0;j<=3;j++)
	      deck[i][j]=1;
	printf("��Ϸ��ʼ��\n\n\n");
	for(i=1;;i++)
	{
	   	if(((i%2==1)&&(k1==1))||((k2==0)&&(k1==1)))
	   	{
	   		printf("��ʾ��\n");
            printf("y:�����������Ʋ�����������Ҫ��һ���ƣ�������y\n"); 
            printf("n:������������һ�㣬��������Ҫ��һ���Ʋ�һ����������n\n");
            printf("q:����㲻�����Ҫ�ƣ�������q\n\n");
	    	printf("========������player-1�Ļغ�========\n\n");
	    	sp(1);
            printf("��������Ӧ��ĸ����:");
	     	memset(a,0,sizeof(a));             //�����������  
    	   	scanf("%s",a);                     //��������
    	    if(a[0]=='y')                //���jio��OK��������Ҫ��һ����   
	        {
	    	    printf("\nOK��");
        	    yp(1);sp(1);
        	    system("pause");
        	    system("cls");
	    	    continue;
	        }
        	else if(a[0]=='n')               //���jio�ú��ǣ�������Ҫ��һ���� 
        	{
        	    printf("\nNot bad��");
        	    yp(1);sp(1);
        	    system("pause");
        	    system("cls");
        	    continue;
        	}
        	else                         //��Ҳ�����������㶪��һ��ծ�� 
            {
        	    printf("\nBye\n");
        	    k1=0;
        	    system("pause");
        	    system("cls");
        	    continue;
    	    }  
		}
		
		else if(((i%2==0)&&(k2==1))||((k1==0)&&(k2==1)))
	    {
	    	printf("��ʾ��\n");
            printf("y:�����������Ʋ�����������Ҫ��һ���ƣ�������y\n"); 
            printf("n:������������һ�㣬��������Ҫ��һ���Ʋ�һ����������n\n");
            printf("q:����㲻�����Ҫ�ƣ�������q\n\n");
	    	printf("========������player-2�Ļغ�========\n\n");
	    	sp(2);
            printf("��������Ӧ��ĸ����:");
	     	memset(a,0,sizeof(a));             //�����������  
    	   	scanf("%s",a);                     //��������
    	    if(a[0]=='y')                //���jio��OK��������Ҫ��һ����   
	        {
	    	    printf("\nOK��");
                yp(2);sp(2);
                system("pause");
                system("cls");
	            continue;
	        }
        	else if(a[0]=='n')               //���jio�ú��ǣ�������Ҫ��һ���� 
        	{
        	    printf("\nNot bad��");
        	    yp(2);sp(2);
        	    system("pause");
        	    system("cls");
        	    continue;
        	}
        	else                         //��Ҳ�����������㶪��һ��ծ�� 
        	{
        	    printf("\nBye\n");
        	    k2=0;
        	    system("pause");
        	    system("cls");
        	    continue;
    	    }  
        }
        else break;
    }
    system("cls");
    sp(1);        //��ʾ������� 
    js(1);        //����������� 
    sp(2);        //��ʾׯ������ 
    js(2); 
    printf("���ֽ�����£�\n"); 
    if(sum1<=21) printf("player-1����Ϊ��%d\n",sum1);        //������ҵ��� 
    else printf("player-1����\n");              //ͬ�� 
    if(sum2<=21) printf("player-12����Ϊ��%d\n\n",sum2);      //����ׯ�ҵ��� 
	else printf("player-2����\n\n");              //ͬ�� 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("player-1ʤ\n\n");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("ƽ��\n\n");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("player-2ʤ\n\n");
    system("pause");
    system("cls");	
}




	
int main ()
{
	
	for(;;)
	{
		int x;
		printf("��ӭ����־��ͬѧ�İ������϶ĳ�\n\n");
	    printf("��ѡ������ģʽ\n"); 
	    printf("1�����vs���\n");
	    printf("2�����vs����\n");
	    printf("3���˳�����\n");
	    printf("����������1~3ѡ����Ӧģʽ�����س���ȷ��\n\n"); 
	    scanf("%d",&x);
	    if (x==1) PvP();
	    else if(x==2) PvE();
	    else if(x==3) break;
    }
	return 0;
}
