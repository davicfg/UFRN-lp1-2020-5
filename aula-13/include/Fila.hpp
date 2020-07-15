#if !defined(FILA_H)
#define FILA_H
#include <iostream>

using namespace std;

template <class Q>

class Fila
{
private:
  int size;
  int top;
  Q *elements;

public:
  Fila(int s)
  {
    this->size = s;
    this->top = -1;
    this->elements = new Q[size];
  }

  void push(Q element)
  {
    if (top == (size - 1))
    {
      cout << "Fila cheia" << endl;
    }
    else
    {
      this->elements[++top] = element;
    }
  }

  void pop()
  {
    if (top == -1)
    {
      cout << "Fila vazia" << endl;
    }
    else
    {
      this->top--;
    }
  }

  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  Q back()
  {
    return this->elements[top];
  }
};

#endif
