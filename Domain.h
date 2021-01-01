#ifndef DOMAIN_H
#define DOMAIN_H


/* Starting with 2D domains, 3D will be done in the future */
class Domain {
private:
	double x_initial, x_end, y_initial, y_end;

public:
	Domain(
		double x_initial,
		double x_end,
		double y_initial,
		double y_end);

    double get_x_initial() const;
    double get_x_end() const;

    double get_y_initial() const;
    double get_y_end() const;
	Domain operator=(const Domain& domain);
	~Domain();
};

#endif /* DOMAIN_H */