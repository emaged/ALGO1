#ifndef SPEL_H
#define	SPEL_H

class State;
class Stapel;
class Spel {
public:
	Spel( );
	Spel(int hoogte, int breedte);
	~Spel( );
	void bouwSpel( );
	void drukAf( );
	bool einde( );
	void invoer( );
	bool optie1(Spel& spel, Stapel& stapel);
	void optie2(Spel& spel, Stapel& stapel);
	void parameters( );
	void setPuzzel( );//set parameters
        void setPuzzel(int i, int j);
	void terug(int i, int j, int waarde, int r, int k);//kan netter?
	void vulRandom( );//random puzzel voor ingevoerde h en b
	bool zet(int i, int j, Stapel& stapel);
	void zetBeste(Spel& spel, Stapel& stapel);
	void zetGretig(Stapel& stapel);
	void zetRandom(Stapel& stapel);
	void vernietig( );
	void pop(Stapel& stapel);
	void result2(Spel& spel, Stapel& stapel);
private:
	char aanZet;
        int aantal;//aantal zetten
	int **tabel;//rijen * kolommen
	int rijen, kolommen;
	int rSter, kSter;//rij van *
	int vakjesVol;//aantal vakjes met getal erin
	int spelerA, spelerB;
	int maxA, maxB;
        int rBeste, kBeste;
	bool winst;
	State* state;
};

int leesGetal(int max, int min);
void wissel(int& A, int& B);

#endif	/* SPEL_H */

