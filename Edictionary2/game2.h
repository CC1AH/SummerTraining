#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int num; int health=100;int coin=100;int lvl=1;

void bosss(){ 
    puts("Ƥ����һ�¾͵�������ҹ֣�����ָ���ƽ��");
    Sleep(3000);
    puts("��л���汾��Ϸ!");
    Sleep(3000);
};

void casino(int*c)
{
    int a; int d;
    S: printf("��ӭ�����������ĳ�,ÿ�β������ӵ����н�Ŷ��ÿ��ֻҪ10coin,��Ŀǰ��coin��:%d,���밴����\"1\"\n�˳��밴\"0\".\n",*c);
    scanf("%d",&a);

    if(a==1){
        *c-=10;
        printf("�������ڷ��ҡ���У�����������Ϊ�ĵ���(1��6��)\n");
        scanf("%d",&d);
        if((rand()%6)+1==d){
            *c+=20;
            printf("��ϲ�������ˣ�����һ������!");
        }
        else{puts("���ź������´���,����û��");}
    }
    else{return;}
    goto S;
}

void theblackforest(int *h,int *c,int *l){
srand(time(0));
A:puts("�������������ˣ�??\n\n");
Sleep(2000);
puts("??ʹ���ؼ�\"�޻�??֮��\"��������");
Sleep(1000);
if((rand()%10)>5)
{ *h-=30;
printf("�������ж��ˣ�����ֵ��ʣ%d\n\n",*h);
}
else{
printf("��ɹ�����������Ķ�Һ����,����ֵ��ʣ%d\n",*h);
*c+=100;
lvl++;
printf("\nƤ����ʹ�ÿ����ڳɹ�����Һ���������������������������ˣ����100���??,1000����!");
}
Sleep(2000);
puts("\nǧ������??�����ˣ�\n??ʹ���ؼ�\"�ѿ�˺ҧ\"���ڿ�ҧ�����㣡");
Sleep(2000);
if((rand()%10)>5)
{ *h-=30;
printf("���ã��㱻��ҧҧ���ˣ�����ֵ��ʣ%d",*h);


}
else{
*c+=100;
*l++;
printf("\n����ҧ���ˣ�Ƥ����ʹ�ÿ����ڽ�������������ײ���ˣ���Ҽ�100�������1000\n");
Sleep(2000);

}
puts("\n���ã�ɭ��֮��??�����ˣ�??ʹ���ؼ�\"�����\"�������㣡");
if((rand()%10)>5){
*h-=80;
printf("??ʹ�������ݺݵ��������㣡����ֵ��ʣ %d",*h);Sleep(2000);

}
else{
*l+=2;
*c+=10000;


puts("\n��ɹ����������𣬲���Ƥ����ɹ�ʹ�ÿ����ڷ����������ɭ��֮�������ˣ���Ҽ�10000,�����2000");Sleep(2000);}
if(*h<=0 || *l>=3){

printf("���Ѿ��������������ڵĵȼ�������ս��ҹ��ˣ��������ɭ�ֵ��˽�����\n");Sleep(2000);


}
else{goto A;}
}

struct baozi{
char name[20];
char skill[200];
double health;
char weakpoint[100];
}boss; 
void bossinfo(struct baozi *p){
printf("%s\n%s\n%f\n%s\n",p->name,p->skill,p->health,p->weakpoint);}
void tale(){
fprintf(stdout,"�ںܾúܾ���ǰ���귨��½������һֻ����__��ҹ�__\n\n\n");
Sleep(2000);
fprintf(stdout,"��ԭ�������࣬��ĸ��������Ϊ�������ڳ����ª��ʼ�ս������䣬���հѴ��и��˼�Ů\n");
Sleep(2000);
fprintf(stdout,"���������ģ����Ա������࣬��һ������??\a\a\a������籩������ӣ�����֪��ô�ģ��ɹ��ɽٳ�����ҹ�............\n\n\n");
Sleep(5000);

fputs(".....���´���ʱ�Ϳ�ʼ��.....\n����ʹ��:ι�����ѣ�������һ�������ע�ⰲȫ����ô�����ܵ����ɭ�����أ�����һֻPEKKA�ɣ��Ժ����ѵ���������Ա�����İ�ȫ��\n\n",stdout);
Sleep(2000);
fputs("�����������������һֻ�ܿɰ���??Ƥ����ż�������³������ڣ�P.....k.....p......k\n\n",stdout);
Sleep(2000);


}

void game2()
{
struct baozi * b=&boss;
sprintf(b->name,"��ҹ�");
sprintf(b->skill,"�ؼ�:�Ӱ���,����Ƥ����ѹ���");
b->health=555.55;
sprintf(b->weakpoint,"����:������ȻƤ�񣬷����޵У��������ʹ�÷������������׻��ư���Ƥ");
tale();
while(1){
B:fputs("\n��ӭ���������Ϸ��Ƥ�����ս��ҹ֡�,���̰�\"1\"�鿴������Ϣ\n��\"2\"�������ɭ�ִ������\n��\"3\"���뿨�����ĳ�\n��\"4\"�������Ҥ�����\n",stdout);
scanf("%d",&num);
if(num==1){
break;
}
else if(num==2)
{
break;

}
else if(num==3){
break;
}
else if(num==4){break;}
else{

puts("�������������1����2����3����4");

}
}
switch(num){
case 1:
bossinfo(b);
break;
case 2:
theblackforest(&health,&coin,&lvl);
break;
case 3:
casino(&coin);
break;
case 4:
if(lvl>=3){
bosss();
return;
}
default:
;

}
goto B;

}