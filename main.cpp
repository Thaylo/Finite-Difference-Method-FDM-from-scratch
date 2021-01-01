#include <iostream>
#include "Domain.h"



int main(int argc, char ** argv)
{
    int nodes_in_u_direction = 3;
    int nodes_in_v_direction = 6;
    double x_initial = 0;
    double x_end = 1;
    double y_initial = 0;
    double y_end = 1;
 
    Domain d(
		nodes_in_u_direction,
		nodes_in_v_direction,
		x_initial,
		x_end,
		y_initial,
		y_end);
    
    d.buildMesh(MESH_UNIFORM);
    d.exportMesh("test.txt");

    return 0;
}