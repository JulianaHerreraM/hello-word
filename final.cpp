#include <iostream>
#include <stdlib.h>

/*PROYECTO FINAL 
1-Hallar el menor elemento de la matriz A.

2-Determinar cuántas veces se encuentra almacenado el elemento menor en la
matriz A.

3-Calcular la matriz B= [bij] tal que bij= (aij)2 e imprimir su resultado
descendente (del ultimo al primer elemento)

4-Calcular la suma de los elementos de la matriz A tales que (i+j) sea un número
impar.   

5- Determine si el promedio de los elementos de su diagonal principal es un
número primo.

6- Almacenar en un vector V la suma de cada una de las columnas de la matriz A.

7- Imprimir el vector V

8- Calcule la suma del menor elemento y el mayor elemento del vector V */

using namespace std;

//1.Lectura de la matriz A
void lecturaMatriz(int matrizA[][50],int filas,int columnas)
{
 	int i,j;
 	for(i=0;i<filas;i++)
 	{
	 	for(j=0;j<columnas;j++) 
		{
		  cout<<"\t\t Ingrese el [" <<i+1<< "] [" <<j+1<< "] elemento a procesar: "; //Pido al usuario que ingrese el numero de filas y columnas a procesar.
		  cin>>matrizA[i][j];
		} cout<<endl;
	}
}

//2.Escritura de la matriz A
void EscrituraMatriz(int matrizA[][50], int filas, int columnas)
{   
 	int i,j;
 	for(i=0;i<filas;i++){
 		for(j=0;j<columnas;j++) 
		{ 
 		cout<<"\t\t"<<"["<<matrizA[i][j]<<"] "; //Muestro la matriz que generé.
	    }cout<<endl;
	}
}
 //3.Hallar el menor elemento de la matriz A
int MenorElemento(int matrizA[][50], int filas, int columnas)
{
	int menor=999999, i , j;
	for (i=0; i < filas ; i++) 
	{
		for (j=0; j<columnas; j ++) 
		{
			if (matrizA[i][j]<menor) 
			{ // Calculo el menor elemento de matriz 
				menor=matrizA[i][j];
			}
		}
	}
	return menor;
}

