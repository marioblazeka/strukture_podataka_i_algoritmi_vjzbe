#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "ATPStackArray.h"


double ar_sred(Stack *S) {
	double suma, brojac=0;
	Stack pomocni;
	InitS(&pomocni);
		while(!IsEmptyS(*S)){
		int x=TopS(*S);
		suma+=x;
		brojac++;
		PushS(x, &pomocni);
		PopS(S);		
	}
	
	while(!IsEmptyS(pomocni)){
		PushS(TopS(pomocni), S);
		PopS(&pomocni);
	}
	return suma/brojac;
}

int main(){

	
	//inicijalizacija stoga: 
	Stack prvi;
	InitS(&prvi);
	//punjenje stoga
	PushS(1, &prvi);
	PushS(2, &prvi);
	PushS(5, &prvi);
	PushS(7, &prvi);
	PrintS(prvi);	
	//izbacimo prva tri elementa sa stoga
	
	cout<<"Aritmeticka sredina stoga: "<<ar_sred(&prvi)<<endl;
	
	
	return 0;
}


