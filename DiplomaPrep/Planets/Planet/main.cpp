#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

class Planet
{
private:
    string name;
    int x, y, z;
public:
    void show();
    int getX();
    int getY();
    int getZ();
    string getName();
    void set(string planetName, int x, int y, int z);
};

int Planet::getX() {return x;}
int Planet::getY() {return y;}
int Planet::getZ() {return z;}
string Planet::getName() {return name;}

void Planet::set(string planetName, int x, int y, int z) {
    name = planetName;
    this->x = x;
    this->y = y;
    this->z = z;
}

void Planet::show() {
   cout << name << endl;
   cout << " x: " << x << " y: " << y << " z: " << z << endl;
}
class PlanetUtil : public Planet{
public:
    static string findNextPlanet(Planet planet, list<Planet> planets);
};

string PlanetUtil::findNextPlanet(Planet planet, list<Planet> planets) {
    double temp = 0;
    double distance =INT_MAX;
    string planetName;
    for(auto & i : planets) {
        temp = sqrt(pow( (planet.getX() - i.getX() ), 2) +
                           pow( (planet.getY() - i.getY() ), 2) +
                           pow( (planet.getZ() - i.getZ() ), 2) );

        if(temp < distance) {
           distance = temp;
           planetName = i.getName();
        }

    }
    return  planetName;
}

int main()
{
    string closestPlanet;
    Planet A;
    Planet planet1;
    Planet planet2;
    Planet planet3;
    list<Planet> planetStore;
    A.set("Planet Center", 5, 5, 6);
    planet1.set("Jupiter", 4, 4, 3);
    planet2.set("Mars", 2, 2, 3);
    planet3.set("Moon", 4, 5, 6);
    planetStore.push_back(planet1);
    planetStore.push_back(planet2);
    planetStore.push_back(planet3);


    closestPlanet = PlanetUtil::findNextPlanet(A, planetStore);

    cout << " The Closest Planet to " <<A.getName()<< " is " << closestPlanet << endl;

    return 0;
}
