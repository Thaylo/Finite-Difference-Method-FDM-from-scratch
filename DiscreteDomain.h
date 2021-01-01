#ifndef DISCRETE_DOMAIN_H
#define DISCRETE_DOMAIN_H

#include "Node.h"
#include "Domain.h"
#include <vector>
#include <string>

using namespace std;



enum NodeDistributionStrategy { MESH_UNIFORM, MESH_UNDEFINED };

/* Starting with 2D domains, 3D will be done in the future */
class DiscreteDomain {
private:
	int id;
	int nodes_in_u_direction;
	int nodes_in_v_direction;
	Domain domain = Domain(0,0,0,0);
	vector<vector <Node> *> mesh;

public:
	DiscreteDomain(
		int nodes_in_u_direction,
		int nodes_in_v_direction,
		const Domain &domain);

	void buildMesh(NodeDistributionStrategy strategy);
	void exportMesh(string filename);

	~DiscreteDomain();
};



#endif /* DISCRETE_DOMAIN_H */