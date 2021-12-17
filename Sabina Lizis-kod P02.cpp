#include <iostream>
#include <fstream>
#include<time.h>
#include<cstdlib>
#include<windows.h>
#include <cstdio>
#include <ctime>
#include <conio.h>
using namespace std;

double t_gnom,t_przez_wybieranie;
clock_t start, koniec,start2,koniec2;
 //zmienne czasowe

void gnom(int* tab, int n)//funkcja sortowania gnoma

 {
long long obiegi = 0;
long long zamiany = 0;
     int poz = 0; //zaczynamy sortowanie od pozycji 0
      while (poz < n) { //dopoki indeks nie bedzie wikszy od rozmiaru tabeli
        if (poz == 0 || tab[poz] >= tab[poz - 1]) {
          poz++;
        } else { //w przeciwnym wypadku zamien element z poprzednim i zmniejsz indeks o 1
          swap(tab[poz], tab[poz - 1]);
          poz = poz - 1;
         zamiany++;//zmienna zliczajaca ilosc zamian
        }
       obiegi++;//zmienna zliczajaca obiegi funkcji
      }
      cout<<"Algorytm sortowania gnoma wykonal "<<obiegi<<" obiegow funkcji dominujacej i wykonal "<<zamiany<<" zamian"<<endl;
}


void przez_wybieranie(int* tab, int n)//funkcja sortowania przez wybieranie

{
	long long obiegi = 0;
	for(int j = 0; j < n - 1; j++)
	{
		int pmin = j;
		for(int i = j + 1; i < n; i++)
		{
			obiegi++;
			if(tab[i] < tab[pmin])
			{
				pmin = i;
			}
			swap(tab[pmin], tab[j]);
		}
		pmin=j;
    }

  cout<<"Algorytm sortowania przez wybieranie wykonal: "<<obiegi<<"porownan";


}

void losowe_gnom_i_wybor( )

{
		fstream a;
	a.open("wynik.txt",ios::out); //utworzenie pliku
	int rozm;
  cout<<"Podaj rozmiar tablicy: ";
  cin>>rozm;
   int *t,*l;
   l = new int[rozm];
  cout<<endl;

  	cout<<"Liczby zostana wylosowane od 0 do 1000 "<<" i wpisane do tablicy o rozmiarze "<<rozm<<endl<<endl;
  	t=new int[rozm];
  for(int i =0; i<rozm;i++)
  {

//wypełnienie tablic
  t[i]=rand()%1000+1;
  l[i] = rand()%1000+1;
}
  a<<"Tablica przed sortowaniem: ";
  a<<endl;
  for(int i = 0;i<rozm;i++){

   a<<t[i]<<" ";//zapis do pliku przed sortowaniem
}
  a<<endl<<endl;



start=clock(); //zapisanie czasu startu mierzenia
  gnom(t,rozm);//wywoalnie funkcji sortowania
  koniec=clock();//zapisanie konca mierzenia
 t_gnom=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczanie czasu wykonywania

  a<<"Posortowana Tablica za pomoca sortowania gnoma:  "<<endl;
	for(int i=0;i<rozm;i++) a<<t[i]<<" ";//zapis do pliku posotowanej tablicy
a<<endl<<endl<<endl;


  a<<"Tablica przed sortowaniem: "<<endl;
  for(int i = 0;i<rozm;i++) a<<l[i]<<" ";
  a<<endl<<endl<<endl;


start=clock(); //zapisanie czasu startu mierzenia
przez_wybieranie(l,rozm);
 koniec=clock();//zapisanie konca mierzenia
 t_przez_wybieranie=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczanie czasu wykonywania

cout<<endl<<endl;
   a<<"Posortowana Tablica za pomoca sortowania przez wybieranie:  "<<endl;
	for(int i=0;i<rozm;i++) a<<l[i]<<" ";
		a<<endl;




cout<<"Czas wykonania algorytmu sortowania gnoma: "<<t_gnom<<"s"<<endl;
cout<<"Czas wykonania algorytmu sortowania przez wybieranie: "<<t_przez_wybieranie<<"s"<<endl;
a<<endl;
a<<"liczba elementow: "<<rozm<<endl;
a<<"Czas wykonania algorytmu sortowania gnoma: "<<t_gnom<<"s"<<endl;
a<<"Czas wykonania algorytmu sortowania przez wybieranie: "<<t_przez_wybieranie<<"s"<<endl;


a.close();
delete[] t;
 delete[] l;
}

