//
// Created by 4s4r on 02.12.2023.
//

#ifndef LAB_5_PLANET_H
#define LAB_5_PLANET_H
#include <iostream>


class Planet {

    std::string Name;

    double x;
    double y;
    double z;

    double weight;

    double volume;

    bool availability;

public:

    //constructors and destructor

    explicit Planet();

    explicit Planet(const std::string &name, double x, double y, double z, double weight, double volume, bool availability);

    ~Planet();

    std::string& get_name();

    void set_name(const std::string &name);

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
};


#endif //LAB_5_PLANET_H