//4.Determinar cuántas veces se encuentra almacenado el elemento menor en la matriz A.
void FrecuenciaMenor(int matrizA[][50], int filas, int columnas)
{
	int cta,menor,i,j;
	menor=MenorElemento(matrizA,filas,columnas);
	for (i=0; i < filas ; i++) { //Busqué otra forma de mostrar el la matriz en forma descendente
		for (j=0; j<columnas; j ++)
		{
			if (matrizA[i][j]==menor) 
			{
			cta++;	
			}
		}
	}
	cout<<"\n\t\t El menor elemento de la matriz A se repite "<<cta<<" veces"<<endl;// muestro el menor elemento de la matriz A
}
//5.Calcular la matriz B= [bij] tal que bij= (aij)2 e imprimir su resultado descendente (del ultimo al primer elemento)
void matrizB(int matrizA[][50], int filas, int columnas,int matrizB[][50])//Calculo la matriz B tal que ij al cuadrado es igual a B
{
	int i,j;
    for (i=0; i < filas ; i++)
	 {
		for (j=0; j<columnas; j ++){
			matrizB[i][j]=matrizA[i][j]*matrizA[i][j];
				
		}
	}
	
}
//Ordenar de manera descendente del ultimo al primer elemento  la matriz B
void OrdenDescendente(int matrizB[][50],int columnas,int filas)
{//Esto no funciona 
	int i,j;
     for (i=filas-1; i>-1; i--) 
	 {
		for (j=columnas-1; j>-1; j --)
		{
		cout<<"\t"<<"["<<matrizB[i][j]<<"] ";
	    }cout<<endl;                 	
	}
}
//6.Calcular la suma de los elementos de la matriz A tales que (i+j) sea un número impar.
// no funciona
int Suma_impares(int matrizA[][50], int filas, int columnas)
{
 int i, j, suma=0;
 for (i=0; i < filas ; i++) 
 {
		for (j=0; j<columnas; j ++)
		{
	    if((i+j)%2!=0)
	    {
	    suma=suma+matrizA[i][j];
	    }
		}
		}
		return (suma);
}
//7.Determine si el promedio de los elementos de su diagonal principal es un número primo.
/*float diagonal_principal(int matrizA[][50], int filas, int columnas)
 {
int i, j, cuenta=0;
float sumadiagonal=0, promedio;
for (i=0; i < filas ; i++) 
 {
		for (j=0; j<columnas; j ++)
		{
	    if(i==j)
	    {
	    sumadiagonal=sumadiagonal+matrizA[i][j];
	    cuenta=cuenta+1;
	}
	if(cuenta!=0)
	{
	promedio= sumadiagonal/cuenta;// Promedio de la diagonal despues de la suma 
	}
}
}return(promedio);
cout<<endl;
}
//Validar si es un  numero primo

int primo(int promedio)
{
int divi=0, i;
for(i=0; i<(promedio+1); i++)
{
if( promedio%i==0)
{
divi++;
}
}
if(divi==2)
{
	return (1);
	
}
else
{
return (0);
}	
}			
 
*/
void PromedioDiagonal(int matrizA[][50], int filas, int columnas)
{
	
	int suma = 0;
	int a = 0;
	int promedio = 0;
	int contador = 0;
	
	if (filas == columnas) {
		for (int i = 0; i < filas; i++){
    		for (int j = 0; j < columnas; j++){
    			if(i == j){
    				suma += matrizA[i][j];
    				contador++;
				}
    		}
    	}
    		promedio = suma/contador;
    	
    	for (int i = 1; i < (promedio+1); i++){
    		
         if(promedio %i ==0){
             a++;
            }
         }
         if(a!=2){
              cout <<"El promedio de la diagonal es "<< promedio<< " y no es un numero primo" << endl;
            }else{
               cout <<"El promedio de la diagonal es "<< promedio<< " y es numero primo" << endl;;
         }
	} else {
		cout <<"La matriz no tiene diagonal principal "<<endl;
	}
	
}
//no funciona
//8. Almacenar en un vector V la suma de cada una de las columnas de la matriz A.
void SumaColumnas(int matrizA[][50], int filas, int columnas, int v[50]) 
{
	
	int i, j, suma = 0;
	for (j=0; j < columnas ; j++) 
	{ suma=0;
		for (i=0; i<filas; i ++)
		{
			suma = suma + matrizA[i][j];
			cout<<"\t\t La suma "<<j+1<< "es: "<<suma<<endl;
		}
		v[j] = suma;
		
	} 
}

// Imprimir el vector V 

void MostrarVector(int v[50],int columnas) 
{
	int j;
	for (j=0 ; j<columnas; j++) 
	{
		cout<<"["<<v[j]<<"] ";// Muestro el vector 
	}
}

//9.Calcule la suma del menor elemento y el mayor elemento del vector V.

int MayorVector(int v[],int columnas)
{     //Mayor Elemento del vector
	  int mayor=-999999,i;
	  for(i=0;i<columnas;i++)
	  {
	  	if(v[i]<mayor)
	  { 
	  mayor=v[i];    
	  }
	  
	  	
	  }
	  return mayor;
}

int MenorVector (int v[],int columnas)
{   //Menor Elemento del vector
	  int i;
	  int menor=999999;
	  for(i=0;i<columnas;i++){
	  	if(v[i]<menor){ menor=v[i];        }
	  }
	  return menor;
}

int SumaMenorMayor_Vector(int v[],int columnas)
   //Suma de los elementos mayores y de los elementos menores del vector.
{
    int menor, mayor, suma=0;
	menor=MenorVector(v,columnas);
	mayor=MayorVector(v,columnas);
	suma=menor+mayor;
	return suma;

}

