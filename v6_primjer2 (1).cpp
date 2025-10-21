#include <iostream>
#include <stack>
using namespace std;
 
void print(stack <int> stog1)
{
    stack <int> pom = stog1;
    while (!pom.empty()){
        cout << " " << pom.top();
        pom.pop();
    }
    cout << endl;
}
 
int main ()
{
    stack <int> stog1;
    stog1.push(2);
    stog1.push(5);
    stog1.push(1);
    stog1.push(4);
    stog1.push(3);
    cout << "Sadrzaj stoga: ";
    print(stog1);
    cout <<endl<<"Velicina stoga: " << stog1.size();
    cout <<endl<<"Element na vrhu stoga: "<< stog1.top()<<endl;
    stog1.pop();
    cout << "Izbaceni element : ";
    print(stog1);
    return 0;
}
