#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void today(int *yearp,int *monthp,int *dayp);   //���� ��¥ ���ϴ� �Լ�  
void input(char *c_birth);  //����� ������� �Է��Լ� 
void change(char *c_birth,int *year,int *month,int *day);  //������� ������ ��������� ���������� ��ȯ��Ű�� �Լ� 
void date(int year,int month,int day,int uyear,int umonth,int uday); //��ƿ� ���� ��� �Լ�  

void main(){
	int year,month,day,uyear,umonth,uday;
	char c_birth[11];
	today(&year,&month,&day);    //���� ��¥ ���ϴ� �Լ� ȣ��  
	input(c_birth);//����� ������� �Է��Լ�ȣ��  
	change(c_birth,&uyear,&umonth,&uday);//������� ������ ��������� ���������� ��ȯ��Ű�� �Լ�ȣ��  
	date(year,month,day,uyear,umonth,uday);//��ƿ� ���� ��� �Լ�ȣ��  
}

void today(int *yearp,int *monthp,int *dayp){
	time_t time_ms;
	struct tm *t;     // ����ü ���� ����
	time_ms=time(NULL);  // ���� �ð� ���   
	t=localtime(&time_ms);  //�ð��� �и��Ͽ� ����ü�� �ֱ�
	*yearp=t->tm_year%100+2000;
	*monthp=t->tm_mon+1;
	*dayp=t->tm_mday;
}

void input(char *c_birth){
	printf("��������� ������� �Է��ϼ���: 0000/00/00\n");
	printf("                              : "); 
	
	scanf("%s",c_birth);
	printf("\n============================================\n"); 
	if(strcmp(c_birth,"0")==0){     //0�� �Է��ϸ� ���α׷� ����  
		printf("���α׷��� ����˴ϴ�");
		exit(1);
	}
}
void change(char *c_birth,int *year,int *month,int *day){
    char sp[2] = "/";
	*year = atoi(strtok(c_birth, sp)); //strtok Ȱ���Ͽ� sp ������ ���� atoi�� ���ڿ��� ���������� ��ȯ 
    *month = atoi(strtok(NULL, sp));//strtok Ȱ���Ͽ� sp ������ ���� atoi�� ���ڿ��� ���������� ��ȯ
    *day = atoi(strtok(NULL, sp));//strtok Ȱ���Ͽ� sp ������ ���� atoi�� ���ڿ��� ���������� ��ȯ
}
void date(int year,int month,int day,int uyear,int umonth,int uday){
	int monthdate[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int date=0,i,a,m;
	i=uyear+1;
	for(i;i<year;i++){       //��ƿ� ��� ���ϱ�  
		if(((i%4==0)&&(i%100!=0))||i%400==0){  //���� ���� 
			date+=366;
		}
		else{
			date+=365;
		}
		
	}
	if(((uyear%4==0)&&(uyear%100!=0))||uyear%400==0){//���� ����
		monthdate[1]=29;     //�����ϰ��  
	}
	else{
		monthdate[1]=28;    //����ϰ�� 
	}
	m=umonth+1;
	if(uyear<year){        
		for(m;m<=12;m++){      //n������ 12������ 
			date+=monthdate[m-1];        //�迭�� �����س� �޸��� ��¥���� date�� ���ϱ� 
		}
		date+=monthdate[umonth-1]-uday+1;
	}
	
	if(((year%4==0)&&(year%100!=0))||year%400==0){//���� ����
		monthdate[1]=29;//�����ϰ��
	}
	else{
		monthdate[1]=28;//����ϰ�� 
	}
	for(a=1;a<month;a++){ //1������ n������ 
		date+=monthdate[a-1];
	}
	date+=day;
	
	printf("��ƿ� ��¥�� %d�� �Դϴ�.\n",date);
}


