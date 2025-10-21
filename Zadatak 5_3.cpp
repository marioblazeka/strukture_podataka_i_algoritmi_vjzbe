#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "ATPStackArray.h"

void obrni(Stack *S) {
	Stack pomocni1, pomocni2;
	while(!IsEmptyS(*S)){
		PushS(TopS(*S), &pomocni1);
		PopS(S);
	}
	PrintS(pomocni1);
	/*
	while(!IsEmptyS(pomocni1)){
		PushS(TopS(pomocni1), &pomocni2);
		PopS(&pomocni1);
	}
	PrintS(pomocni2);
	while(!IsEmptyS(pomocni2)){
		PushS(TopS(pomocni2), S);
		PopS(&pomocni2);
	}
*/
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
	
	cout<<"Obrnuti stog: "<<endl;
	obrni(&prvi);
	PrintS(prvi);
	
	return 0;
}


