/* 
 * File:   Stapel.cc
 * Author: Emiel
 * 
 * Created on 26 maart 2014, 22:47
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#include "Stapel.h"
#include "Spel.h"

State::State( ):next(NULL){
    //leeg
}//constructor

State::State(int i, int j, int w, int r, int k):i(i),j(j),
        waarde(w),rSter(r),kSter(k),next(NULL){
    //leeg
}//constructor met values

Stapel::Stapel( ):top(NULL){
    //leeg
}//constructor

Stapel::~Stapel( ){
    vernietig( );
}//destructor

void Stapel::push(State* laatste){
    laatste->next = top;
    top = laatste;
}//push
void Stapel::pop( ){
    State* discard = top;
    top = top->next;
    delete discard;
}//pop

void Stapel::pop(Spel& puzzel){
    if (top == NULL){
        cout << "Dit is de eerste zet, kan niet terug.\n" << endl;
        return;
    }//if
    int i, j, waarde, r, k;
    i = top->i, j = top->j;
    waarde = top->waarde;
    r = top->rSter, k = top->kSter;
    puzzel.terug(i,j,waarde,r,k);
    State* discard = top;
    top = top->next;
    delete discard;
}//pop met value

bool Stapel::isLeeg( ){
    return (top == NULL);
}//leeg als top nergens naar wijst..

void Stapel::vernietig( ){
    Spel* next;
    while (!isLeeg( )){
        pop( );
    }//while
}//functie voor destructor