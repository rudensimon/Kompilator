#include "Node.h"
#include "stdlib.h"


using namespace std;

struct Record {
    string identifier;
    string type;

    virtual string get_record_type() {
        return("Record");
    }
};

struct ClassRecord : Record {
    virtual string get_record_type() override {
        return("classRecord");
    }
};

struct VariableRecord : Record {
    virtual string get_record_type() override {
        return("VariableRecord");
    }
};

struct MethodRecord : Record {
    virtual string get_record_type() override {
        return("MethodRecord");
    }
};

struct Scope {
    Scope* parent = nullptr;
    string name;

    vector<Scope*> children;
    vector<Record*> records;
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
        //cout << "visiting:" << root->type << ":" << root->value << endl;

        if (root->type == "mainClass") {
            //do stuff
            auto i = root->children.begin();

            ClassRecord* classRecord = new ClassRecord();
            classRecord->identifier = (*i)->value; //set main class name
            classRecord->type = "class";

            put(classRecord);
            enter_scope((*i)->value);
            
            i++; // Move to next child (param identfier)

            MethodRecord* methodRecord = new MethodRecord();
            methodRecord->identifier="main";
            methodRecord->type="void";

            put(methodRecord);
            enter_scope("main");

            VariableRecord* paramRecord = new VariableRecord();
            paramRecord->identifier = (*i)->value;
            paramRecord->type = "String[]";

            put(paramRecord);
        }

        if (root->type == "class declaration") {
           ClassRecord* record = new ClassRecord();
           record->identifier  = root->children.front()->value;
           record->type = "class";

           put(record);

           enter_scope(record->identifier);
        }

        if (root->type == "methodDeclaration") {
            //do stuff
            MethodRecord* record = new MethodRecord();

            auto i = root->children.begin();
            
            record->type = (*i)->type;
            i++;
            record->identifier = (*i)->value;
            

            put(record);
            enter_scope(record->identifier);
        }

        if (root->type == "paramsOpt" && root->children.size() >= 2 ) {
            //add first, second child as variable record if there are params
            
            VariableRecord* record = new VariableRecord();
            auto i = root->children.begin();
            record->type = (*i)->type;
            i++;
            record->identifier = (*i)->value;
            put(record);
        }

        if (root->type == "moreParams" && root->children.size() >= 2) {
            //add rest of params
            auto i = root->children.begin();

            while (i != root->children.end()) {
                VariableRecord* record = new VariableRecord();
                
                record->type = (*i)->type;
                i++;

                record->identifier = (*i)->value;
                i++;

                put(record);
            }

        }

        if (root->type == "varDeclaration") {
            //do stuff
            VariableRecord* record = new VariableRecord();
            record->type = root->children.front()->type;
            record->identifier = root->children.back()->value;
            put(record);
        }           
        
        // Traverse all children recursively
        for (auto i = root->children.begin(); i != root->children.end(); i++) {
        traverse_tree(*i);
        }

        //exit scopes
        if (root->type == "mainClass") {
            exit_scope(); //exit main method
            exit_scope(); //exit main class
        }
        else if (root->type == "class declaration" || root->type == "methodDeclaration") {
            exit_scope();
        }

    };
    
    void enter_scope(string name){

        //Create new scope, set name, set parent, enter scope(set current)
        Scope* child = new Scope();
        child->name = name;
        child->parent = current;

        current->children.push_back(child);

        current = child;
    };
    
    void exit_scope() {
        if (current->parent != nullptr) {
            current = current->parent;
        }
    };

    void print_current_scope() {
         cout << "Current scope: " << current->name << endl;
    }

    void print_current_scope_records() {
        cout << "Scope: " << current->name << endl;

        for (int i = 0; i < current->records.size(); i++) {
            cout << "Identifier: " << current->records[i]->identifier
            << " Type: " << current->records[i]->type
             
            << endl;
        }
    };

    void print_sym_table(){
        print_from_scope(root);
    }

    void print_from_scope(Scope* scope) {
        
        cout << endl << "Scope: " << scope->name << endl;
        cout << "   Records: " << endl;

        //print each record
        for (int i = 0; i < scope->records.size(); i++) {
            cout << "      "<< scope->records[i]->get_record_type()
            << " | Identifier: " << scope->records[i]->identifier
            << " | Type: " << scope->records[i]->type
            << endl;
        }

        //print for each children scope
        for (int j = 0; j < scope->children.size(); j++) {
            print_from_scope(scope->children[j]);
        }

    }


    void put(Record* record) {
        current->records.push_back(record);
        //cout << "\n adding record: " << record->identifier << " : " << record->type << " into scope: " <<  current->name << endl;
    }

    void reset() {
        current = root;
    }
};


