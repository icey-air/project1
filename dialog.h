#ifndef _DIALOG_H
#define _DIALOG_H
#include <windows.h>
#include "plane.h"
#include <stdio.h>
// 对话框和控件ID定义
#define IDD_ADD_PLANE_DIALOG          201

#define IDC_EDIT_ID                   114514
#define IDC_EDIT_WHOLE_SEAT           350204
#define IDC_EDIT_REST_SEAT            3502041
#define IDC_EDIT_TAKE_OFF_TIME_YEAR   3502042
#define IDC_EDIT_TAKE_OFF_TIME_MONTH  3502043
#define IDC_EDIT_TAKE_OFF_TIME_HOUR   3502044
#define IDC_EDIT_TAKE_OFF_TIME_MINUTE 3502045
#define IDC_EDIT_TAKE_OFF_TIME_SECOND 3502046
#define IDC_EDIT_LANDING_TIME_YEAR    3502047
#define IDC_EDIT_LANDING_TIME_MONTH   3502048
#define IDC_EDIT_LANDING_TIME_HOUR    3502049
#define IDC_EDIT_LANDING_TIME_MINUTE  3502050
#define IDC_EDIT_LANDING_TIME_SECOND  3502051
#define IDC_EDIT_PRIZE                3502052
#define IDC_EDIT_SEAT_CATEGORY        3502053


extern Plane_information* g_head; 
INT_PTR CALLBACK AddPlaneDialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void RefreshPlaneList(HWND hwnd);
#endif
