#include "tourist.h"
#include "Apply.h"
#include "plane.h"
#include <stdio.h>
#include "function.h"

/*@breif    预定机票
* @param	当前账户结构体地址
* @param	航班信息结构体头指针
* @return	无
*/
void Book_Ticket(struct tourist*Now_Account,struct Plane_information*head)
{
    struct Plane_information* Book_Plane;

    Book_Plane=Find_Plane_Day(head);
    if(Book_Plane!=NULL)
    {
        printf("是否要预定航班%s的机票(y/n)\n",Book_Plane->id);
        int key;
        key=quit();

        if(key==YES)
        {
            Now_Account->plane=Book_Plane;
            printf("已预定航班%s的机票\n",Book_Plane->id);
        }
        else if(key==NO)
        {
            printf("未预定航班%s的机票\n",Book_Plane->id);
        }
        else
        {
            printf("输入错误\n");
        }
        
    }
    else
    {
        printf("未查找到相应的航班\n");
    }

}

/*@breif    取消预定机票
* @param	当前账户结构体地址
* @return	无
*/
void Cancel_Ticket_Reservation(struct tourist*Now_Account)
{
    printf("正在为您查询已预定的机票");
    List_Ticket_Reservation(Now_Account);
    printf("是否要取消预定的机票(y/n)\n");
    char key;
    while(1)
    {
        scanf("%c",&key);
        if(key=='y')
        {
            Now_Account->plane=NULL;
            printf("已取消预定的机票\n");
            break;
        }
        else if(key=='n')
        {
            printf("未取消预定的机票\n");
            break;
        }
        else
        {
            printf("输入错误，请重新输入(y/n)\n");
        }
    }
}

/*@breif    查找并例出已预定的机票
* @param	当前账户结构体地址
* @return	无
*/
void List_Ticket_Reservation(struct tourist*Now_Account)
{
    if(Now_Account->plane!=NULL)
    {
        printf("您已预定的机票信息如下：\n");
        printf("航班号：%s\n",Now_Account->plane->id);
        printf("起飞时间：%d-%d-%d %d:%d\n",Now_Account->plane->take_off_time[0],Now_Account->plane->take_off_time[1],Now_Account->plane->take_off_time[2],Now_Account->plane->take_off_time[3],Now_Account->plane->take_off_time[4]);
        printf("着陆时间：%d-%d-%d %d:%d\n",Now_Account->plane->landing_time[0],Now_Account->plane->landing_time[1],Now_Account->plane->landing_time[2],Now_Account->plane->landing_time[3],Now_Account->plane->landing_time[4]);
        printf("价格：%d\n",Now_Account->plane->prize);
    }
    else
    {
        printf("您没有预定任何机票\n");
    }
}
