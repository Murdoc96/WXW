
//agrega a la cabeza
template<typename type>
void ListaSimple<type>::push_front(type data){
	Nodo newnode = new Node<type>(data);
	if(!head)
		head = last = newnode;
	else{
		newnode->setNext(head);
		head = newnode;
	}
}

//agregando al final
template<typename typus>
void ListaSimple<typus>::push_back(typus data){
	Nodo newnode = new Node<typus>(data,NULL);
	if(!head)
		head = last = newnode;
	else{
		last->setNext(newnode);
		last = newnode;
	}
}

//eliminamos el inicio
template<typename type>
void ListaSimple<type>::pop_front(){
	if(!head)
		return;
	else{
		Nodo temp = head;
		head = head->getNext();
		delete temp;
	}
}

//eliminando el final
template<typename type>
void ListaSimple<type>::pop_back(){
	if(!head)
		return;
	else if(head == last){
		delete head;
		head = last = 0;
	}
	else{
		Nodo temp = head;
		while(temp->getNext() != last)
			temp = temp->getNext();
		delete last;
		last = temp;
		temp->setNext(0);
	}
}

// imprimiendo una lista
template<typename typus>
void ListaSimple<typus>::print(){
	Nodo temp = head;
	while(temp){
		std::cout << temp->getData() << "-> ";
		temp = temp->getNext();
	}
	std::cout << "\n";

}

//mayor de una ListaSimple
template<typename type>
Node<type> *ListaSimple<type>::getMayor(){
	Nodo temp = head;
	int mayor = temp->getData();
	while(temp){
		if(temp->getData() >= mayor)
			mayor =temp->getData();
		temp = temp->getNext();
	}
	return new Node<type>(mayor);
}
// eliminar un elemento buscado(pasado por parametro)
template<typename type>
void ListaSimple<type>::delete_data_search(type data){
	Nodo temp1 = 0;
	Nodo temp2 = head;
	while(temp2){
		if(temp2->getData() == data)
			break;
		temp1 = temp2;
		temp2 = temp2->getNext();
	}
	//primer caso
    //cuando el elemento a eliminar es la cabeza
	if(temp1 == 0){
		head = head->getNext();
		delete temp2;
	}
	//segundo caso cuando el elemento a eliminar es el last puntero
	else if(temp2 == last){
		last = temp1;
		delete temp2;
		last->setNext(NULL);
	}
	//cuando no encontro nada
	else if(!temp2){return;}
	// tercer caso cuando esta el cualquier parte media o no lo encontro->return
	else{
		temp1->setNext(temp2->getNext());
		delete temp2;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// con puntero doble
// la funcion find->true si lo encuentra y deja el puntero justo antes para agregarle


// template<typename type>
// bool ListaSimple<type>::find(Node<type>** &p,type d){
// 	p = &(this->head);
// 	while((*p)){ // 100pre:-)
// 		if( (*p)->data.key == d )return true;
// 		if( (*p)->data.key > d )return false;
// 		p =&((*p)->next);
// 	}
// 	return false;
// }

// esta funcion llama a la funcion find para verficar que le agregue y deja el puntero justo uno antes
// para agregarle.

// template<typename type>
// bool ListaSimple<type>::add(type data){
// 	Node<type> **q;
// 	if( ! find(q,data)){
// 		Node<type> *newnode = new Node<type>(data);
// 		newnode->setNext(*q);
// 		*q = newnode;
// 		return true;
// 	}
// 	return false;
// }

template<typename type>
bool ListaSimple<type>::find(Node<type>** &p,type d){
	p = &(this->head);
	//int a = 0;
	while((*p)){ // 100pre:-)
		//cout << a++ << endl;
		if( d == (*p)->data )return true;
		//cout << "D: " << d << "... (*p)->data.key,addes: " << (*p)->data.getKey() << " " << (*p)->data.getAddress() <<  "    ademas: " << (d == (*p)->data) << endl;
		if(d < (*p)->data)return false;
		p =&((*p)->next);
	}
	return false;
}



template<typename type>
bool ListaSimple<type>::add(type data){
	Node<type> **q;
	if( ! find(q,data)){
		Node<type> *newnode = new Node<type>(data);
		newnode->setNext(*q);
		*q = newnode;
		return true;
	}
	return false;
}

template<typename type>
bool ListaSimple<type>::deleting(type data){
	Node<type> **q;
	if( find(q,data) ){
		Node<type> *temp = *q;
		*q = (*q)->next;
		delete temp;
		return true;
	}
	return false;
}

template<typename type>
void ListaSimple<type>::indexar(string FileName,string &savekeys){

	ifstream salida;
	salida.open(FileName+ext, ios::in);
	char key[20];
	long int address  = 0;
	char informacion[500];

	while( !salida.eof()){
		salida.getline(key,20,'#');
		salida.getline(informacion,500,'\n');
		savekeys = savekeys + key + "@";
		Record R(key,address);
		add(R);
		address=address + strlen(key) + strlen(informacion) + 2;
	}
	salida.close();
}

//imprimir la lista de records
template<typename type>
void ListaSimple<type>::print_lista_registros(){
	Node<type> *temp = head;
	while(temp){
		cout << "key: "<<temp->data.key << "address: " << temp->data.address << endl;
		temp = temp->getNext();
	}
}

template<typename type>
void ListaSimple<type>::read(string FileName, const char *key){
	Node<type> **p;
	Record temp(key,0);
	if( find(p,temp )){
		char inf[500];
		long int address =(*p)->data.address;

		ifstream salida;
		salida.open(FileName+ext,ios::in);
		salida.seekg(address+strlen(key)+1);
		salida.getline(inf,500);
		cout << "\n\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";
		cout << inf << endl;
		cout << "\n\n//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";
		salida.close();
	}
	else
		cout << "\n\n\t\t\t\t\t\t\t\t\t >->->->->->->->->->->->->->->->  no existe en el Base de Datos";
}




//
// template<typename type>
// void ListaSimple<type>::indexar(char* FileName){
// 	ifstream salida;
// 	salida.open(FileName+ext, ios::in);
// 	char key [30];
// 	long int address  = 0;
// 	char informacion[500];
// 	while( !salida.eof()){
// 		salida.getline(key,30,'#');
// 		salida.getline(informacion,100,'@');
// 		Record R(key,address);
// 		add(R);
// 		address=address + strlen(key) + strlen(informacion)+ 3;
// 	}
// 	salida.close();
// }
// template<typename type>
// void ListaSimple<type>::read(char *key, char *FileName){
// 	Node<type> **p;
// 	if( find(Record(key), p) ){
// 		char inf[500];
// 		long int address =(*p)->data.address;
// 		ifstream salida;
// 		salida.open(Filename+ext,ios::in);
// 		salida.seekg(0,address);
// 		salida.getline(inf,500);
// 		salida.close();
// 	}
// }
