#include <iostream>
#include "geomP.hpp"
using namespace std;

int main () {
    Point A(2.25, 1), B(3, 4);
    Line l(A, B);
    cout<< "line between A"<< A<< " and B"<< B<< " is l1:"<< l<< endl;

    Point C(2, -3);
    cout<< "g:"<< l.parallel(C)<< " is parallel to l and passing through C"<< C<< endl;

    Line g1(1.5, 3, 25), g2(3, 6, -23);
    cout<< "g1:"<< g1<< " and g2:"<< g2<< " are "<< (g1.parallel(g2) ? "" : "not ") <<"parallel"<< endl;
    Line g3(1.5, 3, 25), g4(3, 5, -23);
    cout<< "g3:"<< g3<< " and g4:"<< g4<< " are "<< (g3.parallel(g4) ? "" : "not ") <<"parallel"<< endl;

    Point D(1, 5);
    cout<< "m:"<< l.perpendicular(D)<< " is perpendicular to l and passing through D"<< D<< endl;

    Line m1(2, 3, 25), m2(-6, 4, 15);
    cout<< "m1:"<< m1<< " and m2:"<< m2<< " are "<< (m1.perpendicular(m2) ? "" : "not ") <<"penperticular"<< endl;
    Line m3(12, 32, 25), m4(32, 18, -2);
    cout<< "m3:"<< m3<< " and m4:"<< m4<< " are "<< (m3.parallel(m4) ? "" : "not ") <<"penperticular"<< endl;

    return 0;
}
