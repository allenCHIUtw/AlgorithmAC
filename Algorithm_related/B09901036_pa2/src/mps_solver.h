#ifndef _MPS_SOLVER_H
#define _MPS_SOLVER_H
#include <vector>
#include<iostream>
#include<fstream>
using namespace std;
struct chord{
    int begin;
    int end;
};
enum states{
    CASE1 ,CASE2,CASE3,NA
};
class MapCircle{
   public:
                    MapCircle(int ,vector<chord>&); 
                    ~MapCircle();     
        void        ADD(int);
        void        buildstate(states**,int);
        void        findMIS(states**,int ,int**);
        void        findchords(int , int , int *, states **, int** );

   
   private:
   int size=0;
   int result=0;
   vector<chord> allchord;
   chord* result;
   states **checkstate;
   int **MIS;

  
};


#endif