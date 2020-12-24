#include <stdio.h>
#include <conio.h>
void login();    //�α��� ����� ������ �ִ� �Լ� 
void score(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank);  // ���� ä���Ͽ� ����ȭ �����ִ� �Լ�
void ranking(char(*x)[10],char(*y)[15],char(*z)[10],int *s);  //������������ �����ϴ� �Լ�   
void tie(int *s,int *rank);  //������ ó���Լ�  
void print(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank); //����Լ� + �а��� ��� �Լ� 

void main(){
	char x[20][10],y[20][15],z[20][10];
	int s[20],rank[20];
	login();    //�α��� �Լ� ȣ ��  
	score(x,y,z,s,rank); //��ä���Լ� ȣ ��  
	ranking(x,y,z,s); //������������ �����ϴ� �Լ� ȣ�� 
	tie(s,rank);  //������ ó���ϴ� �Լ� ȣ��  
	print(x,y,z,s,rank); //����Լ�+�а��� ��� ���ϴ� �Լ� ȣ��  
}
///////////////////////////////////////////////////////////////////////////////////
void login(){
	FILE *fp;
	char ID[10],PS[10],UID[10],UPS[10];
	int i,F=0; 
	while(1){
		fp=fopen("user.txt","r");
		printf("============ �α��� ==========\n");
		printf("       ID   :    ");
		gets(UID);
		printf("  Password  :    ");
		for(i=0;i<10;i++){
			UPS[i]=getch();         //getch�� ����Ͽ� ��й�ȣ�� �Է��Ҷ����� *���  
			if(UPS[i]==13){
				UPS[i]='\0';
				printf("\n");
				break;
			} 
			
			printf("*");
		}
		printf("=============================\n");
		while(!feof(fp)==1){
			fscanf(fp,"%s\t%s",ID,PS);
			if(strcmp(UID,ID)==0 && strcmp(UPS,PS)==0){  //�Է��� ������ �ҽ� ������ ��ġ�ϸ� break 
				break;
			}

		}
	if(strcmp(UID,ID)==0 && strcmp(UPS,PS)==0){
		printf("�α��� �Ǿ����ϴ�.\n");
		printf("=============================\n");
		printf("result.txt�� ��µǾ����ϴ�.\n");
		break;
	}
	else{
		F++;
		printf("*****************************\n");
		printf("�߸���ID��Password�Դϴ�\n");
		printf("*****************************\n");
		if(F==3){                                        //F�� ī�����Ͽ� F�� 3�̵Ǹ� ���α׷����� 
			printf("�α��ο� ���� �����Ͽ� ���α׷��� �����մϴ�");
			exit(0);
		}
	}
	
}
}

///////////////////////////////////////////////////////////////////////// 
void score(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank){
	FILE *ap,*sp;
	sp=fopen("source.txt","r");
	ap=fopen("answer.txt","r");
	int i,u,a[10],score,answer[10]; 
	while(!feof(ap)==1){
		for(i=0;i<10;i++){
			fscanf(ap,"%d",&answer[i]);     //�� �о����  
			}
		}
	while(!feof(sp)==1){
		for(i=0;i<17;i++){
			rank[i]=i+1;
			score=0;
			fscanf(sp,"%s %s %s",x[i],y[i],z[i]);
			for(u=0;u<10;u++){
				fscanf(sp,"%d",&a[u]);
				if(answer[u]==a[u]){                //�����̸� ���ھ� +10 
					score=score+10;
				}
		
			}
		s[i]=score;
		}	
	}
	
}
////////////////////////////////////////////////////////////////////////////
void ranking(char(*x)[10],char(*y)[15],char(*z)[10],int *s){
	int u,i;
	char temp[10];
	int temp1;
	for(u=0;u<20;u++){
		for(i=0;i<17;i++){
			if(s[i]<s[i+1]){                             //strcpy �� ����Ͽ� ���ھ���� ������� ����  
				strcpy(temp,x[i]);
				strcpy(x[i],x[i+1]);
				strcpy(x[i+1],temp);
				strcpy(temp,y[i]);
				strcpy(y[i],y[i+1]);
				strcpy(y[i+1],temp);
				strcpy(temp,z[i]);
				strcpy(z[i],z[i+1]);
				strcpy(z[i+1],temp);
				temp1=s[i];
				s[i]=s[i+1];
				s[i+1]=temp1;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
void tie(int *s,int *rank){
	int u,i;
	for(u=0;u<20;u++){
		for(i=0;i<17;i++){
			if(s[i]==s[i+1]){            //���ھ ������ ������ ��� ó�� 
				rank[i]=rank[i+1];
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
void print(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank){
	int a1=0,a2=0,a3=0,a4=0,i;
	FILE *rp;
	float cs=0,as=0,bs=0,es=0;
	rp=fopen("result.txt","w");
	fprintf(rp,"=====================================================\n");
	printf("==============================================================\n");
	fprintf(rp," �̸�\t\t �а� \t\t     �й�     \t ���� \t ���   \n");
	printf(" �̸�\t\t �а� \t\t     �й�     \t ���� \t ���   \n");
	fprintf(rp,"=====================================================\n");
	printf("==============================================================\n");
	for(i=0;i<17;i++){
		fprintf(rp,"%-12s \t %-12s \t %s \t %d \t %d\n",x[i],y[i],z[i],s[i],rank[i]);
		printf("%-12s \t %-12s \t %s \t %d \t %d\n",x[i],y[i],z[i],s[i],rank[i]);
		if(strcmp(y[i],"Computer")==0){              //strcmp�� �а��� �ο����� ��� 
			a1++;
			cs=cs+s[i];
		}
		else if(strcmp(y[i],"Art")==0){
			a2++;
			as=as+s[i];
		}
		else if(strcmp(y[i],"Electricity")==0){
			a3++;
			es=es+s[i];
		}
		else{
			a4++;
			bs=bs+s[i];
		}
		
	}
	fprintf(rp,"=====================================================\n");
	fprintf(rp," \t\t�а�\t\t �ο� \t\t ��� \n");
	fprintf(rp,"=====================================================\n");
	fprintf(rp,"\t\tComputer\t  %d\t\t %.2f\n",a1,cs/a1);
	fprintf(rp,"\t\tElectricity \t  %d\t\t %.2f\n",a3,es/a3);
	fprintf(rp,"\t\tArt \t\t  %d\t\t %.2f\n",a2,as/a2);
	fprintf(rp,"\t\tBusiness \t\t  %d\t\t %.2f\n",a4,bs/a4);\
	printf("==============================================================\n");
	printf(" \t\t�а�\t\t �ο� \t\t ��� \n");
	printf("==============================================================\n");
	printf("\t\tComputer\t  %d\t\t %.2f\n",a1,cs/a1);
	printf("\t\tElectricity \t  %d\t\t %.2f\n",a3,es/a3);
	printf("\t\tArt \t\t  %d\t\t %.2f\n",a2,as/a2);
	printf("\t\tBusiness \t  %d\t\t %.2f\n",a4,bs/a4);


}

