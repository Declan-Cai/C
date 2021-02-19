#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct		//ͨѶ¼�������� 
 {
 	char number[10];		//��� 
	char name[20];		//����
 	char sex[10];		//�Ա�
	char telephone[20];	//�绰 
	char address[30];	//��ַ 
	char group[15];		//���� 
 }DataType;
 
typedef struct node	//������Ͷ��� 
{
	DataType data;	//��������� 
	struct node *next;		//���ָ���� 
}ListNode;

typedef ListNode *LinkList; 
LinkList head;
ListNode *p;

int flag1=0;	//ȫ�ֱ��� flag1Ϊ0 

LinkList CreateList()			//β�巨������ͷ����ͨѶ¼�����㷨 
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));		//����ͷ���
	ListNode *p, *rear;
	char flag='y';				//������־��y
	rear=head;					//βָ���ʼָ��ͷ���
	while(flag=='y') 
	{
		p=(ListNode*)malloc(sizeof(ListNode));		//�����½��
		printf("���	����	�Ա�	�绰	��ַ	����	\n");
		printf("------------------------------------------------\n");
		printf("������(��001)��\n");
		scanf("%s",p->data.number);
		printf("����������\n");
		scanf("%s",p->data.name);
		printf("�����Ա�(��/Ů)��\n");
		scanf("%s",p->data.sex);
		printf("����绰��\n");
		scanf("%s",p->data.telephone);
		printf("�����ַ��\n");
		scanf("%s",p->data.address);
		printf("������飨ͬѧ/����/����������\n");
		scanf("%s",p->data.group);
		rear->next=p;			//�½�����ӵ�β���֮�� 
		rear=p;					//βָ��ָ���½��
		printf("");
		printf("��������(y/n)��");
		scanf("%s",&flag);
	}
	rear->next=NULL;		//�ն˽���ÿ�
	return head;			//��������ͷָ�� 
}
LinkList CreateList1()			//��ʼ������ 
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));		//����ͷ���
	ListNode *p, *rear;
	rear=head;					//βָ���ʼָ��ͷ���
	rear->next=NULL;		//�ն˽���ÿ�
	return head;			//��������ͷָ�� 
}

void AddNode(LinkList head,ListNode *p)		//��ͨѶ¼����head�в�����
{
	ListNode *p1,*p2;
	p1=head;
	p2=p1->next;
	while(p2!=NULL&&strcmp(p2->data.number,p->data.number)<0)
	{
		p1=p2;				//p1ָ��շ��ʹ��Ľ��
		p2=p2->next;		//p2ָ������һ����� 
	}
	p1->next=p;				//����p��ָ��Ľ��
	p->next=p2;				//���ӱ���ʣ��Ľ�� 
 } 

void OrderList(ListNode *&l)		//��������򣬵��ò��뺯�����������֮��ſ������� 
{
	ListNode *p,*q,*s;
	q=head;
	p=q->next->next;
	q->next->next=NULL;
	while(p)
	{
		while(q->next&&(strcmp(p->data.number,q->next->data.number)>0))		//�Ƚ��ַ���
		q=q->next;
		s=p->next;
		p->next=q->next;
		q->next=p;
		p=s;
		q=head;
	}
 } 

ListNode *ListFind(LinkList head)		//����ͨѶ¼����Ĳ��� 
{
	ListNode *p;
	char number[10];
	char name[20];
	char group[20];
	char t;
	printf("----------------\n");
    printf("  1. �����     \n");
    printf("  2. ������     \n");
    printf("----------------\n");
	printf("��ѡ�����1---2��");
	p=head->next;			//�ٶ�ͨѶ¼����н�� 
	scanf("%d",&t);
	if (t==1)  
	{
		printf("����������ı�ţ�");
		scanf("%s",number);
		while(p && strcmp(p->data.number,number)<0)
			p=p->next;
		if(p==NULL || strcmp(p->data.number,number)>0)
			p=NULL; //û�в鵽Ҫ���ҵ�ͨѶ��
	} 
	else
	if(t==2)
	{
		printf("�����������������\n");
		scanf("%s",name);
		while(p&&strcmp(p->data.name,name)!=0)
			p=p->next; 
	}
	return p;
}

