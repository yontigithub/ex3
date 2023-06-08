//
// Created by Yonatan Rappoport on 31/05/2023.
//

#include "HealthPoints.h"

#define DEFAULT_HP 100

HealthPoints::HealthPoints(int HP) :
        m_maxHP(HP),
        m_HP(HP)
{
    if(HP <= 0) {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints::HealthPoints() :
    m_maxHP(DEFAULT_HP),
    m_HP(DEFAULT_HP)
{

}



HealthPoints& HealthPoints::operator+(int HP) {
    HealthPoints result(m_maxHP);

    int current_HP = std::max(m_maxHP + HP, 0);
    current_HP = std::min(current_HP, m_maxHP);

    result.m_HP = current_HP;

    return result;
}
HealthPoints& HealthPoints::operator-(int HP) {
    return (*this + (-HP));
}
void HealthPoints::operator+=(int HP) {
    int current_HP = std::max(m_maxHP + HP, 0);
    current_HP = std::min(current_HP, m_maxHP);

    m_HP = current_HP;
}
void HealthPoints::operator-=(int HP) {
    *this += (-HP);
}
bool HealthPoints::operator==(const HealthPoints& object) {
    return m_HP == object.m_HP;
}
bool HealthPoints::operator!=(const HealthPoints& object) {
    return m_HP != object.m_HP;
}
bool HealthPoints::operator<(const HealthPoints& object) {
    return m_HP < object.m_HP;
}
bool HealthPoints::operator>(const HealthPoints& object) {
    return m_HP > object.m_HP;
}
bool HealthPoints::operator<=(const HealthPoints& object) {
    return m_HP <= object.m_HP;
}
bool HealthPoints::operator>=(const HealthPoints& object) {
    return m_HP >= object.m_HP;
}
