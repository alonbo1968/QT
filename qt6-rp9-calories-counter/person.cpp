#include "person.h"
//#include "widget.h"


double Person::get_weight() {
    return m_weight;
}

void Person::set_weight (double weight) {
    if(m_weight != weight) {
        m_weight = weight;
        //emit weightChanged();
    }
}

