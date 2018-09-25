#include <iostream>
#include "CRDTree.hpp"

using namespace std;

void Affichage (const bool & b){
    if (b == true)
        std::cout << "vrai" << std::endl;
    else if (b == false)
        std::cout << "faux" << std::endl;
}

int main()
{
    cout << "Hello World!" << endl;
    CRDTree<int> myTree (8);

    myTree.Show();

    myTree.Add(4);
    myTree.Add(9);
    myTree.Add(10);
    myTree.Add(12);
    myTree.Add(1);
    myTree.Add(5);
    myTree.Show();
    Affichage(myTree.Find(2520000000));

    return 0;
}

