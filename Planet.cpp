//
// Created by 4s4r on 02.12.2023.
//

#include "Planet.h"
#include <iostream>
//constructor and destructor

Planet::Planet()
{
    this->Name = "standart name";

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

    this->volume = 0.0;

    this->weight = 0.0;

    this->availability = false;
}

Planet::Planet(const std::string &name, double x, double y, double z, double weight, double volume, bool availability)
{
    this->Name = name;

    this->x = x;
    this->y = y;
    this->z = z;

    this->volume = volume;

    this->weight = weight;

    this->availability = availability;
}

Planet::~Planet()
{
    this->Name = "";

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

    this->volume = 0.0;

    this->weight = 0.0;

    this->availability = false;
}

std::string& Planet::get_name()
{
    return Name;
}

void Planet::set_name(const std::string &name)
{
    this->Name = name;
}

double Planet::get_x() const
{
    return x;
}

void Planet::set_x(const double cord_x)
{
    this->x = cord_x;
}

double Planet::get_y() const
{
    return y;
}

void Planet::set_y(const double cord_y)
{
    this->y = cord_y;
}

double Planet::get_z() const
{
    return z;
}

void Planet::set_z(const double cord_z)
{
    this->z = cord_z;
}

double Planet::get_weight() const
{
    return weight;
}

void Planet::set_weight(const double weight_) {
    this->weight = weight_;
}

double Planet::get_volume() const
{
    return volume;
}

void Planet::set_volume(const double volume_) {
    this->volume = volume_;
}

bool Planet::get_avail() const
{
    return availability;
}

void Planet::set_avail(bool availability_)
{
    availability = availability_;
}

