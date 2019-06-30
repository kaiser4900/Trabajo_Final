#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "fstream"
using namespace std;
template<class T>

class linked_list
{
public:
    struct node
    {
        T dato;
        node * p_next;
        node * p_prev;
        node(const T & d,node *p, node *n)
        {
            p_prev = p;
            dato = d;
            p_next = n;
        }
    };
    struct iterator
    {
        node * n;
        public:
        iterator(node * n_ = nullptr)
        {
            n = n_;
        }
        ~iterator() = default;
        T & operator *()
        {
            return n->dato;
        }
        iterator & operator ++()
        {
            n = n->p_next;
            return *this;
        }
        iterator & operator --() //tarea completado -- falta probar
        {
            n = n->p_prev;
            return *this;
        }
        bool operator != (const iterator & it)
        {
            return n!= it.n;
        }
    };
private:
        node * p_head;
    public:

    linked_list(): p_head(nullptr){}
    ~linked_list()
    {
        node * del = p_head;
        while(del)
        {
            p_head = del -> p_next;
            delete del;
            del = p_head;
        }
    }
    iterator begin()
    {
        return iterator(p_head);
    }
    iterator end()
    {
        node * back;
        back = p_head;
        while (back)
        {
              back = back ->p_next;
              if(!back->p_next)
                  return iterator (back);
        }
    }
    /*int my_size(string s)
    {
        int j=0;
        while(s[j]!='\0')
        {
            j++;
        }
        return j;
    }
*/
    T operator []( int i)
    {
        int j=0;
        node * back;
        back = p_head;
        if(i != 0)
        {
            while (j<i)
            {
                  back = back ->p_next;
            }
        }
        return back->dato;
    }
    int size()
    {
        node * cont;
        cont = p_head;
        int i = 0;
        while (cont)
        {
              cont = cont ->p_next;
              i++;
              if(!cont->p_next)
                  return i;
        }
    }
    void push_front(const T & d)
    {
        p_head = new node (d,nullptr ,p_head);
        node * aux = p_head;
        if(aux -> p_next)
        {
            aux = aux -> p_next;
            aux->p_prev = p_head;
        }
    }
    void remove_front()
    {
        if(p_head!=nullptr)
        {
            node * del = p_head;
            p_head = p_head -> p_next;
            delete del;
            p_head -> p_prev = nullptr;
        }
    }
    void push_back(const T & d) //tarea completada
    {
        if(p_head)
        {
            node * back = p_head;
            bool  aux = true;
            while(aux)
            {
                if(back -> p_next == nullptr)
                {
                     back -> p_next  = new node (d,back,nullptr);
                     aux = false;
                }
                else
                    back = back -> p_next;
            }
        }
        else
        {
            push_front(d);
        }

    }
    void remove_back() //tarea completada
    {
        if(p_head!=nullptr)
        {
            node * back = p_head;
            bool  aux = true;
            while(aux)
            {
                back = back -> p_next;
                if(back -> p_next == nullptr)
                {
                    node * del = back;
                    back = back -> p_prev;
                    back -> p_next = nullptr;
                    delete del;
                    aux = false;
                }
            }
        }
    }
};

#endif // LINKED_LIST_H