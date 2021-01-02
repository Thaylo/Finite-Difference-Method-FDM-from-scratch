#include "Domain.h"
#include <iostream>

using namespace std;

Domain::Domain()
{
    this->x_initial = 0;
    this->x_end = 0;
    this->y_initial = 0;
    this->y_end = 0;
}

Domain::Domain(
		double x_initial,
		double x_end,
		double y_initial,
		double y_end)
{
    this->x_initial = x_initial;
    this->x_end = x_end;
    this->y_initial = y_initial;
    this->y_end = y_end;
}

double Domain::get_x_initial() const
{
    return this->x_initial;
}

double Domain::get_x_end() const
{
    return this->x_end;
}

double Domain::get_y_initial() const
{
    return this->y_initial;
}

double Domain::get_y_end() const
{
    return this->y_end;
}

Domain::~Domain()
{
}

Domain Domain::operator=(const Domain& domain)
{
    this->x_initial = domain.x_initial;
    this->x_end = domain.x_end;
    this->y_initial = domain.y_initial;
    this->y_end = domain.y_end;

    return *this;
}