#include <iostream>
#include <Windows.h>

using namespace std;
void log(string ciag, int czy_endl, int czy_to_logi);

void color(short int col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void menu_glowne()
{
    color(06);
    log("[] ",0,0); system("chcp 28592");
    log("[CALC W C++] Kalkulator z interpreterem znakow", 1,0);
    log("[C] Wciœnij C aby wyczyœcic ekran", 1, 0);
    log("[BACKSPC] Wcisnij BACKSPC aby wlaczyc logi ",1,0);
    log("[SPACJA] Wcisnij SPACE aby uzyc kalkulatora", 1, 0);
    log("[] Potega '^' | Mnozenie '/' | logarytm 'l(x)'",1,0);
    log("[ESC] Wcisnij ESC aby zakonczyc ", 1,0);
    log("", 1,0);
    color(02);
}

void logi_wl_wyl(int x)
{
    if (x == 1) 
    {
        color(04);
        log("", 1,0);
        log("[DEVELOPER_MODE]", 1,0);
        log("", 1,0);
    }
    if (x==0)
    {
        color(04);
        log("", 1,0);
        log("[DEVELOPER_MODE OFF]", 1,0);
        log("", 1,0);
    }
}

void inf_gl_func()
{
    log("", 1,0);
    color(04);
    log("[] WPROWADZ dzialanie i nacisnij ENTER : ", 1,0);
    log("", 1,0);
    color(05);
}

void koniec()
{
    color(04);
    log("[] Sam sie zamkne. Dziekuje :)", 1,0);
    Sleep(1500);
}