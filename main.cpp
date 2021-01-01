#include <iostream>
#include "DiscreteDomain.h"



int main(int argc, char ** argv)
{
    int nodes_in_u_direction = 3;
    int nodes_in_v_direction = 3;
    double x_initial = 0;
    double x_end = 1;
    double y_initial = 0;
    double y_end = 1;
 
    Domain domain(x_initial, x_end, y_initial, y_end);

    DiscreteDomain discreteDomain(
      nodes_in_u_direction,
      nodes_in_v_direction,
      domain);
    
    discreteDomain.buildMesh(MESH_UNIFORM);
    discreteDomain.exportMesh("test.txt");

    return 0;
}