void gnom_z_pliku()
{
		fstream a;
	a.open("wynik.txt",ios::out); //stworzenie pliku
       a<<"Posortowana Tablica:  ";
	int T [500] = {0};//stworzenie tablicy
int tmp = 0; //zmienna ktora bedzie odpowiedzialna za indeksy tablicy
ifstream liczby("liczby.txt");
if(!liczby)//jesli plik bedzie pusty to wyswietli taki konukikat
{
	cout<<"nie mozna otworzyc pliku";
}
 while(!liczby.eof())// petla wykonuje sie dopoki dane w pliku sie nie skoncza
       liczby >> T[tmp++];//liczby przypisuje do tablicy
       liczby.close();
       cout<<" Przed sortowaniem: ";
       for (int i=0;i<tmp;i++)
       cout<< T[i]<<" "; //wypisanie na ekranie
       cout<<endl;
       gnom(T,tmp);
       cout<<" Po sortowaniu: ";
       for(int i = 0;i<tmp;i++){
	    cout<< T[i]<<" ";
	    a<< T[i]<<" ";
	}
	a.close();
}
void  przez_wybieranie_z_pliku()
{
	fstream a;
	a.open("wynik.txt",ios::out); //utworzenie pliku
       a<<"Posortowana Tablica:  ";
	int T [500] = {0};//stworzenie tablicy
int tmp = 0; //zmienna ktora bedzie odpowiedzialna za indeksy tablicy
ifstream liczby("liczby.txt");
if(!liczby)//jesli plik bedzie pusty to wyswietli taki konukikat
{
	cout<<"nie mozna otworzyc pliku";
}
 while(!liczby.eof())// petla wykonuje sie dopoki dane w pliku sie nie skoncza
       liczby >> T[tmp++];//liczby przypisuje do tablicy
       liczby.close();
       cout<<" Przed sortowaniem: ";
       for (int i=0;i<tmp;i++)
       cout<< T[i]<<" "; //wypisanie na ekranie
       cout<<endl;
      przez_wybieranie(T,tmp);
       cout<<" Po sortowaniu: ";
        for(int i = 0;i<tmp;i++){
	    cout<< T[i]<<" ";
	    a<< T[i]<<" ";
	}
	a.close();
}

void optymistyczne()
{
	fstream a;
	a.open("wynik.txt",ios::out); //utworzenie pliku
		int n;
	cout<< "Podaj rozmiar tablicy: ";
	cin>>n;
	cout<<endl;
	int *tab3;
	tab3 = new int[n];
	a<<"Przed sortowaniem: "<<endl;
	for(int i=0;i<n;i++)
	{
		tab3[i]=i;
		a<<tab3[i]<<" ";
	}
	a<<endl;
	start=clock();
	gnom(tab3,n);
	koniec=clock();
	t_gnom=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie czyli czasu wykonania

	cout<<"Czas wykonania sortowania gnoma : "<<t_gnom<<"s"<<endl<<endl;
	 a<<"Posortowana Tablica za pomoca sortowania gnoma:  "<<endl;
	for(int i=0;i<n;i++) a<<tab3[i]<<" ";
	a<<endl;
	a<<"Czas wykonania sortowania gnoma : "<<t_gnom<<"s"<<endl;



	start=clock();
	przez_wybieranie(tab3,n);
	koniec=clock();
	t_przez_wybieranie=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie czasu wykonania
	a<<endl;
	cout<<"Czas wykonania sortowania przez wybieranie : "<<t_przez_wybieranie<<"s"<<endl;
       a<<"Posortowana Tablica za pomocą sortowania przez wybieranie:  "<<endl;
	for(int i=0;i<n;i++) a<<tab3[i]<<" ";
		a<<endl;
	a<<"Czas wykonania sortowania przez wybieranie : "<<t_przez_wybieranie<<"s"<<endl;
	a.close();

}

