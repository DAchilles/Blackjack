//UIÃÀ»¯
//PvEÍæ¼Ò±¬ÅÆ×Ô¶¯ÍË³ö 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
char a[110];         //´¢´æÊäÈëÊı¾İ 
int deck[15][5];     //¹¹½¨ÆË¿ËÅÆ×é 
int player[15][5],player2[15][5],dealer[15][5];    //¹¹½¨Íæ¼ÒÊÖÅÆÓë×¯¼ÒÊÖÅÆ 
int sum1=0,sum2=0,sum3=0,cont=1;    //¼ÇÂ¼×¯¼ÒÊÖÅÆ´óĞ¡&&ÊÇ·ñ¼ÌĞøÒªÅÆ 
int s1=0,s2=0,s3=0;
void js(int p)        //½áËã½×¶Î£¬¼ÆËãµãÊı 
{
	int i,k=0;
	if(p==1)          //½áËãplayer-1 
	{
		k=0;
		for(i=0;i<s1;i++)
	    {
		    if(player[i][1]>0&&player[i][1]<10) sum1=sum1+player[i][1]+1;       //2~10æŒ‰ç‚¹æ•°åŠ  
		    else if(player[i][1]!=0&&player[i][1]<13) sum1=sum1+10;        //J,Q,Kç‚¹æ•°è®°ä¸º10 
		    else k++;        //è®°å½•Aå¼ æ•°ï¼Œæœ€åç»“ç®—ç‚¹æ•°
	    }
	    if(k==1)
	    {
	    	if(sum1+11<22) sum1=sum1+11;        //ä¸€å¼ Aæœ€å¤§ç‚¹æ•°11
		    else sum1=sum1+1;        //æœ€å°1 
	    }
	    else if(k==2)
    	{
		    if(sum1+12<22) sum1=sum1+12;        //æœ€å¤§å¯èƒ½ç‚¹æ•°12 
		    else sum1=sum1+2;        //æœ€å°2 
        }
    	else sum1=sum1+k;        //å¤§äºä¸¤å¼ åˆ™å…¨æŒ‰1ç»“ç®— 
    }
	else if(p==2)        //ç»“ç®—player-2 
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
	else        //ç»“ç®—åº„å®¶ 
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



void yp(int p)             //ÒªÅÆ 
{
	int m,n;
	srand((unsigned)(time(NULL)));     //Ê±¼äº¯ÊıÉú³ÉËæ»úÊı 
	if(p==1)
	{
	    for(;;)
    	{
	    	m=rand()%13;n=rand()%4;       //Ëæ»úÈ·¶¨Ò»ÕÅÅÆ 
	        if(deck[m][n])                //ÅĞ¶Ï¸ÃÅÆÊÇ·ñÒÑÓÃ 
	    	{
    		    deck[m][n]=0;             //½«ÅÆ±ê¼ÇÎªÒÑÊ¹ÓÃ 
    			player[s1][1]=m;        //±£´æÍæ¼ÒĞÂÔöÊÖÅÆµãÊı 
    			player[s1][2]=n;          //±£´æÍæ¼ÒĞÂÔöÊÖÅÆ»¨É« 
    			s1++;
    			break;
    		}
    	    else continue;                //Èç¹ûÈ·¶¨µÄÅÆÒÑÊ¹ÓÃ£¬ÖØĞÂÈ·¶¨ÏÂÒ»ÕÅÖ±µ½¿ÉÓÃÎªÖ¹
    	}
	}
	else if(p==2)
	{
    	for(;;)
    	{
    		m=rand()%13;n=rand()%4;       //Ëæ»úÈ·¶¨Ò»ÕÅÅÆ 
    	    if(deck[m][n])                //ÅĞ¶Ï¸ÃÅÆÊÇ·ñÒÑÓÃ 
    		{
    		    deck[m][n]=0;             //½«ÅÆ±ê¼ÇÎªÒÑÊ¹ÓÃ 
    			player2[s2][1]=m;        //±£´æÍæ¼ÒĞÂÔöÊÖÅÆµãÊı 
    			player2[s2][2]=n;          //±£´æÍæ¼ÒĞÂÔöÊÖÅÆ»¨É« 
    			s2++;
    			break;
    		}
    	    else continue;                //Èç¹ûÈ·¶¨µÄÅÆÒÑÊ¹ÓÃ£¬ÖØĞÂÈ·¶¨ÏÂÒ»ÕÅÖ±µ½¿ÉÓÃÎªÖ¹
    	}
	}
	else
	{
		if(sum3>=17) {cont=0;return;}      //×¯¼ÒµãÊı´óÓÚ18Ê±²»ÔÙÒªÅÆ 
    	for(;;)
    	{
    		m=rand()%13;n=rand()%4;          //Ëæ»úÈ·¶¨Ò»ÕÅÅÆ 
    	    if(deck[m][n])                   //ÅĞ¶Ï¸ÃÅÆÊÇ·ñÒÑÓÃ 
    		{
    		    deck[m][n]=0;                //½«ÅÆ±ê¼ÇÎªÒÑÊ¹ÓÃ 
    			dealer[s3][1]=m;           //±£´æ×¯¼ÒĞÂÔöÊÖÅÆµãÊı 
    			dealer[s3][2]=n;             //±£´æ×¯¼ÒĞÂÔöÊÖÅÆ»¨É«
    			s3++;
    			js(3); 
    			break;
    		}
    	    else continue;                   //Èç¹ûÈ·¶¨µÄÅÆÒÑÊ¹ÓÃ£¬ÖØĞÂÈ·¶¨ÏÂÒ»ÕÅÖ±µ½¿ÉÓÃÎªÖ¹ 
    	}	
	}
	return;
}




void sp(int p)        //ÊÖÅÆ 
{
	if(p==1)
	{
		printf("player-1µÄÊÖÅÆÎª:\n");
	    int i;
		if(s1!=0) 
	    for(i=0;i<s1;i++)
	    {
		    if(player[i][1]!=0&&player[i][1]<10)        //ÅÆÎª2~10 
		    {
			    if(player[i][2]==0) printf("ºÚÌÒ%d ",player[i][1]+1); 
			    else if(player[i][2]==1) printf("ºìÌÒ%d ",player[i][1]+1); 
		    	else if(player[i][2]==2) printf("Ã·»¨%d ",player[i][1]+1);
		    	else printf("·½¿é%d ",player[i][1]+1);
			
	    	}
	    	else if(player[i][1]==0)        //ÅÆÎªA 
	    	{
	    		if(player[i][2]==0) printf("ºÚÌÒA "); 
	    		else if(player[i][2]==1) printf("ºìÌÒA "); 
		    	else if(player[i][2]==2) printf("Ã·»¨A ");
	    		else printf("·½¿éA ");	
	    	}
	    	else if(player[i][1]==10)        //ÅÆÎªJ 
	    	{
	     		if(player[i][2]==0) printf("ºÚÌÒJ "); 
	    		else if(player[i][2]==1) printf("ºìÌÒJ "); 
	    		else if(player[i][2]==2) printf("Ã·»¨J ");
		    	else printf("·½¿éJ ");		
		    }
	    	else if(player[i][1]==11)        //ÅÆÎªQ 
	    	{
	    		if(player[i][2]==0) printf("ºÚÌÒQ "); 
	    		else if(player[i][2]==1) printf("ºìÌÒQ "); 
	    		else if(player[i][2]==2) printf("Ã·»¨Q ");
	    		else printf("·½¿éQ ");		
	        }
	    	else         //ÅÆÎªK 
	    	{
		    	if(player[i][2]==0) printf("ºÚÌÒK "); 
		    	else if(player[i][2]==1) printf("ºìÌÒK "); 
		    	else if(player[i][2]==2) printf("Ã·»¨K ");
		    	else printf("·½¿éK ");	
		    }
	    }
	    else printf("¿Õ");
	}
	else if(p==2)
	{
		printf("player-2µÄÊÖÅÆÎª:\n");
	    int i;
	    if(s2!=0) 
	    for(i=0;i<s2;i++)
	    {
		    if(player2[i][1]!=0&&player2[i][1]<10)        //ÅÆÎª2~10 
		    {
			    if(player2[i][2]==0) printf("ºÚÌÒ%d ",player2[i][1]+1); 
			    else if(player2[i][2]==1) printf("ºìÌÒ%d ",player2[i][1]+1); 
		    	else if(player2[i][2]==2) printf("Ã·»¨%d ",player2[i][1]+1);
		    	else printf("·½¿é%d ",player2[i][1]+1);
			
	    	}
	    	else if(player2[i][1]==0)        //ÅÆÎªA 
	    	{
	    		if(player2[i][2]==0) printf("ºÚÌÒA "); 
	    		else if(player2[i][2]==1) printf("ºìÌÒA "); 
		    	else if(player2[i][2]==2) printf("Ã·»¨A ");
	    		else printf("·½¿éA ");	
	    	}
	    	else if(player2[i][1]==10)        //ÅÆÎªJ 
	    	{
	     		if(player2[i][2]==0) printf("ºÚÌÒJ "); 
	    		else if(player2[i][2]==1) printf("ºìÌÒJ "); 
	    		else if(player2[i][2]==2) printf("Ã·»¨J ");
		    	else printf("·½¿éJ ");		
		    }
	    	else if(player2[i][1]==11)        //ÅÆÎªQ 
	    	{
	    		if(player2[i][2]==0) printf("ºÚÌÒQ "); 
	    		else if(player2[i][2]==1) printf("ºìÌÒQ "); 
	    		else if(player2[i][2]==2) printf("Ã·»¨Q ");
	    		else printf("·½¿éQ ");		
	        }
	    	else         //ÅÆÎªK 
	    	{
		    	if(player2[i][2]==0) printf("ºÚÌÒK "); 
		    	else if(player2[i][2]==1) printf("ºìÌÒK "); 
		    	else if(player2[i][2]==2) printf("Ã·»¨K ");
		    	else printf("·½¿éK ");	
		    }
	    }
	    else printf("¿Õ"); 
	}
	else
	{
		printf("×¯¼ÒÊÖÅÆÈçÏÂ:\n");
	    int i;
	    for(i=0;i<s3;i++)
	    {
		    if(dealer[i][1]>0&&dealer[i][1]<10)        //ÅÆÎª2~10 
		    {
			    if(dealer[i][2]==0) printf("ºÚÌÒ%d ",dealer[i][1]+1); 
			    else if(dealer[i][2]==1) printf("ºìÌÒ%d ",dealer[i][1]+1); 
		    	else if(dealer[i][2]==2) printf("Ã·»¨%d ",dealer[i][1]+1);
		    	else printf("·½¿é%d ",dealer[i][1]+1);
			
	    	}
	    	else if(dealer[i][1]==0)        //ÅÆÎªA 
	    	{
	    		if(dealer[i][2]==0) printf("ºÚÌÒA "); 
	    		else if(dealer[i][2]==1) printf("ºìÌÒA "); 
		    	else if(dealer[i][2]==2) printf("Ã·»¨A ");
	    		else printf("·½¿éA ");	
	    	}
	    	else if(dealer[i][1]==10)        //ÅÆÎªJ 
	    	{
	     		if(dealer[i][2]==0) printf("ºÚÌÒJ "); 
	    		else if(dealer[i][2]==1) printf("ºìÌÒJ "); 
	    		else if(dealer[i][2]==2) printf("Ã·»¨J ");
		    	else printf("·½¿éJ ");		
		    }
	    	else if(dealer[i][1]==11)        //ÅÆÎªQ 
	    	{
	    		if(dealer[i][2]==0) printf("ºÚÌÒQ "); 
	    		else if(dealer[i][2]==1) printf("ºìÌÒQ "); 
	    		else if(dealer[i][2]==2) printf("Ã·»¨Q ");
	    		else printf("·½¿éQ ");		
	        }
	    	else         //ÅÆÎªK 
	    	{
		    	if(dealer[i][2]==0) printf("ºÚÌÒK "); 
		    	else if(dealer[i][2]==1) printf("ºìÌÒK "); 
		    	else if(dealer[i][2]==2) printf("Ã·»¨K ");
		    	else printf("·½¿éK ");	
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
	for(i=0;i<=14;i++)                             //Íæ¼ÒºÍ×¯¼ÒÊÖÅÆÇå¿Õ 
    {
	   	memset(player[i],0,sizeof(player[i]));
	    memset(dealer[i],0,sizeof(dealer[i]));
	}
	for(i=0;i<=15;i++)                              //³õÊ¼»¯ÆË¿ËÅÆ 
	  for(j=0;j<=5;j++)
	      deck[i][j]=1;
	printf("ÓÎÏ·¿ªÊ¼£¡\n\n\n");
    printf("ÌáÊ¾£º\n");
    printf("y:Èç¹ûÄã¾õµÃÊÖÅÆ²»´í£¬²¢»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ£¬ÇëÊäÈëy\n"); 
    printf("n:Èç¹ûÄã¾õµÃÊÖÅÆÒ»°ã£¬µ«»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ²«Ò»²«£¬ÇëÊäÈën\n");
    printf("q:Èç¹ûÄã²»Ïë¼ÌĞøÒªÅÆ£¬ÇëÊäÈëq\n");
    printf("ÇëÊäÈëÏàÓ¦×ÖÄ¸¼ÌĞø\n\n");
	for(;;)
	{ 
	    memset(a,0,sizeof(a));             //Çå¿ÕÊäÈëÊı¾İ  
    	scanf("%s",a);                     //ÊäÈëÊı¾İ
	    if(a[0]=='y')                //Íæ¼ÒjioµÃOK£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ   
	    {
		    printf("OK£¬");
    	    yp(1);sp(1);
	        if(cont) yp(3);                //×¯¼ÒÑ¡ÔñÊÇ·ñÒªÅÆ
	        sum1=0;
	        js(1);
	        if(sum1>21) {printf("²»ºÃÒâË¼£¬Äú±¬ÅÆÁË\n"); system("pause");break;}
		    continue;
	    }
    	else if(a[0]=='n')               //Íæ¼ÒjioµÃº£ĞÇ£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ 
    	{
    	    printf("Not bad£¬");
    	    yp(1);sp(1);
    	    if(cont) yp(3);               //×¯¼ÒÑ¡ÔñÊÇ·ñÒªÅÆ
    	    sum1=0;
	        js(1);
	        if(sum1>21) {printf("²»ºÃÒâË¼£¬Äú±¬ÅÆÁË\n"); system("pause");break;}
    	    continue;
    	}
    	else                         //Íæ¼Ò²»Ïë¼ÌĞø²¢ÏòÄã¶ªÁËÒ»¾äÕ®¼û 
    	{
    	    printf("Bye");
    	    while(cont) yp(3);           //×¯¼ÒÑ¡ÔñÊÇ·ñÒªÅÆ 
    	    break;
    	}
    }
    sum1=0; 
    system("cls");
    printf("±¾¾ÖÒÑ¾­½áÊø\n\n\n");
    sp(1);        //ÏÔÊ¾Íæ¼ÒÊÖÅÆ 
    js(1);        //½áËãÍæ¼ÒÊÖÅÆ 
    sp(3);        //ÏÔÊ¾×¯¼ÒÊÖÅÆ 
    printf("±¾¾Ö½á¹ûÈçÏÂ£º\n"); 
    if(sum1<=21) printf("ÄúµÄµãÊıÎª£º%d\n",sum1);        //½áËãÍæ¼ÒµãÊı 
    else printf("Íæ¼Ò±¬ÅÆ\n");              //Í¬ÉÏ 
    if(sum3<=21) printf("×¯¼ÒµÄµãÊıÎª£º%d\n\n",sum3);      //½áËã×¯¼ÒµãÊı 
	else printf("×¯¼Ò±¬ÅÆ\n\n");              //Í¬ÉÏ 
    if((sum1<=21&&sum3<=21&&sum1>sum3)||(sum1<=21&&sum3>21)) printf("Íæ¼ÒÊ¤\n\n");
    else if((sum1<=21&&sum3<=21&&sum1==sum3)||(sum1>21&&sum3>21)) printf("Æ½¾Ö\n\n");
    else if((sum1<=21&&sum3<=21&&sum1<sum3)||(sum1>21&&sum3<=21)) printf("×¯¼ÒÊ¤\n\n");
    system("pause");
    system("cls");
}




void PvP()
{
	system("cls");
	int i,j,k1=1,k2=1;
	sum1=0;sum2=0;
    s1=0,s2=0;
	    for(i=0;i<=14;i++)                             //Íæ¼ÒºÍ×¯¼ÒÊÖÅÆÇå¿Õ 
    {
	  	memset(player[i],0,sizeof(player[i]));
	    memset(player2[i],0,sizeof(player2[i]));
	}
	for(i=0;i<=15;i++)                              //³õÊ¼»¯ÆË¿ËÅÆ 
	    for(j=0;j<=5;j++)
	      deck[i][j]=1;
	printf("ÓÎÏ·¿ªÊ¼£¡\n\n\n");
	for(i=1;;i++)
	{
	   	if(((i%2==1)&&(k1==1))||((k2==0)&&(k1==1)))
	   	{
	   		printf("ÌáÊ¾£º\n");
            printf("y:Èç¹ûÄã¾õµÃÊÖÅÆ²»´í£¬²¢»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ£¬ÇëÊäÈëy\n"); 
            printf("n:Èç¹ûÄã¾õµÃÊÖÅÆÒ»°ã£¬µ«»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ²«Ò»²«£¬ÇëÊäÈën\n");
            printf("q:Èç¹ûÄã²»Ïë¼ÌĞøÒªÅÆ£¬ÇëÊäÈëq\n\n");
	    	printf("========ÏÖÔÚÊÇplayer-1µÄ»ØºÏ========\n\n");
	    	sp(1);
            printf("ÇëÊäÈëÏàÓ¦×ÖÄ¸¼ÌĞø:");
	     	memset(a,0,sizeof(a));             //Çå¿ÕÊäÈëÊı¾İ  
    	   	scanf("%s",a);                     //ÊäÈëÊı¾İ
    	    if(a[0]=='y')                //Íæ¼ÒjioµÃOK£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ   
	        {
	    	    printf("\nOK£¬");
        	    yp(1);sp(1);
        	    system("pause");
        	    system("cls");
	    	    continue;
	        }
        	else if(a[0]=='n')               //Íæ¼ÒjioµÃº£ĞÇ£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ 
        	{
        	    printf("\nNot bad£¬");
        	    yp(1);sp(1);
        	    system("pause");
        	    system("cls");
        	    continue;
        	}
        	else                         //Íæ¼Ò²»Ïë¼ÌĞø²¢ÏòÄã¶ªÁËÒ»¾äÕ®¼û 
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
	    	printf("ÌáÊ¾£º\n");
            printf("y:Èç¹ûÄã¾õµÃÊÖÅÆ²»´í£¬²¢»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ£¬ÇëÊäÈëy\n"); 
            printf("n:Èç¹ûÄã¾õµÃÊÖÅÆÒ»°ã£¬µ«»¹ÏëÔÙÒªÏÂÒ»ÕÅÅÆ²«Ò»²«£¬ÇëÊäÈën\n");
            printf("q:Èç¹ûÄã²»Ïë¼ÌĞøÒªÅÆ£¬ÇëÊäÈëq\n\n");
	    	printf("========ÏÖÔÚÊÇplayer-2µÄ»ØºÏ========\n\n");
	    	sp(2);
            printf("ÇëÊäÈëÏàÓ¦×ÖÄ¸¼ÌĞø:");
	     	memset(a,0,sizeof(a));             //Çå¿ÕÊäÈëÊı¾İ  
    	   	scanf("%s",a);                     //ÊäÈëÊı¾İ
    	    if(a[0]=='y')                //Íæ¼ÒjioµÃOK£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ   
	        {
	    	    printf("\nOK£¬");
                yp(2);sp(2);
                system("pause");
                system("cls");
	            continue;
	        }
        	else if(a[0]=='n')               //Íæ¼ÒjioµÃº£ĞÇ£¬²¢ÇÒÔÙÒªÁËÒ»ÕÅÅÆ 
        	{
        	    printf("\nNot bad£¬");
        	    yp(2);sp(2);
        	    system("pause");
        	    system("cls");
        	    continue;
        	}
        	else                         //Íæ¼Ò²»Ïë¼ÌĞø²¢ÏòÄã¶ªÁËÒ»¾äÕ®¼û 
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
    sp(1);        //ÏÔÊ¾Íæ¼ÒÊÖÅÆ 
    js(1);        //½áËãÍæ¼ÒÊÖÅÆ 
    sp(2);        //ÏÔÊ¾×¯¼ÒÊÖÅÆ 
    js(2); 
    printf("±¾¾Ö½á¹ûÈçÏÂ£º\n"); 
    if(sum1<=21) printf("player-1µãÊıÎª£º%d\n",sum1);        //½áËãÍæ¼ÒµãÊı 
    else printf("player-1±¬ÅÆ\n");              //Í¬ÉÏ 
    if(sum2<=21) printf("player-12µãÊıÎª£º%d\n\n",sum2);      //½áËã×¯¼ÒµãÊı 
	else printf("player-2±¬ÅÆ\n\n");              //Í¬ÉÏ 
    if((sum1<=21&&sum2<=21&&sum1>sum2)||(sum1<=21&&sum2>21)) printf("player-1Ê¤\n\n");
    else if((sum1<=21&&sum2<=21&&sum1==sum2)||(sum1>21&&sum2>21)) printf("Æ½¾Ö\n\n");
    else if((sum1<=21&&sum2<=21&&sum1<sum2)||(sum1>21&&sum2<=21)) printf("player-2Ê¤\n\n");
    system("pause");
    system("cls");	
}




	
int main ()
{
	
	for(;;)
	{
		int x;
		printf("»¶Ó­½øÈëÖ¾ºÆÍ¬Ñ§µÄ°ÄÃÅÏßÉÏ¶Ä³¡\n\n");
	    printf("ÇëÑ¡ÔñÒÔÏÂÄ£Ê½\n"); 
	    printf("1£ºÍæ¼ÒvsÍæ¼Ò\n");
	    printf("2£ºÍæ¼ÒvsµçÄÔ\n");
	    printf("3£ºÍË³ö³ÌĞò\n");
	    printf("ÇëÊäÈëÊı×Ö1~3Ñ¡ÔñÏàÓ¦Ä£Ê½£¬°´»Ø³µ¼üÈ·¶¨\n\n"); 
	    scanf("%d",&x);
	    if (x==1) PvP();
	    else if(x==2) PvE();
	    else if(x==3) break;
    }
	return 0;
}
