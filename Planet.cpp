//
// Created by 4s4r on 02.12.2023.
//

#include "Planet.h"
#include <iostream>
#include <cmath>
#include <cstring>

#define MAX_LENGTH 100
#define Earth_mass 5.974 * pow(10, 24)
#define max_density 1.6 * pow(10, 12)
//constructor and destructor

Planet::Planet() {
    this->Name = new char[0];

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

    this->volume = 0.0;

    this->weight = 0.0;

    this->availability = false;
}

Planet::Planet(char* name, double x, double y, double z, double weight, double volume, bool availability) {

    this->Name = new char[std::strlen(name)+1];
    std::strcpy(this->Name, name);

    this->x = x;
    this->y = y;
    this->z = z;

    this->volume = volume;

    this->weight = weight;

    this->availability = availability;
}

Planet::Planet(const Planet &other)
{
    this->Name = new char[strlen(other.Name)+1];
    std::strcpy(this->Name, other.Name);
    x = other.x;
    y = other.y;
    z = other.z;
    weight = other.weight;
    volume = other.volume;

}

Planet& Planet::operator=(const Planet &other)
{
    if (this != &other) {
        Name = new char[strlen(other.Name)+1];
        std::strcpy(this->Name, other.Name);
        x = other.x;
        y = other.y;
        z = other.z;
        weight = other.weight;
        volume = other.volume;
    }
    return *this;
}

Planet::~Planet()
{
    if (this->volume != 0) delete [] Name;
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

    this->volume = 0.0;

    this->weight = 0.0;

}

char* Planet::get_name() const
{
    return Name;
}

void Planet::set_name(const char *name) {
    delete[] Name;
    if (name != nullptr) {
        Name = new char[std::strlen(name) + 1];
        std::strcpy(this->Name, name);
    } else {
        Name = nullptr;
    }
}

double Planet::get_x() const
{
    return x;
}

void Planet::set_x(const double cord_x)
{
    this->x = cord_x;
}

double Planet::get_y() const {
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

void Planet::set_weight(const double weight)
{
    this->weight = weight;
}

double Planet::get_volume() const
{
    return volume;
}

void Planet::set_volume(const double volume_)
{
    volume = volume_;
}

bool Planet::get_avail() const
{
    return availability;
}

void Planet::set_avail(bool availability_)
{
    availability = availability_;
}

double Planet::distance(const Planet &other) const
{
    double result = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    return result;
}

double Planet::distance(double x, double y, double z) const
{
    double result = sqrt(pow(this->x - x, 2) + pow(this->y - y, 2) + pow(this->z - z, 2));
    return result;
}

double Planet::density() const
{
    return weight / volume;
}

bool Planet::is_gas_giant() const
{
    if (this->density() < max_density && weight > Earth_mass)
        return true;
    else
        return false;
}

double Planet::radius() const
{
    double result = pow(((3 * weight) / (4 * 3.14156535 * this->density())), (1.0 / 3));
    return result;
}


void Planet::sort_planets(Planet* list, size_t count)
{
    for (size_t i = 0; i < count; ++i){
        for (size_t j = 0; j < count - 1 - i; ++j){
            if ( list[j].density() < list[j + 1].density() ){
                Planet temp;
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

size_t Planet::count_of_planet_closer_then(Planet* list, size_t N, size_t count)
{
    size_t result = 0;
    for (size_t i = 0; i < count; ++i){
        if (list[i].distance(0.0, 0.0, 0.0) < N)
            result++;
    }
    return result;
}

size_t Planet::average_weight_of_availability(Planet* list, size_t count)
{
    if (count == 0 || list == NULL) {
        std::cerr << "invalid list or number of member is function average_weight_of_availability" << std::endl;
        return 0;
    }
    size_t summ = 0;
    size_t k = 0;
    size_t test = 0;
    for (size_t j = 0; j < count; ++j){
        (list[j].get_avail()) ? test++ : test;
    }
    if (test == 0)
    {std::cerr << "Availability planets are not include in list " << std::endl;
        return 0;
    }
    for (size_t i = 0; i < count; ++i){
        if (list[i].get_avail())
        {
            summ += list[i].get_weight();
            k += 1;
//            std::cout << "234234" << std::endl;
        }
    }
    return (summ / k);
}