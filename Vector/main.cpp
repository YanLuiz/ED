#include <iostream>
#include <vector>

using namespace std;

struct Vetor{

    int * _data; // bloco dados
    int _capacidade; // tamanho maximo do vetor
    int _size; // quantidade atual dos elementos inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];
        }

    void push_back(int value){
        if(this->_size == this->_capacidade)
             return;
                  //this->reserve(2 * capacidade);
             this->_data[this->_size] = value;
             this->_size += 1;
    }

    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -=1;
    }

    //retorna a referencia a variaval dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }

    int& front(){
        return this->_data[0];
    }

    int& back(){
        return this->_data[this->_size - 1];
    }

    int * begin(){
        return &this->_data[0];
    }

    int * end(){
        return &this->_data[this->_size];
    }

    int size(){
            return this->_size;
        }

    int capacity(){
            return this->_capacidade;
        }

    void reserve(int nova_capacidade){
        if(this->_capacidade > nova_capacidade)
            return;
        _capacidade = _capacidade + nova_capacidade;
        this->_data = new int[_capacidade];
    }
};


int main(){



    Vetor vet(3);

    vet.push_back(15);
    vet.push_back(14);
    vet.push_back(23);
    cout <<  vet.at(15) << endl;


    cout << "Capacidade Atual : " << vet.capacity() << endl;
    vet.reserve(10);


    cout << " Capacidade atualizada : " << vet.capacity() << endl;



    return 0;

}


