#if !defined(VECTOR_H)
#define VECTOR_H

template <class Q>
class vector_supermercado
{
private:
  int size;
  int capacity;
  Q *arr;

public:
  vector_supermercado()
  {
    this->capacity = 1;
    this->size = 0;
    this->arr = new Q[capacity];
  }

  void push(Q element)
  {
    if (capacity == size)
    {
      capacity *= 2;
      Q *temp = new Q[capacity];

      for (int i = 0; i < capacity; i++)
      {
        temp[i] = arr[i];
      }

      delete[] arr;
      arr = temp;
    }
    arr[size] = element;
    size++;
  }

  void push(Q element, int index)
  {

    if (index == capacity)
    {
      push(element);
    }
    else
    {
      arr[index] = element;
    }
  }

  Q get(int index)
  {
    if (index < size && index != -1)
    {
      return arr[index];
    }
  }

  void pop()
  {
    size--;
  }

  int vectorSize()
  {
    return size;
  }
};

#endif
