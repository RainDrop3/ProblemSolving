#include <iostream>
#include <cmath>
#define PI 3.14159265358979
using namespace std;

int main(){
    double x1, y1, r1, x2, y2, r2;
    double r3, d, line, theta, big_ho, small_ho, l, s;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    r3       = abs(r1-r2);                                                       //the difference in radius between two circles
    d        = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));                          //the distance between the centers of two circles
    line     = sqrt(d*d - r3*r3);                                                //Length of tangent to both circles at the same time
    theta    = acos(r3 / d);                                                     //the angle between the radius and d of a large circle perpendicular to the tangent line

    big_ho   = max(r1, r2) * (2*PI - 2*theta);                                      //the length of the outer arc of a large circle
    small_ho = min(r1, r2) * 2*theta;                                               //the length of an arc on the opposite side of a small circle
    l        = big_ho + small_ho + (2*line);                                        //the perimeter of a gaduri
    s        = ((r1+r2)*line) + 0.5*max(r1, r2)*big_ho + 0.5*min(r1, r2)*small_ho;  //the area of a gaduri

    cout << floor(s) << " " << floor(l);
}