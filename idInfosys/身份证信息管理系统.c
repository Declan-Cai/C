#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct person 			//����ṹ�� 
{
	char name[50];
	char sex[5];
	char age[5];
	char year[10];
	char month[10];
	char day[10];
	char num[15];
	char add[20];
	char id[20];
}per[100],del;

void input_add() 			//�������뺯�� 
{

	int i=0,p=1;
	char num1;
	for(i=0;i<100;i++,p++)
	{	
		printf("������Ҫ�����Ա�����ϣ�\n");
		printf("������");
		scanf("%s",per[i].name);
		printf("�Ա�");
		scanf("%s",per[i].sex);
		printf("���䣺");
		scanf("%s",per[i].age);
		printf("����(��/��/��)");
		scanf("%s/%s/%s",per[i].year,per[i].month,per[i].day);
		printf("�绰��");
		scanf("%s",per[i].num);
		printf("��ַ��");
		scanf("%s",per[i].add);
		printf("���֤�ţ�");
		scanf("%s",per[i].id) ;
		printf("������%d��\n",p);
		printf("�Ƿ�������:y/n\n");
		scanf("%c",&num1);
		scanf("%c",&num1); 
		if(num1=='N' || num1=='n')				
		 {
		system("cls");
			jiemian();
		}
	}
	
}
void count()		//ͳ�� 
{
	int y;
	void count_sex();
	void count_add();
	void couont_bir();
	system("cls");
	printf("\n");
    printf("************��ѡ��ͳ������***********\n");
    printf("\n");
    printf("            1.�Ա�ͳ��\n");
    printf("\n");
    printf("            2.��ַͳ��\n");
    printf("\n");
    printf("            3.�������ͳ��\n");
    printf("\n");
    printf("*************************************\n");
    printf("\n");
    printf("����ݲ˵�ѡ��ͳ�����ͣ�");
    scanf("%d",&y);
	switch(y)
	{
		case 1:count_sex();
		break;
		case 2:count_add();
		break;
		case 3:count_bir();
		break;
		default:break;
	}
	printf("\n");
	system("pause");
}
void count_sex()          //�Ա�ͳ��
{
       int k=0,i;
       char sex[10];
       system("cls");
       printf("\n��������Ҫͳ�Ƶ��Ա�");
       scanf("%s",sex);
       for(i=0;i<100;i++)
      	 if(strcmp(sex,per[i].sex)==0)
            k++;
       printf("\n���Ա������Ϊ��%d",k);
       system("pause");
	   jiemian();

}
void count_add()            //����ͳ��
{
       char add[20];
       int k=0,i;
       system("cls");
       printf("\n��������Ҫͳ�Ƶĵ�����");
       scanf("%s",add);
       for(i=0;i<100;i++)
              if(strcmp(add,per[i].add)==0)
              k++;
       printf("\n�õ���������Ϊ��%d",k);
       system("pause");
      jiemian();
}
 
