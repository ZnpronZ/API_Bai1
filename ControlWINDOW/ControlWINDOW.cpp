﻿// ControlWINDOW.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ControlWINDOW.h"

#define MAX_LOADSTRING 100
#define ID_EDITHT 0
#define ID_STATICHT 1
#define ID_OK 2
#define ID_CANCEL 3
#define ID_checkGame 4
#define ID_checkMusic 5
#define ID_Piano 6
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hwndHoTen, hwndHoTen_static,btn_OK,btn_CanCel,checkMusic,checkGame,check3Piano;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CONTROLWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONTROLWINDOW));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CONTROLWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CONTROLWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR noidung[100],hoten[30];
    static int lengh;
    switch (message)
    {
    case WM_CREATE:
        hwndHoTen = CreateWindow(TEXT("edit"), TEXT("Vương Toàn Đạt"), WS_CHILD|WS_VISIBLE|WS_BORDER,200,90,200,50,hWnd,(HMENU)ID_EDITHT,NULL,NULL);
        hwndHoTen_static = CreateWindow(TEXT("static"), TEXT("Họ và tên :"), WS_CHILD | WS_VISIBLE | WS_BORDER|SS_RIGHT, 50, 90, 150, 50, hWnd, (HMENU)ID_STATICHT, NULL, NULL);
        btn_OK = CreateWindow(TEXT("button"), TEXT("OK"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 145, 60, 35, hWnd, (HMENU)ID_OK, NULL, NULL);
        btn_CanCel = CreateWindow(TEXT("button"), TEXT("Cancel"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON , 115, 145, 60, 35, hWnd, (HMENU)ID_CANCEL, NULL, NULL);
        checkGame = CreateWindow(TEXT("button"), TEXT("Game"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 50, 185, 100, 35, hWnd, (HMENU)ID_checkGame, NULL, NULL);
        checkMusic = CreateWindow(TEXT("button"), TEXT("Music"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 50, 225, 100, 35, hWnd, (HMENU)ID_checkMusic, NULL, NULL);
        check3Piano = CreateWindow(TEXT("button"), TEXT("Piano"), WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, 50, 265, 100, 35, hWnd, (HMENU)ID_Piano, NULL, NULL);
            break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_CANCEL:
                SetWindowText(hwndHoTen, TEXT(""));
                SetFocus(hwndHoTen);
                break;
            case ID_OK:
                lengh = GetWindowText(hwndHoTen, hoten, 30);
                if (lengh == 0)
                {
                    MessageBox(NULL, TEXT("ban phai nhap ho va ten"), TEXT("thong bao"),MB_OK|MB_ICONWARNING);
                    SetFocus(hwndHoTen);
                }
                else
                {
                    wsprintfW(noidung, L"Chao ban: %s. So thich cua ban la: ", hoten);
                    if(SendMessage(checkGame,BM_GETCHECK,0,0)==true)
                        wsprintfW(noidung, L" %s choi Game ", noidung);
                    if (SendMessage(checkMusic, BM_GETCHECK, 0, 0) == true)
                        wsprintfW(noidung, L" %s nghe nhac ", noidung);
                    if (SendMessage(check3Piano, BM_GETCHECK, 0, 0) == 1)
                        wsprintfW(noidung, L" %s choi Piano ", noidung);
                    MessageBox(NULL, noidung, TEXT("ket qua"), MB_OK);
                }
                
               
                break;
            case ID_checkGame:
                if (SendMessage(checkGame, BM_GETCHECK, 0, 0) == true)
                    SendMessage(checkGame, BM_SETCHECK, 0, 0);
                else
                    SendMessage(checkGame, BM_SETCHECK, 1, 0);

                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
