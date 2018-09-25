#ifndef CRDTREE_HPP
#define CRDTREE_HPP
#include <iostream>
#include <memory>

#include "node.hpp"

template <typename T>
class CRDTree
{
private:
    std::shared_ptr<CNode<T>> m_Racine;
public:
    CRDTree (const T & Val);
    ~CRDTree () {}
    void Show () const;
    void Add (const T & Val);
    bool Find (const T & Val);
};

template<typename T>
CRDTree<T>::CRDTree(const T & Val)
{
    std::shared_ptr<CNode<T>> ptr (new CNode<T>(Val));
    m_Racine = ptr;
}

template<typename T>
void localShow(const std::shared_ptr<CNode<T>> & ptr)
{
    if (ptr == nullptr)return;
    localShow(ptr->GetLC());
    std::cout << ptr->GetData () << std::endl;
    localShow(ptr->GetRC());
}

template<typename T>
void CRDTree<T>::Show() const
{
    localShow(m_Racine -> GetLC());
    std::cout << m_Racine -> GetData() << std::endl;
    localShow(m_Racine -> GetRC());
}


template<typename T>
void localAdd(const std::shared_ptr<CNode<T>> & ptr, const T & Val)
{
    if (ptr ->GetData() > Val)
    {
        if(ptr ->GetLC() == nullptr)
        {
            std::shared_ptr<CNode<T>> tmp (new CNode<T>(Val));
            ptr ->SetLC(tmp);
            return;
        }
        else if(ptr ->GetLC()->GetData() > Val)
        {
            std::cout << "Gauche" << std::endl;
            localAdd (ptr->GetLC(), Val);
        }
        else if(ptr ->GetRC() == nullptr)
        {
            std::shared_ptr<CNode<T>> tmp (new CNode<T>(Val));
            ptr ->SetRC(tmp);
            return;
        }
        else if (ptr ->GetRC()->GetData() > Val)
        {
            std::cout << "Droite" << std::endl;
            localAdd (ptr->GetRC(), Val);
        }
    }
    else
    {
        std::cout << "insertion refusée" << std::endl;
        return;
    }
}

template<typename T>
void CRDTree<T>::Add(const T & Val)
{
    localAdd (m_Racine, Val);
}

template<typename T>
bool localFind(const std::shared_ptr<CNode<T>> & ptr, const T & Val)
{
    if(ptr ->GetData() > Val)
    {
        if (ptr -> GetLC() == nullptr)
        {
            return false;
        }
        else if (ptr -> GetLC() ->GetData() == Val)
        {
            return true;
        }
        else localFind(ptr ->GetLC(), Val);
    }

    else
    {
        if (ptr -> GetRC() == nullptr)
        {
            return false;
        }
        else if (ptr -> GetRC() ->GetData() == Val)
        {
            return true;
        }
        else localFind(ptr ->GetRC(), Val);
    }
}

template<typename T>
bool CRDTree<T>::Find(const T & Val)
{
    if(m_Racine ->GetData() == Val)
        return true;
    else
        return localFind (m_Racine, Val);
}



#endif // CRDTREE_HPP

