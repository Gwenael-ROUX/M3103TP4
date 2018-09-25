#include <iostream>
#include "CRDTree.hpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    CRDTree<string> myTree ("bidule");

    myTree.Show();

    myTree.Add("hjkfhdks");
    myTree.Add("a");
    myTree.Add("b");
    myTree.Add("c");
    myTree.Add("d");
    myTree.Add("e");
    myTree.Show();

    return 0;
}
