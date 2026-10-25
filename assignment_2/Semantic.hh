#include "Node.h"
#include "stdlib.h"


class Semantic
{
private:
    

public:
    bool errors = false;
    Semantic() {};    
    ~Semantic() {};

    void check_duplicates(Symboltable* symtab) {
        //Traverse each scope recursivly checking if there are dupplicate records in any of them
        Scope* scope;
        scope = symtab->get_root();
        check_duplicates_in_scopes(scope);

    }

    void check_duplicates_in_scopes(Scope* scope) {
        for (int i = 0; i < scope->records.size(); i++ ) {
            for (int j = i + 1; j < scope->records.size(); j++ ) {
                if (scope->records[i]->identifier == scope->records[j]->identifier) {
                    cerr <<  "@error - semantic. already declared in scope: " << scope->records[i]->identifier << endl;
                    errors = true;
                }
            }
        }
        for (int i = 0; i < scope->children.size(); i++) {
            check_duplicates_in_scopes(scope->children[i]);
        }
    }

    void check_undeclared(Node* root, Symboltable* symtab) {
        if (root == nullptr) {
            return;
        }

        //Enter scopes when traversing
        if (root->type == "mainClass") {
            symtab->enter_existing_scope(root->children.front()->value);
            symtab->enter_existing_scope("main");
        }

        if (root->type == "class declaration") {
            symtab->enter_existing_scope(root->children.front()->value);
        }

        if (root->type == "methodDeclaration") {
            auto i = root->children.begin();
            i++; //Second child is identifer/name of scope
            symtab->enter_existing_scope((*i)->value);
        }

        if (root->type == "methodCall") {
            //cout << "method call: " <<  endl;
            resolve_expression(root, symtab);
        }

        if (root->type == "expression NewObject") {
            //cout << "new object: " <<  endl;
            resolve_expression(root, symtab);
        }

        if (root->type == "identifier") {

            Record* record = symtab->look_up(root->value);

            if (record == nullptr) {
                cerr << "@error - semantic. undeclared identifier: " << root->value << endl;
                errors=true;
            }

            else if (record->linenr > root->lineno) {
                cerr << "@error - semantic- identifier used before declaration: " << root->value << endl;
            }
        }
        
        //Traverse children nodes
        if (root->type != "methodCall" && root->type != "expression NewObject" ) {  // methodcalls are already handled in separate function
            for (auto i = root->children.begin(); i != root->children.end(); i++) {
                check_undeclared(*i, symtab);
            }
        }


        //exit scopes
        if (root->type == "mainClass") {
            symtab->exit_scope(); //exit main method
            symtab->exit_scope(); //exit main class
        }
        else if (root->type == "class declaration" || root->type == "methodDeclaration") {
            symtab->exit_scope();
        }
    }

    string resolve_expression(Node* node, Symboltable* symtab) {
        
        if (node->type == "this") {

            return symtab->get_current_class();
        }
        
        
        if (node->type == "identifier") {

            Record* record = symtab->look_up(node->value);
            if (record == nullptr) {
                cerr << "@error - semantic. undeclared identifier: " << node->value << endl;
                errors = true;
                return "";
            }
            return record->type;
        }

        if (node->type == "expression NewObject") {


            //lookup classname
            string className = node->children.front()->value;
            Record* record = symtab->look_up(className);

            if (record == nullptr || record->get_record_type() != "classRecord") {
                cerr << "@error - semantic. Undeclared class: " << className << endl;
                errors = true;
                return "";
            }
            return className;
        }
        
        if (node->type == "methodCall") {
            auto i = node->children.begin();

            Node* object = *i;
            i++;

            // Second child method name
            string methodName = (*i)->value;
            
            //Find the type of the object
            string scope = resolve_expression(object, symtab);
            
            //check arguments
            i++;
            for (; i != node->children.end(); i++) {
                check_undeclared(*i, symtab);
            }


            if (scope == "") {
                return "";
            }

            Record* methodRecord = symtab->method_look_up(scope, methodName); 
            

            if (methodRecord == nullptr) {
                cerr << "@error - semantic. undeclared method: " << methodName << " in scope " << scope << endl;
                errors = true;
                return "";
            }

            //Return the declared return type
            return methodRecord->type;
        }
        return "";
    }
};