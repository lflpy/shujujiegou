#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>

#define N 100
#define M 20
//学生结构体
// 增删改查
struct student {
    char num[12];//学号
    char name[12];//姓名
    char sex[12];//性别
    char Id[12];//身份证号
    char pass[12];//密码
    char isbd[12];//报到
    char dormitory[12];//宿舍
    char cad[12];//班级
    char major[12];//学院
};
//管理员结构体
struct ad {
    char id[10];//账号
    char pass[10];//密码
};

int sum1;//管理员人数
int sum, Sid = -1;

//读入学生数据
void wenjian(struct student stu[N]) {
    FILE *fp;
    int i, no = 0;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("文件打开失败!\n");
        //exit(1);
    }
    for (i = 0; i < N && !feof(fp); i++) {
        fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
               stu[i].num, stu[i].name, stu[i].sex, stu[i].Id, stu[i].pass, stu[i].isbd, stu[i].dormitory, stu[i].cad,
               stu[i].major);
        no++;
    }
    sum = no;
    fclose(fp);
}

//管理员账号密码文件读取
void ador(struct ad add[M]) {
    FILE *fp;
    int i, no = 0;
    if ((fp = fopen("ad.txt", "r")) == NULL) {
        printf("文件打开失败!\n");
    }
    for (i = 0; i < M && !feof(fp); i++) {
        fscanf(fp, "%s\t%s\n",
               add[i].id, add[i].pass);
        no++;
    }
    sum1 = no;
    fclose(fp);
}

//南校区平面图
void picture() {
    int system(const char *command);
    char pic_name[80] = "平面图.jpg";
    char cmd[100];
    sprintf(cmd, pic_name);
    system(cmd);
}

//进入系统界面
int zhu() {
    system("cls");  //清屏函数
    printf("\t\t\t┌······························┐\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t│      新生入学管理系统        │\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t│           欢迎使用           │\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t│           1.管理员           │\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t│           2.新学生           │\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t│           0.退出             │\n");
    printf("\t\t\t│                              │\n");
    printf("\t\t\t└······························┘\n");
    //_getch();
    int flag;
    printf("请选择身份进入系统:");
    scanf("%d", &flag);
    return flag;
}

//学号排序
void Px(struct student stu[N]) {
    int i, j;
    char t[12];
    for (i = sum - 1; i >= 1; i--)
        for (j = 0; j <= i; j++)
            if (strcmp(stu[j].num, stu[j + 1].num) > 0) {
                strcpy(t, stu[j].num);
                strcpy(stu[j].num, stu[j + 1].num);
                strcpy(stu[j + 1].num, t);
                strcpy(t, stu[j].cad);
                strcpy(stu[j].cad, stu[j + 1].cad);
                strcpy(stu[j + 1].cad, t);
                strcpy(t, stu[j].dormitory);
                strcpy(stu[j].dormitory, stu[j + 1].dormitory);
                strcpy(stu[j + 1].dormitory, t);
                strcpy(t, stu[j].Id);
                strcpy(stu[j].Id, stu[j + 1].Id);
                strcpy(stu[j + 1].Id, t);
                strcpy(t, stu[j].isbd);
                strcpy(stu[j].isbd, stu[j + 1].isbd);
                strcpy(stu[j + 1].isbd, t);
                strcpy(t, stu[j].name);
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j + 1].name, t);
                strcpy(t, stu[j].pass);
                strcpy(stu[j].pass, stu[j + 1].pass);
                strcpy(stu[j + 1].pass, t);
                strcpy(t, stu[j].sex);
                strcpy(stu[j].sex, stu[j + 1].sex);
                strcpy(stu[j + 1].sex, t);
                strcpy(t, stu[j].major);
                strcpy(stu[j].major, stu[j + 1].major);
                strcpy(stu[j + 1].major, t);

            }
}

//增加学生数据
void zengjia(struct student stu[N]) {
    FILE *fp;
    int i, j = 0, k = 0;
    char name[10];
    if ((fp = fopen("student.txt", "a")) == NULL) {
        printf("文件打开失败!");
        exit(1);
    }
    printf("添加学生人数:");
    scanf("%d", &i);
    while (j < i) {
        input:
        printf("请输入第%d个学生学号：", j + 1);
        scanf("%s", name);
        for (k = 0; k < sum + j; k++)
            if (strcmp(name, stu[k].num) == 0) {
                printf("该学号已存在！\n");
                goto input;
            }
        if (k == sum + j) {
            strcpy(stu[sum + j].num, name);
            strcpy(stu[sum + j].pass, "123456");
            strcpy(stu[sum + j].isbd, "未");
            printf("请依次按写顺序输入学生信息：\n姓名\t性别\t身份证号\t宿舍\t班级\t学院\n");
            scanf("%s\t%s\t%s\t%s\t%s\t%s",
                  stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].dormitory, stu[sum + j].cad,
                  stu[sum + j].major);
            fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                    stu[sum + j].num, stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].pass,
                    stu[sum + j].isbd, stu[sum + j].dormitory, stu[sum + j].cad, stu[sum + j].major);
            j++;
        }
    }
    sum = sum + i;
    fclose(fp);
    printf("添加成功，按任意键返回主页面!\n");
    _getch();
}

