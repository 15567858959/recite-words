#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM  30    //字符串的最大长度

int Menu(void);         //目录函数
void Addtofile(char *filename); //向单词库中添加单词
struct wordlink *AppendWord(struct wordlink *newwords);//创建生词链表
void DeleteMemory(struct wordlink *newwords);//释放newwords指向的链表中所有的节点所占用的内存
void PutoutNewWords(struct wordlink *newwords);//输出生词表中的单词
void Searchbyenglish(struct wordlink *newwords); //按英文查找生词库中的单词
void Searchbychinese(struct wordlink *newwords);//按中文查找生词库中的单词
void Readfromfile(char *filename);//将文件中的数据显示在屏幕上
int CreateRandNumber(void);//随机产生一个1到4中的随机数
void rightcourage(int (*CreateRandNumber)(void));//答对了随机给出鼓励语句
void errorcourage(int (*CreateRandNumber)(void));//答错了随机给出鼓励语句。
void Outoforder(struct wordlink *newwords,int count);//打乱单向单词链表的顺序
void WriteToNewWordsFile(struct wordlink *newwords,char *filename,int count);//将生词链表中的单词写进生词本newwords中永久保存
void Test(struct wordlink *newwords);//进行生词本的测试。
void Ctest(struct wordlink *newwords);//进行生词本的测试(中译英)
void Etest(struct wordlink *newwords);//进行生词本的测试(英译中)
struct wordlink *Setup(struct wordlink *newwords,int *count);//持续输入单词到生词链表中
void About(void);//用于输出关于这个迷你背单词小工具的相关信息(如程序名称，开发者信息，版本信息，开发时间)
void Help(void);//用于输出本程序的功能说明和使用说明

struct wordlink               //定义了一个拥有四个指针变量的结构体单向链表
{
	char *e;                  //后来用于指向单词英文意思数组
	char *t;                  //后来用于指向单词词性数组
	char *c;                  //后来用于指向单词中文意思数组
	struct wordlink *pnext;   //指向下一个结构体单向链表
};  

int main()
{
	int count=0;
	int h;
	struct wordlink *newwords=NULL;
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t同学，你好。\n");
	printf("\t\t\t\t\t\t遇见你，很幸运!\n\n\n");
	printf("\t\t\t\t\t|程序名称|:\t迷你背单词小工具\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t|版本信息|:\t简易版\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^\n");
	printf("\t\t\t\t\t|开发时间|:\t2018年1月19日\n");
	printf("\t\t\t\t\t~~~~~~~~~~ \t^^^^^^^^^^^^^\n\n");
	printf("\t\t\t\t\t请按ENTER键进入美妙的学习之旅途吧");
	getchar();
	system("cls");
	while(1)
	{
		h=Menu();    //显示菜单，并读取用户输入
		switch(h)
		{
		case 1:system("cls");
			printf("\n\t\t\t\t您现在进行的是输入单词到单词库的操作\n");
			Addtofile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 2:system("cls");
			Readfromfile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 3:system("cls");
			Readfromfile("D:\\vocabulary.txt");
			printf("\n\t\t\t\t您现在进行的是创建生词本的操作\n");
			newwords=Setup(newwords,&count);
			WriteToNewWordsFile(newwords,"D:\\newwords.txt",count);
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 4:Readfromfile("D:\\newwords.txt");
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 5:system("cls");
			Outoforder(newwords,count);
			Ctest(newwords);
			printf("\n\t\t\t\t请输入ENTER键接着进行学习:");
			getchar();
			break;
		case 6:system("cls");
			Outoforder(newwords,count);
			Etest(newwords);
			printf("\n\t\t\t\t清输入ENTER键接着进行学习:");
			getchar();
			break;
		case 7:system("cls");
			Outoforder(newwords,count);
			Test(newwords);
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 8:system("cls");
			Searchbychinese(newwords); 
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 9:system("cls");
			Searchbyenglish(newwords);
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 10:system("cls");
			About();
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 11:system("cls");
			Help();
			printf("\n\t\t\t\t输入ENTER键接着进行学习:");
			getchar();
			break;
		case 0:system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t背累了吧同学。休息一下也好。\n\n");
			printf("\t\t\t\t\t离别是为了更美好的相遇。\n\n");
			printf("\t\t\t\t\t期待我们的再次遇见。\n\n");
			printf("\t\t\t\t\t\t\t\t\t-----迷你背单词小工具\n");
			DeleteMemory(newwords);
	        exit(0);
		default:("\t\t\t\t不好意思，您的输入操作产生了错误。");
		}
	}
	return 0;
}

