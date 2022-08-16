#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct element {
	int wartosc;
	element *next;
};

struct funkcje{
	element *poczatek = NULL;
	
	
	bool czy_pusta()
	{
		return this->poczatek == NULL;
	}
	
	void wrzuc_na_poczatek(int wrzucana)
	{
		element *nowy = new element();
		nowy->wartosc = wrzucana;
		
		nowy->next = this->poczatek;
		poczatek = nowy;
		
	}
	
	void wrzuc_gdzes(int wrzucana,int pozycja)
	{
		if(pozycja>=ile_elementow() || pozycja<=0) 
		{
			cout<<"Nieprawidlowa pozycja. Nie mozna wykonac dodawania el.";
		}
		else
		{
			element *obecna = poczatek;
			element *nowa = new element();
			nowa->wartosc = wrzucana;
			
			if(czy_pusta())
			{
				nowa = poczatek;
			}
			else
			{
				for(int i=2;i<pozycja;i++) obecna = obecna->next;
				nowa->next = obecna->next;
				obecna->next = nowa;		
			}
		}	
	}
	
	void wrzuc_na_koniec(int wrzucana)
	{
		element *nowa = new element;
		element *obecna = poczatek;
		element *poprzednia;
		
		nowa->wartosc = wrzucana;
		nowa->next = NULL;
		
		while(obecna != NULL)
		{
			poprzednia = obecna;
			obecna = obecna->next;					
		}
		poprzednia->next = nowa;
		
	}
	
	
	void usun_element(int pozycja)
	{
		if(pozycja>=ile_elementow() || pozycja<=0) 
		{
			cout<<"Nieprawidlowa pozycja. Nie mozna wykonac usuwania."<<endl;
		}
		else
		{
			element *obecna = poczatek;
			element *usuwana;
			
			for(int i=1;i<pozycja;i++) obecna = obecna->next;
			usuwana = obecna->next;
			obecna->next = usuwana->next;
			
			delete usuwana;		
			
		}
	}
	
	void usun_poczatek()
	{
		if(!czy_pusta())
		{
			element *nastepny = poczatek->next;
			delete poczatek;
			poczatek = nastepny;			
		}
		else
		{
			cout<<"Lista pusta"<<endl;
		}	
	}
	
	void usun_koniec()
	{
		usun_element(ile_elementow()-1);	
	}
	
	
	

	void wypisz_zawartosc()
	{
		element *obecna = poczatek;
		
		while(obecna != NULL)
		{
			cout<<obecna->wartosc<<", ";
			obecna = obecna->next;					
		}
		cout<<endl;
	}
	
	int ile_elementow()
	{
		int licznik=0;
		element *obecna = poczatek;
		
		while(obecna != NULL)
		{
			licznik++;
			obecna = obecna->next;					
		}
		return licznik;
	}
	int min()
	{
		element *obecna = poczatek;
		int min = obecna->wartosc;
		
		while(obecna != NULL)
		{
			if(obecna->wartosc < min) min = obecna->wartosc;
			obecna = obecna->next;					
		}
		return min;
	}
	
	int max()
	{
		element *obecna = poczatek;
		int max = obecna->wartosc;
		
		while(obecna != NULL)
		{
			if(obecna->wartosc > max) max = obecna->wartosc;
			obecna = obecna->next;					
		}
		return max;
	}
	
	void sortowanie()
	{
		int dlugosc = ile_elementow(),n=0; 
		element *obecna = poczatek;
		element *nastepna = poczatek->next;
		
		while(n<dlugosc)
		{
			while(nastepna != NULL)
			{	
				//cout<<obecna->wartosc<<"<->"<<nastepna->wartosc<<endl;
				if(obecna->wartosc>nastepna->wartosc) swap(obecna->wartosc,nastepna->wartosc);
				obecna = obecna->next;
				nastepna = nastepna->next;					
			}
			obecna = poczatek;
			nastepna = poczatek->next;
			n++;
		}
	}
	
