#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int c[3][2][2];

    int num = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            //for(int k = 0; j < 2; k++){
                //c[i][j][k] = num;
                cout<<i<<"  "<<j<<" "<<" "<<num<<endl;
                num += 2;
            }

        }
    
    
    //cout<<c[1][0][1]<<endl;

    return 0;
}
