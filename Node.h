#ifndef NODE_H
#define NODE_H

#include <vector>



class Node {
private:
	int id;
	double u_coordinate, v_coordinate;

public:
	Node(int id, double u_coordinate, double v_coordinate);
	double get_u_coordinate();
    double get_v_coordinate();
    ~Node();
};



#endif /* NODE_H */