//修改学生数据
void xiugai(struct student stu[N]) {
    FILE *fp;
    char i[10];
    int j = 0, k, n, m;
    input:
    printf("请输入修改学生信息的学号:");
    scanf("%s", &i);
    for (k = 0; k < sum; k++) {
        //printf("\n%s\n%s\n",i,stu[k].num);
        if (strcmp(stu[k].num, i) == 0) {
            printf("该学生信息如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass,
                   stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            break;
        }
    }
    if (k == sum) {
        printf("你输入错误，请重新输入！\n");
        goto input;
    }
    printf("请输入要修改的个数:");
    scanf("%d", &n);
    m = 0;
    while (m < n) {
        printf("请选择要修改的第%d个数据（1.学号|2.姓名|3.性别|4.份证号|5.密码|6.报到|7.宿舍|8.班级|9.学院）：", m + 1);
        scanf("%d", &j);
        printf("请输入修改的数据：");
        switch (j) {
            case 1:
                scanf("%s", stu[k].num);
                break;
            case 2:
                scanf("%s", stu[k].name);
                break;
            case 3:
                scanf("%s", stu[k].sex);
                break;
            case 4:
                scanf("%s", stu[k].Id);
                break;
            case 5:
                scanf("%s", stu[k].pass);
                break;
            case 6:
                scanf("%s", stu[k].isbd);
                break;
            case 7:
                scanf("%s", stu[k].dormitory);
                break;
            case 8:
                scanf("%s", stu[k].cad);
                break;
            case 9:
                scanf("%s", stu[k].major);
                break;
        }
        m++;
    }
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("文件打开失败!");
        exit(1);
    }
    k = 0;
    while (k < sum) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad,
                stu[k].major);
        k++;
    }
    fclose(fp);
    printf("修改成功，按任意键返回主页面！\n");
    _getch();
}

//查询学生数据结果
int jieguo(struct student stu[N], int k, int n) {
    n++;
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
           stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad,
           stu[k].major);
    return n;
}

//查询学生数据个数
int Alsole(int n) {
    if (n == 0) {
        printf("\n没有找到!!!，请重新输入！\n");
        return 1;
    } else {
        printf("成功查询到%d个学生信息，按任意键返回主页面！\n", n);
        _getch();
        return 0;
    }
}

