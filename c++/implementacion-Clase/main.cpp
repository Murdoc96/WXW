#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include"listasimple.h"

//tamanhi del terminal 187x44

using namespace std;
/*
	- Número aleatorios entre 250 y 420:
	num=250+rand()%(421-250);
 */

namespace functionSupport{
	void clear(){
		system("clear");
	}

	void viewMenu(){
		unsigned int  a = 1;//chage do{}while()
		//functionSupport::clear();
		cout << "\t\t\t\t\t\t\t\t\t\tMENU GENERAL \n\n\n\n";
		cout << "\t\t" << a++ << ".- " << "Salir " << endl;			//2
		cout << "\t\t" << a++ << ".- " << "Ver informacion de cada Ciencias " << endl;	 //1
		cout << "\t\t" << a++ << ".- " << "mostrar secuencialmente " << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t\t\tDigite la opcion elegida: ";

	}

	void viewMenuIntern(string FileName){
		//functionSupport::clear();
		ifstream salida;
		salida.open(FileName+ext,ios::in);
		cout << "\t\t\tLIST OF SCIENCES\n";
		unsigned int a = 0;
		char key[20];
		char informacion[500];
		while( !salida.eof()){
			salida.getline(key,20,'#');
			salida.getline(informacion,500,'\n');
			cout << " \t"<< ++a << " --> " << key << endl;
		}
		salida.close();
		cout << "\t\t\t\t Escribe el nombre de la ciencia: ";
	}


};




int main(){

	// ifstream salida;
	// char key[3];
	// char info[100];
 // 	long int address = 0;
	// char temp[190];


	// salida.open("data.txt",ios::in);
	//while( !salida.eof()){



	// while(!salida.eof()){
	// 	salida.getline(key,sizeof(key),'#');
	// 	salida.getline(info,sizeof(info),'\n');
	// 	// salida.seekg(address);
	// 	cout << key << " " << info << endl;
	//
	// 	// address = address + sizeof(key) + sizeof(info);
	// }
	// while(!salida.eof()){
	// 	salida.getline(key,3,'#'); // ya lo suma 1 en DEFAULT ADRRESS en caso encuentre el # antes del 3
	// 	salida.getline(info,100,'\n');
	// 	cout << key << " " << info << endl;
	// 	Record R(key,25);
	//
	// 	cout << R.getKey() << endl;		/*
	// 	por dentro hay un puntero que deja en una posicion.
	// 	esto es lo que sucede por dentro:
	// 	address = address + strlen(key) + 1 + strlen(info) + 1;
	// 	cout << address << endl;
	// 	salida.seekg(address);
	// 	*/
	//
	// }


	// salida.seekg(address);
	// salida.getline(key,3,'#');
	// salida.getline(info,100,'\n');
	// cout << key << " " << info << endl;
	//
	// address = address + strlen(key) + strlen(info) + 2;
	// cout << address << endl;
	//
	// salida.seekg(address);
	// salida.getline(key,3,'#');
	// salida.getline(info,100,'\n');
	// cout << key << " " << info << endl;

		// address = address + sizeof(key) + sizeof(info);
		// cout << info << "esta enb el len "<< address <<  endl;

	//}


	// for(int e = 0 ; e < 120 ;e++){
	// 	salida.seekg(e);
	// 	salida.getline(info,sizeof(info));
	// 	cout << "info seekp(" << e << ") : " << info << endl;
	// }

	//salida.close();


	// listas *newlista = new ListaSimple<int>();
	// cout << newlista << endl;
	// int num;
	// for(int e = 1 ; e < 8; e++){
	// 	//num = 0 + rand() % (500 - 0);
	// 	newlista->add(e);
	// }
	// newlista->print();
	// int f; cout << "number add : " ; cin >> f;
	// newlista->add(f);
	// newlista->print();
	//
	//
	//
	// int n; cout << "number delete : "; cin >> n;
	// //newlista->delete_data_search(n);
	// newlista->deleting(n);
	// newlista->print();
	//
	// delete newlista;

	ListaSimple<Record> *lista_registros = new ListaSimple<Record>();



	// paso importante para poder agregar la key y la address a la estrctura de datos que estamos utilizando
	// en este cao los nodos
 	string savekeys;
	lista_registros->indexar("data",savekeys);




	int iop; // opcion en donde correra en switch
	int cont = 0;
	bool ver = true;
	char name[20];
	bool otraciencia = false;
	do{
		functionSupport::clear();
		functionSupport::viewMenu();

		// verificacion de tipaje
		do{
			cin.clear();
			if(cont > 0) cin.ignore(1024, '\n');
			cin >> iop;
			cont++;
			if( !cin.fail() ){
				ver = false;
			}
		}while( ver );

		switch(iop){
			case 2:
					functionSupport::clear();
					do{
						functionSupport::viewMenuIntern("data"); cin >> name;
						lista_registros->read("data",name);
						cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t elegir otra ciencia ?(1/0)";  cin >> otraciencia;
						functionSupport::clear();
					}while(otraciencia);
					break;
			case 3:
				functionSupport::clear();
				ifstream salida;
				char key[20];
				char info[500];
				salida.open("data.txt",ios::in);
				while(!salida.eof()){
					salida.getline(key,20,'#');
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t"<<key << endl;
					salida.getline(info,500,'\n');
					lista_registros->read("data",key);
					cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t next ?(1/0)";  cin >> otraciencia;
					functionSupport::clear();
					if(otraciencia)continue;
					else break;


				}
				salida.close();


		}

	}while(iop != 1);
	//functionSupport::clear();





	delete lista_registros;



	return 0;
}
