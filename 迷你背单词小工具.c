#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM  30    //�ַ�������󳤶�

int Menu(void);         //Ŀ¼����
void Addtofile(char *filename); //�򵥴ʿ�����ӵ���
struct wordlink *AppendWord(struct wordlink *newwords);//������������
void DeleteMemory(struct wordlink *newwords);//�ͷ�newwordsָ������������еĽڵ���ռ�õ��ڴ�
void PutoutNewWords(struct wordlink *newwords);//������ʱ��еĵ���
void Searchbyenglish(struct wordlink *newwords); //��Ӣ�Ĳ������ʿ��еĵ���
void Searchbychinese(struct wordlink *newwords);//�����Ĳ������ʿ��еĵ���
void Readfromfile(char *filename);//���ļ��е�������ʾ����Ļ��
int CreateRandNumber(void);//�������һ��1��4�е������
void rightcourage(int (*CreateRandNumber)(void));//�������������������
void errorcourage(int (*CreateRandNumber)(void));//������������������䡣
void Outoforder(struct wordlink *newwords,int count);//���ҵ��򵥴������˳��
void WriteToNewWordsFile(struct wordlink *newwords,char *filename,int count);//�����������еĵ���д�����ʱ�newwords�����ñ���
void Test(struct wordlink *newwords);//�������ʱ��Ĳ��ԡ�
void Ctest(struct wordlink *newwords);//�������ʱ��Ĳ���(����Ӣ)
void Etest(struct wordlink *newwords);//�������ʱ��Ĳ���(Ӣ����)
struct wordlink *Setup(struct wordlink *newwords,int *count);//�������뵥�ʵ�����������
void About(void);//�����������������㱳����С���ߵ������Ϣ(��������ƣ���������Ϣ���汾��Ϣ������ʱ��)
void Help(void);//�������������Ĺ���˵����ʹ��˵��

struct wordlink               //������һ��ӵ���ĸ�ָ������Ľṹ�嵥������
{
	char *e;                  //��������ָ�򵥴�Ӣ����˼����
	char *t;                  //��������ָ�򵥴ʴ�������
	char *c;                  //��������ָ�򵥴�������˼����
	struct wordlink *pnext;   //ָ����һ���ṹ�嵥������
};  

