#ifndef ENTERTAINMENT_H_INCLUDED
#define ENTERTAINMENT_H_INCLUDED
#include<string.h>
#include<windows.h>
/**
* ���ļ������˵��Ӵǵ�����ֹ���ģ��
* ���ģ���ǲ�����Ŀ�������������ģ��
* @author �Ϲ���
* 2019/7/23
* copyright reserved
*/

int ifLog = 0;
//�����ĺ���ԭ��
void EntertainmentMenu();
void log();
void openWithSystem();

//��������ԭ�͵Ļ�������
/**
* ���ֹ��ܲ˵�
* ûɶ��˵��
*/
void EntertainmentMenu(){
    printf("\n\n\n                       ��ӭ�������ֽ��棬�ý���Ĺ�����ҪVIP��½֮��ſ���ʹ�ã�����015��\n");
	printf("                        ___________________________________________________________________________\n");
	printf("                        |------------------(1)��Ϸ�ȴ������У���ģ�����עgit���Ƿ���£����������ڲ�����...��|\n");
    printf("                        |------------------(2)(windows)������ԭʼ��Դ�ļ�-----------------------------------|\n");
    printf("���������ѡ��\n");

	int choose;
	fflush(stdin);
	printf("�����������������(1-2)��");

	//���û���ѡ����0-10֮��ķ�Χ����ʾ�û������������������
	while((scanf("%d", &choose)!=1) || (choose<0||choose>2))
	{
		printf("�����������������(1-2)��");
		fflush(stdin);
	}

    switch(choose){
        case 1:
            log();
            break;
        case 2:
            openWithSystem();
            break;
        default:
            break;
    }
}

/**
* ��½����
* Ҫ���û�����VIP�����λ��ᣬ������֮������20����ܽ�����
*/
void log(){
    if(ifLog){
        printf("���Ѿ���½����������ģ��Ĺ��ܰ�");
        return;
    }
    char code[30];
    fflush(stdin);
	printf("��������VIP�루015��");
	scanf("%s", &code);

	int leftChance = 2;

	//���û�û������015ʱ��ʾ�û������������������,�ܹ�3�λ���
	while(strcmp(code,"015")!=0)
	{
        if(leftChance!=0){
		printf("�����������������, ʣ��%d����",leftChance);
		fflush(stdin);
		leftChance--;
		scanf("%s", &code);
        }
        else{
            printf("�Բ������ǻ��������ԡ���20�������");
            Sleep(20000);
            return;
        }
	}
    printf("���Ѿ���½����������ģ��Ĺ��ܰ�");
    ifLog = 1;
}

/**
* �ļ�ϵͳ��
* ��½��windows��Դ����������ô������ļ�
*/
void openWithSystem(){
    if(!ifLog){
        log();
        return;
    }
    printf("���������е���Դ�ļ�");
    Sleep(300);
    ShellExecute(NULL,"open","dictionary.txt",NULL,NULL,SW_NORMAL);
    ShellExecute(NULL,"open","collections.txt",NULL,NULL,SW_NORMAL);
    ShellExecute(NULL,"open","dictationInfo.txt",NULL,NULL,SW_NORMAL);
}
#endif // ENTERTAINMENT_H_INCLUDED
