//
// Created by 4s4r on 02.12.2023.
//

#ifndef LAB_5_PLANET_H
#define LAB_5_PLANET_H

#include <iostream>
#include <cmath>


class Planet {
private:
    char *Name;

    double x;
    double y;
    double z;

    double weight;

    double volume;

    bool availability;

public:

    //constructors and destructor

    Planet();

    Planet(char *name, double x, double y, double z, double weight, double volume, bool availability);

    Planet(const Planet &other);

    Planet &operator=(const Planet &other);

    ~Planet();

    //методы для показа/изменения полей класса

    char* get_name() const;

    void set_name(const char *name);

    double get_x() const;

    void set_x(double cord_x);

    double get_y() const;

    void set_y(double cord_y);

    double get_z() const;

    void set_z(double cord_z);

    double get_weight() const;

    void set_weight(double weight_);

    double get_volume() const;

    void set_volume(double volume_);

    bool get_avail() const;

    void set_avail(bool availability_);

    //методы для показа других возможностей класса

    double distance(const Planet &other) const;

    double distance(double x, double y, double z) const;

    double density() const;

    bool is_gas_giant() const;

    double radius() const;

    static void sort_planets(Planet* list, size_t count);

    static size_t count_of_planet_closer_than(Planet* list, size_t N, size_t count);
};


#endif //LAB_5_PLANET_H
