/*
 * prioriCodaHeap.h
 *
 *  Created on: 10 gen 2017
 *      Author: Paolo
 */

#ifndef PRIORICODAHEAP_H_
#define PRIORICODAHEAP_H_

#include"prioriCoda.h"

template<class T>
class prioriCodaHeap : public prioriCoda<T>
{
public:
  typedef T tipoelem;
  prioriCodaHeap();
  prioriCodaHeap(int);
  ~prioriCodaHeap();

  void creaPrioriCoda();
  void inserisci(tipoelem);
  tipoelem min();
  void cancellaMin();

private:
  int MAXLUNG;
  tipoelem *heap;
  int ultimo;

  void fixUp ();
  void fixDown (int, int);
};


template<class T>
prioriCodaHeap<T>::prioriCodaHeap()
{
	MAXLUNG = 100;
	heap = new tipoelem[MAXLUNG];
	creaPrioriCoda ();
};

template<class T>
prioriCodaHeap<T>::prioriCodaHeap(int dim)
{
	MAXLUNG = dim;
	heap = new tipoelem[MAXLUNG];
	creaPrioriCoda();
}

template<class T>
prioriCodaHeap<T>::~prioriCodaHeap()
{
	delete[] heap;
}

template<class T>
void prioriCodaHeap<T>::creaPrioriCoda()
{
	ultimo = 0;
}

template<class T>
void prioriCodaHeap<T>::inserisci(tipoelem x)
{
	if(ultimo < MAXLUNG)
	{
		ultimo++;
		heap[ultimo - 1] = x;
		fixUp();
	}
}

template<class T>
typename prioriCodaHeap<T>::tipoelem prioriCodaHeap<T>::min()
{
	if(ultimo != 0)
		return heap[0];
}

template<class T>
void prioriCodaHeap<T>::cancellaMin()
{
	if(ultimo != 0)
	{

		  heap[0] = heap[ultimo - 1];

		  ultimo--;
		  fixDown (1,ultimo);
	}
}

template<class T>
void prioriCodaHeap<T>::fixUp()
{
  int k = ultimo;

  while (k > 1 && heap[k - 1] < heap[k / 2 - 1])
  {
      tipoelem tmp;
      tmp = heap[k - 1];
      heap[k - 1] = heap[k/2 - 1];
      heap[k/2 - 1] = tmp;
      k = k/2;
    }
}


template<class T>
void prioriCodaHeap<T>::fixDown (int k, int N)
{
	int scambio = 1;

	while (k <= N / 2 && scambio)
	{
		int j = 2 * k;
		tipoelem tmp;
		if (j < N && heap[j - 1] > heap[j])
		{
			j++;
		}
		if (scambio == (heap[j - 1] < heap[k - 1]))
		{
			tmp = heap[k - 1];
			heap[k - 1] = heap[j - 1];
			heap[j - 1] = tmp;

		}
		k = j;
	}
}
#endif /* PRIORICODAHEAP_H_ */
