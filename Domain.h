#ifndef DOMAIN_H
#define DOMAIN_H

#include "Node.h"
#include <vector>
#include <string>

using namespace std;



enum NodeDistributionStrategy { MESH_UNIFORM, MESH_UNDEFINED };

class Domain {
private:
	int id;
	int nodes_in_u_direction;
	int nodes_in_v_direction;
	double x_initial, x_end, y_initial, y_end;
	vector<vector <Node> *> mesh;

public:
	Domain(
		int nodes_in_u_direction,
		int nodes_in_v_direction,
		double x_initial,
		double x_end,
		double y_initial,
		double y_end);

	void buildMesh(NodeDistributionStrategy strategy);
	void exportMesh(string filename);

	~Domain();
};



#endif /* DOMAIN_H */