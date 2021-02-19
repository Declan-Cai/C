#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct		//通讯录数据类型 
 {
 	char number[10];		//编号 
	char name[20];		//姓名
 	char sex[10];		//性别
	char telephone[20];	//电话 
	char address[30];	//地址 
	char group[15];		//分组 
 }DataType;
 
typedef struct node	//结点类型定义 
{
	DataType data;	//结点数据域 
	struct node *next;		//结点指针域 
}ListNode;

typedef ListNode *LinkList; 
LinkList head;
ListNode *p;

int flag1=0;	//全局变量 flag1为0 

LinkList CreateList()			//尾插法建立带头结点的通讯录链表算法 
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));		//申请头结点
	ListNode *p, *rear;
	char flag='y';				//结束标志置y
	rear=head;					//尾指针初始指向头结点
	while(flag=='y') 
	{
		p=(ListNode*)malloc(sizeof(ListNode));		//申请新结点
		printf("编号	姓名	性别	电话	地址	分组	\n");
		printf("------------------------------------------------\n");
		printf("输入编号(如001)：\n");
		scanf("%s",p->data.number);
		printf("输入姓名：\n");
		scanf("%s",p->data.name);
		printf("输入性别(男/女)：\n");
		scanf("%s",p->data.sex);
		printf("输入电话：\n");
		scanf("%s",p->data.telephone);
		printf("输入地址：\n");
		scanf("%s",p->data.address);
		printf("输入分组（同学/好友/黑名单）：\n");
		scanf("%s",p->data.group);
		rear->next=p;			//新结点连接到尾结点之后 
		rear=p;					//尾指针指向新结点
		printf("");
		printf("继续建表？(y/n)：");
		scanf("%s",&flag);
	}
	rear->next=NULL;		//终端结点置空
	return head;			//返回链表头指针 
}
LinkList CreateList1()			//初始化链表 
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));		//申请头结点
	ListNode *p, *rear;
	rear=head;					//尾指针初始指向头结点
	rear->next=NULL;		//终端结点置空
	return head;			//返回链表头指针 
}

void AddNode(LinkList head,ListNode *p)		//在通讯录链表head中插入结点
{
	ListNode *p1,*p2;
	p1=head;
	p2=p1->next;
	while(p2!=NULL&&strcmp(p2->data.number,p->data.number)<0)
	{
		p1=p2;				//p1指向刚访问过的结点
		p2=p2->next;		//p2指向表的下一个结点 
	}
	p1->next=p;				//插入p所指向的结点
	p->next=p2;				//连接表中剩余的结点 
 } 

void OrderList(ListNode *&l)		//按编号排序，调用插入函数或输出函数之后才可以排序 
{
	ListNode *p,*q,*s;
	q=head;
	p=q->next->next;
	q->next->next=NULL;
	while(p)
	{
		while(q->next&&(strcmp(p->data.number,q->next->data.number)>0))		//比较字符串
		q=q->next;
		s=p->next;
		p->next=q->next;
		q->next=p;
		p=s;
		q=head;
	}
 } 

ListNode *ListFind(LinkList head)		//有序通讯录链表的查找 
{
	ListNode *p;
	char number[10];
	char name[20];
	char group[20];
	char t;
	printf("----------------\n");
    printf("  1. 按编号     \n");
    printf("  2. 按姓名     \n");
    printf("----------------\n");
	printf("请选择序号1---2：");
	p=head->next;			//假定通讯录表带有结点 
	scanf("%d",&t);
	if (t==1)  
	{
		printf("请输入所求的编号：");
		scanf("%s",number);
		while(p && strcmp(p->data.number,number)<0)
			p=p->next;
		if(p==NULL || strcmp(p->data.number,number)>0)
			p=NULL; //没有查到要查找的通讯者
	} 
	else
	if(t==2)
	{
		printf("请输入所求的姓名：\n");
		scanf("%s",name);
		while(p&&strcmp(p->data.name,name)!=0)
			p=p->next; 
	}
	return p;
}

