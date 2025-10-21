#include <iostream>
using namespace std;
typedef int elementtype;

struct element{ elementtype value; element* next; };
typedef element* List;

void printL(List Li){ 
element *t=Li;
if(t==NULL)
cout<<"Prazna lista!"<<endl;

while(t!=NULL){
cout<<t->value<<" -> ";
t=t->next;
}

cout<<endl;
}

int main(){
List mojalista;
mojalista=NULL;

element *e1, *e2, *e3, *e4;
e1=new element;
e2=new element;
e3=new element;
e4=new element;
e1->value=1;
e1->next=e2;
e2->value=2;
e2->next=NULL;

mojalista=e1;
printL(mojalista);
 //ispis liste 1,2 e3->value=1; e3->next=e1; 
 // dodavanje 3 na poèetak liste e3->value=3; e3->next=e1; mojalista=e3; printL(mojalista); 
 // dodavanje 4 na kraj liste e4->value=4; e2->next=e4; e4->next=NULL; printL(mojalista);
 
 return 0; } 
