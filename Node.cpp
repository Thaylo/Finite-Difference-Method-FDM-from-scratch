#include "Node.h"
#include <iostream>

using namespace std;



Node::Node(int id, double u_coordinate, double v_coordinate)
{
    this->id = id;
    this->u_coordinate = u_coordinate;
    this->v_coordinate = v_coordinate;

    cout << "Building node with coordinates: " << id;
    cout << ", " << u_coordinate;
    cout << ", " << v_coordinate;
    cout << ") " << endl;
}

double Node::get_u_coordinate()
{
    return this->u_coordinate;
}

double Node::get_v_coordinate()
{
    return this->v_coordinate;
}

Node::~Node()
{

}