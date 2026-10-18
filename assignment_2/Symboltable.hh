#include "Node.h"
#include "stdlib.h"


using namespace std;

struct Record {
    string identifier;
    string type;
};

struct Scope {
    Scope* parent = nullptr;
    string name;

    vector<Scope*> children;
    vector<Record> records;
};



class Symboltable
{
private:
    Scope* root = new Scope();
    Scope* current;

public:
    Symboltable() {
        root->name = "Global";
        current = root;

    };
    
    ~Symboltable() {
        printf("print from desctructor");
    };

    void traverse_tree(Node* root) {
        cout << root->type << ":" << root->value << endl;

        // Traverse all children recursively
        for (auto i = root->children.begin(); i != root->children.end(); i++) {
        traverse_tree(*i);
        }
    };
    
    void enter_scope(string name){

        //Create new scope, set name, set parent, enter scope(set current)
        printf("print from enter scope");
        Scope* child = new Scope();
        child->name = name;
        child->parent = current;

        current->children.push_back(child);

        current = child;
    };
    
    void exit_scope() {
        printf("print from exit scope");
        if (current->parent != nullptr) {
            current = current->parent;
        }
    };

    void print_current_scope() {
         cout << "Current scope: " << current->name << endl;
    }
};


