#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct klasy
{
   string klasa;       
};
class szkola
{
   vector <struct klasy> spis;
   public:
   void wypisz();
   void wprowadz();
   void zapiszDoPliku(const char *);              
};
void szkola::wypisz()
{
   for (vector<struct klasy>::iterator it = spis.begin(); it != spis.end(); ++it)
      {
       cout << it->klasa << "\n";
      }
}
void szkola::wprowadz()
{
   int ilosc_klas;
   struct klasy wprowadz1;
   cout << "Ilosc klas: ";
   cin  >> ilosc_klas;
   for (int i=0; i<ilosc_klas; i++)
   {
      cout << "Podaj nazwe klasy: ";
      cin >> wprowadz1.klasa;
      spis.push_back(wprowadz1); 
   }
}
void szkola::zapiszDoPliku(const char *nazwa)
{
   ofstream plik;
   plik.open(nazwa);
   for (vector<struct klasy>::iterator it = spis.begin(); it != spis.end(); ++it)
   {
      plik << it->klasa << "\n";
   }
   plik.close();  
}
int main(int argc, char** argv) 
{
   szkola k;
   k.wprowadz();
   k.wypisz();
   k.zapiszDoPliku("1.txt");
return 0;
}