void DeleteNode(LinkList head)		//ͨѶ¼�����ϵĽ��ɾ��
{
	char s;
	ListNode *p,*q;
	p=ListFind(head);		//���ò��Һ��� 
	if(p==NULL)
	{
		printf("û�в鵽Ҫɾ����ͨѶ��\n");
		return;
	 } 
	printf("%s  %s  %s  %s  %s  %s\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
	printf("ȷ��Ҫɾ���ý����(y/n)��");
	scanf("%s",&s);
	if(s=='y'||s=='Y')
	{
		q=head; 
		p=head->next;	 //��Ҫ����p 
		while(p!=NULL &&q->next!=p)
			q=q->next;	
		q->next=p->next;	//ɾ�����
		free(p);			//�ͷű�ɾ���Ľ��ռ�
		printf("��ɾ��ͨѶ�ߣ�\n");
		return; 
	}
	else if(s=='n'||s=='N')
	{
		printf("%s  %s  %s  %s  %s  %s\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p=p->next;
		printf("�Ƿ���Ҫɾ���ý�㣿");
			if(s=='y'||s=='Y')
		{
			q=head; 
			p=head->next;	 //��Ҫ����p 
			while(p!=NULL &&q->next!=p)
				q=q->next;	
			q->next=p->next;	//ɾ�����
			free(p);			//�ͷű�ɾ���Ľ��ռ�
			printf("��ɾ��ͨѶ�ߣ�\n");
			return; 
		}
	} 
	 	printf("ɾ��ʧ��");	
 }
  
void AlterNode(LinkList Head)	//ͨѶ¼�����ϵĽ���޸�
{
	char ch;
	ListNode *p;
	printf("��ѡ����һ�������޸�\n");
	p=ListFind(head);
	if(p==NULL)
	{
		printf("û���ҵ�Ҫ�޸ĵ�ͨѶ�ߣ�\n");
			return;
	}
	else if(p!=NULL)
	{
		printf("ȷ��Ҫ�޸ĸý����(y/n)");
		scanf("%s",&ch);
		if(ch=='y'||ch=='Y')
		{
			
			printf("\n����±��:\n");
			scanf("%s",p->data.number);
			printf("�����������\n");
			scanf("%s",p->data.name);
			printf("������Ա�\n");
			scanf("%s",p->data.sex);
			printf("����µ绰��\n");
			scanf("%s",p->data.telephone);
			printf("����µ�ַ\n");
			scanf("%s",p->data.address);
			printf("����·���\n");
			scanf("%s",p->data.group);
			printf("�޸ĳɹ�");
		}
		if(ch=='n'||ch=='N')
			printf("�����޸�\n");
	}
}


void Searchbysex(LinkList head)		//ͨ���Ա���� 
{
	ListNode *p;
	p=head;
	int men=0,women=0;
	while(p!=NULL)
	{
		if(strcmp(p->data.sex,"��")==0)
			men++;
		if(strcmp(p->data.sex,"Ů")==0)
			women++;
		p=p->next; 
	}
	printf("Ů��=%d\n����=%d\n",women,men);
 } 

void PrintList(LinkList head)		//ͨѶ¼����� 
{
	ListNode *p;
	p=head->next;
	printf("���  ����  �Ա�  �绰        ��ַ  ����\n"); 
	printf("-----------------------------------------\n");
	if(p==NULL)
	{
		printf("����Ϊ��\n"); 
	 } 
	while(p)
	{
		  
		  printf("%s    %s  %s    %s   %s  %s  \n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		  printf("----------------------------------------\n");
		  p=p->next;					//����һ����� 
	 } 
}

void Save(LinkList head)			//���ݱ��溯�� 
{
	ListNode *p;
	FILE* fp;
	p = head->next;
	if ((fp = fopen("contactlist.txt", "ab")) == NULL)
	{
		printf("    ���ļ�ʧ�� "	); 
		exit(1);
	} 
	printf("\n�ѱ���\n");
	while (p)
	{
		fprintf(fp,"\t%s\t%s\t%s\t%s\t%s\t%s",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p = p->next;
	}
	fclose(fp);
}


LinkList Load(LinkList head)		//���ݶ�ȡԪ�� 
{
	ListNode *p, *q;
	FILE* fp;
	head=(ListNode *)malloc(sizeof(ListNode));		//�����¿ռ� 
	head->next = NULL;
	p = head;
	if ((fp = fopen("contactlist.txt", "rb")) == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	printf("\n������\n");
	while (!feof(fp))		//������ϵ��ļ������� 
	{
		q = (ListNode *)malloc(sizeof(ListNode));
		if (q == NULL)
		{
			printf("�ļ���λʧ��!\n");
			exit(1);
		}
			fscanf(fp,"\t%s\t%s\t%s\t%s\t%s\t%s",q->data.number,q->data.name,q->data.sex,q->data.telephone,q->data.address,q->data.group);
			q->next = NULL;//����������
			p->next = q;
			p = q;	
	}
	fclose(fp);
	p=head->next;
	printf("���  ����  �Ա�  �绰      ��ַ   ����\n");
	while(p)
	{ 
		printf("%s    %s   %s  %s  %s  %s  \n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
		p=p->next;
	}
	return head;		//����ͷ��� 
}

int main()
 {
 	int k,j=1;
 	ListNode *l;
	while(j)
 	{
 		printf("\t\t\t	ͨѶ¼����ϵͳ 		\n"); 
		printf("\t\t\t******************************"); 
		printf("\n\t\t\t|    1��ͨ Ѷ ¼ �� �� ��    |"); 
		printf("\n\t\t\t|    2��ͨ Ѷ �� �� �� ��    |");
		printf("\n\t\t\t|    3��ͨ Ѷ �� �� �� ѯ    |");
		printf("\n\t\t\t|    4��ͨ Ѷ �� �� ɾ ��    |"); 
		printf("\n\t\t\t|    5��ͨ Ѷ �� �� �� ��    |"); 
		printf("\n\t\t\t|    6��ͨ Ѷ ¼ �� �� ��    |");
		printf("\n\t\t\t|    7���� �� Ů �� �� �� �� | ");
		printf("\n\t\t\t|    8��   �� �� �� ��       |");           
		printf("\n\t\t\t|    9��   �� �� �� ��       |"); 
		printf("\n\t\t\t|    0���˳�ͨѶ¼����ϵͳ   |"); 
		printf("\n\t\t\t******************************\n"); 
		printf("\n ��ѡ��˵��� (0--9):"); 
		scanf("%d",&k);
		getchar();
		switch(k)
		{
			case 1:    
				{
					printf("\n		1.ͨѶ¼�Ľ���		\n");
					head=CreateList();
					flag1=1;
					break;
				}
			case 2:
				{
					if(flag1!=1)
					{
						printf("���Ƚ����������������");
						getchar();
					}
					else
					{
						printf("\n		2.ͨѶ¼��Ϣ����		\n");
						printf("\n���      ����       �Ա�       �绰       ��ַ       ����     \n");
						printf("--------------------------------------\n");
						p=(ListNode *)malloc(sizeof(ListNode));  		//�����½��
						printf("������(��001):\n");
						scanf("%s",p->data.number);
						printf("��������:\n");
						scanf("%s",p->data.name);
						printf("�����Ա�(��/Ů):\n");
						scanf("%s",p->data.sex);
						printf("����绰:\n");
						scanf("%s",p->data.telephone);
						printf("�����ַ:\n");
						scanf("%s",p->data.address);
						printf("�������(����/ͬѧ/������):\n");
						scanf("%s",p->data.group);
						AddNode(head,p);
						printf("����:\n");
	                    OrderList(l); 				//����ͨѶ¼�������˴����ڲ���ģ������
                    	PrintList(head);
                    	system("pause");
					  }
  					break;
				}
			case 3:
				{
					if(flag1!=1)
					{
						printf("���Ƚ����������������");
						getchar();
					}
					else
					{
						printf("\n     3.ͨ Ѷ ¼ �� Ϣ �� �� ѯ      \n");
						p=ListFind(head);
						if (p!=NULL) 
						{
							printf("���   �� ��   �Ա�   �绰       ��ַ       ����\n");
							printf("--------------------------------------------------\n");
							printf("���:%s\n����:%s\n�Ա�:%s\n��ϵ�绰:%s\n��ַ:%s\n����:%s\n\n",p->data.number,p->data.name,p->data.sex,p->data.telephone,p->data.address,p->data.group);
							printf("---------------------------------------------------\n");
						}
						else printf("û�в鵽Ҫ��ѯ��ͨѶ�ߣ�\n");
					}
					break; 
				}
			case 4:
			{
					if(flag1!=1)
				{
					printf("���Ƚ����������������");
					getchar(); 
				} 
				else
				{
					printf("\n		4.ͨѶ¼��Ϣ��ɾ��		\n");
					DeleteNode(head);	//ɾ����� 
					system("pause");
				}
				break; 
			}
			case 5:
			{
				if(flag1!=1)
				{
					printf("���Ƚ����������������!");
					getchar();
				}
				else
				{
					printf("\n		5.ͨѶ¼��Ϣ���޸�		\n");
					AlterNode(head);
					system("pause");
				}
				break;
			}
			case 6:
			{
				if(flag1!=1)
				{
					printf("���Ƚ���������������أ�");
					getchar(); 
					
				}
				else
				{ 
					printf("\n		6.ͨѶ¼��������		\n");
					PrintList(head);
				    system("pause");
	
				}
				break;
			} 
			case 7:
			{
				if(flag1!=1)
				{
					printf("���Ƚ���������������أ�");
					getchar();
				}
				else
				{
					printf("\n		7.ͨѶ¼����Ů��������		\n");
					Searchbysex(head);
					system("pause");
				}
				break;
			}
			case 8:
			{
				if(flag1!=1)
				{
					printf("���Ƚ���������������أ�");
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
				printf("�˳�ǰ��ȷ���Ƿ񱣴��ļ�������\n�����뷵�ر��棡\n"); 
				printf("�Ƿ��˳�(y/n)?");
				k=getchar();
				if(k=='y'||k=='Y')
				{
					j=0;
					printf("\nллʹ��");
					printf("\n��������˳�");
				}
				break;
			default:
				printf("\n�����������������!\n");
				printf("\n�����������...");
				getchar();
				break;
	 	}
 	}
 } 



