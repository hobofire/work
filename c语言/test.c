#include<stdio.h>
#include<string.h>
#include<stdlib.h>        //exit()的头文件
#include<conio.h>     //屏幕操作函数
#define N 100           //控制学生记录的容量
#define M 3             //控制课程数
#define LEN 9
void menu();
void browse();
typedef struct student          //定义学生结构体
{
    char num[11];               //把学号定义成字符数组类型,一来学号可能比较长，二来可直接用strcmp来比较，确保无雷同
    char name[20];
    int score[M];
    double ave;
}STU;
STU stu[N];             //定义一个外部学生结构体变量
/*****以写的方式保存数据到文件的函数【原数据将被覆盖】*****/
int save(int n)             //保存函数，保存n个记录
{
    FILE *fp;
    int i;
    if((fp=fopen("zhouhao.txt","wb"))==NULL)//以二进制写的方式打开，在此前的记录被覆盖
    {
        printf("无法打开文件!\n任意键退出程序... ...\n");
        getch();                            //预防闪屏
        return 0;
    }
    for(i=0;i<n;i++)
        if(stu[i].ave!=0)                   //在后面的del()函数中通过将stu[i].ave=0来表示该记录被删除了
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)//开始写入文件
                printf("文件写入发生错误\n");
    fclose(fp);
    return 0;                       // 注意下这个地方 ，我只是随便赋的值，只是为了消除一个警告
}
/********【拷贝函数单纯的将一个文件拷贝到另一个文件中】*******/
void copy()
{
    char outfile[20],infile[10];    //保存源文件名和目标文件名
    FILE *sfp,*tfp;                 //定义指向源文件(sourcefile)和目标文件(targetfile)的指针
    STU *p=NULL;                    //定义临时指针，暂存读出的记录
    system("CLS");                  //清屏;
    printf("请输入需要被复制的文件名（默认数据处理在zhouhao.txt中）:\n");
    scanf("%s",infile);             //输入源文件名
    if((sfp=fopen(infile,"rb"))==NULL)//以二进制方式打开源文件
    {
        printf("无法打开文件!\n任意键退出程序... ...\n");//显示不能打开文件的信息
        getch();
        return;
    }
    printf("另存为...,比如:hao.txt:\n"); //提示输入目标文件名
    scanf("%s",outfile);                    //输入目标文件名
        if((tfp=fopen(outfile,"wb"))==NULL)//以二进制写方式打开目标文件
    {
        printf("无法打开文件!\n\n");//显示不能打开文件的信息
        getch();
        return;                     //退出程序,同exit(0)
    }
        while(!feof(sfp))           //读文件直到文件尾
            fputc(fgetc(sfp),tfp);  //从stp复制文件到tfp
        fclose(sfp);                //关闭源文件
        fclose(tfp);                //关闭目标文件
        printf("\n复制成功!!!\n");  //显示拷贝成功信息
        printf("\n输入任意键返回主菜单");
        getch();
        menu();
}
/***【加载记录或可以计算记录个数的函数】***/
int load()
{
    FILE *fp;
    int i;
    if((fp=fopen("zhouhao.txt","rb"))==NULL)                            //以二进制读的方式打开
    {
        printf("无法打开文件!\n任意键退出程序... ...\n");            //显示不能打开文件的信息
        getch();                                                    //预防闪屏
        return 0;
    }
    for(i=0;!feof(fp);i++)
        fread(&stu[i],sizeof(struct student),1,fp);                 //将文件数据读入学生结构体
    fclose(fp);
    return(i-1);                                                    //返回目前总的记录个数，注意是i-1
}
/***【一个任务结束时的选择浏览还是返回的函数】***/
void printf_back()
{
    int w;
    printf("\n\t操作成功!^_^\n");
    printf("\t接着干什么?\n\t1).立刻浏览全部数据\t2).返回:[ ]\b\b");
    scanf("%d",&w);
    if(w==1)
        browse();
    else
        menu();
}
/***【显示数据结构项目函数】***/
void printf_face()
{
    printf("\n\t学号\t姓名\t\t   数学\t    英语    C语言    平均分\n");   //显示行头
}
/***【求平均分函数】因为后面在修改数据中要专门重算平均数***/
void average(int i)
{
    int j,sum;
    for(sum=0,j=0;j<M;j++)
        sum+=stu[i].score[j];
    stu[i].ave=sum*1.0/M;
}
/*******【学号长度处理函数】********/
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
/*******【学号输入函数】*******/
int no_input(int i,int n)                           //i表示第i个学生信息，n表示比较到第n个学生
{
    int j,k,w1;
    do{
        w1=0;
        printf("学号:\t\t 【%d位,低于%d位前面补0,长的截尾处理!】\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",LEN,LEN);
        scanf("%s",stu[i].num);
        no_deal(i);
        for(j=0;stu[i].num[j]!='\0';j++)                    //学号输入函数，作了严格的规定
            if(stu[i].num[j]<'0' || stu[i].num[j]>'9')        //判断学号是否为数字
            {
                puts("别开玩笑!只能输入0——9.好吧，再给你一次机会，别让我失望!\n");
                w1=1;                                       //这个w1=1，表示学号中输入了不是数字的字符
                break;
            }
            if(w1!=1)                                       //w1!=1,确保验证时学号已经是由0-9的数组成的
                for(k=0;k<n;k++)                         //比较到第n个学生
                    if(k!=i && strcmp(stu[k].num,stu[i].num)==0)//判断学号是否有雷同
                    {
                        puts("已经存在啦!重来一次!\n");
                        w1=1;                               //w1=1,表示学号存在雷同
                        break;
                    }
    }
    while(w1==1);                                           //总之，w1=1代表学号输入又问题，要重新输入
    return 0;
}
/***【分数输入函数】***/
int score_input(int i)
{
    int j;
    for(j=0;j<M;j++)
    {
        printf("分数 %d:",j+1);
        scanf("%d",&stu[i].score[j]);
    }
    return 0;
}
/***【输入一整条记录的函数】***/
void input(int i)
{
    no_input(i,i);                              //调用输入学号的函数
    printf("姓名:");
    scanf("%s",stu[i].name);                    //输入姓名
    score_input(i);                             //输入分数
    average(i);                                 //计算平均分
}
/***【显示一整条记录的函数】***/
void printf_one(int i)
{
    int j;
    printf("%11s    %-14s",stu[i].num,stu[i].name); //输出学号和姓名
    for(j=0;j<M;j++)
    printf("%9d",stu[i].score[j]);                  //输出分数
    printf("  %9.2f\n",stu[i].ave);                 //输出平均分
}
/*【显示----函数顶部】*/
void topput___()
{
    printf("\n                 记 录 浏 览                      ");
    printf("\n--------------------------------------------------------------------------------\n");
}
/*【显示----函数底部】*/
void puts___()
{
    printf("\n\n--------------------------------------------------------------------------------\n");
}
/*【修改记录函数】*/
int modify_data(int i,int n)                    //修改数据函数，修改第i个记录
{
    int c,w1;
    do
    {
        puts("\n你想修改什么: =>\n\n1).学号\t2).姓名\t3).数学\t4).英语\t5).C语言\n6).重输所有分数\t7).重输所有记录\t8).取消并返回");
        printf("想好就输，快:[ ]\b\b");
        scanf("%d",&c);
        if(c>8 || c<1)
        {
            puts("\n选择失误!严肃点,再来一次!");//判断选择是否错误，若是则重新选择
            getchar();                          //当输入时字符时可以防止死循环   ，觉得这个很重要 ，老师也没提过
        }
    }while(c>8 || c<1);
    do
    {
        switch(c)                               //选择要修改的项目
        {
        case 1:no_input(i,n);break;
        case 2:printf("姓名:");scanf("%s",stu[i].name);break;//调用学号输入函数
        case 3:printf("数学:");scanf("%d",&stu[i].score[0]);break;
        case 4:printf("英语:");scanf("%d",&stu[i].score[1]);break;
        case 5:printf("C语言:");scanf("%d",&stu[i].score[2]);break;
        case 6:score_input(i);break;
        case 7:input(i);break;
        case 8:menu();          //break;   在最后，有没有无所谓
        }
        if(c>2 && c<7)
            average(i);         //由于3，4，5，6项改变的同时也把平均分动了，必须修正一下
        puts("\n现在:\n");
        printf_face();
        printf_one(i);          //显示修改后的数据
        printf("\n你确定你目前的决定?\n\n\t1).当然啦! \t2).不不不,重修改一下!\n\t3).算了还是走吧,别保存了![ ]\b\b");//是否确定
        scanf("%d",&w1);        //选择2则表示这次修改错误要重新修改
    }while(w1==2);
    return w1;                  //返回控制值
}
/* * * * * * * * * * * * 输入模块 * * * * * * * * * * * */
void enter()
{
    int i,n;
    system("CLS");                  //引用外部清屏，clrscr()在VC++中不好用
    printf("输入你要记录的学生数吧:(1~%d)?\t['0'返回]:\n",N);
    scanf("%d",&n);                 //要输入的计入个数
    if(n==0)
        menu();                     //输 0 的时候返回
    else
    {
        printf("\n\t好的!开始输入...\n");
        for(i=0;i<n;i++)
        {
            printf("\n请输入第%d个的记录.\n",i+1);
            input(i);                       //调用输入函数
        }
        if(i!=0)
            save(n);                        //调用保存函数
        printf_back();
    }           //一个任务结束时让用户选择是浏览还是返回
}
/*******************************追加模块*************************************/
int add()
{
    int i,n,m,k;
    FILE *fp;
    system("CLS");
    n=load();                               //获得总记录的个数，并加载记录
    printf("你需要加入多少学生:(0 ~ %d)?:",N-n);
    scanf("%d",&m);                         //输入要追加记录的个数
    if(m==0)
        menu();
    else
    {
        k=m+n;
        for(i=n;i<k;i++)
        {
            printf("\n请输入第%d个的记录.\n",i-n+1);
            input(i);                       //调用输入函数
        }
        if((fp=fopen("zhouhao.txt","ab"))==NULL)//以ab方式打开，追加保存
        {
            printf("文件打不开!\n");     //显示不能打开文件的信息
            getch();
            return 0;
        }
        for(i=n;i<k;i++)
            if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
                printf("文件写入错误!\n");
        fclose(fp);
        printf_back();                      //一个任务结束时让用户选择是浏览还是返回
    }
    return 0;
}
/***************************** 修改模块 *************************/
void modify()
{
    struct student s;
    int i,n,k,w0=0,w1,w2=0;
    n=load();                               //获得总记录的个数，并加载记录
    do
    {
        system("CLS");
        k=-1;
        /*****给用户看所有的记录以便用户确认要修改的记录*****/
        topput___();
        printf_face();
        for(i=0;i<n;i++)
            printf_one(i);              //调用显示一个记录的函数
        puts___();
        /*****给用户看所有的记录以便用户确认要修改的记录*****/
        do
        {
            printf("\n\n输入你要修改记录的学号! 学号. :\t【'Ctrl-z' 退出】");
            if(scanf("%s",s.num)!=1)        //输入要修改数据的学号
            menu();
            for(i=0;i<n;i++)             //查找要修改的数据
                if(strcmp(s.num,stu[i].num)==0)
                {
                    k=i;                    //找到要修改的记录
                    s=stu[i];               //把stu[i]（即把当次修改的学生记录）备份给s，以便用户反悔时恢复
                }

        if(k==-1)
            printf("\n\n不存在! 请重新输入~");
        }while(k==-1);                      //当K=-1表示没有找到
    printf_face();                          //调用显示数据结构项目函数
    printf_one(k);                          //显示查找的记录
    w1=modify_data(k,n);                    //修改学生记录并且返回保存控制值w1，w1=1则表示用户已确认修改[w1只能是1或3(1代表确认修改，3代表不保存返回)]
    if(w1==1)                               //w1=1代表确认修改
    {
        printf("\n操作成功!\n\n决定修改别的吗?\n\n\t1).是的\t2).不!保存并返回\t[ ]\b\b");
        scanf("%d",&w0);
        w2=1;                   //来控制保存，使w2=1是标记已有过修改
    }
    else                        //此时w1=3，表示不保存返回
    {
        w0=0;
        if(w2==1)               //w2=1表示已有过修改
            stu[k]=s;           //反悔了，将修改前的值复原
    }
    if(w0!=1 && w2==1)              //w0不等于1则表示正常返回，w2=1表示在此之前有修改过，这时就保存用户已确认修改的并返回
        save(n);                    //w2不等于1表示在此之前没有修改过，而又反悔这次修改，则不保存，保存时覆盖原先数据
    }while(w0==1);
    menu();                         //返回主菜单
}
/*******************************删除模块 *************************/
void del()
{
    struct student s;
    int i,k,n,c,w0=1;
    system("CLS");
    n=load();                       //获得总记录的个数，并加载记录
    do
    {
        system("CLS");
        k=-1;
        /*给用户看全部记录以便确认要删除的记录*/
        topput___();
        printf_face();              //调用显示数据结构项目的函数
        for(i=0;i<n;i++)
            if(stu[i].ave!=0)
                printf_one(i);      //显示所有数据
        puts___();
        /*给用户看全部记录以便确认要删除的记录*/
        do                          //输入要删除记录的学号，并寻找
        {
            printf("\n\n输入你要删除记录的学号! NO.:\t【'Ctrl-z' 退出】");
            if(scanf("%s",s.num)!=1)
                menu();
            for(i=0;i<n;i++)
                if(strcmp(s.num,stu[i].num)==0)
                {
                    k=i;                //重赋k值表示找到寻找的数据
                    s=stu[i];
                }
            if(k==-1)                   //k=-1表示没找到相同的
                printf("\n\n不存在! 请重新输入!");
        }while(k==-1);
        puts("\n");
        printf_face();
        printf_one(k);                  //显示要删除的记录
        printf("\n你确定?\n\t1).确定   2).不，我要删除其他的   3).不保存退出[ ]\b\b");//给用户一次反悔的机会
        scanf("%d",&c);
        if(c==1)
        {
            stu[k].ave=0;               //这是很重要的，通过stu[k].ave=0，通知保存的时候忽略掉，不进行保存
            printf("\n\n操作成功!\n\n要继续删数据吗?\n\t1).继续 2).返回主菜单\t[ ]\b\b");
            scanf("%d",&w0);
        }
        if(c==3)
            w0=0;                       //w0=0不删除直接返回
        if(w0!=0 && c!=3)               //只有当确认删除后返回才保存，不删除直接返回则不保存，且不保存在此之前删除过的记录
            save(n);
    }while(w0==1);
    menu();
}
/**************************************浏览（全部）模块*****************************************/
void browse()
{
    int i,n;
    n=load();                   //获得总记录的个数，并加载记录
    system("CLS");
    topput___();
    printf_face();              //调用显示数据结构项目的函数
    for(i=0;i<n;i++)         //循环输出所有学生的信息
        printf_one(i);
    puts___();
    printf("\n\t 这里一共有 %d 个记录!\n",n);
    printf("\n\t 输入任意键返回主菜单... ...");
    getch();
    menu();
}
/*******************************查找模块************************************/
void search()
{
    int i,n,k,w1=1,w2,w3,w4;
    struct student s;
    system("CLS");
    n=load();                                       //获得总记录的个数，并加载记录
    do
    {
        do
        {
            k=-1;
            printf("\n\n输入你要查找记录的主人公!  姓名:");
            scanf("%s",s.name);
            printf_face();
            for(i=0;i<n;i++)
                if(strcmp(s.name,stu[i].name)==0)
                {
                    k=i;
                    printf_one(k);                  //考虑到同名的情况，可能输出不只一个,把所有的记录都查找一下
                }
            if(k==-1)                               //k=-1表示没找到相同的
            {
                printf("\n\n不存在! 请重新输入!");
                printf("\n\n要继续吗?\n\t1).继续\t 2).不,我要返回 \t[ ]\b\b");
                scanf("%d",&w1);
            }
        }while(k==-1 && w1!=2);                     //k=-1表示没找到要查找的对象，w1!=2表示继续查找
        w4=w3=0;                                    //初始化w4=w3=0
        if(k!=-1)
        {
            printf("\n\n接着干什么?\n\t1).再次查找 2).修改 3).删除 4).返回主菜单 [ ]\b\b");
            scanf("%d",&w2);
            switch(w2)
            {
            case 2:w3=modify_data(k,n);break;
            case 3:
                {
                    printf("\n\n你确定了吗?\n\t1).确定 2).不,还是返回吧! \t[ ]\b\b");
                    scanf("%d",&w4);
                    if(w4==1)               //w4=1,表示确定删除
                        stu[k].ave=0;       //表示删除,当stu[k].ave=0,在save()中就不保存该数据,表示删除
                    break;
                }
            }
            if(w3==1 || w4==1)
            {
                save(n);
                printf("\n\n操作成功!");
                printf("\n\n接着干什么?\n\t1).再次查找 2).返回 [ ]\b\b");
                scanf("%d",&w2);
            }
        }
    }while(w2==1);
    menu();
}

