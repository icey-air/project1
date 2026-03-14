#include <windows.h>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "function.h"


/*@breif    查找并例出已预定的机票
* @param	当前账户结构体地址
* @return	无
*/
int Get_Key_YES_NO(void)
{   

    char key=0;
    while(1)
    {
        if(_kbhit())//应该在这之前或者前面清空一下键盘输入会好点
        {
            key=_getch();
        
        if(key=='y')
        {
        return YES;

        }
        else if(key=='n')
        {
            return NO;
        }
        else
        {
            printf("输入错误 请重新输入\n");
        }
        }
    }
    

}