//函数功能：显示菜单并获得用户输入
int Menu(void)
{
	int itemSelected;
	system("cls");
	printf("\t\t\t\t\t\t#________________________#\n");
	printf("\t\t\t\t\t\t|*|<<迷你背单词小工具>>|*|\n");
	printf("\t\t\t\t\t\t#------------------------#\n");
	printf("\t\t\t\t\t*|1增加单词库中的单词|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|2查看单词库的单词|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|3创建你独享的生词本|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|4查看你独享的生词本|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|5生词测试(中译英)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|6生词测试(英译中)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|7生词测试(中英掺杂组合拳)|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|8按中文意思查找生词本中的单词|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|9按英文查找生词本中的单词|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\t\t*|10关于|\n");
	printf("\t\t\t\t\t^^^^^^^^^\n");
	printf("\t\t\t\t\t*|11帮助|\n");
	printf("\t\t\t\t\t^^^^^^^^^\n");
	printf("\t\t\t\t\t*|0休息一下,结束程序|\n");
	printf("\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
	printf("************************************************************************************************************************\n");
	printf("\t\t\t\t\t请输入你的选择：");
	scanf("\t\t\t\t\t%d",&itemSelected);//读入用户输入的选择
	getchar();
	return itemSelected;
}

//向单词库中添加单词
//参数：filename。
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
		printf("\t\t\t\t打开文件失败!\n");
		exit(0);
	}
	do{
		printf("\t\t\t\t请输入英文单词：");
		gets(english);
		printf("\t\t\t\t请输入词性：");
		gets(type);
		printf("\t\t\t\t请输入中文意思:");
		gets(chinese);
		fprintf(fp, "%42s%15s%20s\n",english, type, chinese);
		printf("\t\t\t\t请问您是否还需要添加单词(Y/N)：");
		scanf("%c",&d);
		getchar();
	}while(d=='y'||d=='Y');
	printf("\t\t\t\t完美，你已经成功添加单词。\n");
	fclose(fp);
}
//函数功能：将文件中的数据显示在屏幕上
//参数：filename。输出了文件中的单词到屏幕中
void Readfromfile(char *filename)
{
	FILE *fp;
	char ch;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\t\t\t\t打开文件失败。");
		exit(0);
	}
	while(!feof(fp))
	{
		ch=fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
}
//函数功能：创建生词链表
//本程序关键函数，利用结构体单向链表，创建了一个单向生词链表。以用于后续操作。
struct wordlink *AppendWord(struct wordlink *newwords)  
{
	struct wordlink *p=NULL,*pr=newwords;//newwords是头结点，p为新建的节点，即一个要新添加的单词。
	char english[NUM];
	char type[NUM];
	char chinese[NUM];
	p=(struct wordlink *)malloc(sizeof(struct wordlink));//让p指向新建节点
	if(p==NULL)//若为新建节点申请内存失败，则退出程序
	{
		printf("\t\t\t\t为新建节点申请动态内存失败！");
		exit(0);
	}
	if(newwords==NULL)//若原生词表为空表
	{
		newwords=p;
	}
	else
	{
		while(pr->pnext != NULL)
		{
			pr=pr->pnext;  //让pr指向下一个节点
		}
		pr->pnext=p;       //让末节点的指针指向新建生词
	}
	printf("\t\t\t\t请输入你想要添加的单词英文：");
	gets(english);
	printf("\t\t\t\t它的词性：");
	gets(type);
	printf("\t\t\t\t它的中文意思：");
	gets(chinese);
	p->e=strdup(english);//strdup为拷贝函数，可以将词组的数据拷贝到p->e指向的地址的数据值
	p->t=strdup(type);
	p->c=strdup(chinese);
	p->pnext=NULL;
	return newwords; //返回添加了单词后的头指针
} 
//函数功能：持续输入单词到生词链表中
//参数：count。利用此函数可计算得出生词链表中有多少节点并返回该节点值到主函数中。
struct wordlink *Setup(struct wordlink *newwords,int *count)
{
	char d;
	*count=0;
	do
	{
		newwords=AppendWord(newwords);
		printf("\t\t\t\t还要接着输入单词吗？(Y/N)：");
		scanf("%c",&d);
		getchar();
		*count = *count + 1;
	}while(d=='y'|| d=='Y');
	return newwords;
}
//函数功能：将生词链表中的单词写进生词本newwords中永久保存
//参数：文件名，count。
void  WriteToNewWordsFile(struct wordlink *newwords,char *filename,int count)
{
	FILE *fp;
	int i=0;
	struct wordlink *p = newwords;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("\t\t\t\t打开文件失败。");
		exit(0);
	}
	fprintf(fp,"\t\t\t\t\t________________\n");
	fprintf(fp,"\t\t\t\t\t|总共有%d个单词|\n", count);//利用生词链表中的节点个数，输入共有多少单词在生词表中
	fprintf(fp,"\t\t\t\t\t~~~~~~~~~~~~~~~~\n");
	while(p)
	{
		fprintf(fp,"%20s%8s%25s",p->e,p->t,p->c);//将生词链表中的单词写入生词本中
		p = p->pnext;
		i++;
		if(i%2==0)fprintf(fp, "\n");//此举意在让生词本中每行写两个单词信息
	}
	fclose(fp);
	printf("\t\t\t\t成功写入文件!\n");
}
//函数功能：输出生词表中的单词
void PutoutNewWords(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	printf("\n");
	for(;p!=NULL;p=p->pnext)
	{
		printf("%20s%10s%25s\n",p->e,p->t,p->c);
	}
}
//函数功能：按英文查找生词库中的单词
void Searchbyenglish(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	int i=0;
	char chazhao[NUM];
	printf("\t\t\t\t请输入你想要查找的单词的英文:");
	gets(chazhao);
	for(;p != NULL;p=p->pnext)
	{
		if(strcmp(p->e,chazhao)==0)//逐个比较生词链表中的单词，寻找是否有用户需要查找的单词
		{
			printf("\t\t\t\t%s\n",p->c);
			i=1;
		}
	}
	if(i==0)
	{
		printf("\t\t\t\t不好意思，没有你想要查找的单词。");
	}
}
//按中文查找生词库中的单词
void Searchbychinese(struct wordlink *newwords)
{
	struct wordlink *p=newwords;
	int i=0;
	char chazhao[NUM];
	printf("\t\t\t\t请输入你想要查找的单词的中文:");
	gets(chazhao);
	for(;p!=NULL;p=p->pnext)
	{
		if(strstr(p->c,chazhao))//strstr函数可以比较chazhao地址值里面的数据是不是属于p->c指向的地址里的数据的子集
		{
			printf("\t\t\t\t%s\n",p->e);
			i=1;
		}
	}
	if(i==0)
	{
		printf("\t\t\t\t不好意思，没有你想要查找的单词。");
	}
}
//函数功能：打乱单向生词链表的顺序，返回一个打乱了节点顺序的生词链表的头指针
//本程序后续进行的单词测试正是依靠这个函数打乱了生词链表的节点的，才得以实现每次进行单词测试得以随机出题
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
//函数功能：随机产生一个1到4中的随机数，并返回该随机数的值。
int CreateRandNumber(void)
{
	int m;
	srand(time(NULL));
	m=rand() % 4 + 1;
	return m;
}

