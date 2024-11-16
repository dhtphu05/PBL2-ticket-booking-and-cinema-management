#include <windows.h>

// Hàm xử lý sự kiện của cửa sổ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Đường dẫn đến file .ico
            LPCWSTR iconPath = L"C:\\Users\\admin\\Downloads\\Screenshot 2024-07-14 225556.ico";
            
            // Tải biểu tượng từ file .ico
            HICON hIcon = (HICON)LoadImage(NULL, iconPath, IMAGE_ICON, 64, 64, LR_LOADFROMFILE);
            if (hIcon) {
                // Vẽ biểu tượng lên cửa sổ tại tọa độ (50, 50)
                DrawIcon(hdc, 50, 50, hIcon);
                DestroyIcon(hIcon); // Giải phóng tài nguyên sau khi vẽ xong
            } else {
                TextOut(hdc, 50, 50, L"Failed to load icon!", 18); // Hiển thị lỗi nếu không tải được
            }

            EndPaint(hwnd, &ps);
        }
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    // Đăng ký lớp cửa sổ
    const wchar_t CLASS_NAME[] = L"MyWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Tạo cửa sổ
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"My ICO Viewer",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Vòng lặp xử lý sự kiện
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
