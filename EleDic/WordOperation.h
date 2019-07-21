#ifndef WORDOPERATION_H_INCLUDED
#define WORDOPERATION_H_INCLUDED
#define BASICSTRUCTRUE_H_INCLUDED
/**
* 该文件描述了电子辞典的单词操作模块（单词的增，改，删）
* @author 邢国浩
* 2019/7/21
* copyright reserved
*/

//包含的函数原型
nodeptr addWord(nodeptr list);
nodeptr deleteWord(nodeptr list);
nodeptr modifyWord(nodeptr list);



//包含函数原型的基本内容
/**
* 增添单词
* 以接受的指针为头按字母顺序向链表中增加一个单词
* 由于是用户增加的单词，可能有错误出现，故文件中
* 将不会有体现。只会在链表中增加。
* 但是收藏夹功能中将允许用户在文件中添加自己的单词
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr addWord(nodeptr list){
    struct content input;
    nodeptr judge;
    nodeptr add;

	fflush(stdin);
    printf("请输入一个英文单词：");
    scanf("%s",&input.word);
    printf("请输入这个英文单词的解释：");
	scanf("%s", &input.mean);

    //判是否已经存在
    if((judge=ExistOrNot(list,input.word))==NULL)
    {
		//新建add
        add=(nodeptr)malloc(sizeof(node));
        if(add != NULL)
        {
            strcpy((add->data).word,input.word);
            strcpy((add->data).mean,input.mean);
            //把add中的英文单词首字母按字母表顺序插入list链表中
            InsertList(list,add);
        }
    }
    else
    {
        printf("该词条已存在\n");
        printf("%10s %10s\n","英文单词","中文解释");
        printf("%10s %10s\n",(judge->data).word,(judge->data).mean);
    }
    return list;
}

/**
* 删除单词
* 以接受的指针为头从链表中删除一个词  由于是用户删除
* 的单词，故文件中将不会有体现。只会在链表中增加。但
* 是收藏夹功能中将允许用户在文件中删除自己的单词
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr deleteWord(nodeptr list){
    char deleteWord[WORDNUM+1];

	fflush(stdin);
    printf("请输入要删除的英文单词：");
	scanf("%s", &deleteWord);

	//寻找需要删除节点的前驱和后继
	nodeptr aim,last;
	aim = list;
	while(strcmp((aim->data).word,deleteWord)!=0&&aim!=NULL){
        last = aim;
        aim = aim->next;
	}

	//如果没有这个存在的节点
	if(aim==NULL)
	{
		printf("不存在该单词\n");
	}
	//如果存在非空的合规节点
	else{
        last->next = aim->next;
        free(aim);
        printf("单词删除成功！");
	}

	return list;
}

/**
* 修改单词
* 以接受的指针为头从链表中修改一个单词  由于是用户改
* 的单词，故文件中将不会有体现。只会在链表中修改。但
* 是收藏夹功能中将允许用户在文件中修改自己的单词
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr modifyWord(nodeptr list){
    struct content edit;
    nodeptr judge;
    char editWord[WORDNUM+1];

	fflush(stdin);
    printf("请输入要修改的英文单词：");
	scanf("%s", &editWord);

    //判是否存在
    if((judge=ExistOrNot(list,editWord))!=NULL)
    {
        fflush(stdin);
        printf("请输入要修改成的英文单词：");
		scanf("%s", &edit.word);
        printf("请输入要修改成的英文单词的中文解释：");
		scanf("%s", &edit.mean);
        strcpy((judge->data).word,edit.word);
        strcpy((judge->data).mean,edit.mean);
		printf("修改成功");
    }
    else
        printf("不存在该词条\n");
    return list;
}

#endif // WORDOPERATION_H_INCLUDED
