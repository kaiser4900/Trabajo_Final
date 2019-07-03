#ifndef BST_H
#define BST_H


#include<iostream>
using namespace std;

template<class K, class D>
class bst
{
    struct node
    {
        K key;
        D dato;
        node * p_child[2];
        node(const K & k) : key(k)
        {
            p_child[0] = p_child[1] = nullptr;
        }
        node(const K & k,const D & d) : key (k), dato(d)
        {
            p_child[0] = p_child[1] = nullptr;
        }
        ~node() = default;
    };
    private:
    node * p_root;

    public:
    bst() : p_root(nullptr){}
    bool insert(const K & k, const D & d)
    {
        node **n;
        if(find(n,k)) return false;
        *n = new node(k,d);
        return true;
    }
    bool find(const K & k)
    {
        node **n;
        return (find (n,k));
    }
    bool remove(const K & k)
    {
        node **n;
        if(!find(n,k)) return false;
        //completar
        return true;
    }
    D & operator [] (const K & key)
    {
        node ** n;
        if(!find(n,key))
            *n = new node (key);
        return (*n) -> dato;
    }

    private :
    bool find(node **& n, const K & key)
    {
        n = & p_root;
        while(*n)
        {
            if(key == (*n)->key){return true;}
            n = &(*n)-> p_child[key > (*n) -> key];
        }
        return false;
    }
};

#endif // BST_H
