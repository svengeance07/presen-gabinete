#include <windows.h>
#include "Config.h"

using Overtone::WIDTH, Overtone::HEIGHT, Overtone::M_HEIGHT;

void SetupConsoleWindow() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 1. Obtener la resolución del monitor actual
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // 2. Calcular tamaño de fuente dinámico
    // Queremos que el alto de la matriz (HEIGHT + M_HEIGHT) ocupe un 80% del alto de la pantalla
    int totalRows = HEIGHT + M_HEIGHT + 1; // +5 por márgenes
    short fontSize = (short)(screenHeight * 0.83 / totalRows);

    // 3. Aplicar el tamaño de fuente
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;           // Ancho automático basado en el alto
    cfi.dwFontSize.Y = fontSize;    // Alto calculado
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Fuente fija para que la matriz no se rompa
    SetCurrentConsoleFontEx(hOut, FALSE, &cfi);

    // 4. Ajustar el Búfer y la Ventana
    short consoleWidth = WIDTH * 2; // *2 por los espacios que usas en ArrayHandler
    short consoleHeight = HEIGHT + M_HEIGHT + 1;

    COORD bufferSize = { consoleWidth, consoleHeight };
    SetConsoleScreenBufferSize(hOut, bufferSize);

    SMALL_RECT windowSize = { 0, 0, consoleWidth - 1, consoleHeight - 1 };
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // 5. Centrar la ventana en el monitor
    HWND hwnd = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);
    int winWidth = rect.right - rect.left;
    int winHeight = rect.bottom - rect.top;

    int posX = (screenWidth - winWidth) / 2;
    int posY = (screenHeight - winHeight) / 2;
    SetWindowPos(hwnd, NULL, posX, posY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    // 6. Limpieza visual (Ocultar cursor y evitar scroll)
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    // 7. Bonus: Cambiar el título de la consola
    SetConsoleTitleA("Overtone");
}