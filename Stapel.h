/* 
 * File:   Stapel.h
 * Author: Emiel
 *
 * Created on 26 maart 2014, 22:47
 */

#ifndef STAPEL_H
#define	STAPEL_H
class Spel;

class State {
public:
	State( );
	State(int i, int j, int w, int r, int k);
	int i, j;
	int rSter, kSter;
	int waarde;
	State* next;
	//beurt?
};

class Stapel {
public:
	Stapel( );
	~Stapel( );
	void push(State* laatste);
	void pop(Spel& puzzel);
	void pop( );
	bool isLeeg( );
	void vernietig( );
private:
	State* top;
};

#endif	/* STAPEL_H */

