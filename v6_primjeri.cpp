#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "ATPStackArray.h"
void ispisi_prve(int a, Stack *pS) {
	Stack pomocni;
	InitS(&pomocni);
	for(int i=0;i<a;i++){
		if(IsEmptyS(*pS)) break;
		elementtype x=TopS(*pS);
		PushS(x,&pomocni);
		cout<<x<<endl;
		PopS(pS);	
	}
	while(!IsEmptyS(pomocni)){
		PushS(TopS(pomocni), pS);
		PopS(&pomocni);
	}	
}
void razdvoji(Stack *pS, Stack *poz, Stack *neg) {
	InitS(poz);
	InitS(neg);
	while(!IsEmptyS(*pS)){
		elementtype x=TopS(*pS);
		if(x>=0)	
			PushS(x, poz);
		else
			PushS(x, neg);
		PopS(pS);		
	}
	
}
int main(){

	
	//inicijalizacija stoga: 
	Stack prvi;
	InitS(&prvi);
	//punjenje stoga
	PushS(111, &prvi);
	PushS(222, &prvi);
	for(int i=10;i<17;i++)
		PushS(i, &prvi);
	//ispisimo stog
	cout<<"Ispisujem stog:"<<endl;
	PrintS(prvi);	
	//izbacimo prva tri elementa sa stoga
	for(int i=1;i<=3;i++)
		PopS(&prvi);
	//ispisimo sve elemente stoga bez funkcije PrintS()
	cout<<"Ispisujem stog:"<<endl;
	while(!IsEmptyS(prvi)){ //nakon petlje stog je prazan!
		cout<<TopS(prvi)<<endl;
		PopS(&prvi);	
	}
	cout<<"Ispisujem stog:"<<endl;
	PrintS(prvi);
	
	cout<<endl<<endl;
	cout<<"Primjeri s funkcijama: "<<endl;
	
	Stack drugi;
	InitS(&drugi);
	for(int i=0;i<=15;i++)
		PushS(rand()%21-10, &drugi);
	cout<<"Ispisujem stog: "<<endl;
	PrintS(drugi);
	cout<<"Ispisi_prve(3,..."<<endl;
	ispisi_prve(3, &drugi);
	cout<<"Ispisujem stog: "<<endl;
	PrintS(drugi);
	Stack p, n;
	razdvoji(&drugi,&p,&n);
	cout<<"Ispisujem stog poz "<<endl;
	PrintS(p);
	cout<<"Ispisujem stog neg "<<endl;
	PrintS(n);
	cout<<"Ispisujem stog drugi "<<endl;
	PrintS(drugi);
	return 0;
}
