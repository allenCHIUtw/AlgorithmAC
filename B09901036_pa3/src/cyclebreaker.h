#ifndef  CYCLEBREAKER_H
#define  CYCLEBREAKER_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
using namespace std;

struct D_EDGE{
   int weight;
   int s;   //start
   int t;   // terminate



};


class cyclebreaker
{
    public:
        cyclebreaker();
        ~cyclebreaker();
        
        void DFS();

        void D_cyceleDetect();
        void MaxSpanTree();

        
    private:
        char cycletype; 
        int vertex,edge;
        D_EDGE *edge_way;



 
};



#endif
