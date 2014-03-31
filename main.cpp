#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif
using namespace std;
#include "Spel.h"
#include "Stapel.h"

void hoofdMenu( );
void stats( );
typedef long long int64; 
typedef unsigned long long uint64;
int64 GetTimeMs64( );

int main( ) {
    stats( );
    cout << endl;
    hoofdMenu( );
    return 0;
}

void hoofdMenu( ){
    char keuze;
    srand(time(0));
    Stapel s;
    Spel puzzel;
    puzzel.drukAf( );
    cout << endl;
    do {
        cout    << "(P)arameters, Optie(1), Optie(2), (S)toppen.\n"
                << "(B)este, (G)retig, of (R)andom zet.\n"
                << "(T)erug voor vorige zet.\n" << endl;
        keuze = cin.get( );
        switch (keuze){
            case 'p': case 'P':
                    puzzel.parameters( );
                    break;
            case '1':
                if (puzzel.optie1(puzzel,s))
                    cout << "Het spel is winnend voor A.\n" << endl;
                else
                    cout << "Het spel is winnend voor B.\n" << endl;
                cin.ignore(100, '\n');
                break;
            case '2':
                puzzel.result2(puzzel,s);
                cin.ignore(100, '\n');
                break;
            case 'b': case 'B':
                puzzel.zetBeste(puzzel,s);
                cin.ignore(100, '\n');
                break;
            case 'g': case 'G':
                puzzel.zetGretig(s);
                break;
            case 'r': case 'R':
                puzzel.zetRandom(s);
                break;
            case 't': case 'T':
                s.pop(puzzel);
                cin.ignore(100, '\n');
                puzzel.drukAf( );
                break;
            case 's': case 'S':
                break;
            default:
                cout << "Verkeerde input, probeer opnieuw.\n";
                cin.ignore(1, '\n');
                break;
        }//switch
        cout << endl;
    } while (!(keuze == 's') && !(keuze == 'S'));
     cout << "Einde Programma!.\n";
}

void stats( ){
    double a[50];
    for (int g = 0; g < 50; g++)
        a[g] = 0;
    ofstream uitvoer;
    srand(time(0));
    Stapel s;
    Spel puzzel;
    int i, j, k; 
    double av = 0;
    int64 start, end;
    
    string uitvoerNaam;
	cout	<< "Schrijft beschrijving weg naar een output file.\n"
        	<< "Geeft de naam van de output file.\n" << endl;
	cin	>> uitvoerNaam;
	uitvoer.open (uitvoerNaam.c_str( ), ios::out);
        
        cout << "hoi" << endl;
    for (j = 0, k = 0; j < 10; j++, k++){
        for (i = 0; i < 50; i++){
            puzzel.setPuzzel(3,4);
            start = GetTimeMs64( );
            puzzel.optie2(puzzel,s);
            end = GetTimeMs64( );
            av = av + (end - start);
        }//for i
        av = av/50;
        a[k] = av;
        av = 0;
    }//for j
        cout << "hoi" << endl;
    for (j = 0; j < 10; j++, k++){
        for (i = 0; i < 4; i++){
            puzzel.setPuzzel(3,5);
            start = GetTimeMs64( );
            puzzel.optie2(puzzel,s);
            end = GetTimeMs64( );
            av = av + (end - start);
        }//for i
        av = av/4;
        a[k] = av;
        av = 0;
    }//for j
        cout << "hoi" << endl;
         for (j = 0; j < 10; j++, k++){
        for (i = 0; i < 2; i++){
            puzzel.setPuzzel(3,6);
            start = GetTimeMs64( );
            puzzel.optie2(puzzel,s);
            end = GetTimeMs64( );
            av = av + (end - start);
        }//for i
        av = av/2;
        a[k] = av;
        av = 0;
    }//for j
        cout << "hoi" << endl;
    for (j = 0; j < 10; j++, k++){
        for (i = 0; i < 3; i++){
            puzzel.setPuzzel(4,4);
            start = GetTimeMs64( );
            puzzel.optie2(puzzel,s);
            end = GetTimeMs64( );
            av = av + (end - start);
        }//for 
        av = av/3;
        a[k] = av;
        av = 0;
    }//for j
    cout << "hoi" << endl;
    for (j = 0; j < 10; j++, k++){
        for (i = 0; i < 1; i++){
            puzzel.setPuzzel(4,5);
            start = GetTimeMs64( );
            puzzel.optie2(puzzel,s);
            end = GetTimeMs64( );
            av = av + (end - start);
        }//for i
        a[k] = av;
        av = 0;
    }//for j
    
    for (k = 0; k < 10; k++){
        uitvoer << a[k] << " - " << a[k + 10] << " - " << a[k + 20]
                << " - "  << a[k + 30] << " - " << a[k + 40] << endl;
    }//for
    
    for (i = 0; i < 10; i++){
        a[0] = a[0] + a[i];
        a[10] +=a[10 + i];
        a[20] +=a[20 + i];
        a[30] +=a[30 + i];
        a[40] += a[40 + i];
    }//for
    uitvoer << endl;
    uitvoer <<  "gemiddelden: " << endl;
    uitvoer << a[0]/10 << endl << a[10]/10 << endl
            << a[20]/10 << endl << a[30]/10 <<endl << a[40]/10 << endl;
}//stats

int64 GetTimeMs64( )
{
#ifdef WIN32
 /* Windows */
 FILETIME ft;
 LARGE_INTEGER li;

 /* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it
  * to a LARGE_INTEGER structure. */
 GetSystemTimeAsFileTime(&ft);
 li.LowPart = ft.dwLowDateTime;
 li.HighPart = ft.dwHighDateTime;

 uint64 ret = li.QuadPart;
 ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
 ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */

 return ret;
#else
 /* Linux */
 struct timeval tv;

 gettimeofday(&tv, NULL);

 uint64 ret = tv.tv_usec;
 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
 ret /= 1000;

 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
 ret += (tv.tv_sec * 1000);

 return ret;
#endif
}