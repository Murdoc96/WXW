#include<omp.h>
#include<iostream>
#include<sys/time.h>
#include<stdio.h>

using namespace std;
void suma(){//empesamos con el metodo suma 
int m;//dimension de las matrices 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);

  omp_set_num_threads(8);//colocamos este comando para el numero de hilos 
  cout<<"ingrese el numero de filas y columnas"<<endl;
  cin>>m;//ingresamos un valor para definir la dimencion de las matrices
  

  int  A[m][m],B[m][m],C[m][m];//declaramos las matrices con una dimencion de m 
  
  //en los sigues linias de codigo llenamos las matriz A con la suma de j+i 
  for( int i=0;i<m;i++){
     for(int j=0;j<m;j++){
           A[i][j]=j+i;
      }
  }
  //en las siguientes linias de codigo llenamos las matriz B con la multiplicacion j*i
   for( int i=0;i<m;i++){
      for(int j=0;j<m;j++){
            B[i][j]=j*i;
      }
   }
 
#pragma omp parallel for //este comando se ejecuta la programacion paralela en el proceso de la suma de la matriz A +B y almacenamos en C
	for( int i=0;i<m;i++){
		for(int j=0;j<m;j++){
            C[i][j]=A[i][j]+B[i][j];
		}
	}

cout<<endl;
cout<<"LA MATRIZ C"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
 for( int i=0;i<m;i++){
        cout<<"      "<<endl;
     for(int j=0;j<m;j++){

            cout<<"      "<<C[i][j];
      }
  }
  
cout<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion  
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*1000+usecons/1000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tienpo duro "<<mtime<<" mili segundo";//imprimimos el tiempo de ejecucion 

}

void resta(){
int m;//dimension de las matrices 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);

  omp_set_num_threads(8);//colocamos este comando para el numero de hilos para la programacion paralela
  cout<<"ingrese el numero de filas y columnas"<<endl;
  cin>>m;//ingresamos un valor para definir la dimencion de las matrices
  

  int  A[m][m],B[m][m],C[m][m];//declaramos las matrices con una dimencion de m 
  
  //en los sigues linias de codigo llenamos las matriz A con la suma de j+i 
  for( int i=0;i<m;i++){
     for(int j=0;j<m;j++){
           A[i][j]=j+i;
      }
  }
  //en las siguientes linias de codigo llenamos las matriz B con la multiplicacion j*i
   for( int i=0;i<m;i++){
      for(int j=0;j<m;j++){
            B[i][j]=j*i;
      }
   }
 
#pragma omp parallel for //este comando se ejecuta la programacion paralela en el proceso de la suma de la matriz A +B y almacenamos en C
	for( int i=0;i<m;i++){
		for(int j=0;j<m;j++){
            C[i][j]=A[i][j]-B[i][j];
		}
	}

cout<<endl;
cout<<"LA MATRIZ C"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
 for( int i=0;i<m;i++){
        cout<<"      "<<endl;
     for(int j=0;j<m;j++){

            cout<<"      "<<C[i][j];
      }
  }
  
cout<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion  
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*1000+usecons/1000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tienpo duro "<<mtime<<" mili segundo";//imprimimos el tiempo de ejecucion 


}




void multi(){
int m,i,j,k;//declaramos variables 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);


omp_set_num_threads(8);//colocamos este comando para el numero de hilos para la programacion paralela
cout<<"INGRESE LA FILA Y COLUMNA DE LAS MATRICES"<<endl;;
cin>>m;//ingresamos un valor para definir la dimencion de las matrices


int A[m][m],B[m][m],C[m][m];//declaracion de las matrices
//con los siguientes codigos empesamos a llenar las matriz A con la i+j
for (i=0;i<m;i++)
{
	for (j=0;j<m;j++)
	{ 
	A[i][j]=i+j;
	}
}
//con los siguientes codigos empesamos a llenar las matriz B con la i*j
for (i=0;i<m;i++)
	{
   for (j=0;j<m;j++)
    { 
		B[i][j]=i*j;
    }
}

//este comando se ejecuta la programacion paralela en el proceso de la multiplicacion de la matriz A*B y almacenamos en C

#pragma omp parallel for
	for (i=0;i<m;i++)
	{
			for (j=0;j<m;j++)
			{
				C[i][j]=0;
			for (k=0;k<m;k++)
			{
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	

cout<<"LA MULTIPLICACION DE LAS MATRICES ES:"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
  for (i=0;i<m;i++)
  {
	cout<<"      "<<endl;
   for (j=0;j<m;j++)
    { 
		cout<<"     "<<C[i][j];
    }
  }
cout<<"  "<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion 
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*1000+usecons/1000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tienpo duro "<<mtime<<" mili segundo";//imprimimos el tiempo de ejecucion 
}
 
	

int main(){
	//Aqui procedemos a hacer un menu sencillo para llamar a los metodos de suma, resta y multiplicacion
    int op;//creamos una variable para las opciones del  menu
    cout<<"---------------------"<<endl;
    cout<<"selecione un opcion "<<endl;
    cout<<"1.- suma de matrices "<<endl;
    cout<<"2.- resta de matrices "<<endl;
    cout<<"3.- multiplicaion de matrices"<<endl;
     cout<<"---------------------"<<endl;
    cin>>op;//Ingresamos la opcion
     switch(op){
        case 1:suma();break;//en la primera opcion tenemos a la suma y por tanto instanciamos al metodo suma
		case 2:resta();break;//en la segunda opcion tenemos a la resta y por tanto instanciamos al metodo resta
		case 3:multi();break;//en la tercera opcion tenemos a la multiplicacion y por tanto instanciamos al metodo multi
     }


return 0;
}