/*******************************排序模块（按平均成绩）*********************************/
void order()
{

    int i,j,k,n;
    struct student s;
    system("CLS");              //清屏
    n=load();                   //获得总记录的个数，并加载记录
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(stu[j].ave>stu[k].ave)    //选择法排序，按平均分降序
                k=j;
        s=stu[i];
        stu[i]=stu[k];
        stu[k]=s;
    }
    save(n);
    puts("\n\n");
    printf_back();
}
/**********************************主界面************************************/
void menu()
{
    int n,w1;
    do
    {
        system("CLS");;
        puts("\n\t\t\t\t学生信息管理系统\n");
        puts("\t                    ------- 周浩   \n");
        puts("\t    ************************ 主菜单 *********************\n\n");
        puts("\t\t\t 1.初始数据输入(会覆盖已有数据)");
        puts("\t\t\t 2.可选择个数的数据添加");
        puts("\t\t\t 3.数据部分修改");
        puts("\t\t\t 4.数据部分删除");
        puts("\t\t\t 5.数据查看与浏览");
        puts("\t\t\t 6.数据查找(按姓名)");
        puts("\t\t\t 7.数据排序(按平均分降序)");
        puts("\t\t\t 8.已有文件文件拷贝");
        puts("\t\t\t 0.退出系统");
        puts("\n\n\t    ****************************************************\n");
        printf("\t输入你的选择(0~8):[ ]\b\b");
        scanf("%d",&n);
        if(n<0 || n>8)
        {
            w1=1;
            printf("\t你的选择不再 0 到 8 之间,按任意键重新输入!");
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
/************************************主函数***************************************/
void main()
{
    menu();
}
