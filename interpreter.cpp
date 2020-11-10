#include <iostream>
#include <string>
#include <iomanip>

	using namespace std;

	int logi = 0;

	_int64 xy = 0, licznik = 0;
	

	const char chars[6] = { 'l', '^', '/', '*', '-', '+' };
	const char chars_niedozwolone[25] = { 'a','b','c','d','e','f','g','h','i','j','k','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	long double dod(double w1, double w2, char o);

	void log(string ciag,int czy_endl,int czy_to_logi)
	{

		if (czy_endl == 0 && czy_to_logi == 1 && logi == 1)
		{
			std::cout << ciag;
		}
		else if (czy_endl == 1 && czy_to_logi == 1 && logi == 1)
		{
			std::cout << ciag << endl;
		}
		else if(czy_to_logi == 0 && czy_endl == 1)
		{
			std::cout << ciag << std::endl;
		}
		else if (czy_to_logi == 0 && czy_endl == 0)
		{
			std::cout << ciag;
		}
		
	}

	void lo(double wartosc,short int czy_endl)
	{	
		if (logi == 1)
		{
			if (czy_endl == 0)
			{
				std::cout << " "<<wartosc<<" ";
			}
			else if (czy_endl == 1)
			{
				std::cout<<" " << wartosc<<" " << std::endl;
			}
		}
	}
	void znak_jaki_log(int b,int j)
	{
		if (logi == 1&&j==1)
		{
			std::cout << chars[b] << std::endl;
		}
		else if (logi == 1 && j == 0)
		{
			std::cout<<" " << chars[b] << " ";
		}
	}

	bool znaki_niedozwolone(string srt)
	{
		for (int i = 0; i < 25; i++)
		{
			if (srt.find(chars_niedozwolone[i],0) != -1)
			{
				return false;
			}
		}
		return true;
	}

	bool znak_przed(string str)
	{
		for (int i = 0; i <= 6 ;i++)
		{
			if (str.front() == chars[i])
			{
				return false;
			}
		}
		return true;
	}

	_int64 petla_za(string str,short int poz_znaku,short int min_za)
	{
		_int64 poz_za,arr[6];
		for (int i = 0; i <= 5; i++)
		{
			log("Poczatek for loop za znakiem nr:", 0, 1);
			lo(i,0);
			poz_za = str.find_first_of(chars[xy], (poz_znaku + 1));
			lo(poz_za,1);
			arr[i] = poz_za;
			xy++;

			for (int i = 0; i <= 5; i++)
			{
				if (arr[i] > 0 && arr[i] < min_za)
				{
					min_za = arr[i];
				}
				if (arr[i] == (-1))
				{
					licznik++;
				}
			}

			if (licznik == 6)
			{
				min_za = str.length();
			}
		}
		licznik = 0;
		xy = 0;
		log("Wartosc min_za: ", 0, 1);
		lo(min_za,1);
		log("Koniec for loop! dla poz_za !", 1, 1);
		log("", 1, 1);
		return min_za;
	}

	_int64 petla_przed(string str, short int poz_znaku, short int min_przed)
	{
		_int64 poz_przed,ara[6];

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

	void interpreter(int l)
	{
		logi = l;
		string dzialanie,str;
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

			log("Inicjalizacja while loop.! ",1,1);
			log("Poczatkowa pozycja znaku: ",0,1);
			lo(poz_znaku,1);
			log("Rozmiar ciagu: ", 0, 1);
			lo(size,1);

			while (x < 6 || poz_znaku == -1)
			{
				log("Zewnetrzna while loop nr: ", 0, 1);
				lo(x,1);

				while (poz_znaku == -1 && x < 6)
				{
					log("Wewnetrzna while loop nr: ", 0, 1);
					lo(x,1);
					x++;

					poz_znaku = str.find(chars[x], 0);
					log("Pozycja znaku nowa : ", 0, 1);
					lo(poz_znaku,1);
					if (poz_znaku > -1)
					{
						log("Jaki znak : ", 0, 1);
						znak_jaki_log(x,1);
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
					short int poz_za, poz_przed, min_za = size, min_przed = -1;

					long double wynik =0;
					string war_lewa, war_prawa, war_wyraz, wynik_str;

					min_za = petla_za(str,poz_znaku, min_za);

					min_przed = petla_przed(str, poz_znaku, min_przed);

					log("Pozycja lewa= ", 0, 1);
					lo(poz_znaku,0); log("(-)", 0, 1); lo(min_przed,0); log("=", 0, 1); lo((poz_znaku - (min_przed)),0);
					war_lewa = str.substr((min_przed + 1), ((poz_znaku - min_przed) - 1));
					log("Wartosc lewa= ", 0, 1);
					log(war_lewa, 1, 1);


					log("Pozycja prawa= ", 0, 1);
					lo(min_za,0); log("(-)", 0, 1); lo(poz_znaku,0); log("=", 0, 1); lo((min_za - poz_znaku),0);
					war_prawa = str.substr((poz_znaku + 1), ((min_za - poz_znaku) - 1));
					log("War prawa= ", 0, 1);
					log(war_prawa, 1, 1);

					log("War wyraz = ", 0, 1);
					war_wyraz = str.substr((min_przed + 1), ((min_za - min_przed) - 1));
					log(war_wyraz, 1, 1);

					log("Operacje matematyczne", 0, 1);
					znak_jaki_log(x,0);
					wynik = dod(stold(war_lewa), stold(war_prawa), chars[x]);
					lo(wynik,1);

					log("Zamiana wartosci na string ", 1, 1);
					wynik_str = to_string(wynik);

					log("Zmiana w stringach", 1, 1);
					str.replace((min_przed + 1), ((min_za - min_przed) - 1), wynik_str);
					log("String wyglada tak: ", 0, 1);
					log(str, 1, 1);

					log("Nowa dlugosc stringa: ", 0, 1);
					size = str.length();
					lo(size,1);

					log("Czyœcimy stringi i wartosci", 1, 1);
					wynik_str.clear();
					war_lewa.clear();
					war_prawa.clear();
					war_wyraz.clear();
					poz_znaku = str.find(chars[x], 0);
					continue;
				}
			}
			log(str,1,1);
			log(to_string(str.length()), 1, 1);
			short int precyzja = str.length() + 1;
			std::cout << dzialanie << " = "<< setprecision(precyzja) << stod(str)<< std::endl;
		}
		else
		{
		log("Nie rozumiem liter :) [oprocz l(x) bo to logarytm :P]", 1, 0);
		}
	}
