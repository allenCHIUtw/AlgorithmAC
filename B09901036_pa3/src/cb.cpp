#include "cyclebreaker.h"
#include <fstream>
using namespace std;
int main()
{
    fstream idata;
    fstream odata;
    char type;
    int vertexs,edges;
    vector <int> idata;
    D_EDGE *all_edge; // direxted edges
    cyclebreaker cycle_cal(type,vertexs,edges,all_edge);
    if(type == 'u') {
        cycle_cal.MaxSpanTree();
        cycle_cal.;
    } // indirected
    else{


    } // directed
     
    return 0;
}
