#include "Program.h"

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

int main()
{
    SetWindowSize(50, 80);
    Program program;
    program.loadAdmins();
    program.loadItems();
    program.run();
}

// Di chuyển con trỏ văn bản trên console
void GoTo(SHORT posX, SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

    SetConsoleCursorPosition(hStdout, Position);
}

void SetColor(eColor hglt_color, eColor txt_color)
{
    int highlight_color = (int)hglt_color;
    int text_color = (int)txt_color;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = highlight_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}