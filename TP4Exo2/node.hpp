#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_LC;
    std::shared_ptr<CNode> m_RC;
public:
    //constructor
    CNode (const T &  val = T(), const std::shared_ptr<CNode> & ptrLC = nullptr, const std::shared_ptr<CNode> & ptrRC = nullptr);
    //destructor
    ~CNode ();

    //getter / setter
    const T & GetData () const;
    const std::shared_ptr<CNode> & GetRC () const;
    const std::shared_ptr<CNode> & GetLC () const;
    void SetData (const T & val);
    void SetRC (const std::shared_ptr<CNode> &);
    void SetLC (const std::shared_ptr<CNode> &);
};


template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode> & ptrLC, const std::shared_ptr<CNode> & ptrRC) :
    m_Data (val), m_LC (ptrLC), m_RC (ptrRC)
{
}

template <typename T>
CNode<T>::~CNode ()
{
    //delete m_RC;
    //cout << m_Data << endl;
}

template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
const std::shared_ptr<CNode<T>> &CNode<T>::GetLC() const
{
    return m_LC;
}

template <typename T>
const std::shared_ptr<CNode<T>> & CNode<T>::GetRC() const
{
    return m_RC;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetLC(const std::shared_ptr<CNode> & ANode)
{
    m_LC = ANode;
}

template <typename T>
void CNode<T>::SetRC (const std::shared_ptr<CNode> & ANode)
{
    m_RC = ANode;
}



#endif // NODE_HPP
