/*
 * InterfaceSegragation.cpp
 *
 *  Created on: Dec 17, 2020
 *      Author: pravinkumar
 */

#include "InterfaceSegragation.h"

struct IDocument;

/*
 * Below struct define way to more than the functions that a regular printer may do;
 * This is ok when you are very sure about implementing all these listed features;
 * But when we just going to use partial functionalities of an interface,
 * Then the below may not fit;
 * ****
 */
//--------------------------------------------------------------------------------Before;

struct IMachine {
	virtual void Print(IDocument&) = 0;
	virtual void Scan(IDocument&) = 0;
	virtual void Fax(IDocument&) = 0;
	virtual ~IMachine() {
	}
};

/*
 * suppose a printer machine supports all the above IMachine functions then fine;
 * */

struct Machine: IMachine {
	void Print(IDocument &doc) {

	}
	void Scan(IDocument &doc) {

	}
	void Fax(IDocument &doc) {

	}
};

/*
 * but when it is just a single job handler; like below;
 * */
struct Scanner: IMachine {
	void Print(IDocument &doc) {
	} // these methods are not necessary;
	void Fax(IDocument &doc) {
	}   // these methods are not necessary;
	void Scan(IDocument &doc) {
		// Just for this single method you don't need to use the other methods;
		//then you are giving something un-necessary
	}
};


//--------------------------------------------------------------------------------After;
/*
 * IN this case;
 * You may segragate the interfaces to just handle a single fucntionality;
 *
 * */

struct IScanner {
	virtual void Scan(IDocument&) = 0;
	virtual ~IScanner() {
	}
};
struct IPrinter {
	virtual void Print(IDocument&) = 0;
	virtual ~IPrinter() {
	}
};

/*
 * and now  you can just inherit them to create another structure; which more easy to manipulate;
 * */

struct IMachineEx : IScanner, IPrinter{

};

/*
 * and when implementing the IMachineEx; you will have complete control over this;
 *
 * For example you may use the existing functionalities like Scanner and Printer in this case;
 *
 * See below
 *
 * */

struct MachineEx : IMachineEx{
	IPrinter &printer;
	IScanner &scanner;
	MachineEx(IPrinter &printer_, IScanner &scanner_) : printer(printer_), scanner(scanner_){

	}
	// and when we have to the operations we can use the existing printer and scanner services
	// provided by the interfaces;

	void Scan(IDocument &doc)override{
		//Scan here;
	}
	void Print(IDocument &doc)override{
		//Print here;
	}

	~MachineEx(){

	}

};





void InterfaceSegragation::Run() {

}

InterfaceSegragation::~InterfaceSegragation() {
	// TODO Auto-generated destructor stub
}

