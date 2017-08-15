#ifndef TABLA_H
#define TABLA_H
#include"listado.h"
const int TABLE_SIZE = 5;

class HashMap {
private:
	Campo **table;
public:
	HashMap() {
		table =	new Campo*[TABLE_SIZE];
		for(int	i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int get(int	key){
		int hash = (key % TABLE_SIZE);
		if (table[hash] == NULL)
			return -1;
		else{
			Campo *entry = table[hash];
			while (entry != NULL && entry->getKey() != key)
				entry = entry->getNext();
			if(entry == NULL)
				return -1;
			else
				return entry->getValue();
		}
	}

	void put(int key, int value){
		int hash = key % TABLE_SIZE;
		Campo *newcampo = new Campo(key,value,NULL);
		if (table[hash] == NULL)
			table[hash] = new Campo(key,value,NULL);
		else{
			Campo *before = NULL;
			Campo *current = table[hash];
			if( current->getKey() > key){ // cuando la cabeza es mayor de el que se va a agregar
				newcampo->setNext(current);
				table[hash] = newcampo;
			}
			else{
				//aseguramos como minimo 2
				before = current;
				current = current->getNext();
				while(before->getNext() != NULL && before->getKey() < key && before->getNext()->getKey() < key){
					before = current;
					current = current->getNext();
				}
				before->setNext(newcampo);
				newcampo->setNext(current);

			}
		}
	}

	void remove(int key) {
		int hash = (key % TABLE_SIZE);
		if(table[hash] != NULL){
			Campo *before = NULL;
			Campo *current = table[hash];
			//caso:1 cuando hay una sola cabeza y este sera a eliminarse
			if(current->getNext() == NULL && current->getKey() == key){
				before = current;
				table[hash] = NULL;
				delete before;
			}
			// cas0 2: cuando hay mas de un elemento y la cabeza es a eliminarse
			else{
				if (current->getNext() != NULL && current->getKey() == key){
					before = current;
					table[hash] = current->getNext();
					delete before;

				}
				else{
					before = current;
					current = current->getNext();
					while(current->getKey() != key){
						before = current;
						current = current->getNext();
					}
					before->setNext(current->getNext());
					delete current;
				}
			}
		}
	}

    void print(){
	    for(auto e = 0 ; e < TABLE_SIZE ; e++){
	    	if(table[e] == NULL)
	    		std::cout << "[" << e << "]:  ";
	    	else{
	    	Campo *temp = table[e];
	    	std::cout << "[" << e << "]:  " ;
	    		while(temp != NULL){
	    			std::cout << "|" <<temp->getKey() << "|"<< temp->getValue() << "| -> ";
	    			temp = temp->getNext();
	    		}
	    	}
	    	std::cout << "NULL" << std::endl << std::endl;
	    }
    	}

   ~HashMap(){
		for (int i = 0; i < TABLE_SIZE; i++){
			if (table[i] != NULL){
				Campo *prevEntry = NULL;
				Campo *entry = table[i];
				while (entry != NULL){
            		prevEntry = entry;
            		entry = entry->getNext();
            		delete prevEntry;
           	}
			}
		}
	delete [] table;
	}
};

#endif // TABLA_H
