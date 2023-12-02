#include <iostream>
#include "Planet.h"

int main() {
    Planet standart; // //создание экземлпяра класса Planet без параметров
    Planet Earth("Earth", 0, 0, 0, 1, 1, true); //создание экземлпяра класса Planet с параметрами
    std::cout << standart.get_name() << std::endl; // вывод имени standart, созданного без параметров

    // демонстрация работы методов класса

    std::cout << Earth.get_name() << " - name of Earth" <<std::endl;
    std::cout << Earth.get_x() << " - x cord Earth" << std::endl;
    std::cout << Earth.get_y() << " - y cord Earth" << std::endl;
    std::cout << Earth.get_z() << " - z cord Earth" << std::endl;
    std::cout << Earth.get_volume() << " - volume of Earth" << std::endl;
    std::cout << Earth.get_weight() << " - weight of Earth" << std::endl;
    std::cout << "Is the Earth habitable?" << Earth.get_avail() << std::endl;

    // изменение полей объекта Earth

    Earth.set_name("Venera");
    Earth.set_x(1);
    Earth.set_y(2);
    Earth.set_z(3);
    Earth.set_volume(3);
    Earth.set_weight(0.5);
    Earth.set_avail(false);

    // Выводим измененные поля
    std::cout << "Output of changed field values: " << std::endl;

    std::cout << Earth.get_name() << " - name of changed Earth" <<std::endl;
    std::cout << Earth.get_x() << " - x cord of changed Earth" << std::endl;
    std::cout << Earth.get_y() << " - y cord of changed Earth" << std::endl;
    std::cout << Earth.get_z() << " - z cord of changed Earth" << std::endl;
    std::cout << Earth.get_volume() << " - changed Earth volume" << std::endl;
    std::cout << Earth.get_weight() << " - changed Earth weight" << std::endl;
    std::cout << "Is the changed Earth habitable?" << Earth.get_avail() << std::endl;
}
