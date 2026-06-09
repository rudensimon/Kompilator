#include "Node.h"
#include "stdlib.h"


using namespace std;



class Record 
{
    public:
    string recordType;
    string name;
    string dataType;
    Record* parent;
    vector<Record*> children;

RecordRecord() {
    recordType = "";
    name = "";
    dataType = "";
    parent = nullptr;
}

RecordRecord(string recordType, string name, string dataType, Record* parent = nullptr) {
    recordType = "";
    name = "";
    dataType = "";
    parent = nullptr;
}

void add_child(Record* child) {
        child->parent = this;
        children.push_back(child);
    }

};



class symboltable
{
private:
    
    
public:
    symboltable();
    ~symboltable();

    void traverse_tree(Node*);
};

symboltable::symboltable() /*Construcor*/
{
}


void symboltable::traverse_tree(Node* ast_root) {
    printf("print root node from ast:");
    if (ast_root == nullptr) {
        cout << "AST root is null" << endl;
        return;
    }

    cout << "Root node: " << ast_root->type << ":" << ast_root->value << endl;
}
    





symboltable::~symboltable()
{
}
