#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "ATPStackArray.h"

void ispisi_nepar(Stack *S){
	Stack pomocni;
	InitS(&pomocni);
	while(!IsEmptyS(*S)){
		int x=TopS(*S);
		if(x%2!=0)
			cout<<x<<endl;
		PushS(x, &pomocni);
		PopS(S);		
	}
	
	while(!IsEmptyS(pomocni)){
		PushS(TopS(pomocni), S);
		PopS(&pomocni);
	}

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
	
	cout<<"Ispis neparnih clanova stoga: "<<endl;
	ispisi_nepar(&prvi);
	
	return 0;
}


