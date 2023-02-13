#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
struct chord{
    int begin;
    int end;
};
enum states{
    CASE1 ,CASE2,CASE3,NA
};
using namespace std;
int main()
{   
    fstream dtin; vector<int> data_string;
    int planesize=data_string[0];
    int csize=data_string.size()/2-1;
    chord *ipchrd=new chord[csize];
    for(int u=0; u<csize;  u++)
    {
         ipchrd[u].begin=0;

         ipchrd[u].end=0;
    }
    int number ;
    
    int **MIS=new int*[planesize]; 
    states **MIS_state = new states*[planesize];
for (int i = 0; i < planesize; i++) {
 MIS[planesize] = new int[planesize];
 MIS_state[planesize] = new  states[planesize];
}
for (int i = 0; i < planesize; i++){
    for (int ii = 0; ii < planesize; ii++)
    {
        MIS[i][ii]= 0 ;  MIS_state[i][ii] = NA;
    }
}

    return 0;
}