//函数功能：当用户答对了单词测试，随机给出一句鼓励语句。
void rightcourage(int (*CreateRandNumber)(void))
{
	int m=CreateRandNumber();//调用了函数int CreateRandNumber(void)
	switch(m)
	{
		case 1:printf("\t\t\t\t哎呦不错哦，答对了。\n");
			break;
		case 2:printf("\t\t\t\t厉害了优秀大学生!\n");
			break;
		case 3:printf("\t\t\t\t这么牛逼的吗？！对了。\n");
			break;
		case 4:printf("\t\t\t\t佩服的不知所措！！！\n");
			break;
		default:printf("\t\t\t\t很难过，程序运行出现了错误!\n");
	}
}

//函数功能：当用户答错了单词测试，随机给出一句鼓励语句。
void errorcourage(int (*CreateRandNumber)(void))
{
	int m=CreateRandNumber();//调用了函数int CreateRandNumber(void)
	switch(m)
	{
		case 1:printf("\t\t\t\t加油，下次肯定能答对！\n");
			break;
		case 2:printf("\t\t\t\t不要放弃，你能行！\n");
			break;
		case 3:printf("\t\t\t\t努力啊，去成为优秀同学！\n");
			break;
		case 4:printf("\t\t\t\t小错一题，问题不大。下题稳\n");
			break;
		default:printf("\t\t\t\t很难过，程序运行出现了错误!\n");
	}					
}
//函数功能：进行生词本的测试。
//该测试10道测试题为一个小轮回
void Test(struct wordlink *newwords)
{
	int flag;        
	int j=0;      
	int i=0;         //定义i是为了便于下面程序控制出几道目为一个循环
	char d;
	char answer[NUM];
	struct wordlink *p=newwords;
	srand(time(NULL));
	do{
		for(;p!=NULL;p=p->pnext)
		{
			i++;
			flag=rand() % 2 + 1;
			if(flag==1)//进行英翻译成中文的测试
			{
				printf("%20s%10s",p->e,p->t);
				printf("\t\t\t\t中文:");
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
				printf("\t\t\t\t英文:");
				gets(answer);
				if(strcmp(p->e,answer)==0)
			{
				rightcourage(CreateRandNumber);//给出用户答对后的鼓励语句
			}
			else
			{
				errorcourage(CreateRandNumber);//给出用户答错后的鼓励语句
			} 	
			}
			if(i%10==0)//控制10道题目为一个测试轮回
			{	
				printf("\t\t\t\tb不过瘾？！没学够？！不要慌，问题不大。要不再来一把？(y/n)：");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t测试结束，期待你下次再来。\n");
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
//函数功能：进行生词本的测试(英译中)
//该测试5道题目为一个小轮回
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
			printf("\t\t\t\t中文:");
			gets(answer);
			if(strstr(p->c,answer))
			{
				rightcourage(CreateRandNumber);
			}
			else
			{
				errorcourage(CreateRandNumber);
			}
			if(i%5==0)//控制五到题目测试为一个测试轮回
			{
				printf("\t\t不过瘾？！没学够？！不要慌，问题不大。要不再来一把？(y/n)：");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t测试结束，期待你下次再来。\n");
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
//函数功能：进行生词本的测试(中译英)
//该测试5道题目为一个小轮回
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
			printf("\t\t\t\t英文:");
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
				printf("\t\t\t\t不过瘾？！没学够？！不要慌，问题不大。要不再来一把？(y/n)：");
				scanf("%c",&d);
				getchar();
				if(d=='n' || d=='N')
				{
					printf("\t\t\t\t测试结束，期待你下次再来。\n");
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
//函数功能：释放newwords指向的链表中所有的节点所占用的内存
//前面程序为新的节点申请了动态空间内存，当新单词已经写入生词链表和生词本，就该把申请的动态内存释放掉
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
//函数功能：用于输出关于这个迷你背单词小工具的相关信息(如程序名称，开发者信息，版本信息，开发时间)
void About(void)
{
	printf("\n\n\n\n\t\t|程序名称|:\t\t\t迷你背单词小工具\n");
	printf("\t\t~~~~~~~~~~~ \t\t\t^^^^^^^^^^^^^^^^\n\n");
	printf("\t\t|版本信息|:\t\t\t简易版\n");
	printf("\t\t~~~~~~~~~~ \t\t\t^^^^^^\n\n");
	printf("\t\t|开发时间|:\t\t\t2018年1月19日\n");
	printf("\t\t~~~~~~~~~~ \t\t\t^^^^^^^^^^^^^\n\n");
	printf("\t\t|开发者信息|:   \t\t姓名:黄龙    学号:8002117337  专业:软件工程 班级:软工八班\n");
	printf("\t\t~~~~~~~~~~~~    \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t                \t\t姓名:张子健  学号:8002117321  专业:软件工程 班级:软工八班\n");
	printf("\t\t                \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t                \t\t姓名:刘家成  学号:8002117305  专业:软件工程 班级:软工八班\n");
	printf("\t\t                \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

}
//函数功能：用于输出本程序的功能说明和使用说明
void Help(void)
{
	printf("\n\n\n\t\t#|迷你背单词小工具的功能说明|：\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t这是一个简易的背单词小工具，用户可以利用这个小程序进行输入新学的英语单词的进行背诵\n");
	printf("\t\t或者用户可以复习单词库中已经有的单词，选出不会的单词进行背诵。不管是新学的单词，还\n");
	printf("\t\t是单词库中的单词，在用户背诵之后用户都可以把不会的单词选出来创建一个生词本，进行集\n");
	printf("\t\t中记忆。并可以在新建的生词本中进行单词查询，同时，用户还可以利用此程序进行单词测试。\n");
	printf("\t\t以检测自己的背单词成效并加深记忆。\n\n");
	printf("\t\t#|迷你背单词小工具的使用说明|：\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t在使用这个程序时，要先确保使用此程序的用户的电脑中有一个名为'vocabulary.txt'的文本\n");
	printf("\t\t文件，特别的，本程序要求这个文本文件存在在D盘中。且这个单词库先前就存储着很多的单词\n");
	printf("\t\t用户可以使用程序打开单词库，查看里面的单词，如果该文件里没有也没关系，只是查看该单\n");
	printf("\t\t词库是会看不到单词而已，但是用户可以在使用过程中想该单词库中添加单词，逐步丰富单词\n");
	printf("\t\t库的单词量。同时用户需知道，在用户使用单词查询和单词测试功能时，一定要先确保用户您\n");
	printf("\t\t已经创建了生词本，最好每次创建的生词本单词量大于十个。创建单词本用户只需按照程序给\n");
	printf("\t\t词库的单词的添加和删除。至于单词查询或者单词测试，用户只需要根据程序提示操作就可以.\n");
	printf("\t\t出的提示就行了。当用户已经熟悉此程序的单词库时，用户也可自己打开单词库文件，进行单\n");
	printf("\t\t如果用户在使用此程序时发生了不规范的输入导致程序不正常运行，用户只需要强行关闭程序\n");
	printf("\t\t即可。如果用户正常用完此程序，用户最好按菜单栏最后一项退出程序。本程序遗憾的一点，\n");
	printf("\t\t当用户关闭了程序，当用户再次打开此程序后，用户必须重新创建生词本才可以重新进行单词\n");
}
