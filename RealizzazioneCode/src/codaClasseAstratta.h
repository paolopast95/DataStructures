/*
 * codaClasseAstratta.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef CODACLASSEASTRATTA_H_
#define CODACLASSEASTRATTA_H_

template<class T, class P>
class coda{
public:
	typedef T tipoelem;
	typedef P posizione;

	virtual void createQueue() = 0;
	virtual bool emptyQueue() = 0;
	virtual tipoelem readQueue() = 0;
	virtual void insertQueue(tipoelem) = 0;
	virtual void eraseQueue() = 0;
};



#endif /* CODACLASSEASTRATTA_H_ */