void DeleteNode(LinkList head)		//通讯录链表上的结点删除
{
	char s;
	ListNode *p,*q;
	p=ListFind(head);		//调用查找函数 
	if(p==NULL)
	{
		printf("没有查到要删除的通讯者\n");
		return;
	 } 
	printf("%s  %s  %s  %s  %s  %s\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
	printf("确定要删除该结点吗？(y/n)：");
	scanf("%s",&s);
	if(s=='y'||s=='Y')
	{
		q=head; 
		p=head->next;	 //需要定义p 
		while(p!=NULL &&q->next!=p)
			q=q->next;	
		q->next=p->next;	//删除结点
		free(p);			//释放被删除的结点空间
		printf("已删除通讯者！\n");
		return; 
	}
	else if(s=='n'||s=='N')
	{
		printf("%s  %s  %s  %s  %s  %s\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p=p->next;
		printf("是否需要删除该结点？");
			if(s=='y'||s=='Y')
		{
			q=head; 
			p=head->next;	 //需要定义p 
			while(p!=NULL &&q->next!=p)
				q=q->next;	
			q->next=p->next;	//删除结点
			free(p);			//释放被删除的结点空间
			printf("已删除通讯者！\n");
			return; 
		}
	} 
	 	printf("删除失败");	
 }
  
void AlterNode(LinkList Head)	//通讯录链表上的结点修改
{
	char ch;
	ListNode *p;
	printf("请选择按哪一个分类修改\n");
	p=ListFind(head);
	if(p==NULL)
	{
		printf("没有找到要修改的通讯者！\n");
			return;
	}
	else if(p!=NULL)
	{
		printf("确定要修改该结点吗？(y/n)");
		scanf("%s",&ch);
		if(ch=='y'||ch=='Y')
		{
			
			printf("\n输出新编号:\n");
			scanf("%s",p->data.number);
			printf("输出新姓名：\n");
			scanf("%s",p->data.name);
			printf("输出新性别：\n");
			scanf("%s",p->data.sex);
			printf("输出新电话：\n");
			scanf("%s",p->data.telephone);
			printf("输出新地址\n");
			scanf("%s",p->data.address);
			printf("输出新分类\n");
			scanf("%s",p->data.group);
			printf("修改成功");
		}
		if(ch=='n'||ch=='N')
			printf("无需修改\n");
	}
}


void Searchbysex(LinkList head)		//通过性别查找 
{
	ListNode *p;
	p=head;
	int men=0,women=0;
	while(p!=NULL)
	{
		if(strcmp(p->data.sex,"男")==0)
			men++;
		if(strcmp(p->data.sex,"女")==0)
			women++;
		p=p->next; 
	}
	printf("女生=%d\n男生=%d\n",women,men);
 } 

void PrintList(LinkList head)		//通讯录的输出 
{
	ListNode *p;
	p=head->next;
	printf("编号  姓名  性别  电话        地址  分类\n"); 
	printf("-----------------------------------------\n");
	if(p==NULL)
	{
		printf("链表为空\n"); 
	 } 
	while(p)
	{
		  
		  printf("%s    %s  %s    %s   %s  %s  \n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		  printf("----------------------------------------\n");
		  p=p->next;					//后移一个结点 
	 } 
}

void Save(LinkList head)			//数据保存函数 
{
	ListNode *p;
	FILE* fp;
	p = head->next;
	if ((fp = fopen("contactlist.txt", "ab")) == NULL)
	{
		printf("    打开文件失败 "	); 
		exit(1);
	} 
	printf("\n已保存\n");
	while (p)
	{
		fprintf(fp,"\t%s\t%s\t%s\t%s\t%s\t%s",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p = p->next;
	}
	fclose(fp);
}


LinkList Load(LinkList head)		//数据读取元素 
{
	ListNode *p, *q;
	FILE* fp;
	head=(ListNode *)malloc(sizeof(ListNode));		//申请新空间 
	head->next = NULL;
	p = head;
	if ((fp = fopen("contactlist.txt", "rb")) == NULL)
	{
		printf("打开文件失败");
		exit(1);
	}
	printf("\n已载入\n");
	while (!feof(fp))		//检测流上的文件结束符 
	{
		q = (ListNode *)malloc(sizeof(ListNode));
		if (q == NULL)
		{
			printf("文件定位失败!\n");
			exit(1);
		}
			fscanf(fp,"\t%s\t%s\t%s\t%s\t%s\t%s",q->data.number,q->data.name,q->data.sex,q->data.telephone,q->data.address,q->data.group);
			q->next = NULL;//插入链表中
			p->next = q;
			p = q;	
	}
	fclose(fp);
	p=head->next;
	printf("编号  姓名  性别  电话      地址   分类\n");
	while(p)
	{ 
		printf("%s    %s   %s  %s  %s  %s  \n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p=p->next;
	}
	return head;		//返回头结点 
}

int main()
 {
 	int k,j=1;
 	ListNode *l;
	while(j)
 	{
 		printf("\t\t\t	通讯录管理系统 		\n"); 
		printf("\t\t\t******************************"); 
		printf("\n\t\t\t|    1．通 讯 录 的 建 立    |"); 
		printf("\n\t\t\t|    2．通 讯 者 的 插 入    |");
		printf("\n\t\t\t|    3．通 讯 者 的 查 询    |");
		printf("\n\t\t\t|    4．通 讯 者 的 删 除    |"); 
		printf("\n\t\t\t|    5．通 讯 者 的 修 改    |"); 
		printf("\n\t\t\t|    6．通 讯 录 的 输 出    |");
		printf("\n\t\t\t|    7．男 生 女 生 的 人 数 | ");
		printf("\n\t\t\t|    8．   保 存 数 据       |");           
		printf("\n\t\t\t|    9．   加 载 数 据       |"); 
		printf("\n\t\t\t|    0．退出通讯录管理系统   |"); 
		printf("\n\t\t\t******************************\n"); 
		printf("\n 请选择菜单号 (0--9):"); 
		scanf("%d",&k);
		getchar();
		switch(k)
		{
			case 1:    
				{
					printf("\n		1.通讯录的建立		\n");
					head=CreateList();
					flag1=1;
					break;
				}
			case 2:
				{
					if(flag1!=1)
					{
						printf("请先建立表，按任意键返回");
						getchar();
					}
					else
					{
						printf("\n		2.通讯录信息插入		\n");
						printf("\n编号      姓名       性别       电话       地址       分组     \n");
						printf("--------------------------------------\n");
						p=(ListNode *)malloc(sizeof(ListNode));  		//申请新结点
						printf("输入编号(如001):\n");
						scanf("%s",p->data.number);
						printf("输入姓名:\n");
						scanf("%s",p->data.name);
						printf("输入性别(男/女):\n");
						scanf("%s",p->data.sex);
						printf("输入电话:\n");
						scanf("%s",p->data.telephone);
						printf("输入地址:\n");
						scanf("%s",p->data.address);
						printf("输入分组(好友/同学/黑名单):\n");
						scanf("%s",p->data.group);
						AddNode(head,p);
						printf("排序:\n");
	                    OrderList(l); 				//调用通讯录排序函数此处放在插入模块下面
                    	PrintList(head);
                    	system("pause");
					  }
  					break;
				}
			case 3:
				{
					if(flag1!=1)
					{
						printf("请先建立表！按任意键返回");
						getchar();
					}
					else
					{
						printf("\n     3.通 讯 录 信 息 的 查 询      \n");
						p=ListFind(head);
						if (p!=NULL) 
						{
							printf("编号   姓 名   性别   电话       地址       分组\n");
							printf("--------------------------------------------------\n");
							printf("编号:%s\n姓名:%s\n性别:%s\n联系电话:%s\n地址:%s\n分组:%s\n\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
							printf("---------------------------------------------------\n");
						}
						else printf("没有查到要查询的通讯者！\n");
					}
					break; 
				}
			case 4:
			{
					if(flag1!=1)
				{
					printf("请先建立表，按任意键返回");
					getchar(); 
				} 
				else
				{
					printf("\n		4.通讯录信息的删除		\n");
					DeleteNode(head);	//删除结点 
					system("pause");
				}
				break; 
			}
			case 5:
			{
				if(flag1!=1)
				{
					printf("请先建立表，按任意键返回!");
					getchar();
				}
				else
				{
					printf("\n		5.通讯录信息的修改		\n");
					AlterNode(head);
					system("pause");
				}
				break;
			}
			case 6:
			{
				if(flag1!=1)
				{
					printf("请先建立表，按任意键返回！");
					getchar(); 
					
				}
				else
				{ 
					printf("\n		6.通讯录链表的输出		\n");
					PrintList(head);
				    system("pause");
	
				}
				break;
			} 
			case 7:
			{
				if(flag1!=1)
				{
					printf("请先建立表，按任意键返回！");
					getchar();
				}
				else
				{
					printf("\n		7.通讯录中男女生的人数		\n");
					Searchbysex(head);
					system("pause");
				}
				break;
			}
			case 8:
			{
				if(flag1!=1)
				{
					printf("请先建立表，按任意键返回！");
					getchar();
				}
				else
				{
					Save(head);
					system("pause");
				}
				break;
			}
			case 9:
	 			head=CreateList1();
				flag1=1;
				head=Load(head);
				system("pause");
				break;
			case 0:
				printf("退出前请确认是否保存文件！！！\n若无请返回保存！\n"); 
				printf("是否退出(y/n)?");
				k=getchar();
				if(k=='y'||k=='Y')
				{
					j=0;
					printf("\n谢谢使用");
					printf("\n按任意键退出");
				}
				break;
			default:
				printf("\n输入错误，请重新输入!\n");
				printf("\n按任意键继续...");
				getchar();
				break;
	 	}
 	}
 } 



