#include <iostream>
#include <vector>
using namespace std;


const double pi = 3.14;

class Figure {
public:
    double surface() const { return -1;}
    double perimetre() const { return -1;}
    void afficher() const { cout << "Affichage Figure";}
    
};

class Rectangle : public Figure {
public:
    Rectangle(double longueur, double largeur)
    : longueur(longueur), largeur(largeur)
    {
    }
    
    double surface() const {
        return longueur * largeur;
    }
    
    double perimetre() const {
        return (longueur + largeur) * 2;
    }
    
    void afficher() const {
        cout << "Rectangle:" << endl;
        cout << "longueur = " << longueur << endl;
        cout << "largeur = " << largeur << endl;
    }
    
private:
    double longueur;
    double largeur;
};



class Cercle : public Figure {
public:
    Cercle(double rayon)
    : rayon(rayon)
    {
    }
    
    double surface() const {
        return pi * rayon * rayon;
    }
    
    double perimetre() const {
        return 2 * pi * rayon;
    }
    
    void afficher() const {
        cout << "Cercle:" << endl;
        cout << "rayon = " << rayon << endl;
    }
    
private:
    double rayon;
};