	void odwracanie()
	{
		element *poprzednia = NULL;
		element *nastepna;
		element *obecna = poczatek;
		
		while(obecna != NULL)
		{
			nastepna = obecna->next;
			obecna->next = poprzednia;
			
			poprzednia = obecna;
			obecna = nastepna;
		}
		
		poczatek = poprzednia;
	}
	
//	void czyszczenie()
//	{
//		element *obecna = poczatek;
//		element *nastepna = new element;
//		
//		while(nastepna != NULL)
//		{
//			nastepna = obecna->next;
//			obecna = NULL;
//			//cout<<nastepna->wartosc<<endl;
//			obecna = nastepna;		
//		}
//	}
	
	
};


int main()
{
	funkcje lista;
	
	srand(time(NULL));
	int n,liczba,pozycja;
	
	cout<<"Podaj ilu elementawa liste chcesz stworzyc: ";cin>>n;
	for(int i=0;i<n;i++)
	lista.wrzuc_na_poczatek(rand()%100+1);
	cout<<endl;
	
	cout.width(30);
	cout<<"Poczatkowa zawartosc: ";
	lista.wypisz_zawartosc();
	cout<<endl;
	
	Sleep(5000);
	
	lista.usun_poczatek();
	cout.width(30);
	cout<<"Usuwamy poczatek: ";
	lista.wypisz_zawartosc();
	
	Sleep(1000);
	
	lista.usun_koniec();
	cout.width(30);
	cout<<"Usuwamy koniec: ";
	lista.wypisz_zawartosc();
	cout<<endl;
	
	Sleep(1000);
	
	cout.width(30);
	cout<<"Aktualna dlugosc listy: "<<lista.ile_elementow()<<endl<<endl;
	
	Sleep(5000);
	
	lista.wrzuc_na_poczatek(6);
	cout.width(30);
	cout<<"Dodajemy '6' na poczatek: ";
	lista.wypisz_zawartosc();
	
	lista.wrzuc_na_koniec(6);
	cout.width(30);
	cout<<"Dodajemy '6' na koniec: ";
	lista.wypisz_zawartosc();
	cout<<endl;
	
	cout.width(30);
	cout<<"Aktualna dlugosc listy: "<<lista.ile_elementow()<<endl;
	
	cout<<"\n\n\nPodaj liczbe i pozycje ktora chcesz dodac: ";cin>>liczba>>pozycja;
	lista.wrzuc_gdzes(liczba,pozycja);
	cout<<endl;
	cout.width(30);
	cout<<"Pod dodaniu: ";
	lista.wypisz_zawartosc();
	
	cout<<"\nPodaj liczbe i pozycje ktora chcesz dodac: ";cin>>liczba>>pozycja;
	lista.wrzuc_gdzes(liczba,pozycja);
	cout<<endl;
	cout.width(30);
	cout<<"Pod dodaniu: ";
	lista.wypisz_zawartosc();
	
	cout<<"\nAktualna dlugosc listy: "<<lista.ile_elementow()<<endl;
	
	Sleep(5000);
	
	cout.width(30);
	cout<<"Aktualna zawartosc: ";
	lista.wypisz_zawartosc();
	
	Sleep(1000);
	
	cout.width(30);
	cout<<"Zawiera: ";
	cout<<lista.ile_elementow()<<" elementow"<<endl;
	
	Sleep(500);
	
	cout.width(30);
	cout<<"Minimum: ";
	cout<<lista.min()<<endl;
	
	Sleep(500);
	
	cout.width(30);
	cout<<"Minimum: ";
	cout<<lista.max()<<endl<<endl;
	
	Sleep(5000);

	cout.width(30);
	cout<<"Aktualna zawartosc: ";
	lista.wypisz_zawartosc();
	cout<<endl;
	
	Sleep(1000);
	
	cout.width(30);
	cout<<"Posortowana: ";
	lista.sortowanie();
	lista.wypisz_zawartosc();
	cout<<endl;
	
	Sleep(1000);
	
	cout.width(30);
	cout<<"Odwrocona: ";
	lista.odwracanie();
	lista.wypisz_zawartosc();
	cout<<endl;
	


	return 0;
}