int main()
{
	int count=0;
	int h;
	struct wordlink *newwords=NULL;
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\tͬѧ����á�\n");
	printf("\t\t\t\t\t\t�����㣬������!\n\n\n");
	printf("\t\t\t\t\t|��������|:\t���㱳����С����\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t|�汾��Ϣ|:\t���װ�\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^\n");
	printf("\t\t\t\t\t|����ʱ��|:\t2018��1��19��\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^^^^^^^^\n\n");
	printf("\t\t\t\t\t�밴ENTER�����������ѧϰ֮��;��");
	getchar();
	system("cls");
	while(1)
	{
		h=Menu();    //��ʾ�˵�������ȡ�û�����
		switch(h)
		{
		case 1:system("cls");
			printf("\n\t\t\t\t�����ڽ��е������뵥�ʵ����ʿ�Ĳ���\n");
			Addtofile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 2:system("cls");
			Readfromfile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 3:system("cls");
			Readfromfile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t�����ڽ��е��Ǵ������ʱ��Ĳ���\n");
			newwords=Setup(newwords,&count);
			WriteToNewWordsFile(newwords,"D:\\newwords.txt",count);
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 4:Readfromfile("D:\\newwords.txt");
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 5:system("cls");
			Outoforder(newwords,count);
			Ctest(newwords);
			printf("\n\t\t\t\t������ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 6:system("cls");
			Outoforder(newwords,count);
			Etest(newwords);
			printf("\n\t\t\t\t������ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 7:system("cls");
			Outoforder(newwords,count);
			Test(newwords);
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 8:system("cls");
			Searchbychinese(newwords); 
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 9:system("cls");
			Searchbyenglish(newwords);
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 10:system("cls");
			About();
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 11:system("cls");
			Help();
			printf("\n\t\t\t\t����ENTER�����Ž���ѧϰ:");
			getchar();
			break;
		case 0:system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t�����˰�ͬѧ����Ϣһ��Ҳ�á�\n\n");
			printf("\t\t\t\t\t�����Ϊ�˸����õ�������\n\n");
			printf("\t\t\t\t\t�ڴ����ǵ��ٴ�������\n\n");
			printf("\t\t\t\t\t\t\t\t\t-----���㱳����С����\n");
			DeleteMemory(newwords);
	        exit(0);
		default:("\t\t\t\t������˼������������������˴���");
		}
	}
	return 0;
}

//�������ܣ���ʾ�˵�������û�����
int Menu(void)
{
	int itemSelected;
	system("cls");
	printf("\t\t\t\t\t\t#________________________#\n");
	printf("\t\t\t\t\t\t|*|<<���㱳����С����>>|*|\n");
	printf("\t\t\t\t\t\t#------------------------#\n");
	printf("\t\t\t\t\t*|1���ӵ��ʿ��еĵ���|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|2�鿴���ʿ�ĵ���|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|3�������������ʱ�|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|4�鿴���������ʱ�|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|5���ʲ���(����Ӣ)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|6���ʲ���(Ӣ����)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|7���ʲ���(��Ӣ�������ȭ)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|8��������˼�������ʱ��еĵ���|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|9��Ӣ�Ĳ������ʱ��еĵ���|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|10����|\n");
	printf("\t\t\t\t\t^^^^^^^^^\n");
	printf("\t\t\t\t\t*|11����|\n");
	printf("\t\t\t\t\t^^^^^^^^^\n");
	printf("\t\t\t\t\t*|0��Ϣһ��,��������|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
	printf("************************************************************************************************************************\n");
	printf("\t\t\t\t\t���������ѡ��");
	scanf("\t\t\t\t\t%d",&itemSelected);//�����û������ѡ��
	getchar();
	return itemSelected;
}

//�򵥴ʿ�����ӵ���
//������filename��
void Addtofile(char *filename)
{
	FILE *fp;
	char d;
	char english[NUM];
	char type[NUM];
	char chinese[NUM];
	fp=fopen(filename,"a");
	if(fp==NULL)
	{
		printf("\t\t\t\t���ļ�ʧ��!\n");
		exit(0);
	}
	do{
		printf("\t\t\t\t������Ӣ�ĵ��ʣ�");
		gets(english);
		printf("\t\t\t\t��������ԣ�");
		gets(type);
		printf("\t\t\t\t������������˼:");
		gets(chinese);
		fprintf(fp, "%42s%15s%20s\n",english, type, chinese);
		printf("\t\t\t\t�������Ƿ���Ҫ��ӵ���(Y/N)��");
		scanf("%c",&d);
		getchar();
	}while(d=='y'||d=='Y');
	printf("\t\t\t\t���������Ѿ��ɹ���ӵ��ʡ�\n");
	fclose(fp);
}
//�������ܣ����ļ��е�������ʾ����Ļ��
//������filename��������ļ��еĵ��ʵ���Ļ��
void Readfromfile(char *filename)
{
	FILE *fp;
	char ch;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\t\t\t\t���ļ�ʧ�ܡ�");
		exit(0);
	}
	while(!feof(fp))
	{
		ch=fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
}
//�������ܣ�������������
//������ؼ����������ýṹ�嵥������������һ�������������������ں���������
struct wordlink *AppendWord(struct wordlink *newwords)  
{
	struct wordlink *p=NULL,*pr=newwords;//newwords��ͷ��㣬pΪ�½��Ľڵ㣬��һ��Ҫ����ӵĵ��ʡ�
	char english[NUM];
	char type[NUM];
	char chinese[NUM];
	p=(struct wordlink *)malloc(sizeof(struct wordlink));//��pָ���½��ڵ�
	if(p==NULL)//��Ϊ�½��ڵ������ڴ�ʧ�ܣ����˳�����
	{
		printf("\t\t\t\tΪ�½��ڵ����붯̬�ڴ�ʧ�ܣ�");
		exit(0);
	}
	if(newwords==NULL)//��ԭ���ʱ�Ϊ�ձ�
	{
		newwords=p;
	}
	else
	{
		while(pr->pnext != NULL)
		{
			pr=pr->pnext;  //��prָ����һ���ڵ�
		}
		pr->pnext=p;       //��ĩ�ڵ��ָ��ָ���½�����
	}
	printf("\t\t\t\t����������Ҫ��ӵĵ���Ӣ�ģ�");
	gets(english);
	printf("\t\t\t\t���Ĵ��ԣ�");
	gets(type);
	printf("\t\t\t\t����������˼��");
	gets(chinese);
	p->e=strdup(english);//strdupΪ�������������Խ���������ݿ�����p->eָ��ĵ�ַ������ֵ
	p->t=strdup(type);
	p->c=strdup(chinese);
	p->pnext=NULL;
	return newwords; //��������˵��ʺ��ͷָ��
} 
//�������ܣ��������뵥�ʵ�����������
//������count�����ô˺����ɼ���ó������������ж��ٽڵ㲢���ظýڵ�ֵ���������С�
struct wordlink *Setup(struct wordlink *newwords,int *count)
{
	char d;
	*count=0;
	do
	{
		newwords=AppendWord(newwords);
		printf("\t\t\t\t��Ҫ�������뵥����(Y/N)��");
		scanf("%c",&d);
		getchar();
		*count = *count + 1;
	}while(d=='y'|| d=='Y');
	return newwords;
}
//�������ܣ������������еĵ���д�����ʱ�newwords�����ñ���
//�������ļ�����count��
void  WriteToNewWordsFile(struct wordlink *newwords,char *filename,int count)
{
	FILE *fp;
	int i=0;
	struct wordlink *p = newwords;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("\t\t\t\t���ļ�ʧ�ܡ�");
		exit(0);
	}
	fprintf(fp,"\t\t\t\t\t________________\n");
	fprintf(fp,"\t\t\t\t\t|�ܹ���%d������|\n", count);//�������������еĽڵ���������빲�ж��ٵ��������ʱ���
	fprintf(fp,"\t\t\t\t\t~~~~~~~~~~~~~~~~\n");
	while(p)
	{
		fprintf(fp,"%20s%8s%25s",p->e,p->t,p->c);//�����������еĵ���д�����ʱ���
		p = p->pnext;
		i++;
		if(i%2==0)fprintf(fp, "\n");//�˾����������ʱ���ÿ��д����������Ϣ
	}
	fclose(fp);
	printf("\t\t\t\t�ɹ�д���ļ�!\n");
}
//�������ܣ�������ʱ��еĵ���
void PutoutNewWords(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	printf("\n");
	for(;p!=NULL;p=p->pnext)
	{
		printf("%20s%10s%25s\n",p->e,p->t,p->c);
	}
}
//�������ܣ���Ӣ�Ĳ������ʿ��еĵ���
void Searchbyenglish(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	int i=0;
	char chazhao[NUM];
	printf("\t\t\t\t����������Ҫ���ҵĵ��ʵ�Ӣ��:");
	gets(chazhao);
	for(;p != NULL;p=p->pnext)
	{
		if(strcmp(p->e,chazhao)==0)//����Ƚ����������еĵ��ʣ�Ѱ���Ƿ����û���Ҫ���ҵĵ���
		{
			printf("\t\t\t\t%s\n",p->c);
			i=1;
		}
	}
	if(i==0)
	{
		printf("\t\t\t\t������˼��û������Ҫ���ҵĵ��ʡ�");
	}
}
//�����Ĳ������ʿ��еĵ���
void Searchbychinese(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	int i=0;
	char chazhao[NUM];
	printf("\t\t\t\t����������Ҫ���ҵĵ��ʵ�����:");
	gets(chazhao);
	for(;p!=NULL;p=p->pnext)
	{
		if(strstr(p->c,chazhao))//strstr�������ԱȽ�chazhao��ֵַ����������ǲ�������p->cָ��ĵ�ַ������ݵ��Ӽ�
		{
			printf("\t\t\t\t%s\n",p->e);
			i=1;
		}
	}
	if(i==0)
	{
		printf("\t\t\t\t������˼��û������Ҫ���ҵĵ��ʡ�");
	}
}
//�������ܣ����ҵ������������˳�򣬷���һ�������˽ڵ�˳������������ͷָ��
//������������еĵ��ʲ��������������������������������Ľڵ�ģ��ŵ���ʵ��ÿ�ν��е��ʲ��Ե����������
void Outoforder(struct wordlink *newwords,int count)
{
	int i,j,k;
	char *temp1;
	char *temp2;
	char *temp3;
	struct wordlink *p = newwords;
	struct wordlink *pr = newwords;
	srand(time(NULL));
	for(i=0;i<(int)(count/3);i++)
	{
		j=rand() % count + 1;
		for(k=1;k<j-1;k++)
		{
			pr=pr->pnext;
		}
		p = pr->pnext;
		temp1=p->e;
		p->e=pr->e;
		pr->e=temp1;
		temp2=p->t;
		p->t=pr->t;
		pr->t=temp2;
		temp3=p->c;
		p->c=pr->c;
		pr->c=temp3;
		pr = newwords;
	}
}
//�������ܣ��������һ��1��4�е�������������ظ��������ֵ��
int CreateRandNumber(void)
{
	int m;
	srand(time(NULL));
	m=rand() % 4 + 1;
	return m;
}

//�������ܣ����û�����˵��ʲ��ԣ��������һ�������䡣
void rightcourage(int (*CreateRandNumber)(void))
{
	int m=CreateRandNumber();//�����˺���int CreateRandNumber(void)
	switch(m)
	{
		case 1:printf("\t\t\t\t���ϲ���Ŷ������ˡ�\n");
			break;
		case 2:printf("\t\t\t\t�����������ѧ��!\n");
			break;
		case 3:printf("\t\t\t\t��ôţ�Ƶ��𣿣����ˡ�\n");
			break;
		case 4:printf("\t\t\t\t����Ĳ�֪���룡����\n");
			break;
		default:printf("\t\t\t\t���ѹ����������г����˴���!\n");
	}
}

//�������ܣ����û�����˵��ʲ��ԣ��������һ�������䡣
void errorcourage(int (*CreateRandNumber)(void))
{
	int m=CreateRandNumber();//�����˺���int CreateRandNumber(void)
	switch(m)
	{
		case 1:printf("\t\t\t\t���ͣ��´ο϶��ܴ�ԣ�\n");
			break;
		case 2:printf("\t\t\t\t��Ҫ�����������У�\n");
			break;
		case 3:printf("\t\t\t\tŬ������ȥ��Ϊ����ͬѧ��\n");
			break;
		case 4:printf("\t\t\t\tС��һ�⣬���ⲻ��������\n");
			break;
		default:printf("\t\t\t\t���ѹ����������г����˴���!\n");
	}					
}
//�������ܣ��������ʱ��Ĳ��ԡ�
//�ò���10��������Ϊһ��С�ֻ�
void Test(struct wordlink *newwords)
{
	int flag;        
	int j=0;      
	int i=0;         //����i��Ϊ�˱������������Ƴ�����ĿΪһ��ѭ��
	char d;
	char answer[NUM];
	struct wordlink *p=newwords;
	srand(time(NULL));
	do{
		for(;p!=NULL;p=p->pnext)
		{
			i++;
			flag=rand() % 2 + 1;
			if(flag==1)//����Ӣ��������ĵĲ���
			{
				printf("%20s%10s",p->e,p->t);
				printf("\t\t\t\t����:");
				gets(answer);
				if(strstr(p->c,answer))
				{
					rightcourage(CreateRandNumber);
				}
				else
				{
					errorcourage(CreateRandNumber);
				}
			}
			if(flag==2)
			{
			   	printf("%20s%10s",p->c,p->t);
				printf("\t\t\t\tӢ��:");
				gets(answer);
				if(strcmp(p->e,answer)==0)
			{
				rightcourage(CreateRandNumber);//�����û���Ժ�Ĺ������
			}
			else
			{
				errorcourage(CreateRandNumber);//�����û�����Ĺ������
			} 	
			}
			if(i%10==0)//����10����ĿΪһ�������ֻ�
			{	
				printf("\t\t\t\tb����񫣿��ûѧ��������Ҫ�ţ����ⲻ��Ҫ������һ�ѣ�(y/n)��");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t���Խ������ڴ����´�������\n");
					return;
				}
				else if(d=='Y'||d=='y')
				{
					j=1;
				}
			}
		}
	}while(j==1);
}
//�������ܣ��������ʱ��Ĳ���(Ӣ����)
//�ò���5����ĿΪһ��С�ֻ�
void Etest(struct wordlink *newwords)
{
	int j=0;
	int i=0;
	char d;
	char answer[NUM];
	struct wordlink *p=newwords;
	do{
		for(;p!=NULL;p=p->pnext)
		{
			i++;
			printf("%20s%10s",p->e,p->t);
			printf("\t\t\t\t����:");
			gets(answer);
			if(strstr(p->c,answer))
			{
				rightcourage(CreateRandNumber);
			}
			else
			{
				errorcourage(CreateRandNumber);
			}
			if(i%5==0)//�����嵽��Ŀ����Ϊһ�������ֻ�
			{
				printf("\t\t����񫣿��ûѧ��������Ҫ�ţ����ⲻ��Ҫ������һ�ѣ�(y/n)��");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t���Խ������ڴ����´�������\n");
					return;
				}
				else if(d=='Y'||d=='y')
				{
					j=1;
				}

			}
		}
	}while(j==1);
}
//�������ܣ��������ʱ��Ĳ���(����Ӣ)
//�ò���5����ĿΪһ��С�ֻ�
void Ctest(struct wordlink *newwords)
{
	int i=0;
	int j=0;
	char d;
	char answer[NUM];
	struct wordlink *p=newwords;
	do{
		for(;p!=NULL;p=p->pnext)
		{
			i++;
			printf("%20s%10s",p->c,p->t);
			printf("\t\t\t\tӢ��:");
			gets(answer);
			if(strcmp(p->e,answer)==0)
			{
				rightcourage(CreateRandNumber);
			}
			else
			{
				errorcourage(CreateRandNumber);
			} 	
		
			if(i%5==0)
			{
				printf("\t\t\t\t����񫣿��ûѧ��������Ҫ�ţ����ⲻ��Ҫ������һ�ѣ�(y/n)��");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t���Խ������ڴ����´�������\n");
					return;
				}
				else if(d=='Y'||d=='y')
				{
					j=1;
				}
			}
		}
	}while(j==0);
}
//�������ܣ��ͷ�newwordsָ������������еĽڵ���ռ�õ��ڴ�
//ǰ�����Ϊ�µĽڵ������˶�̬�ռ��ڴ棬���µ����Ѿ�д��������������ʱ����͸ð�����Ķ�̬�ڴ��ͷŵ�
void DeleteMemory(struct wordlink *newwords)
{
	struct wordlink *p=newwords,*pr=NULL;
	while(p!=NULL)
	{
		pr=p;
		p=p->pnext;
		free(pr);
	}
}
//�������ܣ������������������㱳����С���ߵ������Ϣ(��������ƣ���������Ϣ���汾��Ϣ������ʱ��)
void About(void)
{
	printf("\n\n\n\n\t\t|��������|:\t\t\t���㱳����С����\n");
	printf("\t\t~~~~~~~~~~~ \t\t\t^^^^^^^^^^^^^^^^\n\n");
	printf("\t\t|�汾��Ϣ|:\t\t\t���װ�\n");
	printf("\t\t~~~~~~~~~~ \t\t\t^^^^^^\n\n");
	printf("\t\t|����ʱ��|:\t\t\t2018��1��19��\n");
	printf("\t\t~~~~~~~~~~ \t\t\t^^^^^^^^^^^^^\n\n");
	printf("\t\t|��������Ϣ|:   \t\t����:����    ѧ��:8002117337  רҵ:������� �༶:���˰�\n");
	printf("\t\t~~~~~~~~~~~~    \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t                \t\t����:���ӽ�  ѧ��:8002117321  רҵ:������� �༶:���˰�\n");
	printf("\t\t                \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t                \t\t����:���ҳ�  ѧ��:8002117305  רҵ:������� �༶:���˰�\n");
	printf("\t\t                \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

}
//�������ܣ��������������Ĺ���˵����ʹ��˵��
void Help(void)
{
	printf("\n\n\n\t\t#|���㱳����С���ߵĹ���˵��|��\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t����һ�����׵ı�����С���ߣ��û������������С�������������ѧ��Ӣ�ﵥ�ʵĽ��б���\n");
	printf("\t\t�����û����Ը�ϰ���ʿ����Ѿ��еĵ��ʣ�ѡ������ĵ��ʽ��б��С���������ѧ�ĵ��ʣ���\n");
	printf("\t\t�ǵ��ʿ��еĵ��ʣ����û�����֮���û������԰Ѳ���ĵ���ѡ��������һ�����ʱ������м�\n");
	printf("\t\t�м��䡣���������½������ʱ��н��е��ʲ�ѯ��ͬʱ���û����������ô˳�����е��ʲ��ԡ�\n");
	printf("\t\t�Լ���Լ��ı����ʳ�Ч��������䡣\n\n");
	printf("\t\t#|���㱳����С���ߵ�ʹ��˵��|��\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t��ʹ���������ʱ��Ҫ��ȷ��ʹ�ô˳�����û��ĵ�������һ����Ϊ'vocabulary.txt'���ı�\n");
	printf("\t\t�ļ����ر�ģ�������Ҫ������ı��ļ�������D���С���������ʿ���ǰ�ʹ洢�źܶ�ĵ���\n");
	printf("\t\t�û�����ʹ�ó���򿪵��ʿ⣬�鿴����ĵ��ʣ�������ļ���û��Ҳû��ϵ��ֻ�ǲ鿴�õ�\n");
	printf("\t\t�ʿ��ǻῴ�������ʶ��ѣ������û�������ʹ�ù�������õ��ʿ�����ӵ��ʣ��𲽷ḻ����\n");
	printf("\t\t��ĵ�������ͬʱ�û���֪�������û�ʹ�õ��ʲ�ѯ�͵��ʲ��Թ���ʱ��һ��Ҫ��ȷ���û���\n");
	printf("\t\t�Ѿ����������ʱ������ÿ�δ��������ʱ�����������ʮ�����������ʱ��û�ֻ�谴�ճ����\n");
	printf("\t\t�ʿ�ĵ��ʵ���Ӻ�ɾ�������ڵ��ʲ�ѯ���ߵ��ʲ��ԣ��û�ֻ��Ҫ���ݳ�����ʾ�����Ϳ���.\n");
	printf("\t\t������ʾ�����ˡ����û��Ѿ���Ϥ�˳���ĵ��ʿ�ʱ���û�Ҳ���Լ��򿪵��ʿ��ļ������е�\n");
	printf("\t\t����û���ʹ�ô˳���ʱ�����˲��淶�����뵼�³����������У��û�ֻ��Ҫǿ�йرճ���\n");
	printf("\t\t���ɡ�����û���������˳����û���ð��˵������һ���˳����򡣱������ź���һ�㣬\n");
	printf("\t\t���û��ر��˳��򣬵��û��ٴδ򿪴˳�����û��������´������ʱ��ſ������½��е���\n");
}
