#include <windows.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

int logi = 0;
short int xy = 0, licznik, xz = 0;
const char chars[6] = { 'l', '^', '/', '*', '-', '+' };
const char chars_niedozwolone[25] = { 'a','b','c','d','e','f','g','h','i','j','k','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

double dod(double w1, double w2, char o)
{
    switch (o)
    {
    case '+':
        return w1 + w2;
    case '-':
        return w1 - w2;
    case '*':
        if (w1 == 0 || w2 == 0)
        {
            return 0;
        }
        return w1 * w2;
    case '/':
        return w1 / w2;
    case '^':
        return pow(w1, w2);
    }
    return 0;
}

void log(string ciag, bool czy_endl, bool czy_to_logi)
{

	if (czy_endl == 0 && czy_to_logi == 1 && logi == 1)
	{
		std::cout << ciag;
	}
	else if (czy_endl == 1 && czy_to_logi == 1 && logi == 1)
	{
		std::cout << ciag << endl;
	}
	else if (czy_to_logi == 0 && czy_endl == 1)
	{
		std::cout << ciag << std::endl;
	}
	else if (czy_to_logi == 0 && czy_endl == 0)
	{
		std::cout << ciag;
	}

}
void lo(double wartosc, bool czy_endl)
{
	if (logi == 1)
	{
		if (czy_endl == 0)
		{
			std::cout << " " << wartosc << " ";
		}
		else if (czy_endl == 1)
		{
			std::cout << " " << wartosc << " " << std::endl;
		}
	}
}
void znak_jaki_log(int b, int j)
{
	if (logi == 1 && j == 1)
	{
		std::cout << chars[b] << std::endl;
	}
	else if (logi == 1 && j == 0)
	{
		std::cout << " " << chars[b] << " ";
	}
}
void color(short int col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void menu_glowne()
{
    color(06);
    log("[] ", 0, 0); system("chcp 28592");
    log("[CALC W C++] Kalkulator z interpreterem znakow", 1, 0);
    log("[C] Wciśnij C aby wyczyścic ekran", 1, 0);
    log("[BACKSPC] Wcisnij BACKSPC aby wlaczyc logi ", 1, 0);
    log("[SPACJA] Wcisnij SPACE aby uzyc kalkulatora", 1, 0);
    log("[] Potega '^' | Mnozenie '/' | logarytm 'l(x)'", 1, 0);
    log("[ESC] Wcisnij ESC aby zakonczyc ", 1, 0);
    log("", 1, 0);
    color(02);
}
void logi_wl_wyl(int x)
{
    if (x == 1)
    {
        color(04);
        log("", 1, 0);
        log("[DEVELOPER_MODE]", 1, 0);
        log("", 1, 0);
    }
    if (x == 0)
    {
        color(04);
        log("", 1, 0);
        log("[DEVELOPER_MODE OFF]", 1, 0);
        log("", 1, 0);
    }
}
void inf_gl_func()
{
    log("", 1, 0);
    color(04);
    log("[] WPROWADZ dzialanie i nacisnij ENTER : ", 1, 0);
    log("", 1, 0);
    color(05);
}
void koniec()
{
    color(04);
    log("[] Sam sie zamkne. Dziekuje :)", 1, 0);
    Sleep(1500);
}

bool znaki_niedozwolone(string srt)
{
	for (int i = 0; i < 25; i++)
	{
		if (srt.find(chars_niedozwolone[i], 0) != -1)
		{
			return false;
		}
	}
	return true;
}
bool znak_przed(string str)
{
	for (int i = 0; i <= 6; i++)
	{
		if (str.front() == chars[i])
		{
			return false;
		}
	}
	return true;
}

int petla_przed(string str, int poz_znaku, int min_przed)
{
	int poz_przed, ara[6];

	for (int i = 0; i <= 5; i++)
	{
		log("Poczatek for loop przed znakiem nr: ", 0, 1);
		lo(i, 0);
		poz_przed = str.find_last_of(chars[xy], (poz_znaku - 1));
		lo(poz_przed, 1);
		ara[i] = poz_przed;
		xy++;
	}

	for (int i = 0; i <= 5; i++)
	{
		if (ara[i] >= min_przed && ara[i] < poz_znaku)
		{
			min_przed = ara[i];
		}
	}

	xy = 0;
	log("Wartosc min_przed", 0, 1);
	lo(min_przed, 1);
	log("Koniec for loop! dla poz_przed !", 1, 1);
	log("", 1, 1);
	return min_przed;
}
int petla_za(string str, int poz_znaku, int min_za)
{
	int poz_za, arr[6];
	for (int i = 0; i <= 5; i++)
	{
		log("Poczatek for loop za znakiem nr:", 0, 1);
		lo(i, 0);
		poz_za = str.find_first_of(chars[xz], (poz_znaku + 1));
		lo(poz_za, 1);
		arr[i] = poz_za;
		xz++;

		for (int i = 0; i <= 5; i++)
		{
			if (arr[i] > 0 && arr[i] < min_za)
			{
				min_za = arr[i];
			}
			else if (arr[i] < 0)
			{
				licznik++;
			}
		}

		if (licznik == 6)
		{
			min_za = str.length();
			licznik = 0;
		}
	}

	xz = 0;
	log("Wartosc min_za: ", 0, 1);
	lo(min_za, 1);
	log("Koniec for loop! dla poz_za !", 1, 1);
	log("", 1, 1);
	return min_za;
}

string kropki(string wynik_str)
{
	short int dlugosc = wynik_str.length();
	short int czy_kropka = wynik_str.find(".");

	if (czy_kropka > 0)
	{
		if (czy_kropka != dlugosc)
		{
			short int gdzie_zero = wynik_str.find('0', dlugosc - 1);
			while (gdzie_zero == dlugosc - 1)
			{
				log("Found", 1, 1);
				wynik_str.pop_back();
				dlugosc = wynik_str.length();
				gdzie_zero = wynik_str.find('0', dlugosc - 1);
			}
		}
		if (czy_kropka == dlugosc - 1)
		{
			wynik_str.pop_back();
		}
		return wynik_str;
	}
	else
	{
		return wynik_str;
	}

}

bool interpreter(int l)
{
	logi = l;
	string dzialanie, str;
	cin >> dzialanie;
	str = dzialanie;
	if (znaki_niedozwolone(str) != false)
	{
		if (znak_przed(str) == false)
		{
			str.erase(0, 1);
			dzialanie.erase(0, 1);
		}

		short int x = 0;
		int size = str.length();
		int poz_znaku = str.find(chars[x], 0);

		log("Inicjalizacja while loop.! ", 1, 1);
		log("Poczatkowa pozycja znaku: ", 0, 1);
		lo(poz_znaku, 1);
		log("Rozmiar ciagu: ", 0, 1);
		lo(size, 1);

		while (x < 6 || poz_znaku == -1)
		{
			log("Zewnetrzna while loop nr: ", 0, 1);
			lo(x, 1);

			while (poz_znaku == -1 && x < 6)
			{
				log("Wewnetrzna while loop nr: ", 0, 1);
				lo(x, 1);
				x++;

				poz_znaku = str.find(chars[x], 0);
				log("Pozycja znaku nowa : ", 0, 1);
				lo(poz_znaku, 1);
				if (poz_znaku > -1)
				{
					log("Jaki znak : ", 0, 1);
					znak_jaki_log(x, 1);
				}
			}

			if ((x + 1) == 7)
			{
				log("Koniec petli glownej ", 1, 1);
				log("", 1, 1);
				break;
			}

			while (poz_znaku != -1)
			{

				log("Znaleziono znak, szukanie znakow obok ", 1, 1);
				log("", 1, 1);
				int min_za = size, min_przed = -1;

				long double wynik;
				string war_lewa, war_prawa, war_wyraz, wynik_str;

				min_przed = petla_przed(str, poz_znaku, min_przed);
				min_za = petla_za(str, poz_znaku, min_za);

				log("Pozycja lewa= ", 0, 1);
				lo(poz_znaku, 0); log("(-)", 0, 1); lo(min_przed, 0); log("=", 0, 1); lo((poz_znaku - (min_przed)), 0);
				war_lewa = str.substr((min_przed + 1), ((poz_znaku - min_przed) - 1));
				log("Wartosc lewa= ", 0, 1);
				log(war_lewa, 1, 1);

				log("Pozycja prawa= ", 0, 1);
				lo(min_za, 0); log("(-)", 0, 1); lo(poz_znaku, 0); log("=", 0, 1); lo((min_za - poz_znaku), 0);
				war_prawa = str.substr((poz_znaku + 1), ((min_za - poz_znaku) - 1));
				log("War prawa= ", 0, 1);
				log(war_prawa, 1, 1);

				log("War wyraz = ", 0, 1);
				war_wyraz = str.substr((min_przed + 1), ((min_za - min_przed) - 1));
				log(war_wyraz, 1, 1);

				log("Operacje matematyczne", 0, 1);
				znak_jaki_log(x, 0);
				wynik = dod(stod(war_lewa), stod(war_prawa), chars[x]);
				lo(wynik, 1);

				log("Zamiana wartosci na string ", 1, 1);
				wynik_str = kropki(to_string(wynik));

				log("Zmiana w stringach", 1, 1);
				str.replace((min_przed + 1), ((min_za - min_przed) - 1), wynik_str);
				log("String wyglada tak: ", 0, 1);
				log(str, 1, 1);

				log("Nowa dlugosc stringa: ", 0, 1);
				size = str.length();
				lo(size, 1);

				log("Czyścimy stringi i wartosci", 1, 1);
				wynik_str.clear();
				war_lewa.clear();
				war_prawa.clear();
				war_wyraz.clear();
				poz_znaku = str.find(chars[x], 0);
				continue;
			}
		}
		log(str, 1, 1);
		log(to_string(str.length()), 1, 1);
		short int precyzja = str.length() + 1;
		if (str == "inf")
		{
			log("[] Wynik jest powyzej wartosci ktora rozumiem czyli 1.79769e+308", 1, 1);
			log("[] Soryy memory nie oblicze", 1, 1);
			return 1;
		}
		else
		{
			log(dzialanie, 0, 0);
			log(" = ", 0, 0);
			setprecision(precyzja);
			log(str, 1, 0);
			return 0;
		}
	}
	else
	{
		log("Nie rozumiem liter :) [oprocz l(x) bo to logarytm :P]", 1, 0);
		return 1;
	}
}

int main()
{
	const wchar_t* txt = L"SystemQuestion";
	
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
				if (interpreter(f) == 0)
				{
					Beep(1480, 50); 
				}
				else
				{ 
					PlaySound(TEXT("erro.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
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