void menu() {  
	int opc, matrizA[50][50]={0}, matrizB[50][50]={0}, v[50]={0};
	int filas,columnas,menor;
	int cuenta;
	float promedio;
	//esto para que el tamaño de las matrices sea igual y poder trabajar con la diagonal.
 	do 
    {
 		
	 system("cls");
	 
   		cout<<" \t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  "<<endl; 	 
   		cout<<" \t\t                  MENU PRINCIPAL                            "<<endl; 
		cout<<"\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  "<<endl;   	  
   		cout<<" \t\t  1* Captura Matriz A                                       "<<endl;   
   		cout<<" \t\t  2* Escritura Matriz A                                     "<<endl;  
   		cout<<" \t\t  3* Menor elemento de la matriz A                          "<<endl;  
   		cout<<" \t\t  4* Frecuencia menor elemento de la matriz A               "<<endl; 
		cout<<" \t\t  5* Matriz B =(A*A)                   |                    "<<endl;
		cout<<" \t\t  6* Suma del elemento de A (i+j=impar)                     "<<endl; 
		cout<<" \t\t  7* Evaluar diagonal principal de matriz A                 "<<endl;
		cout<<" \t\t  8* Vector columnas de la matriz A	                        "<<endl;
		cout<<" \t\t  9* Suma menor y mayor elemento		                    "<<endl;  
	    cout<<" \t\t  10*Salir.     	                                        "<<endl;
   		cout<<" \t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  "<<endl;   
 		cout<<"\n\t\t Por favor elija una opcion ";
   		cin>>opc;
   switch(opc){
   	case 1: cout<<"\t\t Captura matriz A "<<endl;
            cout<<"\t\t Ingrese la cantidad de Filas y de Columnas: ";
            cin>>filas>>columnas;
            lecturaMatriz(matrizA,filas, columnas);
            system("pause");
            break;		   
	 case 2:
	      cout<<"\t\t Escritura matriz "<<endl;
	      EscrituraMatriz(matrizA,filas, columnas);
		  system("pause");
		  break;			  
	case 3:
		EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\t Menor valor de A";
		menor=MenorElemento(matrizA,filas,columnas);
		cout<<"\n\t\t El menor elemento de la matriz a es: ["<<menor<<"] "<<endl;
		system("pause");
		break;
	case 4:
	    EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\t Frecuencia del menor elemento";
		FrecuenciaMenor(matrizA, filas, columnas);
		system("pause");
		break;
	case 5:
		EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\t Matriz B "<<endl;
		cout<<"\t La matriz B en orden descendente es :";
		OrdenDescendente( matrizB,columnas,filas);
		system("pause");
		break;
	case 6:
		EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\t Suma de los Elementos (i+j)"<<endl;
		cout<<"\t La suma de los elementos impares es: ";
		Suma_impares(matrizA,  filas, columnas);
		system("pause");
		break;
	case 7:
		EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\tEvaluar diagonal principal de la matriz A "<<endl;
		cout<<"\t El promedio de la diagonal principal es: ";
	    PromedioDiagonal( matrizA,  filas,  columnas);
     	system("pause");
		break;
	case 8:
		EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\t Vector columnas de la matriz A "<<endl;
		SumaColumnas( matrizA,  filas, columnas, v);
	    MostrarVector(v,columnas);
		system("pause");
		break;
	case 9:
	    EscrituraMatriz(matrizA,filas,columnas);
		cout<<"\t\tSuma del Mayor y Menor elemento del Vector"<<endl;
		SumaMenorMayor_Vector( v,columnas);
		system("pause");
		break;
		default: 
		cout<<endl<<endl;
		cout<<"\t\t Salir"<<endl;
	}
}while (opc!=10);
}

		
	    
		

int main(int argc, char** argv) 
{
	system("COLOR f2");
	menu();
	cout<<endl;
	return 0;
}
