#include <windows.h>
#include <conio.h>

void menu_glowne();
void logi_wl_wyl(int o);
void inf_gl_func();
void interpreter(int x);
void koniec();

int main()
{
    int f = 0;
    pocz_2:
        menu_glowne();
        pocz:
        if (_kbhit() == 0)
        {
            switch (_getch())
            {
            case 8:                
                if (f==0)
                {
                    logi_wl_wyl(1);
                    f++;
                }
                else if (f==1)
                {
                    logi_wl_wyl(0);
                    f--;
                }
                goto pocz;
                break;

            case 32:
                inf_gl_func();                
                interpreter(f);                
                Beep(1480, 50);
                goto pocz_2;
                break;

            case 99:
            case 67:
                system("cls");
                goto pocz_2;
                break;

            case 27:
                koniec();
                goto koniec;
                break;

            default:                
                goto pocz;
                break;
            }
        }
        else
        {
            goto pocz;
        }
    koniec:
    return 0;
}