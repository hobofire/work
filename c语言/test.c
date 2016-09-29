#include<stdio.h>
#include<string.h>
#include<stdlib.h>        //exit()��ͷ�ļ�
#include<conio.h>     //��Ļ��������
#define N 100           //����ѧ����¼������
#define M 3             //���ƿγ���
#define LEN 9
void menu();
void browse();
typedef struct student          //����ѧ���ṹ��
{
    char num[11];               //��ѧ�Ŷ�����ַ���������,һ��ѧ�ſ��ܱȽϳ���������ֱ����strcmp���Ƚϣ�ȷ������ͬ
    char name[20];
    int score[M];
    double ave;
}STU;
STU stu[N];             //����һ���ⲿѧ���ṹ�����
/*****��д�ķ�ʽ�������ݵ��ļ��ĺ�����ԭ���ݽ������ǡ�*****/
int save(int n)             //���溯��������n����¼
{
    FILE *fp;
    int i;
    if((fp=fopen("zhouhao.txt","wb"))==NULL)//�Զ�����д�ķ�ʽ�򿪣��ڴ�ǰ�ļ�¼������
    {
        printf("�޷����ļ�!\n������˳�����... ...\n");
        getch();                            //Ԥ������
        return 0;
    }
    for(i=0;i<n;i++)
        if(stu[i].ave!=0)                   //�ں����del()������ͨ����stu[i].ave=0����ʾ�ü�¼��ɾ����
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)//��ʼд���ļ�
                printf("�ļ�д�뷢������\n");
    fclose(fp);
    return 0;                       // ע��������ط� ����ֻ����㸳��ֵ��ֻ��Ϊ������һ������
}
/********���������������Ľ�һ���ļ���������һ���ļ��С�*******/
void copy()
{
    char outfile[20],infile[10];    //����Դ�ļ�����Ŀ���ļ���
    FILE *sfp,*tfp;                 //����ָ��Դ�ļ�(sourcefile)��Ŀ���ļ�(targetfile)��ָ��
    STU *p=NULL;                    //������ʱָ�룬�ݴ�����ļ�¼
    system("CLS");                  //����;
    printf("��������Ҫ�����Ƶ��ļ�����Ĭ�����ݴ�����zhouhao.txt�У�:\n");
    scanf("%s",infile);             //����Դ�ļ���
    if((sfp=fopen(infile,"rb"))==NULL)//�Զ����Ʒ�ʽ��Դ�ļ�
    {
        printf("�޷����ļ�!\n������˳�����... ...\n");//��ʾ���ܴ��ļ�����Ϣ
        getch();
        return;
    }
    printf("���Ϊ...,����:hao.txt:\n"); //��ʾ����Ŀ���ļ���
    scanf("%s",outfile);                    //����Ŀ���ļ���
        if((tfp=fopen(outfile,"wb"))==NULL)//�Զ�����д��ʽ��Ŀ���ļ�
    {
        printf("�޷����ļ�!\n\n");//��ʾ���ܴ��ļ�����Ϣ
        getch();
        return;                     //�˳�����,ͬexit(0)
    }
        while(!feof(sfp))           //���ļ�ֱ���ļ�β
            fputc(fgetc(sfp),tfp);  //��stp�����ļ���tfp
        fclose(sfp);                //�ر�Դ�ļ�
        fclose(tfp);                //�ر�Ŀ���ļ�
        printf("\n���Ƴɹ�!!!\n");  //��ʾ�����ɹ���Ϣ
        printf("\n����������������˵�");
        getch();
        menu();
}
/***�����ؼ�¼����Լ����¼�����ĺ�����***/
int load()
{
    FILE *fp;
    int i;
    if((fp=fopen("zhouhao.txt","rb"))==NULL)                            //�Զ����ƶ��ķ�ʽ��
    {
        printf("�޷����ļ�!\n������˳�����... ...\n");            //��ʾ���ܴ��ļ�����Ϣ
        getch();                                                    //Ԥ������
        return 0;
    }
    for(i=0;!feof(fp);i++)
        fread(&stu[i],sizeof(struct student),1,fp);                 //���ļ����ݶ���ѧ���ṹ��
    fclose(fp);
    return(i-1);                                                    //����Ŀǰ�ܵļ�¼������ע����i-1
}
/***��һ���������ʱ��ѡ��������Ƿ��صĺ�����***/
void printf_back()
{
    int w;
    printf("\n\t�����ɹ�!^_^\n");
    printf("\t���Ÿ�ʲô?\n\t1).�������ȫ������\t2).����:[ ]\b\b");
    scanf("%d",&w);
    if(w==1)
        browse();
    else
        menu();
}
/***����ʾ���ݽṹ��Ŀ������***/
void printf_face()
{
    printf("\n\tѧ��\t����\t\t   ��ѧ\t    Ӣ��    C����    ƽ����\n");   //��ʾ��ͷ
}
/***����ƽ���ֺ�������Ϊ�������޸�������Ҫר������ƽ����***/
void average(int i)
{
    int j,sum;
    for(sum=0,j=0;j<M;j++)
        sum+=stu[i].score[j];
    stu[i].ave=sum*1.0/M;
}
/*******��ѧ�ų��ȴ�������********/
void no_deal(int i)
{
    int j,l,a;
    l=strlen(stu[i].num);
    if(l<LEN)
    {
        for(j=LEN-l,a=0;j<LEN;j++)
        {
            stu[i].num[j]=stu[i].num[a++];
        }
        stu[i].num[i]='\0';
        for(a=0;a<LEN-l;a++)
            stu[i].num[a]='0';
    }
    if(l>LEN)
        stu[i].num[l]='\0';
}
/*******��ѧ�����뺯����*******/
int no_input(int i,int n)                           //i��ʾ��i��ѧ����Ϣ��n��ʾ�Ƚϵ���n��ѧ��
{
    int j,k,w1;
    do{
        w1=0;
        printf("ѧ��:\t\t ��%dλ,����%dλǰ�油0,���Ľ�β����!��\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",LEN,LEN);
        scanf("%s",stu[i].num);
        no_deal(i);
        for(j=0;stu[i].num[j]!='\0';j++)                    //ѧ�����뺯���������ϸ�Ĺ涨
            if(stu[i].num[j]<'0' || stu[i].num[j]>'9')        //�ж�ѧ���Ƿ�Ϊ����
            {
                puts("����Ц!ֻ������0����9.�ðɣ��ٸ���һ�λ��ᣬ������ʧ��!\n");
                w1=1;                                       //���w1=1����ʾѧ���������˲������ֵ��ַ�
                break;
            }
            if(w1!=1)                                       //w1!=1,ȷ����֤ʱѧ���Ѿ�����0-9������ɵ�
                for(k=0;k<n;k++)                         //�Ƚϵ���n��ѧ��
                    if(k!=i && strcmp(stu[k].num,stu[i].num)==0)//�ж�ѧ���Ƿ�����ͬ
                    {
                        puts("�Ѿ�������!����һ��!\n");
                        w1=1;                               //w1=1,��ʾѧ�Ŵ�����ͬ
                        break;
                    }
    }
    while(w1==1);                                           //��֮��w1=1����ѧ�����������⣬Ҫ��������
    return 0;
}
/***���������뺯����***/
int score_input(int i)
{
    int j;
    for(j=0;j<M;j++)
    {
        printf("���� %d:",j+1);
        scanf("%d",&stu[i].score[j]);
    }
    return 0;
}
/***������һ������¼�ĺ�����***/
void input(int i)
{
    no_input(i,i);                              //��������ѧ�ŵĺ���
    printf("����:");
    scanf("%s",stu[i].name);                    //��������
    score_input(i);                             //�������
    average(i);                                 //����ƽ����
}
/***����ʾһ������¼�ĺ�����***/
void printf_one(int i)
{
    int j;
    printf("%11s    %-14s",stu[i].num,stu[i].name); //���ѧ�ź�����
    for(j=0;j<M;j++)
    printf("%9d",stu[i].score[j]);                  //�������
    printf("  %9.2f\n",stu[i].ave);                 //���ƽ����
}
/*����ʾ----����������*/
void topput___()
{
    printf("\n                 �� ¼ � ��                      ");
    printf("\n--------------------------------------------------------------------------------\n");
}
/*����ʾ----�����ײ���*/
void puts___()
{
    printf("\n\n--------------------------------------------------------------------------------\n");
}
/*���޸ļ�¼������*/
int modify_data(int i,int n)                    //�޸����ݺ������޸ĵ�i����¼
{
    int c,w1;
    do
    {
        puts("\n�����޸�ʲô: =>\n\n1).ѧ��\t2).����\t3).��ѧ\t4).Ӣ��\t5).C����\n6).�������з���\t7).�������м�¼\t8).ȡ��������");
        printf("��þ��䣬��:[ ]\b\b");
        scanf("%d",&c);
        if(c>8 || c<1)
        {
            puts("\nѡ��ʧ��!�����,����һ��!");//�ж�ѡ���Ƿ��������������ѡ��
            getchar();                          //������ʱ�ַ�ʱ���Է�ֹ��ѭ��   �������������Ҫ ����ʦҲû���
        }
    }while(c>8 || c<1);
    do
    {
        switch(c)                               //ѡ��Ҫ�޸ĵ���Ŀ
        {
        case 1:no_input(i,n);break;
        case 2:printf("����:");scanf("%s",stu[i].name);break;//����ѧ�����뺯��
        case 3:printf("��ѧ:");scanf("%d",&stu[i].score[0]);break;
        case 4:printf("Ӣ��:");scanf("%d",&stu[i].score[1]);break;
        case 5:printf("C����:");scanf("%d",&stu[i].score[2]);break;
        case 6:score_input(i);break;
        case 7:input(i);break;
        case 8:menu();          //break;   �������û������ν
        }
        if(c>2 && c<7)
            average(i);         //����3��4��5��6��ı��ͬʱҲ��ƽ���ֶ��ˣ���������һ��
        puts("\n����:\n");
        printf_face();
        printf_one(i);          //��ʾ�޸ĺ������
        printf("\n��ȷ����Ŀǰ�ľ���?\n\n\t1).��Ȼ��! \t2).������,���޸�һ��!\n\t3).���˻����߰�,�𱣴���![ ]\b\b");//�Ƿ�ȷ��
        scanf("%d",&w1);        //ѡ��2���ʾ����޸Ĵ���Ҫ�����޸�
    }while(w1==2);
    return w1;                  //���ؿ���ֵ
}
/* * * * * * * * * * * * ����ģ�� * * * * * * * * * * * */
void enter()
{
    int i,n;
    system("CLS");                  //�����ⲿ������clrscr()��VC++�в�����
    printf("������Ҫ��¼��ѧ������:(1~%d)?\t['0'����]:\n",N);
    scanf("%d",&n);                 //Ҫ����ļ������
    if(n==0)
        menu();                     //�� 0 ��ʱ�򷵻�
    else
    {
        printf("\n\t�õ�!��ʼ����...\n");
        for(i=0;i<n;i++)
        {
            printf("\n�������%d���ļ�¼.\n",i+1);
            input(i);                       //�������뺯��
        }
        if(i!=0)
            save(n);                        //���ñ��溯��
        printf_back();
    }           //һ���������ʱ���û�ѡ����������Ƿ���
}
/*******************************׷��ģ��*************************************/
int add()
{
    int i,n,m,k;
    FILE *fp;
    system("CLS");
    n=load();                               //����ܼ�¼�ĸ����������ؼ�¼
    printf("����Ҫ�������ѧ��:(0 ~ %d)?:",N-n);
    scanf("%d",&m);                         //����Ҫ׷�Ӽ�¼�ĸ���
    if(m==0)
        menu();
    else
    {
        k=m+n;
        for(i=n;i<k;i++)
        {
            printf("\n�������%d���ļ�¼.\n",i-n+1);
            input(i);                       //�������뺯��
        }
        if((fp=fopen("zhouhao.txt","ab"))==NULL)//��ab��ʽ�򿪣�׷�ӱ���
        {
            printf("�ļ��򲻿�!\n");     //��ʾ���ܴ��ļ�����Ϣ
            getch();
            return 0;
        }
        for(i=n;i<k;i++)
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
                printf("�ļ�д�����!\n");
        fclose(fp);
        printf_back();                      //һ���������ʱ���û�ѡ����������Ƿ���
    }
    return 0;
}
/***************************** �޸�ģ�� *************************/
void modify()
{
    struct student s;
    int i,n,k,w0=0,w1,w2=0;
    n=load();                               //����ܼ�¼�ĸ����������ؼ�¼
    do
    {
        system("CLS");
        k=-1;
        /*****���û������еļ�¼�Ա��û�ȷ��Ҫ�޸ĵļ�¼*****/
        topput___();
        printf_face();
        for(i=0;i<n;i++)
            printf_one(i);              //������ʾһ����¼�ĺ���
        puts___();
        /*****���û������еļ�¼�Ա��û�ȷ��Ҫ�޸ĵļ�¼*****/
        do
        {
            printf("\n\n������Ҫ�޸ļ�¼��ѧ��! ѧ��. :\t��'Ctrl-z' �˳���");
            if(scanf("%s",s.num)!=1)        //����Ҫ�޸����ݵ�ѧ��
            menu();
            for(i=0;i<n;i++)             //����Ҫ�޸ĵ�����
                if(strcmp(s.num,stu[i].num)==0)
                {
                    k=i;                    //�ҵ�Ҫ�޸ĵļ�¼
                    s=stu[i];               //��stu[i]�����ѵ����޸ĵ�ѧ����¼�����ݸ�s���Ա��û�����ʱ�ָ�
                }

        if(k==-1)
            printf("\n\n������! ����������~");
        }while(k==-1);                      //��K=-1��ʾû���ҵ�
    printf_face();                          //������ʾ���ݽṹ��Ŀ����
    printf_one(k);                          //��ʾ���ҵļ�¼
    w1=modify_data(k,n);                    //�޸�ѧ����¼���ҷ��ر������ֵw1��w1=1���ʾ�û���ȷ���޸�[w1ֻ����1��3(1����ȷ���޸ģ�3�������淵��)]
    if(w1==1)                               //w1=1����ȷ���޸�
    {
        printf("\n�����ɹ�!\n\n�����޸ı����?\n\n\t1).�ǵ�\t2).��!���沢����\t[ ]\b\b");
        scanf("%d",&w0);
        w2=1;                   //�����Ʊ��棬ʹw2=1�Ǳ�����й��޸�
    }
    else                        //��ʱw1=3����ʾ�����淵��
    {
        w0=0;
        if(w2==1)               //w2=1��ʾ���й��޸�
            stu[k]=s;           //�����ˣ����޸�ǰ��ֵ��ԭ
    }
    if(w0!=1 && w2==1)              //w0������1���ʾ�������أ�w2=1��ʾ�ڴ�֮ǰ���޸Ĺ�����ʱ�ͱ����û���ȷ���޸ĵĲ�����
        save(n);                    //w2������1��ʾ�ڴ�֮ǰû���޸Ĺ������ַ�������޸ģ��򲻱��棬����ʱ����ԭ������
    }while(w0==1);
    menu();                         //�������˵�
}
/*******************************ɾ��ģ�� *************************/
void del()
{
    struct student s;
    int i,k,n,c,w0=1;
    system("CLS");
    n=load();                       //����ܼ�¼�ĸ����������ؼ�¼
    do
    {
        system("CLS");
        k=-1;
        /*���û���ȫ����¼�Ա�ȷ��Ҫɾ���ļ�¼*/
        topput___();
        printf_face();              //������ʾ���ݽṹ��Ŀ�ĺ���
        for(i=0;i<n;i++)
            if(stu[i].ave!=0)
                printf_one(i);      //��ʾ��������
        puts___();
        /*���û���ȫ����¼�Ա�ȷ��Ҫɾ���ļ�¼*/
        do                          //����Ҫɾ����¼��ѧ�ţ���Ѱ��
        {
            printf("\n\n������Ҫɾ����¼��ѧ��! NO.:\t��'Ctrl-z' �˳���");
            if(scanf("%s",s.num)!=1)
                menu();
            for(i=0;i<n;i++)
                if(strcmp(s.num,stu[i].num)==0)
                {
                    k=i;                //�ظ�kֵ��ʾ�ҵ�Ѱ�ҵ�����
                    s=stu[i];
                }
            if(k==-1)                   //k=-1��ʾû�ҵ���ͬ��
                printf("\n\n������! ����������!");
        }while(k==-1);
        puts("\n");
        printf_face();
        printf_one(k);                  //��ʾҪɾ���ļ�¼
        printf("\n��ȷ��?\n\t1).ȷ��   2).������Ҫɾ��������   3).�������˳�[ ]\b\b");//���û�һ�η��ڵĻ���
        scanf("%d",&c);
        if(c==1)
        {
            stu[k].ave=0;               //���Ǻ���Ҫ�ģ�ͨ��stu[k].ave=0��֪ͨ�����ʱ����Ե��������б���
            printf("\n\n�����ɹ�!\n\nҪ����ɾ������?\n\t1).���� 2).�������˵�\t[ ]\b\b");
            scanf("%d",&w0);
        }
        if(c==3)
            w0=0;                       //w0=0��ɾ��ֱ�ӷ���
        if(w0!=0 && c!=3)               //ֻ�е�ȷ��ɾ���󷵻زű��棬��ɾ��ֱ�ӷ����򲻱��棬�Ҳ������ڴ�֮ǰɾ�����ļ�¼
            save(n);
    }while(w0==1);
    menu();
}
/**************************************�����ȫ����ģ��*****************************************/
void browse()
{
    int i,n;
    n=load();                   //����ܼ�¼�ĸ����������ؼ�¼
    system("CLS");
    topput___();
    printf_face();              //������ʾ���ݽṹ��Ŀ�ĺ���
    for(i=0;i<n;i++)         //ѭ���������ѧ������Ϣ
        printf_one(i);
    puts___();
    printf("\n\t ����һ���� %d ����¼!\n",n);
    printf("\n\t ����������������˵�... ...");
    getch();
    menu();
}
/*******************************����ģ��************************************/
void search()
{
    int i,n,k,w1=1,w2,w3,w4;
    struct student s;
    system("CLS");
    n=load();                                       //����ܼ�¼�ĸ����������ؼ�¼
    do
    {
        do
        {
            k=-1;
            printf("\n\n������Ҫ���Ҽ�¼�����˹�!  ����:");
            scanf("%s",s.name);
            printf_face();
            for(i=0;i<n;i++)
                if(strcmp(s.name,stu[i].name)==0)
                {
                    k=i;
                    printf_one(k);                  //���ǵ�ͬ������������������ֻһ��,�����еļ�¼������һ��
                }
            if(k==-1)                               //k=-1��ʾû�ҵ���ͬ��
            {
                printf("\n\n������! ����������!");
                printf("\n\nҪ������?\n\t1).����\t 2).��,��Ҫ���� \t[ ]\b\b");
                scanf("%d",&w1);
            }
        }while(k==-1 && w1!=2);                     //k=-1��ʾû�ҵ�Ҫ���ҵĶ���w1!=2��ʾ��������
        w4=w3=0;                                    //��ʼ��w4=w3=0
        if(k!=-1)
        {
            printf("\n\n���Ÿ�ʲô?\n\t1).�ٴβ��� 2).�޸� 3).ɾ�� 4).�������˵� [ ]\b\b");
            scanf("%d",&w2);
            switch(w2)
            {
            case 2:w3=modify_data(k,n);break;
            case 3:
                {
                    printf("\n\n��ȷ������?\n\t1).ȷ�� 2).��,���Ƿ��ذ�! \t[ ]\b\b");
                    scanf("%d",&w4);
                    if(w4==1)               //w4=1,��ʾȷ��ɾ��
                        stu[k].ave=0;       //��ʾɾ��,��stu[k].ave=0,��save()�оͲ����������,��ʾɾ��
                    break;
                }
            }
            if(w3==1 || w4==1)
            {
                save(n);
                printf("\n\n�����ɹ�!");
                printf("\n\n���Ÿ�ʲô?\n\t1).�ٴβ��� 2).���� [ ]\b\b");
                scanf("%d",&w2);
            }
        }
    }while(w2==1);
    menu();
}