void count_bir()           //���ͳ��
{
       int y;
       int k=0,i;
       system("cls");
       printf("\n��������Ҫͳ�Ƶ���ݣ�");
       scanf("%d",&y);
       for(i=0;i<100;i++)
       if(y==per[i].year)
       k++;
       printf("�������������Ϊ��%d",k);
		system("pause");
		jiemian();
}
void search_id()		//ͨ�����֤���� 
{
	int i;
	char num[50];
	printf("������Ҫ���ҵ����֤��:");
	scanf("%s",num);
	for(i=0; i<50; i++)
		if(strcmp(per[i].id,num)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("���Ҳ���!����������!\n");
	getch();
	system("cls");
	jiemian();
}

void search_name()			//ͨ�����ֲ��� 
{
	int i;
	char name[50];
	printf("������Ҫ���ҵ�����:");
	scanf("%s",name);
	for(i=0; i<50; i++)
		if(strcmp(per[i].name,name)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("���Ҳ���!����������!\n");
	getch();
	system("cls");
	jiemian();
}
void search_age()			//ͨ��������� 
{
	int i;
	char age[50];
	printf("������Ҫ���ҵ�����:");
	scanf("%s",age);
	for(i=0; i<50; i++)
		if(strcmp(age,per[i].age)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("���Ҳ���!����������!\n");
	getch();
	system("cls");
	jiemian();
}

void search_year()			//ͨ�����ղ��� 
{
	int i;
	char year[50];
	printf("������Ҫ���ҵ����:");
	scanf("%s",year);
	for(i=0; i<50;i++)
		if(strcmp(year,per[i].year)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
				break;
		}

	if(i==50)
	printf("���Ҳ���!����������!\n");
	getch();
	system("cls");
	jiemian();
}

void search_add()			//ͬ����ַ���� 
{
	int i;
	char add[50];
	printf("������Ҫ���ҵĵ�ַ:");
	scanf("%s",add);
	for(i=0; i<50; i++)
		if(strcmp(per[i].add,add)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("���Ҳ���!����������!\n");
	getch();
	system("cls");
	jiemian();
}


void change_name()			//�޸����� 
{
	char num1,i=0;
	printf("������Ҫ�޸ĵ�����");
	scanf("%s",per[i].name);
	printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t:\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
	printf("������");
	scanf("%s",per[i].name);
	printf("�Ա�");
	scanf("%s",per[i].sex);
	printf("���䣺");
	scanf("%s",per[i].age);
	printf("����(��/��/��)");
	scanf("%s",per[i].year,per[i].month,per[i].day);
	printf("�绰��");
	scanf("%s",per[i].num);
	printf("��ַ��");
	scanf("%s",per[i].add);
	printf("���֤�ţ�");
	scanf("%s",per[i].id) ;
	printf("�Ƿ�������:y/n\n");
	scanf("%c",&num1);
	scanf("%c",&num1);
	if(num1=='N' || num1=='n')
		 {
		system("cls");
			jiemian();
		}
}

void dele()				//ɾ����Ա 
{
	int i;
	char num[50];
	printf("������Ҫɾ����������");
	scanf("%s",num);
	for(i=0;i<50;i++)
		if(strcmp(num,per[i].name)==0)
		{
			printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			per[i]=del;
			printf("��Ϣ��ɾ���������������..\n");
			break; 
		}
	if(i==50)
		printf("���������Ϣ������!\n");
		getch();
		system("cls");
		jiemian();
}

void display()				//ȫ����ʾ 
{
	int i=0;
	printf(" ����	�Ա�	����	����		�绰		��ַ		���֤��\n");
	for(i=0;i<50;i++)
	{
		if(per[i].age==0)
		break;
		printf(" %s\t %s\t %s\t%s%s%s \t%s\t %s\t %s\t\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			
	}
	printf("�����������...");
	getch();
	system("cls");
	jiemian();
}

void save() 			//���� 
{
	FILE *fp;
	int i;
	char filename[50];
	printf("\n");
	printf("\n");
	printf("������Ҫ������ļ���:");
	scanf("%s",filename);
	if((fp=fopen(filename,"wb"))==NULL)
		printf("�ļ���Ϊ��,���ܱ���!\n");
	for(i=0; i<50; i++) 
	{
		if(fwrite(&per[i],sizeof(struct person),1,fp)!=1)
			printf("�ļ�����ʧ��!\n");
	}
	fclose(fp);
	printf("�ļ��ѱ���!\n");
	printf("�����������...\n");
	getch();
	system("cls");
	jiemian();
}

void load() 			//���� 
{
	FILE *fp;     //���ļ�
	int i=0;
	char filename[50];
	printf("�������ļ�����");
	scanf("%s",filename);           //����Ҫ������ļ���
	if((fp=fopen(filename,"rb"))==0) {   //�����ǰĿ¼�²��������Ӧ���ļ�������ļ������ڣ��˳�ϵͳ��
		printf("�ļ������ڣ�\n");
		exit(0);
	}
	while(fread(&per[i],sizeof(struct person),1,fp)!=0) { //�����ڣ���ȡ
		i++;
	}
	fclose(fp);                                            //����������ر��ļ���
	printf("��Ϣ�����룡\n");
	printf("���س������� ");
	getchar();
	getchar();
	system("cls");
	jiemian();
}

void leave()			//�˳� 
{
	printf("��������˳�...");
	exit(0);
}

void search_by()		//��ѯ�б� 
 {
 	int num0;
 	printf("�����Ҫ��ѯ��ѡ��\n");
	printf("1.ͨ�����֤�Ų�ѯ\n");
	printf("2.ͨ��������ѯ\n");
	printf("3.ͨ�������ѯ\n");
	printf("4.ͨ�����ղ�ѯ\n"); 
	printf("5.ͨ����ַ��ѯ\n");  
 	scanf("%d",&num0);
 	switch(num0){			//ѡ���ѯ��ʽ 
 		case 1:
 			system("pause");
 			search_id();
 			break;
 		case 2:system("pause");
 			search_name();
 			break;
 		case 3:system("pause");
 			search_age();
 			break;
 		case 4:system("pause");
 			search_year();
 			break;

		case 5:system("pause");
			search_add();
			break; 
			 
			default:
			printf(" ");
			break;
	 }
 }
void xuanze() 				//Ŀ¼ѡ����� 
{
	int num;
	scanf("%d",&num);
	switch(num) {			//ѡ��Ŀ¼ 
		case 1:
			system("cls");
			input_add();
			break;
		case 2:
			system("cls");
			search_by();
			break;
		case 3:
			system("cls");
			change_name();
			break;
		case 4:
			system("cls");
			dele();
			break;
		case 5:
			system("cls");
			display();
			break;
		case 6:
			system("cls");
			count();
			break;
		case 7:
			system("cls");
			save();
			break;
		case 8:
			system("cls");
			load();
			break;
		case 0:
			system("cls");
			leave();
			break;

		default:
			printf(" ");
			break;
	}

}

jiemian() 			//Ŀ¼���� 
{
	
	printf("            ѧ����Ϣ����ϵͳ\n\n");
	printf("                        ������\n\n");
	printf("                    1:¼�������Ϣ\n");
	printf("                    2:��ѯ�����Ϣ\n");
	printf("                    3:�޸������Ϣ\n");
	printf("                    4:ɾ�������Ϣ\n");
	printf("                    5:��ʾ�����Ϣ\n");
	printf("                    6:ͳ�������Ϣ\n");
	printf("                    7:����������Ϣ\n");
	printf("                    8:����������Ϣ\n");
	printf("                    0:�˳�����");
	printf("\n\n");
	printf("           ��ѡ�����:");
	xuanze();
}

void main() 
{
		jiemian();

}


