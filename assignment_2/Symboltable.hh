#include "Node.h"
#include "stdlib.h"


using namespace std;

class record {

};


class symboltable
{
private:
    /* data */
public:
    symboltable(/* args */);
    ~symboltable();
    void traverse_tree(Node*);
};

symboltable::symboltable(/* args */) /*Construcor*/
{
    printf("Hello!");
}


void symboltable::traverse_tree(Node* ast_root) {
    printf("print from symboltable!");
    ast_root->print_tree();
};


symboltable::~symboltable()
{
}
