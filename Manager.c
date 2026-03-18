#include "Manager.h"

/*@brief	管理员登录
* @param	windows句柄
* @return	无
*/
void Manager_Login(HWND hwnd)
{
    char username[20], password[20];
    GetDlgItemText(hwnd, ID_EDIT_USERNAME, username, 20);
    GetDlgItemText(hwnd, ID_EDIT_PASSWORD, password, 20);
    
    if(strcmp(username, MANAGER_ACCOUNT) == 0 && strcmp(password, MANAGER_PASSWORD) == 0)
    {
        MessageBox(hwnd, "管理员登录成功", "提示", MB_OK);
        ShowAdminWindow(hwnd);
    }
    else
    {
        MessageBox(hwnd, "管理员登录失败", "提示", MB_OK);
    }
}


Plane_information* Manager_Delete_Plane(HWND hwnd,Plane_information*head)//多次一举的函数，不过相比直接用Delete_Plane函数，这个函数多了全局头指针的传参和刷新界面
{
    head=Delete_Plane(hwnd,head);
    g_head=head;//更新全局头指针,不然删除了但是全局头指针没变，刷新界面还是会显示被删除的航班，同时这行代码可以减少RefreshPlane的传参
    //这么一想，如果有地方需要刷新都得多写这一行代码，感觉不是很好
    //或者呢，下方多传一个参数
    RefreshPlaneList(hwnd);
    return head;
}

/**
 * @brief 显示添加航班对话框


void ShowAddPlaneDialog(HWND hwnd)
{
    // 简化版：使用DialogBox，这里用输入框演示
    char id[20] = "", whole_seat[10] = "", rest_seat[10] = "", prize[10] = "";
    char takeoff[50] = "", landing[50] = "";
    
    // 在实际应用中，这里应该创建一个对话框
    // 为简化，我们使用一个输入对话框
    id[0] = '\0';
    if(InputBox(hwnd, "请输入航班号:", id, 20))
    {
        // 这里简化处理，实际应该获取所有信息
        int w_seat = 200, r_seat = 200;
        float pr = 800.0;
        int takeoff_time[5] = {2024, 3, 15, 8, 0};
        int landing_time[5] = {2024, 3, 15, 10, 30};
        
      
        RefreshPlaneList(hwnd);
    }
    else//这里做了一个输入失败的改动
        //即没有输入信息就结束或输入不正确
        //暂时还没想到其它bug
    {
        MessageBox(hwnd,"没有输入，请重新添加","提示",MB_OK);

    }
}
*/
// 简单的输入框函数
BOOL InputBox(HWND hwnd, char* prompt, char* result, int max_len)
{
    //这里打算再写一个bool类型函数判断输入 这样方便后续tourist也一起改动
    /*if(){

        return FALSE;
    }*/
    MessageBox(hwnd, "在实际应用中，这里会弹出输入对话框", "提示", MB_OK);
    strcpy(result, "CA1003");
    return TRUE;
}

/**
 * @brief 判断输入是否全输入完成或输入不正确
 */
BOOL InputError(HWND hwnd, char* prompt, char* result, int max_len)
{
    
}

/**
 * @brief 显示修改航班对话框
 */
void ShowUpdatePlaneDialog(HWND hwnd)
{
    char id[20] = "";
    if(InputBox(hwnd, "请输入要修改的航班号:", id, 20))
    {
        // 简化处理
      
        RefreshPlaneList(hwnd);
    }
}