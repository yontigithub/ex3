//
// Created by Yonatan Rappoport on 31/05/2023.
//

#ifndef EX3_HEALTH_POINTS_H
#define EX3_HEALTH_POINTS_H

#include <iostream>

class HealthPoints {
public:
    HealthPoints(int HP);
    HealthPoints();
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;

    HealthPoints& operator+(int HP);
    HealthPoints& operator-(int HP);
    void operator+=(int HP);
    void operator-=(int HP);
    bool operator==(const HealthPoints&);
    bool operator!=(const HealthPoints&);
    bool operator<(const HealthPoints&);
    bool operator>(const HealthPoints&);
    bool operator<=(const HealthPoints&);
    bool operator>=(const HealthPoints&);

private:
    int m_maxHP;
    int m_HP;

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& object) {
        os << object.m_HP << '(' << object.m_maxHP << ')';
        return os;
    }



    class InvalidArgument : public std::exception {};
};

#endif //EX3_HEALTH_POINTS_H
