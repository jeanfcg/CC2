#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

class Graph{
    private:
        vector<int> start, end;
    public:
        void push(int orig, int dest){
            start.push_back(orig);
            end.push_back(dest);
        }

        void display(){
            int length = start.size();
            for(int i = 0; i < length; i++)
                cout<<start[i]<<"   ";
            
            cout<<endl;
            for(int i = 0; i < length; i++)
                cout<<end[i]<<"   ";
        }

        int numOutGoing(const int nodeID){
            int count = 0; 
            for(int i = 0; i < start.size(); i++)
                if(start[i] == nodeID)
                    count++;
            return count;
        }

        vector<int> adjacent(const int nodeID){
            vector<int> list;
            for(int i = 0; i < start.size(); i++)
                if(start[i] == nodeID)
                    list.push_back(end[i]);
            return list;
        }

};


string showList(vector<int> list){
    string str = "";
    for(auto i = list.begin(); i != list.end(); i++){
        str += to_string(*i);
        str += " ";
    }
    return str;
}
    

int main(){

    Graph g;
    srand(time(NULL));
    int r, a;

    for(int i = 0; i < 10 ;i++){
        r = 1+rand()%10;
        a = 1+rand()%10;
        g.push(r,a);
    }

    g.display();
    for(int i = 0; i < 10; i++){
    cout<<endl<<i<<": "<<g.numOutGoing(i)<<" -> "<<showList(g.adjacent(i))<<endl;

    }


    return 0;
}