#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Stack{
    private:
        // la lista de elementos
        vector<T> elements;
    public:

        // pushear un nuevo elemento
        void push(T item){
            elements.push_back(item);
        }

        // borar el ultimo elemento
        void pop(){
            elements.pop_back();
        }

        // retorna el ultimo elemento ingresado
        T & top(){
            return elements.at(elements.size() - 1);
        }

        // retorna el elemento segun el indice
        T & getAt(int index){
            return elements.at(index);
        }

        // booleano para identificar si esta vacio
        bool empty(){
            return elements.empty();
        }

        // la sobrecarga para sumar otro stack en este mismo
        void operator+=(Stack<T> s){
            T aux;
            int index = 0;
            while(aux != s.top()){
                aux = s.getAt(index);
                this->push(aux);
                index++;
            }
        }

        // podemos reasignar valores con el operador =
        void operator=(Stack<T> s){
            while (!this->empty())
                this->pop();
            
            T aux;
            int index = 0;
            while(aux != s.top()){
                aux = s.getAt(index);
                this->push(aux);
                index++;
            }
        }
    
};

// sobrecarga del operador de salida de texto
template<typename T>
ostream & operator<<(ostream & output, Stack<T> s){
    string str = "";
    int index = 0;
    T aux;
    while(aux != s.top()){
        aux = s.getAt(index);
        str += to_string(aux);
        str += " ";
        index++;
    }
    
    output<<str;
    return output;
}

// sumar dos stacks y crear uno nuevo
template<typename T>
Stack<T> operator+(Stack<T> s1, Stack<T> s2){
    T aux;
    int index = 0;
    while(aux != s2.top()){
        aux = s2.getAt(index);
        s1.push(aux);
        index++;
    }
    return s1;
}

int main(){

    Stack<int> s;
    for(int i = 0; i < 20; i += 2)
        s.push(i);

    cout<<"S: "<<s<<endl;

    cout<<"top S: "<<s.top()<<endl;

    Stack<int> r;
    r.push(6);
    r.push(5);


    Stack<int> t = s + r;
    cout<<"T: "<<t<<endl;
    cout<<"S: "<<s<<endl;

    cout<<"top T: "<<t.top()<<endl;

    r += s;
    cout<<"R: "<<r<<endl;

    Stack<int> u, v;

    u = t;
    cout<<"U: "<<u<<endl;

    u = r;
    cout<<"U: "<<u<<endl;


    return 0;
}