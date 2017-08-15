#ifndef LISTADO_H
#define LISTADO_H


class Campo{
private:
	int key;
	int value;
	Campo *next;
public:
	Campo(int key, int value, Campo *next = NULL):
		key(key), value(value){
			next = next;
		}
	int getKey()const{ return key;}
	int getValue()const {return value;}
	void setValue(int valor){this->value = valor;}
	Campo *getNext(){ return next; }
	void setNext(Campo *sgte){ this->next = sgte;}
};

int  sumaCharacters(std::string word)
{
	int cont = 0 ;
	for(auto it = word.begin() ; it != word.end() ; it++)
	{
		//conssiderando los caracteres de ascci
		cont += *it;
	}
	return cont;
}




#endif // LISTADO_H
