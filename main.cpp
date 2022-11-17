#include <iostream>
#include <vector>
using namespace std;


const double pi = 3.14;

class Figure {
public:
    Figure(double hauteur) : hauteur(hauteur) {}

    void afficher() const { 
        cout << "Figure:";
        cout << "Hauteur:" << hauteur << endl;
        cout << "Volume:" << volume() << endl;
    }
    double volume() const { 
        return hauteur * surface();
    } 

protected:
    double surface() const { return -1;}
    double perimetre() const { return -1;}

private:
    double hauteur;
};

class Rectangle : public Figure {
public:
    Rectangle(double hauteur, double longueur, double largeur)
    : Figure(hauteur), longueur(longueur), largeur(largeur)
    {
    }
    
    void afficher() const {
        cout << "Rectangle:" << endl;
        cout << "longueur = " << longueur << endl;
        cout << "largeur = " << largeur << endl;
    }

protected:
    double surface() const {
        return longueur * largeur;
    }
    
    double perimetre() const {
        return (longueur + largeur) * 2;
    }
    
private:
    double longueur;
    double largeur;
};



class Cercle : public Figure {
public:
    Cercle(double hauteur, double rayon)
    : Figure(hauteur), rayon(rayon)
    {
    }
    
    void afficher() const {
        cout << "Cercle:" << endl;
        cout << "rayon = " << rayon << endl;
    }
protected:
    double surface() const {
        return pi * rayon * rayon;
    }
    
    double perimetre() const {
        return 2 * pi * rayon;
    }
    
private:
    double rayon;
};

int main() {

    Cercle c(100,10);
    c.afficher(); 

    return 0;

}