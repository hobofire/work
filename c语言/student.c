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
    printf("-----------------------------����,��ӭʹ��ѧ������ϵͳ-------------------------\n");
    if(p==NULL)
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+       ���ǵ�һ��ʹ�ø�ϵͳ�����ѡ����          |\n");
        printf("\t\t\t+      1.¼��ѧ����Ϣ          |\n");
        printf("\t\t\t+      0.�˳�ϵͳ              |\n");
    else
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
        printf("\t\t\t--------------------------------\n");
        printf("\t\t\t+      1.¼��ѧ����Ϣ          |\n");
        printf("\t\t\t+      2.���ѧ����Ϣ          |\n");
        printf("\t\t\t+      3.��ѯѧ����Ϣ          |\n");
        printf("\t\t\t+      4.ɾ��ѧ����Ϣ          |\n");
        printf("\t\t\t+      5.�޸�ѧ����Ϣ          |\n");
        printf("\t\t\t+      0.�˳�ϵͳ              |\n");
        printf("\t\t\t+*��*��*��*��*��*��*��*��*��*��|\n");
        printf("\t\t\t+ ��ϵͳ��֣��Τ���������\n")
        printf("\t\t\t--------------------------------\n");
        printf("����������Ҫѡ�����Ӧ����\n");
    scanf("%d",i);
    switch(i)
    {
        case 1: add(student* p);break;
        case 2: ll();break;
        case 3: cx();break;
        case 4: sc();break;
        case 5: xg();break;
        case 0: exit(0);
        default printf("��������ȷ�����ֽ���ѡ��");
    }
}

void save()
{
    if((fp=fopen("student.txt","wb"))==NULL)
    {
        printf("�޷����ļ�!\n������˳�����... ...\n");
        getch();
        return 0;
    }
    for(i=0;i<n;i++)
        if(stu[i].ave!=0)
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
                printf("�ļ�д�뷢������\n");
    fclose(fp);
    return 0;



}
ll()
{
    display
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        ѧ��������Ϣ      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("ѧ��\t����\t�Ա�\t��������\tרҵ\t�༶\t���Һ�\n");
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
        printf("������ѧ��������:  ");
        scanf("%s",p.name);
        printf("������ѧ����ѧ��:");
        scanf("%s",p.id);
        printf("������ѧ�����Ա�:  ");
        scanf("%c",p.sex);
        printf("������ѧ���ĳ�������:  ");
        scanf("%s",p.birth);
        printf("������ѧ����רҵ:  ");
        scanf("%s",p.marjon);
        printf("������ѧ���İ༶:  ");
        scanf("%s",p.classes);
        printf("������ѧ���ĵ�ַ:  ");
        scanf("%c",p.address;
        printf("������ѧ�������Һ�:  ");
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
    printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        ��ѯѧ����Ϣ      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+      1.����ѧ�Ų�ѯ        |\n");
    printf("\t\t\t+      2.����������ѯ        |\n");
    scanf("%d",i);
    if(i==1)
    {
        printf("��������Ҫ��ѯ��ѧ��\n");
        sanf("");
        while(student.id==x)
            pEnd=pEnd->nexr;
        print("\n");
    }
    else
    {
        if(i==2)
        {
            printf("��������Ҫ��ѯ������\n");
            scanf("");
            for(n=0,student.name==name,pEnd=pEnd->next);
            {
                print("\n");
            }
            print("һ���ҵ�%d�����\n",n);
        }
        else
            print("��������ȷ��ѡ��\n");
    }
}
sc()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("��������Ҫɾ����ѧ��\n");
    scanf("",id);
    while(id!=id)
        pEnd=pEnd->next;
    printf("ȷ��Ҫɾ������\n");



}
xg()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
    printf("\t\t\t--------------------------------\n");
    printf("��������Ҫ�޸ĵ�ѧ��\n");
    scanf("");
    while(id!=id)
        pEnd=pEnd->next;

}
exit()
{
    printf("\t\t\t--------------------------------\n");
    printf("\t\t\t+        ѧ����Ϣ����ϵͳ      |\n");
    printf("\t\t\t--------------------------------\n");
    print("��л����ʹ��\n");

}

