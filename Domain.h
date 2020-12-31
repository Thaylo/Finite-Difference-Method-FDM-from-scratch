#ifndef DOMAIN_H
#define DOMAIN_H

class Domain {
private:
	int id;
	int nodes_in_u_direction;
	int nodes_in_v_direction;

public:
	Domain(int nodes_in_u_direction, int nodes_in_v_direction);
	~Domain();
};



#endif /* DOMAIN_H */