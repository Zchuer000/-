// FILEleaning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


//参考本章授课视频中的文件读写部分，通过编写程序，实现下面的功能：
//将玩家信息（可以包括名字、魔法值、健康值等信息），保存到硬盘中。
//将保存好的文件读取进来，并进行输出。

#include <iostream>
#include <time.h>
#include <stdlib.h>


int main()
{

    typedef struct
    {
        char name[16];
        int mana = 0;
        int health = 0;


    }players;/*players是类型名*/
    FILE* actor;
    FILE* pown;
    srand(time(NULL));
    players P[3];
    //////////////////生成actor属性//////////////////////////
    
    for (int i = 0; i < 3; i++) {
        printf("请输入角色%d名称\n", i);
        scanf_s("%s", &P[i].name,16);
        //printf("%s\n", P[i].name);
    }
    for (int j = 0; j < 3; j++)
    {
        P[j].mana = rand() % 100;
        P[j].health = rand() % 100;
        printf("Name:%s Mana：%d  Health：%d\n", P[j].name, P[j].mana, P[j].health);
    }
    ////////////////////////写入数据/////////////////////////////

    fopen_s(&actor, "actor.txt", "w"); 
    fopen_s(&pown, "pown.txt", "wb");
    if (fopen_s != NULL)
    {
        for (int k = 0; k < 3; k++)
        {
            fprintf(actor, "%s  %d  %d", P[k].name, P[k].mana, P[k].health);
            fprintf(pown, "%s  %d %d\n", P[k].name, P[k].mana, P[k].health);
        }
        fclose(actor); 
        
    }
    else
        printf("打开失败 甭玩了");
    /////////////////////////////////////////////////////
    printf("///////////////////写入完毕，开始读取数据///////////////////////\n");
    /////////////////////////////////读取数据******打开文件********************************
    fopen_s(&actor, "actor.txt", "r");
    
    ///////////////////////////////
    struct hero
    {
        char HerosName[16];
        int MANA = 0;
        int Health = 0;
    } Hero[3];
    int sum = 0;

    for (int l = 0; l < 3; l++)
    {
       // fscanf_s(actor, "%s %d %d", P[l].name,16, P[l].mana, P[l].health);
        fscanf_s(actor, "%s %d %d", &Hero[l].HerosName, 16, &Hero[l].MANA, &Hero[l].Health);
       // sum = P[l].mana + P[l].health;
        sum = Hero[l].MANA + Hero[l].Health;
        //printf("英雄%s  你的法力值为%d  生命值为%d\n", P[l].name, P[l].mana, P[l].health);
        printf("英雄%s  你的法力值为%d  生命值为%d\n",Hero[l].HerosName ,Hero[l].MANA, Hero[l].Health);
        if (sum > 50)
        {
            printf("Strong enough to get in\n\n");
        }
        else
            printf("Later, you rookie\n\n");
    }

};

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
