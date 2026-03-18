#include <windows.h>
#include <stdio.h>
#include "dialog.h"
#include "plane.h"




// 添加航班对话框过程函数
INT_PTR CALLBACK AddPlaneDialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // 获取所有输入框的内容
                    char szID[256], szWholeSeat[256], szRestSeat[256];
                    char szTakeOffYear[256], szTakeOffMonth[256], szTakeOffHour[256];
                    char szTakeOffMinute[256], szTakeOffSecond[256];
                    char szLandingYear[256], szLandingMonth[256], szLandingHour[256];
                    char szLandingMinute[256], szLandingSecond[256];
                    char szPrize[256], szSeatCategory[256];

                    GetDlgItemText(hDlg, IDC_EDIT_ID, szID, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_WHOLE_SEAT, szWholeSeat, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_REST_SEAT, szRestSeat, 256);
                    
                    GetDlgItemText(hDlg, IDC_EDIT_TAKE_OFF_TIME_YEAR, szTakeOffYear, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_TAKE_OFF_TIME_MONTH, szTakeOffMonth, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_TAKE_OFF_TIME_HOUR, szTakeOffHour, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_TAKE_OFF_TIME_MINUTE, szTakeOffMinute, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_TAKE_OFF_TIME_SECOND, szTakeOffSecond, 256);
                    
                    GetDlgItemText(hDlg, IDC_EDIT_LANDING_TIME_YEAR, szLandingYear, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_LANDING_TIME_MONTH, szLandingMonth, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_LANDING_TIME_HOUR, szLandingHour, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_LANDING_TIME_MINUTE, szLandingMinute, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_LANDING_TIME_SECOND, szLandingSecond, 256);
                    
                    GetDlgItemText(hDlg, IDC_EDIT_PRIZE, szPrize, 256);
                    GetDlgItemText(hDlg, IDC_EDIT_SEAT_CATEGORY, szSeatCategory, 256);

                    // 验证数据
                    if (strlen(szID) == 0) {
                        MessageBox(hDlg, "航班ID不能为空", "错误", MB_ICONERROR);
                        return TRUE;
                    }

                    // 创建新的航班信息并添加到链表
                    Plane_information* newPlane = (Plane_information*)malloc(sizeof(Plane_information));
                    if (newPlane != NULL) {
                        strcpy(newPlane->id, szID);
                        newPlane->whole_seat = atoi(szWholeSeat);
                        newPlane->rest_seat = atoi(szRestSeat);
                        
                        newPlane->take_off_time[0] = atoi(szTakeOffYear);
                        newPlane->take_off_time[1] = atoi(szTakeOffMonth);
                        newPlane->take_off_time[2] = atoi(szTakeOffHour);
                        newPlane->take_off_time[3] = atoi(szTakeOffMinute);
                        newPlane->take_off_time[4] = atoi(szTakeOffSecond);
                        
                        newPlane->landing_time[0] = atoi(szLandingYear);
                        newPlane->landing_time[1] = atoi(szLandingMonth);
                        newPlane->landing_time[2] = atoi(szLandingHour);
                        newPlane->landing_time[3] = atoi(szLandingMinute);
                        newPlane->landing_time[4] = atoi(szLandingSecond);
                        
                        newPlane->prize = atof(szPrize);
                       // strcpy(newPlane->Seat_Category, szSeatCategory);
                        
                        // 添加到链表
                        newPlane->next = g_head;
                        g_head = newPlane;
                        
                        MessageBox(hDlg, "航班添加成功", "成功", MB_ICONINFORMATION);
                    }

                    EndDialog(hDlg, IDOK);
                    return TRUE;
                }

                case IDCANCEL:
                    EndDialog(hDlg, IDCANCEL);
                    return TRUE;
            }
            break;
    }
    return FALSE;
}
