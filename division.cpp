#include<iostream>
#include <math.h>
using namespace std;
void Entero_binario(int n,int *&p,int numero)
{
	p=new int [n];
	for (int i=n-1;i>=0;i--){
		p[i]=numero%2;
		numero=numero/2;
	}
	
}
int binario_entero(int n,int *p)
{
	int resultado=0;
	
	for (int i=n-1, h=0;i>=0,h<n;i--,h++){
		if (p[i]==1){
			resultado=resultado+pow(2, h);
			
		}
	}
	return resultado;
	
}
void imprimir(int n,int *p){
	for (int i=0;i<n;i++){
		cout<<p[i];
	}

}
void suma_bits(int *&m,int*g,int n){
	int acarreo=0;
	for (int i=n-1;i>=0;i--){
		if ((m[i]==0)&(g[i]==0)&(acarreo==0)){
			m[i]=0,acarreo=0;
		}
		else if ((m[i]==1)&(g[i]==1)&(acarreo==1)){
			m[i]=1,acarreo=1;
		}
		else if(((m[i]==1)&(g[i]==0)&(acarreo==0))|((m[i]==0)&(g[i]==1)&(acarreo==0))|((m[i]==0)&(g[i]==0)&(acarreo==1))){
			m[i]=1,acarreo=0;
		}
		else if(((m[i]==1)&(g[i]==1)&(acarreo==0))|((m[i]==0)&(g[i]==1)&(acarreo==1))|((m[i]==1)&(g[i]==0)&(acarreo==1))){
			m[i]=0,acarreo=1;
		}
		}
	}

	
void resta_bits(int *&a,int *m,int n ){
	for (int i=0;i<n;i++){
		if(m[i]==0){
			m[i]=1;
		}
		else {
			m[i]=0;
		}
		}
	
	int *bits_1=new int[n];
	
	for (int j=0;j<n;j++){
		if (j==(n-1)){
			bits_1[j]=1;
		}
		else {
			bits_1[j]=0;
		}
		
	}
	
	suma_bits(m,bits_1,n);
	
	suma_bits(a,m,n);
	delete [] bits_1;
	
}
void divisor_binarios(int *&a,int *&q,int *&m,int n,int divisor){
	a=new int[n];
	for (int i=0;i<n;i++){
		a[i]=0;
	}
	int value;
	int temp=q[n-1];
	int temp2=0;
	for(int i=n;i>0;i--){
		for (int j=(n-2);j>=0;j--){
			temp2=q[j],q[j]=temp;temp=temp2;
				
		}
		
		for (int j=(n-1);j>=0;j--){
			temp2=a[j],a[j]=temp;temp=temp2;
		
		}
		
		
		resta_bits(a,m,n );
	
		Entero_binario(n,m,divisor);
	
			
		if (a[0]==1){
			q[n-1]=0;
			suma_bits(a,m,n);
			
			
		}
		else {
			q[n-1]=1;
			
		}
		temp=q[n-1];
		
		
	}
	
}
 
int main(){
	int *a=new int [0];
	int *q=new int [0];
	int *m=new int [0];
	int n;
	int dividendo;
	int divisor;
	cout<<"N bits: ";
	cin>>n;
	cout<<"ingrese el dividendo: " ;
	cin>>dividendo;
	
	cout<<"ingrese el divisor: " ;
	cin>>divisor;
	
	Entero_binario(n,q,dividendo);
	Entero_binario(n,m,divisor);
	cout<<"\nDivision\n";
	imprimir(n,q);
	cout<<("\n");
	imprimir(n,m);
	cout<<("\n");
	cout<<"-----------------------\n";
	divisor_binarios(a,q, m,n,divisor);
	imprimir(n,q);
	cout<<" = "<<binario_entero(n,q)<<" (Resultado)";
	cout<<("\n\n");
	
	imprimir(n,a);
	cout<<" = "<<binario_entero(n,a)<<" (Residuo)\n";;
	delete [] a;
	delete [] q;
	delete [] m;
	
}
