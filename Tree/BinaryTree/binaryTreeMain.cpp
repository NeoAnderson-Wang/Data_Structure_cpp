#include <iostream>
#include "binaryTree.cpp"
using namespace std;

int main()
{
    binaryTree<char> tree1, tree2;

    tree1.createTree('@'); //加单引号
    tree2.createTree('@');
    // tree1.ExchangeSons();
    tree1.preOrder();
    tree1.midOrder();
    tree1.postOrder();
    tree1.levelOrder();

    // tree2.ExchangeSons();
    tree2.preOrder();
    tree2.midOrder();
    tree2.postOrder();
    tree2.levelOrder();

    cout << endl;
    cout << tree1.DegreeofTwo() << " " << tree2.DegreeofTwo() << endl;
    cout << tree1.isFull() << " " << tree1.isComplete() << endl;

    cout << (tree1 == tree2) << endl;
    cout << isMirror(tree1, tree2) << endl;
    cout << isMirrorConst(tree1, tree2) << endl;

    // cout << endl;
    // cout << tree.DegreeofTwo() << endl;
    // cout << tree.isFull() << endl;
    // cout << endl;
    // cout << tree.isComplete() << endl;

    // printTree(tree, '@');
    // tree.delLeft('L');
    // tree.delRight('C');
    // tree.delLeft('C');
    // printTree(tree, '@');

    system("pause");
    return 0;
}