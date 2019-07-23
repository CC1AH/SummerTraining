#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int num; int health=100;int coin=100;int lvl=1;

void bosss(){ 
    puts("皮卡丘一下就电死了吴家怪，人类恢复了平静");
    Sleep(3000);
    puts("感谢您玩本游戏!");
    Sleep(3000);
};

void casino(int*c)
{
    int a; int d;
    S: printf("欢迎来到卡丽熙赌场,每次猜中塞子点数有奖哦！每次只要10coin,您目前的coin数:%d,玩请按键盘\"1\"\n退出请按\"0\".\n",*c);
    scanf("%d",&a);

    if(a==1){
        *c-=10;
        printf("点数正在疯狂摇动中，请输入您认为的点数(1到6点)\n");
        scanf("%d",&d);
        if((rand()%6)+1==d){
            *c+=20;
            printf("恭喜您猜中了！奖励一倍本金!");
        }
        else{puts("很遗憾，您猜错了,本金没收");}
    }
    else{return;}
    goto S;
}

void theblackforest(int *h,int *c,int *l){
srand(time(0));
A:puts("万年树妖出现了！??\n\n");
Sleep(2000);
puts("??使用特技\"无花??之毒\"喷向了你");
Sleep(1000);
if((rand()%10)>5)
{ *h-=30;
printf("不好你中毒了！生命值还剩%d\n\n",*h);
}
else{
printf("你成功躲避了树妖的毒液攻击,生命值还剩%d\n",*h);
*c+=100;
lvl++;
printf("\n皮卡丘使用空气炮成功将毒液向万年树妖，万年树妖被击败了！获得100金币??,1000经验!");
}
Sleep(2000);
puts("\n千年蛇妖??出现了！\n??使用特技\"裂空撕咬\"！腾空咬向了你！");
Sleep(2000);
if((rand()%10)>5)
{ *h-=30;
printf("不好！你被蛇咬咬伤了！生命值还剩%d",*h);


}
else{
*c+=100;
*l++;
printf("\n蛇妖咬空了！皮卡丘使用空气炮将蛇妖吹向树上撞死了！金币加100，经验加1000\n");
Sleep(2000);

}
puts("\n不好！森林之王??出现了！??使用特技\"灭天火\"砸向了你！");
if((rand()%10)>5){
*h-=80;
printf("??使用灭天火狠狠地砸向了你！生命值还剩 %d",*h);Sleep(2000);

}
else{
*l+=2;
*c+=10000;


puts("\n你成功躲过了灭天火，并且皮卡丘成功使用空气炮反弹了灭天火，森林之王被灭了！金币加10000,经验加2000");Sleep(2000);}
if(*h<=0 || *l>=3){

printf("你已经死亡或者你现在的等级可以挑战吴家怪了，本次奇幻森林到此结束！\n");Sleep(2000);


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
fprintf(stdout,"在很久很久以前，玛法大陆存在着一只怪兽__吴家怪__\n\n\n");
Sleep(2000);
fprintf(stdout,"它原先是人类，它母亲卖包子为生，由于长相丑陋，始终交不上配，最终把处男给了妓女\n");
Sleep(2000);
fprintf(stdout,"它怀恨在心，誓言报复人类，在一次闪电??\a\a\a雷鸣狂风暴雨的日子，它不知怎么的，成功渡劫成了吴家怪............\n\n\n");
Sleep(5000);

fputs(".....故事从那时就开始了.....\n怪物使者:喂！醒醒！孩子你一个人外出注意安全！怎么可以跑到奇幻森林玩呢？送你一只PEKKA吧，以后积极训练它，可以保护你的安全！\n\n",stdout);
Sleep(2000);
fputs("孩子醒来发现身边有一只很可爱的??皮卡丘，偶尔还会吐出空气炮，P.....k.....p......k\n\n",stdout);
Sleep(2000);


}

void game2()
{
struct baozi * b=&boss;
sprintf(b->name,"吴家怪");
sprintf(b->skill,"特技:扔包子,包子皮厚很难攻击");
b->health=555.55;
sprintf(b->weakpoint,"弱点:包子虽然皮厚，防御无敌，但是如果使用反作用力会轻易击破包子皮");
tale();
while(1){
B:fputs("\n欢迎来到睿智游戏《皮卡丘大战吴家怪》,键盘按\"1\"查看怪物信息\n按\"2\"进入奇幻森林打怪升级\n按\"3\"进入卡丽熙赌场\n按\"4\"进入吴家窑打包子\n",stdout);
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

puts("输入错误，请输入1或者2或者3或者4");

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