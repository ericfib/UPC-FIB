#include <iostream>
using namespace std;

int main () {
    int main(){
	int n;
	int a=0,b=0,c=0;
	char resposta;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>resposta;
		if (resposta=='a') ++a;
		if (resposta=='b') ++b;
		if (resposta=='c') ++c;
	}
	if(a>=b && a>=c){
	       	cout<<"majoria de a"<<endl;
		cout<<a<<" repeticio(ns)"<<endl;
	}
	else if(b>a && b>=c){
		cout<<"majoria de b"<<endl;
		cout<<b<<" repeticio(ns)"<<endl;
	}
	else{
	       	cout<<"majoria de c"<<endl;
		cout<<c<<" repeticio(ns)"<<endl;
	}
}
