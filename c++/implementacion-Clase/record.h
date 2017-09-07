#ifndef RECORD_H
#define RECORD_H


#include"node.h"

class Record{
public:
	char key[20];
	long int address;
public:
	Record(const char *msg,long int address = 0):
		address(address){
			strcpy(key,msg);
		}
	~Record(){}

	//sets and get
	void setKey(const char *newkey){strcpy(key,newkey);}
	void setAddress(long int newadd){address = newadd;}
	const char *getKey()const{return key;}
	long int getAddress()const{return address;}

	friend std::ostream& operator << (std::ostream &out,const Record &r){
		out << r.key << " " << r.address;
		return out;
	}

	bool operator == (const Record &d2){
		if(strcmp(key,d2.key) == 0)
			return true;
		return false;
	}

	// friend bool operator == (const Record &d1,const Record &d2){
	// 	if(strcmp(d1.key,d2.key) == 0)
	// 		return true;
	// 	return false;
	// }

	friend bool operator < (const Record &d1,const Record &d2){
		if ( d1.key < d2.key)
			return true;
		return false;
	}



};




#endif // RECORD_H
