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
class MapCircle{
   public:
                    MapCircle(int ,vector<chord>&); 
                    ~MapCircle();     
        void        ADD(int);
   
   private:
   int size;
   int result=0;
   vector<chord> allchord;
   vector<chord> result;
  
};


#endif