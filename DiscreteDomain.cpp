#include "DiscreteDomain.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



DiscreteDomain::DiscreteDomain(
		int nodes_in_u_direction,
		int nodes_in_v_direction,
		const Domain &domain)
{
    this->nodes_in_u_direction = nodes_in_u_direction;
    this->nodes_in_v_direction = nodes_in_v_direction;
    this->domain = domain;
}

void DiscreteDomain::buildMesh(NodeDistributionStrategy strategy)
{
    switch(strategy)
    {
        case MESH_UNIFORM:
        {
            int id = 0; // Node IDs starting at 0

            double x_initial = this->domain.get_x_initial();
            double x_end = this->domain.get_x_end();
            double y_initial = this->domain.get_y_initial();
            double y_end = this->domain.get_y_end();
            
            double step_u = (x_end - x_initial)/(this->nodes_in_u_direction-1);
            double step_v = (y_end - y_initial)/(this->nodes_in_v_direction-1);

            for(int i = 0; i < this->nodes_in_u_direction; i++)
            {
                this->mesh.push_back(new vector<Node>());   
            }

            for(int i = 0; i < this->nodes_in_u_direction; i++)
            {
                double x = i*step_u + x_initial;

                for(int j = 0; j < this->nodes_in_v_direction; j++)
                {
                    double y = j*step_v + y_initial;

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


void DiscreteDomain::exportMesh(string filename)
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


DiscreteDomain::~DiscreteDomain()
{
    for(int i = 0; i < this->nodes_in_u_direction; i++)
    {
        for(int j = 0; j < this->nodes_in_v_direction; j++)
        {
            this->mesh[i]->pop_back();
        }
        delete this->mesh[i];
    }

}