/*******************************����ģ�飨��ƽ���ɼ���*********************************/
void order()
{

    int i,j,k,n;
    struct student s;
    system("CLS");              //����
    n=load();                   //����ܼ�¼�ĸ����������ؼ�¼
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(stu[j].ave>stu[k].ave)    //ѡ�����򣬰�ƽ���ֽ���
                k=j;
        s=stu[i];
        stu[i]=stu[k];
        stu[k]=s;
    }
    save(n);
    puts("\n\n");
    printf_back();
}
/**********************************������************************************/
void menu()
{
    int n,w1;
    do
    {
        system("CLS");;
        puts("\n\t\t\t\tѧ����Ϣ����ϵͳ\n");
        puts("\t                    ------- �ܺ�   \n");
        puts("\t    ************************ ���˵� *********************\n\n");
        puts("\t\t\t 1.��ʼ��������(�Ḳ����������)");
        puts("\t\t\t 2.��ѡ��������������");
        puts("\t\t\t 3.���ݲ����޸�");
        puts("\t\t\t 4.���ݲ���ɾ��");
        puts("\t\t\t 5.���ݲ鿴�����");
        puts("\t\t\t 6.���ݲ���(������)");
        puts("\t\t\t 7.��������(��ƽ���ֽ���)");
        puts("\t\t\t 8.�����ļ��ļ�����");
        puts("\t\t\t 0.�˳�ϵͳ");
        puts("\n\n\t    ****************************************************\n");
        printf("\t�������ѡ��(0~8):[ ]\b\b");
        scanf("%d",&n);
        if(n<0 || n>8)
        {
            w1=1;
            printf("\t���ѡ���� 0 �� 8 ֮��,���������������!");
            getch();
        }
        else
            w1=0;
        }while(w1==1);
    switch(n)
    {
    case 1:enter();break;
    case 2:add();break;
    case 3:modify();break;
    case 4:del();break;
    case 5:browse();break;
    case 6:search();break;
    case 7:order();break;
    case 8:copy();break;
    case 0:exit(0);break;
    }
}
/************************************������***************************************/
void main()
{
    menu();
}
