#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


class Graph{
    private:
        // vectores coorepondientes a los nodos de 
        vector<int> start, end;
        // vector del grafo 
        vector<vector<int>> elements;
    public:
        Graph(vector<int> start, vector<int> end){
            this->start = start;
            this->end = end;

            this->setHeaders();
            this->setGraph();
        }

        // funcion para setear los nodos cabezeras
        void setHeaders(){

            bool existe = false;

            for(int item : start){
                for(int i = 0; i < elements.size(); i++){
                    if(*elements[i].begin() == item){
                    // se encontro el elemento en elements
                        existe = true;
                        break;
                    }
                }

                // no encontro el elemento en elements
                if(!existe){
                    vector<int> aux ={item};
                    elements.push_back(aux);
                }

                existe = false;

            }
        }

        // funcion para armar el grafo
        void setGraph(){
            int indexHeader, indexItem = 0;
            for(int item : start){
                indexHeader = this->getNumOfHeader(item);
                elements[indexHeader].push_back(end.at(indexItem));
                indexItem++;
            }
        }

        // obtenemos en que indice del vector fue creado esta cabecera
        int getNumOfHeader(int header){
            int index = 0;
            for(;index < elements.size(); index++){
                if(*elements[index].begin() == header){
                    return index;
                } 
            }
            return index;
        }

        // se devuelve como output una representacion del grafo
        void displayGraph(){
            for(vector<int> vec : elements){
                for(int item : vec){
                    cout<<item<<"\t";
                }
                cout<<endl;
            }
        }

        // tambien podemos mostrar la lista de inicio y finales
        void displayStartAndEnd(){
            int length = start.size();
            for(int i = 0; i < length; i++)
                cout<<start[i]<<"   ";
            
            cout<<endl;
            for(int i = 0; i < length; i++)
                cout<<end[i]<<"   ";
        }

        // la cantidad de elementos que tiene la cabecera
        int numOutGoing(const int nodeID){
            int index = this->getNumOfHeader(nodeID);
            int count = elements[index].size();
            if(count == 0) return count;
            return count - 1;
        }

        // la lista de los vertices adyacentes
        vector<int> adjacent(const int nodeID){
            vector<int> list;
            int index = this->getNumOfHeader(nodeID);
            for(int item: elements[index]){
                if(item != *elements[index].begin())
                    list.push_back(item);
            }
            return list;
        }

};


// funcion para mostrar la lista de adyacentes
string showList(vector<int> list){
    string str = "";
    for(auto i = list.begin(); i != list.end(); i++){
        str += to_string(*i);
        str += " ";
    }
    return str;
}
    

int main(){

    srand(time(NULL));

    vector<int> start, end;

    for(int i = 0; i < 10 ;i++){
        start.push_back(1+rand()%10);
        end.push_back(1+rand()%10);
    }

    Graph g(start,end);

    cout<<"La lista de nodos que fue guardado: "<<endl;
    g.displayStartAndEnd();
    cout<<endl<<endl;

    cout<<"El grafo completo: "<<endl;
    g.displayGraph();
    cout<<endl;

    cout<<"Cantidad de elementos adyacentes y su lista por numero: "<<endl;
    for(int i = 0; i < 10; i++){
        cout<<endl<<i<<"("<<g.numOutGoing(i)<<") -> "<<showList(g.adjacent(i))<<endl;
    }


    return 0;
}