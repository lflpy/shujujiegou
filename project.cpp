#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>

#define N 100
#define M 20
//ѧ���ṹ��
// ��ɾ�Ĳ�
struct student {
    char num[12];//ѧ��
    char name[12];//����
    char sex[12];//�Ա�
    char Id[12];//���֤��
    char pass[12];//����
    char isbd[12];//����
    char dormitory[12];//����
    char cad[12];//�༶
    char major[12];//ѧԺ
};
//����Ա�ṹ��
struct ad {
    char id[10];//�˺�
    char pass[10];//����
};

int sum1;//����Ա����
int sum, Sid = -1;

//����ѧ������
void wenjian(struct student stu[N]) {
    FILE *fp;
    int i, no = 0;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("�ļ���ʧ��!\n");
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

//����Ա�˺������ļ���ȡ
void ador(struct ad add[M]) {
    FILE *fp;
    int i, no = 0;
    if ((fp = fopen("ad.txt", "r")) == NULL) {
        printf("�ļ���ʧ��!\n");
    }
    for (i = 0; i < M && !feof(fp); i++) {
        fscanf(fp, "%s\t%s\n",
               add[i].id, add[i].pass);
        no++;
    }
    sum1 = no;
    fclose(fp);
}

//��У��ƽ��ͼ
void picture() {
    int system(const char *command);
    char pic_name[80] = "ƽ��ͼ.jpg";
    char cmd[100];
    sprintf(cmd, pic_name);
    system(cmd);
}

//����ϵͳ����
int zhu() {
    system("cls");  //��������
    printf("\t\t\t����������������������������������������������������������������\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t��      ������ѧ����ϵͳ        ��\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t��           ��ӭʹ��           ��\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t��           1.����Ա           ��\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t��           2.��ѧ��           ��\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t��           0.�˳�             ��\n");
    printf("\t\t\t��                              ��\n");
    printf("\t\t\t����������������������������������������������������������������\n");
    //_getch();
    int flag;
    printf("��ѡ����ݽ���ϵͳ:");
    scanf("%d", &flag);
    return flag;
}

//ѧ������
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

//����ѧ������
void zengjia(struct student stu[N]) {
    FILE *fp;
    int i, j = 0, k = 0;
    char name[10];
    if ((fp = fopen("student.txt", "a")) == NULL) {
        printf("�ļ���ʧ��!");
        exit(1);
    }
    printf("���ѧ������:");
    scanf("%d", &i);
    while (j < i) {
        input:
        printf("�������%d��ѧ��ѧ�ţ�", j + 1);
        scanf("%s", name);
        for (k = 0; k < sum + j; k++)
            if (strcmp(name, stu[k].num) == 0) {
                printf("��ѧ���Ѵ��ڣ�\n");
                goto input;
            }
        if (k == sum + j) {
            strcpy(stu[sum + j].num, name);
            strcpy(stu[sum + j].pass, "123456");
            strcpy(stu[sum + j].isbd, "δ");
            printf("�����ΰ�д˳������ѧ����Ϣ��\n����\t�Ա�\t���֤��\t����\t�༶\tѧԺ\n");
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
    printf("��ӳɹ����������������ҳ��!\n");
    _getch();
}

//�޸�ѧ������
void xiugai(struct student stu[N]) {
    FILE *fp;
    char i[10];
    int j = 0, k, n, m;
    input:
    printf("�������޸�ѧ����Ϣ��ѧ��:");
    scanf("%s", &i);
    for (k = 0; k < sum; k++) {
        //printf("\n%s\n%s\n",i,stu[k].num);
        if (strcmp(stu[k].num, i) == 0) {
            printf("��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass,
                   stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            break;
        }
    }
    if (k == sum) {
        printf("������������������룡\n");
        goto input;
    }
    printf("������Ҫ�޸ĵĸ���:");
    scanf("%d", &n);
    m = 0;
    while (m < n) {
        printf("��ѡ��Ҫ�޸ĵĵ�%d�����ݣ�1.ѧ��|2.����|3.�Ա�|4.��֤��|5.����|6.����|7.����|8.�༶|9.ѧԺ����", m + 1);
        scanf("%d", &j);
        printf("�������޸ĵ����ݣ�");
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
        printf("�ļ���ʧ��!");
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
    printf("�޸ĳɹ����������������ҳ�棡\n");
    _getch();
}

//��ѯѧ�����ݽ��
int jieguo(struct student stu[N], int k, int n) {
    n++;
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
           stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad,
           stu[k].major);
    return n;
}

//��ѯѧ�����ݸ���
int Alsole(int n) {
    if (n == 0) {
        printf("\nû���ҵ�!!!�����������룡\n");
        return 1;
    } else {
        printf("�ɹ���ѯ��%d��ѧ����Ϣ���������������ҳ�棡\n", n);
        _getch();
        return 0;
    }
}

//��ѯѧ������
void chaxu(struct student stu[N]) {
    char cx[20];
    int j = 0, k, n = 0, y;
    struct student *p;
    p = stu;
    printf("��ѡ��Ҫ��ѯ����Ϣ��1.ѧ��|2.����|3.�Ա�|4.���֤��|5.����|6.����|7.����|8.�༶|9.ѧԺ����");
    scanf("%d", &j);
    input:
    printf("������Ҫ��ѯ�����ݣ�");
    scanf("%s", &cx);
    printf("��ѯ������£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n");
    switch (j) {
        case 1: {
            for (k = 0; k < sum; k++) {
                if (strcmp(stu[k].num, cx) == 0) {
                    n = jieguo(p, k, n);
                    break;
                }
            }
            if (Alsole(n)) {
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
    }
}

//ɾ��ѧ������
void deletee(struct student stu[N]) {
    FILE *fp;
    char sc[10];
    int k, n, j;
    input:
    printf("������Ҫɾ����ѧ��ѧ�ţ�");\
     scanf("%s", &sc);
    for (k = 0; k < sum; k++) {
        //printf("\n%s\n%s\n",i,stu[k].num);
        if (strcmp(stu[k].num, sc) == 0) {
            printf("��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                   stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory,
                   stu[k].cad, stu[k].major);
            break;
        }
    }
    if (k == sum) {
        printf("û�и�ѧ�ţ����������룡\n");
        goto input;
    }
    printf("�Ƿ�ɾ����ѧ����Ϣ(1.��|2.��)��");
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
            printf("�ļ���ʧ��!");
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
        printf("ɾ���ɹ�,�����⽡���أ�");
        _getch();

    } else if (n == 2) {
        printf("�����⽡���أ�");
        _getch();
    } else {
        printf("��������������������룡");
        goto input;
    }
}

//ѧ����Ϣ���
void shouyou(struct student stu[N]) {
    struct student *p;
    char cx[20];
    int j = 0, k, n = 0, y;
    p = stu;
    Px(p);
    printf("��ѡ��Ҫ��ѯ����Ϣ��1.����|2.�Ա�|3.�༶|4.����|5.ѧԺ|6.����|0.���أ���");
    scanf("%d", &j);
    if (j != 1) {
        input:
        printf("������Ҫ��ѯ�����ݣ�");
        scanf("%s", &cx);
        printf("��ѯ������£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n");
    }
    switch (j) {
        case 1: {
            printf("����%d��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n", sum);
            for (k = 0; k < sum; k++) {
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory,
                       stu[k].cad, stu[k].major);
            }
            printf("����������أ�");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
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
                printf("\n�Ƿ�����������Ϣ(1��|0��)\n");
                scanf("%d", &y);
                if (y == 1)
                    goto input;
            }
            break;
        }
    }
}

// �鿴״̬��ע�ᱨ��
void baodao(struct student stu[N]) {
    int i, k;
    FILE *fp;
    printf("ע�ᱨ������:\nѲ��¥ע��ɷѡ�������ȡԿ�ס�ʳ�ð�������ͼ��ݰ������֤��ע�ᱨ���ɹ�\n");
    printf("��ı���״̬�ǣ�");
    if (strcmp(stu[Sid].isbd, "��") == 0) {
        printf("�ѱ���\n");
        printf("�����⽡���أ�");
        _getch();
    } else {
        printf("δ����\n");
        printf("��ȷ����������̲���ע�ᱨ����1.��|2.�񣩣�");
        scanf("%d", &i);
        if (i == 1) {
            strcpy(stu[Sid].isbd, "��");
            if ((fp = fopen("student.txt", "w")) == NULL) {
                printf("�ļ���ʧ��!");
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
            printf("ע��ɹ����������������ҳ�棡\n");
            _getch();
        }
    }
}

// �鿴���޸���Ϣ
void chakai(struct student stu[N]) {
    FILE *fp;
    char i[10];
    int j = 0, k, n = 5, m;
    printf("������Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t����\t����\t����\t�༶\tѧԺ\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[Sid].num, stu[Sid].name, stu[Sid].sex, stu[Sid].Id,
           stu[Sid].pass, stu[Sid].isbd, stu[Sid].dormitory, stu[Sid].cad, stu[Sid].major);
    printf("\n");
    printf("�����ѧ������ֻ���޸�������Ϣ��\n�Ա�\t���֤��\t����\t����\n");
    printf("%s\t%s\t%s\t%s\n", stu[Sid].sex, stu[Sid].Id, stu[Sid].pass, stu[Sid].isbd);
    printf("\n");
    printf("������Ҫ�޸ĵĸ�����1-4,  0Ϊ���أ�:");
    scanf("%d", &n);
    if (n == 0)
        goto input;
    m = 0;
    while (m < n) {
        printf("\n��ѡ��Ҫ�޸ĵĵ�%d�����ݣ�1.�Ա�|2.���֤��|3.����|4.��������", m + 1);
        scanf("%d", &j);
        printf("�������޸ĺ����Ϣ��");
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
        printf("�ļ���ʧ��!");
        exit(1);
    }
    k = 0;
    //����Ϣ����д���ļ�
    while (k < sum) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass,
                stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
        k++;
    }
    fclose(fp);
    printf("�޸ĳɹ�!");
    input:
    printf("�������������ҳ�棡\n");
    _getch();
}

// �鿴���ᡢ�༶��ѧԺ���
void insitite(struct student stu[N]) {
    char cx[20];
    int j = 0, k, n = 0;
    printf("��ѡ��Ҫ��ѯ�����ݣ�1.����|2.�༶|3.ѧԺ|4.���أ���");
    scanf("%d", &j);
    if (j == 1) {
        printf("��Ϣ���£�\nѧ��\t����\t����\t����\t�༶\tѧԺ\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].dormitory, stu[k].dormitory) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("��ѯ��%d��ѧ�����������������ҳ�棡\n", n);
        _getch();
    } else if (j == 2) {
        printf("��Ϣ���£�\nѧ��\t�Ա�\t����\t����\t����\t�༶\tѧԺ\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].cad, stu[k].cad) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("��ѯ��%d��ѧ�����������������ҳ�棡\n", n);
        _getch();
    } else if (j == 3) {
        printf("��Ϣ���£�\nѧ��\t�Ա�\t����\t����\t����\t�༶\tѧԺ\n");
        for (k = 0; k < sum; k++) {
            if (strcmp(stu[Sid].major, stu[k].major) == 0) {
                n++;
                printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                       stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad, stu[k].major);
            }
        }
        printf("\n");
        printf("��ѯ��%d��ѧ�����������������ҳ�棡\n", n);
        _getch();
    } else
        printf("û�и�ѧ����Ϣ������");
}

//ѧ����¼��ѡ�������ҳ
void Student(struct student stu[N]) {
    int i, n = 0;
    struct student *p;
    p = stu;
    char pass[10];
    char num[10];
    input:
    printf("������ѧ�ţ�");
    scanf("%s", &num);
    printf("���������룺");
    scanf("%s", &pass);
    for (i = 0; i < sum; i++) {

        if (strcmp(stu[i].num, num) == 0 && strcmp(stu[i].pass, pass) == 0) {
            Sid = i;
            break;
        }
    }
    if (i == sum) {
        printf("������������������룡\n");
        goto input;
    }
    while (n < 5) {
        system("cls");
        printf("\t\t\t��������������������������������������������������������������������\n");
        printf("\t\t\t��             ѧ��               ��\n");
        printf("\t\t\t��������������������������������������������������������������������\n");
        printf("\t\t\t��      1. �鿴״̬��ע�ᱨ��     ��\n");
        printf("\t\t\t��      2. �鿴���޸ĸ�����Ϣ     ��\n");
        printf("\t\t\t��      3. �鿴���ᡢ�༶��ѧԺ���\n");
        printf("\t\t\t��      4. �鿴ѧУ��ƽ��ͼ       ��\n");
        printf("\t\t\t��      0. �˳�                   ��\n");
        printf("\t\t\t��                                ��\n");
        if (Sid != (-1)) {
            printf("\t\t\t��         ��ӭ%s��¼��          ��\n", stu[Sid].name);
        }
        printf("\t\t\t��������������������������������������������������������������������\n\n");
        printf("��ѡ��0-4����");
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

//����Աҳ��
void ad1(struct student stu[N]) {
    int n = 0;
    struct student *p;
    p = stu;
    while (n < 6) {
        system("cls");
        printf("\t\t����������������������������������������������������������������\n");
        printf("\t\t��             ����Ա           ��                             ��\n");
        printf("\t\t����������������������������������������������������������������\n");
        printf("\t\t��      1. ���ѧ��             ��          *********          ��\n");
        printf("\t\t��      2. �޸�ѧ����Ϣ         ��        *************        ��\n");
        printf("\t\t��      3. ��ѯѧ����Ϣ         ��      ****************       ��\n");
        printf("\t\t��      4. ɾ��ѧ��             ��    ********************     ��\n");
        printf("\t\t��      5. ��������             ��  ************************   ��\n");
        printf("\t\t��      0. �˳�                 ��**************************** ��\n");
        printf("\t\t����������������������������������������������������������������\n\n");
        printf("��ѡ��0-5����");
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

//����Ա��¼����
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
    printf("\t\t\t����������������������������������������������������������������\n");
    printf("\t\t\t��             ����Ա           ��\n");
    printf("\t\t\t����������������������������������������������������������������\n");
    printf("\t\t\t��      1. ��¼                 ��\n");
    printf("\t\t\t��      2. ע��                 ��\n");
    printf("\t\t\t��      3. �һ�����             ��\n");
    printf("\t\t\t��      0. �˳�                 ��\n");
    printf("\t\t\t����������������������������������������������������������������\n\n");
    printf("�������ѡ��");
    scanf("%d", &choose);
    if (choose == 1) {
        input:
        printf("���������Ա�ʺţ�");
        scanf("%s", &id);
        //gets(id);
        printf("���������Ա���룺");
        scanf("%s", &pass);
        //gets(pass);
        for (i = 0; i < sum1; i++) {
            if (strcmp(add[i].id, id) == 0 && strcmp(add[i].pass, pass) == 0) {
                break;
            }
        }
        if (i == sum1) {
            printf("������������������룡\n");
            goto input;
        }
        ad1(p);
        choose = 4;
    } else if (choose == 2) {
        if ((fp = fopen("student.txt", "a")) == NULL) {
            printf("�ļ���ʧ��!");
            exit(1);
        }
        input1:
        printf("��������Ҫע��ĵ绰���룺");
        scanf("%s", &id);
        printf("\n�������ֻ���֤�룺");
        scanf("%s", &f);
        if (strcmp(f, ch) == 0) {
            printf("\n��֤����������º˶ԣ�����\n\n");
            goto input1;
        }
        for (k = 0; k < sum1; k++)
            if (strcmp(id, add[k].id) == 0) {
                printf("�õ绰�����Ѵ��ڣ�����������.\n\n");
                goto input1;
            }
        printf("���������룺");
        scanf("%s", &pass);
        strcpy(add[sum1].id, id);
        strcpy(add[sum1].pass, pass);
        fprintf(fp, "%s\t%s\n", add[sum1].id, add[sum1].pass);
        fclose(fp);
        sum1 = sum1 + 1;
        printf("ע��ɹ��������µ�¼");
        scanf("%s", &f);
        exit(1);
    } else if (choose == 3) {
        if ((fp = fopen("student.txt", "a")) == NULL) {
            printf("�ļ���ʧ��!");
            exit(1);
        }
        printf("������Ҫ�һص��˺ţ�");
        scanf("%s", &id);
        for (k = 0; k < sum1; k++)
            if (strcmp(id, add[k].id) == 0) {
                input2:
                printf("\n��������֤�룺");
                scanf("%s", &f);
                if (strcmp(f, ch) == 0) {
                    printf("\n��֤ͨ����\n");
                    printf("��������ǣ�%s", add[k].pass);
                    scanf("%s", &f);
                    exit(1);
                } else {
                    printf("\n��֤��ͨ��������");
                    goto input2;
                }

            }
        printf("���˺�û��ע�ᣡ����\n");
        scanf("%s", &f);
        exit(1);
    } else
        exit(1);

}

//������
int main() {
    int n, flag;
    struct student *p, stu[N];
    struct ad *p1, techer[M];
    p = stu;
    wenjian(p);//��������
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
        //system("cls");  //��������
    }
    return 0;
}