void pesymistyczne()
{
	fstream a;
	a.open("wynik.txt",ios::out); //utworzenie pliku
		int n,i;
	cout<< "Podaj rozmiar tablicy: ";
	cin>>n;
	int *tab1;
	tab1 = new int[n];
	a<<"Przed sortowaniem: "<<endl;
	for( i=n-1;i>0;i--)
	{
		//wypelnienie tablicy i zapis do pliku przed sortowaniem
          tab1[i]=i;
		a<<tab1[i]<<" ";
	}
	a<<endl;
	start=clock();
    gnom(tab1,n);
	koniec=clock();
	t_gnom=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie czasu wykonania
	cout<<endl;
	cout<<"Czas wykonania sortowania gnoma : "<<t_gnom<<"s"<<endl;
	a<<"Posortowana Tablica za pomoca sortowania gnoma:  "<<endl;
	for( i=0;i<n;i++) a<<tab1[i]<<" ";
	delete[] tab1;
	a<<endl;
	a<<"Czas wykonania sortowania gnoma : "<<t_gnom<<"s"<<endl;
	int *tab2;
	tab2 = new int[n];
	a<<"Przed sortowaniem:"<<endl;
		for( i=n-1;i>0;i--)
	{
        tab2[i]=i;
		a<<tab2[i]<<" ";
	}
    a<<endl;

	start=clock();
	przez_wybieranie(tab2,n);
	koniec=clock();
	t_przez_wybieranie=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie czasu wykonania
	cout<<"Czas wykonania sortowania przez wybieranie : "<<t_przez_wybieranie<<"s"<<endl;
       a<<"Posortowana Tablica za pomoca sortowania przez wybieranie:"<<endl;
	for( i=0;i<n;i++) a<<tab2[i]<<" ";
		a<<endl;
	a<<"Czas wykonania sortowania przez wybieranie : "<<t_przez_wybieranie<<"s"<<endl;
	a.close();

}


int main()
{
 cout<<"Zapis wszystkich tablic pseudolosowych do pliku 'wynik' pozwala na szybsze ukazanie wynikow czasowych'"<<endl<<endl;
	cout<<"1 - Sortowanie na liczbach pseudolosowych i porownanie czasow"<<endl<<endl;
	cout<<"2 - Sortowanie gnoma na liczbach z  pliku"<<endl<<endl;
	cout<<"3 - Sortowanie przez wybieranie na liczbach z  pliku"<<endl<<endl;
	cout<<"4 - Przypadek optymistyczny dla sortowania gnoma i sortowania przez wybieranie "<<endl<<endl;
	cout<<"5 - Przypadek pesymistyczny dla sortowania gnoma i sortowania przez wybieranie "<<endl<<endl;
	 int sposob;
       cout<<" ";
	 cout<<"wybierz sposob dzialania programu: ";
	 cin>>sposob;
	 cout<<endl;

	 switch(sposob)
	 {

	 	case 1:
	 		{
//wywoływanie funkcji
	 		losowe_gnom_i_wybor();
	 		break;
	 	}
	 	case 2:{
	 		gnom_z_pliku();
			break;
		 }
		 case 3:{
		 	przez_wybieranie_z_pliku();
			break;
		 }
		 case 4:{
		 	optymistyczne();
			break;
		 }
		 case 5:{
		 	pesymistyczne();
			break;
		 }

	 }

	return 0;
}

