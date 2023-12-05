#include <iostream>
#include "Planet.h"
#include <cmath>

int main() {
    //конструкторы/деструкторы
    Planet standart; // //создание экземлпяра класса Planet без параметров
    char name1[] = "Earth";
    Planet Earth(name1, 0, 0, 0, 1, 1, true); //создание экземлпяра класса Planet с параметрами
    std::cout << standart.get_name() << std::endl; // вывод имени standart, созданного без параметров

    // демонстрация работы методов класса

    std::cout << Earth.get_name() << " - name of Earth" << std::endl;
    std::cout << Earth.get_x() << " - x cord Earth" << std::endl;
    std::cout << Earth.get_y() << " - y cord Earth" << std::endl;
    std::cout << Earth.get_z() << " - z cord Earth" << std::endl;
    std::cout << Earth.get_volume() << " - volume of Earth" << std::endl;
    std::cout << Earth.get_weight() << " - weight of Earth" << std::endl;
    std::cout << "Is the Earth habitable?" << (Earth.get_avail() ? "True" : "False") << std::endl;

    // изменение полей объекта Earth

    char venera[] = "Venera";
    Earth.set_name(venera);
    Earth.set_x(1);
    Earth.set_y(2);
    Earth.set_z(3);
    Earth.set_volume(3);
    Earth.set_weight(0.5);
    Earth.set_avail(false);

    // Выводим измененные поля
    std::cout << "Output of changed field values: " << std::endl;

    std::cout << Earth.get_name() << " - name of changed Earth" << std::endl;
    std::cout << Earth.get_x() << " - x cord of changed Earth" << std::endl;
    std::cout << Earth.get_y() << " - y cord of changed Earth" << std::endl;
    std::cout << Earth.get_z() << " - z cord of changed Earth" << std::endl;
    std::cout << Earth.get_volume() << " - changed Earth volume" << std::endl;
    std::cout << Earth.get_weight() << " - changed Earth weight" << std::endl;
    std::cout << "Is the changed Earth habitable? " << (Earth.get_avail() ? "True" : "False") << std::endl;

    //показ работы пользовательских методов
    char name_mars[] = "Mars";
    Planet mars(name_mars, 57 * pow(10, 6), 57 * pow(10, 6), 57 * pow(10, 6), 6.4191 * pow(10, 23), 1.632 * pow(10, 11),
                false);
    char name_earth[] = "Earth";
    Planet earth(name_earth, 0, 0, 0, 5.974 * pow(10, 24), 1.0832 * pow(10, 12), true);
    char name_jupiter[] = "Jupiter";
    Planet jupiter(name_jupiter, 404 * pow(10, 6), 404 * pow(10, 6), 404 * pow(10, 6), 1.8987 * pow(10, 27),
                   1.431 * pow(10, 15), false);

    std::cout << mars.distance(earth) << " km - Distance between Earth and Mars."
              << std::endl; //расстояние от Земли до Марса
    std::cout << earth.density() << " kg/km^3 - Earth density. " << std::endl; //плотность Земли
    std::cout << "Is Jupiter a gas giant?: " << (jupiter.is_gas_giant() ? "True" : "False") << std::endl;
    std::cout << "Is Earth a gas giant?: " << (earth.is_gas_giant() ? "True" : "False") << std::endl;
    std::cout << earth.radius() << " km - Earth radius" << std::endl; // метод для вычисления радиуса

    Planet test;
    test = earth;
    std::cout << test.get_name() << std::endl;


    // Демонстрация сортировки

    Planet planet1;
    Planet planet2;
    Planet planet3;
    Planet planet4;

    planet1.set_weight(100.0);
    planet1.set_volume(10.0);

    planet2.set_weight(50);
    planet2.set_volume(10);

    planet3.set_weight(150);
    planet3.set_volume(10);

    planet4.set_weight(400);
    planet4.set_volume(10);

    Planet *list_of_planet = new Planet[4];
    list_of_planet[0] = planet1;
    list_of_planet[1] = planet2;
    list_of_planet[2] = planet3;
    list_of_planet[3] = planet4;

    std::cout << "Original massive:" << std::endl;
    for (size_t i = 0; i < 4; ++i) // вывод изначальных плотностей
        std::cout << list_of_planet[i].density() << std::endl;


    Planet::sort_planets(list_of_planet, 4);

    std::cout << "Changed massive:" << std::endl;
    for (size_t i = 0; i < 4; ++i) // вывод измененных плотностей
        std::cout << list_of_planet[i].density() << std::endl;


    // Количество планет на расстоянии меньшем чем N единиц

    Planet planet5;
    Planet planet6;
    Planet planet7;
    Planet planet8;

    planet5.set_x(100);
    planet5.set_y(100);
    planet5.set_z(100);

    planet6.set_x(10);
    planet6.set_y(10);
    planet6.set_z(10);

    planet7.set_x(20);
    planet7.set_y(20);
    planet7.set_z(20);

    planet8.set_x(40);
    planet8.set_y(40);
    planet8.set_z(40);

    Planet* another_list_of_planets = new Planet[4];

    another_list_of_planets[0] = planet5;
    another_list_of_planets[1] = planet6;
    another_list_of_planets[2] = planet7;
    another_list_of_planets[3] = planet8;

    double N = 50;

    std::cout << "Count of planet, that closer that " << N << "km is " << Planet::count_of_planet_closer_then(another_list_of_planets, N, 4) << std::endl;    //демонстрации функции average_weight_of_availability()

    another_list_of_planets[0].set_avail(true);
    another_list_of_planets[1].set_avail(true);
    another_list_of_planets[2].set_avail(false);
    another_list_of_planets[3].set_avail(true);

    another_list_of_planets[0].set_weight(100);
    another_list_of_planets[1].set_weight(200);
    another_list_of_planets[2].set_weight(50);
    another_list_of_planets[3].set_weight(400);

    std::cout << "Average weight of planet, that are availability is " << Planet::average_weight_of_availability(another_list_of_planets, 4) << std::endl;

    return 0;
}