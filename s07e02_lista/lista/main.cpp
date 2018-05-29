#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){        
        this->value = value;
        this->next = next;
    }


};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }
    
    ~SList(){
        
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }
    

    Node *apagar(Node* node){

        if(node== nullptr){

            return nullptr;
        }
        apagar(node->next);
        delete node;
        return nullptr;

    }

    Node * _inserir_ordenado(Node * node, int value){

        if(node==nullptr)
            return new Node(value, node->next);

        if(node->value > value)
            return head = new Node(value, node);

        if(node->next==nullptr || node->next->value > value )
            return node->next = new Node(value,node->next);



        _inserir_ordenado(node->next,value);


        return node;
}



    int rsomar(Node * node){
        if(node->next==nullptr)
            return node->value;

        return node->value + rsomar(node->next);

    }

    int somar(){
        return rsomar(head);
    }


    void inserir_ordenado(int value){
        _inserir_ordenado(head,value);
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }
    Node *rpush_back(Node * node, int value){
        if(head == nullptr){
            head =

        }



    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    void show(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }

    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);    
    }


    Node * _rpush_back(Node * node,int value){

        if(head==nullptr)
            return head = new Node(value);


        if(node->next == nullptr)
            return node->next = new Node(value);

        _rpush_back(node->next,value);

        return node;

    }
    
    
    int size(){
        auto node = head;
        int cont = 0;
        while(node->next!= nullptr){
            cont++;
            
            node = node->next;
            
            
            
        }
            
        return cont;
        
                
        
        
    }


   void rrpush_back(int value){
      _rpush_back(head,value);
   }


    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void remove(int value){
        head = _remove(head, value);
    }
};


int main()
{
    SList lista;


    lista.push_back(6);

    lista.inserir_ordenado(555);


    lista.inserir_ordenado(4);
    lista.inserir_ordenado(27);
    lista.rrpush_back(39);
    lista.push_front(77);




    lista.show();

    return 0;
}
                                                                             
