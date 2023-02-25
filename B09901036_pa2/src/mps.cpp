#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
enum states{
    CASE1 ,CASE2,CASE3,NA
};
int find_line(int*ipt,int key);
using namespace std;
int main()
{   
    fstream dtin; vector<int> data_string;
    int planesize=data_string[0];
    int csize=data_string.size()/2-1;
    int *ipchrd=new int[planesize];
    for(int u=0; u<planesize;  u++) {ipchrd[u]=-1;}
    for(int ix=1; ix<data_string.size()-1; ++ix)
      {
        if(ix%2==0)
        ipchrd[data_string[ix]]=data_string[ix+1];
        else
        ipchrd[data_string[ix]]=data_string[ix-1];
      }
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
    for(int j=0; j<planesize; j++)
    {  
     int strt=0; int ed=strt+j;
    }

    return 0;
}
int find_line(int *ipt,int key){
   return ipt[key];
}