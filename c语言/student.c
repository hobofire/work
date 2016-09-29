#include<stdio.h>
#include<stdlib.h>
struct Student{
    char name[20];
    char id[10];
    char sex[5];
    char birth[6];
    char majon[20];
    char classes[6];
    char address[30];
    char dormnum[8];
    struct Student* next;
};

void save();
void ll();
void cx();
void add();
void sc();
void xg();
void exit();

void main()
{
    int i;
    printf("-----------------------------您好,欢迎使用学生管理系统-------------------------\n");
    if(p==NULL)
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+        学生信息管理系统      |\n");
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+       这是第一次使用该系统，你的选择是          |\n");
        printf("\t\t\t+      1.录入学生信息          |\n");
        printf("\t\t\t+      0.退出系统              |\n");
    else
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+        学生信息管理系统      |\n");
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+      1.录入学生信息          |\n");
        printf("\t\t\t+      2.浏览学生信息          |\n");
        printf("\t\t\t+      3.查询学生信息          |\n");
        printf("\t\t\t+      4.删除学生信息          |\n");
        printf("\t\t\t+      5.修改学生信息          |\n");
        printf("\t\t\t+      0.退出系统              |\n");
        printf("\t\t\t+*·*·*·*·*·*·*·*·*·*·|\n");
        printf("\t\t\t+ 本系统由郑智韦设计与制作\n")
        printf("\t\t\t--------------------------------\n");
        printf("请输入你想要选择的相应数字\n");
    scanf("%d",i);
    switch(i)
    {
        case 1: add(student* p);break;
        case 2: ll();break;
        case 3: cx();break;
        case 4: sc();break;
        case 5: xg();break;
        case 0: exit(0);
        default printf("请输入正确的数字进行选择");
    }
}

void save()
{
    if((fp=fopen("student.txt","wb"))==NULL)
    {
        printf("无法打开文件!\n任意键退出程序... ...\n");
        getch();
        return 0;
    }
    for(i=0;i<n;i++)
        if(stu[i].ave!=0)
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
                printf("文件写入发生错误\n");
    fclose(fp);
    return 0;



}
ll()
{
    display
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        学生基本信息      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("学号\t姓名\t性别\t出生年月\t专业\t班级\t寝室号\n");
    while(head!=NULL)
        printf("")
        p = p->pEnd.next;
    printf("\n",);
}
add()
{   if(p==NULL)
        {
        student* head = NUll;
        student* p;
        student* pEnd;
        p=malloc(student);
        printf("请输入学生的姓名:  ");
        scanf("%s",p.name);
        printf("请输入学生的学号:");
        scanf("%s",p.id);
        printf("请输入学生的性别:  ");
        scanf("%c",p.sex);
        printf("请输入学生的出生年月:  ");
        scanf("%s",p.birth);
        printf("请输入学生的专业:  ");
        scanf("%s",p.marjon);
        printf("请输入学生的班级:  ");
        scanf("%s",p.classes);
        printf("请输入学生的地址:  ");
        scanf("%c",p.address;
        printf("请输入学生的寝室号:  ");
        scanf("%c",p.dormnum);
        save(p);
        }
    while(p->d!=0)
    {
        if(head = NULLL)
        head = p;
        else pEnd->next=p;
        pEnd=p;
        p=;

    }
}
cx()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        学生信息管理系统      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        查询学生信息      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+      1.根据学号查询        |\n");
    printf("\t\t\t+      2.根据姓名查询        |\n");
    scanf("%d",i);
    if(i==1)
    {
        printf("请输入你要查询的学号\n");
        sanf("");
        while(student.id==x)
            pEnd=pEnd->nexr;
        print("\n");
    }
    else
    {
        if(i==2)
        {
            printf("请输入你要查询的姓名\n");
            scanf("");
            for(n=0,student.name==name,pEnd=pEnd->next);
            {
                print("\n");
            }
            print("一共找到%d个结果\n",n);
        }
        else
            print("请输入正确的选择\n");
    }
}
sc()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        学生信息管理系统      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("请输入你要删除的学号\n");
    scanf("",id);
    while(id!=id)
        pEnd=pEnd->next;
    printf("确定要删除它吗\n");



}
xg()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        学生信息管理系统      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("请输入你要修改的学号\n");
    scanf("");
    while(id!=id)
        pEnd=pEnd->next;

}
exit()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        学生信息管理系统      |\n");
    printf("\t\t\t--------------------------------\n");
    print("感谢您的使用\n");

}