//查询学生数据
void chaxu(struct student stu[N]) {
    char cx[20];
    int j = 0, k, n = 0, y;
    struct student *p;
    p = stu;
    printf("请选择要查询的信息（1.学号|2.姓名|3.性别|4.身份证号|5.密码|6.报到|7.宿舍|8.班级|9.学院）：");
    scanf("%d", &j);
    input:
    printf("请输入要查询的数据：");
    scanf("%s", &cx);
    printf("查询结果如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n");
    switch (j) {
        case 1: {
            for (k = 0; k < sum; k++) {
                if (strcmp(stu[k].num, cx) == 0) {
                    n = jieguo(p, k, n);
                    break;
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 2: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].name, cx) == 0) {
                    n = jieguo(p, k, n);
                    break;
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 3: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].sex, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 4: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].Id, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 5: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].pass, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 6: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].isbd, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 7: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].dormitory, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 8: {
            for (k = 0; k < sum; k++) {
                //printf("\n%s\n%s\n",i,stu[k].num);
                if (strcmp(stu[k].cad, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 9: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].major, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
    }
}

//删除学生数据
void deletee(struct student stu[N]) {
    FILE *fp;
    char sc[10];
    int k, n, j;
    input:
    printf("请输入要删除的学生学号：");\
     scanf("%s", &sc);
    for (k = 0; k < sum; k++) {
        //printf("\n%s\n%s\n",i,stu[k].num);
        if (strcmp(stu[k].num, sc) == 0) {
            printf("该学生信息如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                   stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory,
                   stu[k].cad, stu[k].major);
            break;
        }
    }
    if (k == sum) {
        printf("没有该学号，请重新输入！\n");
        goto input;
    }
    printf("是否删除该学生信息(1.是|2.否)：");
    scanf("%d", &n);
    if (n == 1) {
        for (k; k < sum; k++) {
            strcpy(stu[k].num, stu[k + 1].num);
            strcpy(stu[k].name, stu[k + 1].name);
            strcpy(stu[k].sex, stu[k + 1].sex);
            strcpy(stu[k].Id, stu[k + 1].Id);
            strcpy(stu[k].pass, stu[k + 1].pass);
            strcpy(stu[k].isbd, stu[k + 1].isbd);
            strcpy(stu[k].dormitory, stu[k + 1].dormitory);
            strcpy(stu[k].cad, stu[k + 1].cad);
            strcpy(stu[k].cad, stu[k + 1].major);
        }
        if ((fp = fopen("student.txt", "w")) == NULL) {
            printf("文件打开失败!");
            exit(1);
        }
        j = 0;
        sum = sum - 1;
        while (j < sum) {
            fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                    stu[j].num, stu[j].name, stu[j].sex, stu[j].Id, stu[j].pass, stu[j].isbd, stu[j].dormitory,
                    stu[j].cad, stu[j].major);
            j++;
        }
        fclose(fp);
        printf("删除成功,按任意健返回！");
        _getch();

    } else if (n == 2) {
        printf("按任意健返回！");
        _getch();
    } else {
        printf("你的输入有误，请重新输入！");
        goto input;
    }
}

