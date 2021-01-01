#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

using namespace std;



class Node {
private:
	int id;
	double u_coordinate, v_coordinate;

public:
	Node(int id, double u_coordinate, double v_coordinate);

	int get_id() const;
	double get_u_coordinate() const;
    double get_v_coordinate() const;
	
    ~Node();
};

ostream& operator<<(ostream& os, const Node& node);


#endif /* NODE_H */