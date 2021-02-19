#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct person 			//定义结构体 
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

void input_add() 			//定义输入函数 
{

	int i=0,p=1;
	char num1;
	for(i=0;i<100;i++,p++)
	{	
		printf("请输入要添加人员的资料：\n");
		printf("姓名：");
		scanf("%s",per[i].name);
		printf("性别：");
		scanf("%s",per[i].sex);
		printf("年龄：");
		scanf("%s",per[i].age);
		printf("生日(年/月/日)");
		scanf("%s/%s/%s",per[i].year,per[i].month,per[i].day);
		printf("电话：");
		scanf("%s",per[i].num);
		printf("地址：");
		scanf("%s",per[i].add);
		printf("身份证号：");
		scanf("%s",per[i].id) ;
		printf("已输入%d人\n",p);
		printf("是否继续添加:y/n\n");
		scanf("%c",&num1);
		scanf("%c",&num1); 
		if(num1=='N' || num1=='n')				
		 {
		system("cls");
			jiemian();
		}
	}
	
}
void count()		//统计 
{
	int y;
	void count_sex();
	void count_add();
	void couont_bir();
	system("cls");
	printf("\n");
    printf("************请选择统计类型***********\n");
    printf("\n");
    printf("            1.性别统计\n");
    printf("\n");
    printf("            2.地址统计\n");
    printf("\n");
    printf("            3.出生年份统计\n");
    printf("\n");
    printf("*************************************\n");
    printf("\n");
    printf("请根据菜单选择统计类型：");
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
void count_sex()          //性别统计
{
       int k=0,i;
       char sex[10];
       system("cls");
       printf("\n请输入需要统计的性别：");
       scanf("%s",sex);
       for(i=0;i<100;i++)
      	 if(strcmp(sex,per[i].sex)==0)
            k++;
       printf("\n该性别的数量为：%d",k);
       system("pause");
	   jiemian();

}
void count_add()            //地区统计
{
       char add[20];
       int k=0,i;
       system("cls");
       printf("\n请输入需要统计的地区：");
       scanf("%s",add);
       for(i=0;i<100;i++)
              if(strcmp(add,per[i].add)==0)
              k++;
       printf("\n该地区的数量为：%d",k);
       system("pause");
      jiemian();
}
 
void count_bir()           //年段统计
{
       int y;
       int k=0,i;
       system("cls");
       printf("\n请输入需要统计的年份：");
       scanf("%d",&y);
       for(i=0;i<100;i++)
       if(y==per[i].year)
       k++;
       printf("该年出生的数量为：%d",k);
		system("pause");
		jiemian();
}
void search_id()		//通过身份证查找 
{
	int i;
	char num[50];
	printf("请输入要查找的身份证号:");
	scanf("%s",num);
	for(i=0; i<50; i++)
		if(strcmp(per[i].id,num)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("查找不到!请重新输入!\n");
	getch();
	system("cls");
	jiemian();
}

void search_name()			//通过名字查找 
{
	int i;
	char name[50];
	printf("请输入要查找的姓名:");
	scanf("%s",name);
	for(i=0; i<50; i++)
		if(strcmp(per[i].name,name)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("查找不到!请重新输入!\n");
	getch();
	system("cls");
	jiemian();
}
void search_age()			//通过年龄查找 
{
	int i;
	char age[50];
	printf("请输入要查找的年龄:");
	scanf("%s",age);
	for(i=0; i<50; i++)
		if(strcmp(age,per[i].age)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("查找不到!请重新输入!\n");
	getch();
	system("cls");
	jiemian();
}

void search_year()			//通过生日查找 
{
	int i;
	char year[50];
	printf("请输入要查找的年份:");
	scanf("%s",year);
	for(i=0; i<50;i++)
		if(strcmp(year,per[i].year)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
				break;
		}

	if(i==50)
	printf("查找不到!请重新输入!\n");
	getch();
	system("cls");
	jiemian();
}

void search_add()			//同个地址查找 
{
	int i;
	char add[50];
	printf("请输入要查找的地址:");
	scanf("%s",add);
	for(i=0; i<50; i++)
		if(strcmp(per[i].add,add)==0)
		{
		printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			break;
		}

	if(i==50)
	printf("查找不到!请重新输入!\n");
	getch();
	system("cls");
	jiemian();
}


void change_name()			//修改名字 
{
	char num1,i=0;
	printf("请输入要修改的姓名");
	scanf("%s",per[i].name);
	printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t:\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
	printf("姓名：");
	scanf("%s",per[i].name);
	printf("性别：");
	scanf("%s",per[i].sex);
	printf("年龄：");
	scanf("%s",per[i].age);
	printf("生日(年/月/日)");
	scanf("%s",per[i].year,per[i].month,per[i].day);
	printf("电话：");
	scanf("%s",per[i].num);
	printf("地址：");
	scanf("%s",per[i].add);
	printf("身份证号：");
	scanf("%s",per[i].id) ;
	printf("是否继续添加:y/n\n");
	scanf("%c",&num1);
	scanf("%c",&num1);
	if(num1=='N' || num1=='n')
		 {
		system("cls");
			jiemian();
		}
}

void dele()				//删除成员 
{
	int i;
	char num[50];
	printf("请输入要删除的姓名：");
	scanf("%s",num);
	for(i=0;i<50;i++)
		if(strcmp(num,per[i].name)==0)
		{
			printf("%s\t%s\t%s\t%s%s%s\t%s\t%s\t%s\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			per[i]=del;
			printf("信息已删除，按任意键返回..\n");
			break; 
		}
	if(i==50)
		printf("你输入的信息不存在!\n");
		getch();
		system("cls");
		jiemian();
}

void display()				//全部显示 
{
	int i=0;
	printf(" 姓名	性别	年龄	生日		电话		地址		身份证号\n");
	for(i=0;i<50;i++)
	{
		if(per[i].age==0)
		break;
		printf(" %s\t %s\t %s\t%s%s%s \t%s\t %s\t %s\t\t\n",per[i].name,per[i].sex,per[i].age,per[i].year,per[i].month,per[i].day,per[i].num,per[i].add,per[i].id);
			
	}
	printf("按任意键返回...");
	getch();
	system("cls");
	jiemian();
}

void save() 			//保存 
{
	FILE *fp;
	int i;
	char filename[50];
	printf("\n");
	printf("\n");
	printf("请输入要保存的文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"wb"))==NULL)
		printf("文件名为空,不能保存!\n");
	for(i=0; i<50; i++) 
	{
		if(fwrite(&per[i],sizeof(struct person),1,fp)!=1)
			printf("文件保存失败!\n");
	}
	fclose(fp);
	printf("文件已保存!\n");
	printf("按任意键返回...\n");
	getch();
	system("cls");
	jiemian();
}

void load() 			//加载 
{
	FILE *fp;     //打开文件
	int i=0;
	char filename[50];
	printf("请输入文件名：");
	scanf("%s",filename);           //输入要载入的文件名
	if((fp=fopen(filename,"rb"))==0) {   //如果当前目录下不存在相对应的文件，输出文件不存在，退出系统。
		printf("文件不存在！\n");
		exit(0);
	}
	while(fread(&per[i],sizeof(struct person),1,fp)!=0) { //若存在，读取
		i++;
	}
	fclose(fp);                                            //程序结束，关闭文件。
	printf("信息已载入！\n");
	printf("按回车键返回 ");
	getchar();
	getchar();
	system("cls");
	jiemian();
}

void leave()			//退出 
{
	printf("按任意键退出...");
	exit(0);
}

void search_by()		//查询列表 
 {
 	int num0;
 	printf("输出需要查询的选项\n");
	printf("1.通过身份证号查询\n");
	printf("2.通过姓名查询\n");
	printf("3.通过年龄查询\n");
	printf("4.通过生日查询\n"); 
	printf("5.通过地址查询\n");  
 	scanf("%d",&num0);
 	switch(num0){			//选择查询方式 
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
void xuanze() 				//目录选择界面 
{
	int num;
	scanf("%d",&num);
	switch(num) {			//选择目录 
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

jiemian() 			//目录界面 
{
	
	printf("            学生信息管理系统\n\n");
	printf("                        程序功能\n\n");
	printf("                    1:录入身份信息\n");
	printf("                    2:查询身份信息\n");
	printf("                    3:修改身份信息\n");
	printf("                    4:删除身份信息\n");
	printf("                    5:显示身份信息\n");
	printf("                    6:统计身份信息\n");
	printf("                    7:保存所有信息\n");
	printf("                    8:加载所有信息\n");
	printf("                    0:退出程序");
	printf("\n\n");
	printf("           请选择序号:");
	xuanze();
}

void main() 
{
		jiemian();

}


