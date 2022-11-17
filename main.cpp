#include <iostream>
#include <vector>
using namespace std;


const double pi = 3.14;

class Figure {
public:
    Figure(double hauteur) : hauteur(hauteur) {}

    void afficher() const {
        doAfficher();
        cout << "Hauteur:" << hauteur << endl;
        cout << "Volume:" << volume() << endl;
        cout << "surface = " << surface() << endl;
        cout << "perimetre = " << perimetre() << endl;
    }
    double volume() const { 
        return hauteur * surface();
    } 

    virtual double surface() const = 0;
    virtual double perimetre() const = 0;

protected:
    virtual void doAfficher() const = 0;

private:
    double hauteur;
};

class Rectangle : public Figure {
public:
    Rectangle(double hauteur, double longueur, double largeur)
    : Figure(hauteur), longueur(longueur), largeur(largeur)
    {
    }
    
    void doAfficher() const {
        cout << "Rectangle:" << endl;
        cout << "longueur = " << longueur << endl;
        cout << "largeur = " << largeur << endl;
    }

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
    
    void doAfficher() const {
        cout << "Cercle:" << endl;
        cout << "rayon = " << rayon << endl;
    }

    double surface() const {
        return pi * rayon * rayon;
    }
    
    double perimetre() const {
        return 2 * pi * rayon;
    }
    
private:
    double rayon;
};

void afficher(const Figure & f) {
    f.afficher();
}

int main() {

    Cercle c(100,10);
//     // c.afficher();
//     // c.Figure::afficher(); 
    
//     // afficher(c);
                        // Compilation      Execution
                        // Statique         Dynamique
    // Figure   f1 = c;    // Figure           Figure
    Figure & f2 = c;    // Figure           Cercle
    Figure * f3 = &c;   // Figure*          Cercle*

    // f1.afficher();
    f2.afficher();
    f3->afficher();


    

    return 0;

}

// int main () {
    
//     vector<Figure *> figures;
    
//     figures.push_back(new Rectangle(10, 7, 3));
//     figures.push_back(new Cercle(100, 10));
    
//     for (size_t i = 0; i < figures.size(); ++i) {
//         figures[i] -> afficher();
//         cout << endl;
        
//         delete figures[i];
//     }
// }


