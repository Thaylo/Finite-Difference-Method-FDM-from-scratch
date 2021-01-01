#include "Domain.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



Domain::Domain(
		int nodes_in_u_direction,
		int nodes_in_v_direction,
		double x_initial,
		double x_end,
		double y_initial,
		double y_end)
{
    this->nodes_in_u_direction = nodes_in_u_direction;
    this->nodes_in_v_direction = nodes_in_v_direction;

    this->x_initial = x_initial;
    this->x_end = x_end;
    this->y_initial = y_initial;
    this->y_end = y_end;
}

void Domain::buildMesh(NodeDistributionStrategy strategy)
{
    switch(strategy)
    {
        case MESH_UNIFORM:
        {
            int id = 0; // Node IDs starting at 0

            double step_u = (this->x_end - this->x_initial)/(this->nodes_in_u_direction-1);
            double step_v = (this->y_end - this->y_initial)/(this->nodes_in_v_direction-1);

            cout << "Building domain with uniform node spacing" << endl;

            for(int i = 0; i < this->nodes_in_u_direction; i++)
            {
                this->mesh.push_back(new vector<Node>());   
            }

            for(int i = 0; i < this->nodes_in_u_direction; i++)
            {
                double x = i*step_u + this->x_initial;

                for(int j = 0; j < this->nodes_in_v_direction; j++)
                {
                    double y = j*step_v + this->y_initial;

                    this->mesh[i]->push_back(Node(id++, x, y));
                }
            }
            break;
        }
        case MESH_UNDEFINED:
        {
            cout << "Undefined node spacing strategy" << endl;
            return;
        }
    }
}


void Domain::exportMesh(string filename)
{
    ofstream meshfile;
    meshfile.open (filename);

    for(int i = 0; i < this->nodes_in_u_direction; i++)
    {
        for(int j = 0; j < this->nodes_in_v_direction; j++)
        {
            meshfile << (*(this->mesh[i]))[j];
        }
    }

    meshfile.close();
}


Domain::~Domain()
{
    cout << "Bye bye Domain!" << endl;
}