//学生信息输出
void shouyou(struct student stu[N]) {
    struct student *p;
    char cx[20];
    int j = 0, k, n = 0, y;
    p = stu;
    Px(p);
    printf("请选择要查询的信息（1.汇总|2.性别|3.班级|4.宿舍|5.学院|6.报道|0.返回）：");
    scanf("%d", &j);
    if (j != 1) {
        input:
        printf("请输入要查询的数据：");
        scanf("%s", &cx);
        printf("查询结果如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n");
    }
    switch (j) {
        case 1: {
            printf("汇总%d个学生信息如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n", sum);
            for (k = 0; k < sum; k++) {
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory,
                       stu[k].cad, stu[k].major);
            }
            printf("按任意件返回！");
            _getch();
            break;
        }
        case 2: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].sex, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 3: {
            for (k = 0; k < sum; k++) {
                //printf("\n%s\n%s\n",i,stu[k].num);
                if (strcmp(stu[k].cad, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 4: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].dormitory, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 5: {
            for (k = 0; k < sum; k++) {
                //printf("\n%s\n%s\n",i,stu[k].num);
                if (strcmp(stu[k].major, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
        case 6: {
            for (k = 0; k < sum; k++) {

                if (strcmp(stu[k].isbd, cx) == 0) {
                    n = jieguo(p, k, n);
                }
            }
            if (Alsole(n)) {
                printf("\n是否重新输入信息(1是|0否)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
    }
}

// 查看状态、注册报到
void baodao(struct student stu[N]) {
    int i, k;
    FILE *fp;
    printf("注册报到流程:\n巡天楼注册缴费—宿舍领取钥匙—食堂办理饭卡—图书馆办理借书证—注册报到成功\n");
    printf("你的报到状态是：");
    if (strcmp(stu[Sid].isbd, "已") == 0) {
        printf("已报到\n");
        printf("按任意健返回！");
        _getch();
    } else {
        printf("未报到\n");
        printf("你确认已完成流程并且注册报到（1.是|2.否）：");
        scanf("%d", &i);
        if (i == 1) {
            strcpy(stu[Sid].isbd, "已");
            if ((fp = fopen("student.txt", "w")) == NULL) {
                printf("文件打开失败!");
                exit(1);
            }
            k = 0;
            while (k < sum) {
                fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                        stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory,
                        stu[k].cad, stu[k].major);
                k++;
            }
            fclose(fp);
            printf("注册成功，按任意键返回主页面！\n");
            _getch();
        }
    }
}

// 查看、修改信息
void chakai(struct student stu[N]) {
    FILE *fp;
    char i[10];
    int j = 0, k, n = 5, m;
    printf("个人信息如下：\n学号\t姓名\t性别\t身份证号\t密码\t报到\t宿舍\t班级\t学院\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[Sid].num, stu[Sid].name, stu[Sid].sex, stu[Sid].Id,
           stu[Sid].pass, stu[Sid].isbd, stu[Sid].dormitory, stu[Sid].cad, stu[Sid].major);
    printf("\n");
    printf("身份是学生，你只能修改以下信息：\n性别\t身份证号\t密码\t报到\n");
    printf("%s\t%s\t%s\t%s\n", stu[Sid].sex, stu[Sid].Id, stu[Sid].pass, stu[Sid].isbd);
    printf("\n");
    printf("请输入要修改的个数（1-4,  0为返回）:");
    scanf("%d", &n);
    if (n == 0)
        goto input;
    m = 0;
    while (m < n) {
        printf("\n请选择要修改的第%d个数据（1.性别|2.身份证号|3.密码|4.报到）：", m + 1);
        scanf("%d", &j);
        printf("请输入修改后的信息：");
        switch (j) {
            case 1:
                scanf("%s", stu[Sid].sex);
                break;
            case 2:
                scanf("%s", stu[Sid].Id);
                break;
            case 3:
                scanf("%s", stu[Sid].pass);
                break;
            case 4:
                scanf("%s", stu[Sid].isbd);
                break;
        }
        m++;
    }
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("文件打开失败!");
        exit(1);
    }
    k = 0;
    //将信息重新写入文件
    while (k < sum) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass,
                stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
        k++;
    }
    fclose(fp);
    printf("修改成功!");
    input:
    printf("按任意键返回主页面！\n");
    _getch();
}

// 查看宿舍、班级、学院情况
void insitite(struct student stu[N]) {
    char cx[20];
    int j = 0, k, n = 0;
    printf("请选择要查询的数据（1.宿舍|2.班级|3.学院|4.返回）：");
    scanf("%d", &j);
    if (j == 1) {
        printf("信息如下：\n学号\t姓名\t报到\t宿舍\t班级\t学院\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].dormitory, stu[k].dormitory) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("查询到%d个学生，按任意键返回主页面！\n", n);
        _getch();
    } else if (j == 2) {
        printf("信息如下：\n学号\t性别\t姓名\t报到\t宿舍\t班级\t学院\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].cad, stu[k].cad) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("查询到%d个学生，按任意键返回主页面！\n", n);
        _getch();
    } else if (j == 3) {
        printf("信息如下：\n学号\t性别\t姓名\t报到\t宿舍\t班级\t学院\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].major, stu[k].major) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("查询到%d个学生，按任意键返回主页面！\n", n);
        _getch();
    } else
        printf("没有该学生信息！！！");
}

//学生登录、选择界面主页
void Student(struct student stu[N]) {
    int i, n = 0;
    struct student *p;
    p = stu;
    char pass[10];
    char num[10];
    input:
    printf("请输入学号：");
    scanf("%s", &num);
    printf("请输入密码：");
    scanf("%s", &pass);
    for (i = 0; i < sum; i++) {

        if (strcmp(stu[i].num, num) == 0 && strcmp(stu[i].pass, pass) == 0) {
            Sid = i;
            break;
        }
    }
    if (i == sum) {
        printf("你输入错误，请重新输入！\n");
        goto input;
    }
    while (n < 5) {
        system("cls");
        printf("\t\t\t┌────────────────────────────────┐\n");
        printf("\t\t\t│             学生               │\n");
        printf("\t\t\t├────────────────────────────────┤\n");
        printf("\t\t\t│      1. 查看状态和注册报到     │\n");
        printf("\t\t\t│      2. 查看和修改个人信息     │\n");
        printf("\t\t\t│      3. 查看宿舍、班级、学院情况\n");
        printf("\t\t\t│      4. 查看学校的平面图       │\n");
        printf("\t\t\t│      0. 退出                   │\n");
        printf("\t\t\t│                                │\n");
        if (Sid != (-1)) {
            printf("\t\t\t│         欢迎%s登录！          │\n", stu[Sid].name);
        }
        printf("\t\t\t└────────────────────────────────┘\n\n");
        printf("请选择（0-4）：");
        scanf("%d", &n);
        switch (n) {
            case 1:
                baodao(p);
                break;
            case 2:
                chakai(p);
                break;
            case 3:
                insitite(p);
                break;
            case 4:
                picture();
                break;
            case 0:
                n = 5;
                break;
        }
    }
}

//管理员页面
void ad1(struct student stu[N]) {
    int n = 0;
    struct student *p;
    p = stu;
    while (n < 6) {
        system("cls");
        printf("\t\t┌——————————————————————————————┐\n");
        printf("\t\t│             管理员           │                             │\n");
        printf("\t\t├——————————————————————————————┤\n");
        printf("\t\t│      1. 添加学生             │          *********          │\n");
        printf("\t\t│      2. 修改学生信息         │        *************        │\n");
        printf("\t\t│      3. 查询学生信息         │      ****************       │\n");
        printf("\t\t│      4. 删除学生             │    ********************     │\n");
        printf("\t\t│      5. 汇总新生             │  ************************   │\n");
        printf("\t\t│      0. 退出                 │**************************** │\n");
        printf("\t\t└——————————————————————————————┘\n\n");
        printf("请选择（0-5）：");
        scanf("%d", &n);
        switch (n) {
            case 1:
                zengjia(p);
                break;
            case 2:
                xiugai(p);
                break;
            case 3:
                chaxu(p);
                break;
            case 4:
                deletee(p);
                break;
            case 5:
                shouyou(p);
                break;
            case 0:
                n = 6;
                break;
        }
    }
}

//管理员登录函数
void sign(struct ad add[M], struct student stu[N]) {
    int i, k;
    int j;
    char f[7];
    char ch[7] = "11122";
    FILE *fp;
    struct student *p;
    char id[10];
    char pass[10];
    int choose;
    p = stu;
    system("cls");
    printf("\t\t\t┌──────────────────────────────┐\n");
    printf("\t\t\t│             管理员           │\n");
    printf("\t\t\t├──────────────────────────────┤\n");
    printf("\t\t\t│      1. 登录                 │\n");
    printf("\t\t\t│      2. 注册                 │\n");
    printf("\t\t\t│      3. 找回密码             │\n");
    printf("\t\t\t│      0. 退出                 │\n");
    printf("\t\t\t└──────────────────────────────┘\n\n");
    printf("输入你的选择：");
    scanf("%d", &choose);
    if (choose == 1) {
        input:
        printf("请输入管理员帐号：");
        scanf("%s", &id);
        //gets(id);
        printf("请输入管理员密码：");
        scanf("%s", &pass);
        //gets(pass);
        for (i = 0; i < sum1; i++) {
            if (strcmp(add[i].id, id) == 0 && strcmp(add[i].pass, pass) == 0) {
                break;
            }
        }
        if (i == sum1) {
            printf("你输入错误，请重新输入！\n");
            goto input;
        }
        ad1(p);
        choose = 4;
    } else if (choose == 2) {
        if ((fp = fopen("student.txt", "a")) == NULL) {
            printf("文件打开失败!");
            exit(1);
        }
        input1:
        printf("请输入你要注册的电话号码：");
        scanf("%s", &id);
        printf("\n请输入手机验证码：");
        scanf("%s", &f);
        if (strcmp(f, ch) == 0) {
            printf("\n验证码错误，请重新核对！！！\n\n");
            goto input1;
        }
        for (k = 0; k < sum1; k++)
            if (strcmp(id, add[k].id) == 0) {
                printf("该电话号码已存在！请重新输入.\n\n");
                goto input1;
            }
        printf("请输入密码：");
        scanf("%s", &pass);
        strcpy(add[sum1].id, id);
        strcpy(add[sum1].pass, pass);
        fprintf(fp, "%s\t%s\n", add[sum1].id, add[sum1].pass);
        fclose(fp);
        sum1 = sum1 + 1;
        printf("注册成功，请重新登录");
        scanf("%s", &f);
        exit(1);
    } else if (choose == 3) {
        if ((fp = fopen("student.txt", "a")) == NULL) {
            printf("文件打开失败!");
            exit(1);
        }
        printf("请输入要找回的账号：");
        scanf("%s", &id);
        for (k = 0; k < sum1; k++)
            if (strcmp(id, add[k].id) == 0) {
                input2:
                printf("\n请输入验证码：");
                scanf("%s", &f);
                if (strcmp(f, ch) == 0) {
                    printf("\n验证通过！\n");
                    printf("你的密码是：%s", add[k].pass);
                    scanf("%s", &f);
                    exit(1);
                } else {
                    printf("\n验证不通过！！！");
                    goto input2;
                }

            }
        printf("此账号没有注册！！！\n");
        scanf("%s", &f);
        exit(1);
    } else
        exit(1);

}

//主函数
int main() {
    int n, flag;
    struct student *p, stu[N];
    struct ad *p1, techer[M];
    p = stu;
    wenjian(p);//读入数据
    p1 = techer;
    ador(p1);
    while (1) {
        flag = zhu();
        if (flag == 1)
            sign(p1, p);
        else if (flag == 2)
            Student(p);
        else
            exit(1);
        //system("cls");  //清屏函数
    }
    return 0;
}
