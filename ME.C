#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char *medicine,buff[100],a,*next,c[100];
	char *x, *med,*rs,*exp,*y,*z, *str2,*gst;
	int *p, i=1,j=0,unit,rup,cost,gst1,total=0,k=1;
	FILE *fmedicine;
	FILE *tr;
	clrscr();
	tr=tmpfile();
	fputs("\nS.no\tName\tEx.D\tPrice\tGST(%)\tQuantity\tCost\n",tr);
	do
	{
	printf("\nEnter the medicine name: ");
	scanf("%s",medicine);
	printf("Enter the unit: ");
	scanf("%d",&unit);
	fmedicine=fopen("c:\\turboc3\\programs\\project\\medicine.txt","r");
	if(fmedicine==NULL)
	{
		printf("File not found");
		exit(0);
	}
	do
	{       x = fgets(x,100,fmedicine);
		strcpy(c,x);
		med= strtok(x,"\t");
	       if(strcmp(med,medicine)==0)
	       {
			rs=strtok(NULL,"\t");
			exp=strtok(NULL,"\t");
			gst=strtok(NULL,"\t");
			gst1=atoi(gst);
			rup=atoi(exp);
		      //	printf("%d",*gst);
			cost=(unit*rup)+(int)((unit*rup*(gst1))/100);
			total += cost;
			if(tr==NULL)
			{
				printf("Unable to create temp file");
			}
			if(strcmp(med,medicine)==0)
			{        //printf("Check");
				fprintf(tr, "\n%d.\t%s\t%d\t\t%d\n",i,strtok(c,"\n"),unit,cost);
				i++;
			}
			break;

	       }

	}while(x!=EOF && x!=NULL);
	printf("Conti...");
	printf("\nY/N:");
	scanf(" %s",next);
	}while(strcmp(next,"Y")==0);
	rewind(tr);
	printf("\n\n");
	printf("\n---------------------BILL-----------------------------------\n");

	printf("Date : "__DATE__,"r");
	printf("\nTime : "__TIME__,"r");
	printf("\n------------------------------------------------------------");
	while(!feof(tr))
	{               //printf("Check");
		puts(fgets(str2,100,tr));
	}
	printf("\n------------------------------------------------------------\n");

	printf("\t\t\t\tTotal Amount\t=\t%d",total);
	fcloseall();
	getch();
}