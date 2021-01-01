#include "Node.h"
#include <iostream>

using namespace std;



Node::Node(int id, double u_coordinate, double v_coordinate)
{
    this->id = id;
    this->u_coordinate = u_coordinate;
    this->v_coordinate = v_coordinate;
}    

int Node::get_id() const
{
    return this->id;
}

double Node::get_u_coordinate() const
{
    return this->u_coordinate;
}

double Node::get_v_coordinate() const
{
    return this->v_coordinate;
}

ostream& operator<<(ostream& os, const Node& node)
{
    os << node.get_id() << ' ';
    os << node.get_u_coordinate() << ' ';
    os << node.get_v_coordinate() << '\n';
    
    return os;
}

Node::~Node()
{

}