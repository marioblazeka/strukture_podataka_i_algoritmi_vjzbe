#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "ATPStackArray.h"

void zamijeni(elementtype x, elementtype y , Stack *S){
	elementtype z;
	Stack pomocni;
	InitS(&pomocni);
	while(!IsEmptyS(*S)){
		int z=TopS(*S);
		if(z==x)
			PushS(y, &pomocni);
		else
			PushS(z, &pomocni);
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
	
	cout<<"zamjena 2 sa 9: "<<endl;
	zamijeni(2, 9,&prvi);
	PrintS(prvi);
	
	return 0;
}


