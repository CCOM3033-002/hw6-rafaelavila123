// Rafael Avila Hernandez, rafaelavila123, 801244941


#include <iostream>
#include <iomanip>   // Para setprecision
#include <cmath>     // Para pow y M_PI
using namespace std;

// Prototipos de funciones (overloading)
double volumen(double radio, double altura);                   // Cilindro
double volumen(double radio);                                 // Esfera
double volumen(double largo, double ancho, double alto);      // Prisma rectangular

double area(double radio, double altura);                     // Cilindro
double area(double radio);                                    // Esfera
double area(double largo, double ancho, double alto);         // Prisma rectangular

// Función principal
int main() {
    char figura;
    char operacion;
    double radio, altura, largo, ancho;

    cout << "Este programa calcula el volumen y el \u00e1rea de la superficie de tres figuras.\n";

    // Menú de figuras con validación y switch
    do {
        cout << "\nEscoja una figura:\n";
        cout << "  a. Cilindro\n";
        cout << "  b. Esfera\n";
        cout << "  c. Prisma rectangular\n";
        cout << "Selecci\u00f3n: ";
        cin >> figura;
        figura = tolower(figura);
    } while (figura != 'a' && figura != 'b' && figura != 'c');

    // Menú de operación
    do {
        cout << "\nEscoja entre las siguientes opciones:\n";
        cout << "  a. Volumen\n";
        cout << "  b. \u00c1rea de la superficie\n";
        cout << "Selecci\u00f3n: ";
        cin >> operacion;
        operacion = tolower(operacion);
    } while (operacion != 'a' && operacion != 'b');

    cout << fixed << setprecision(2);

    switch (figura) {
        case 'a': // Cilindro
            do {
                cout << "\nEntre el radio del cilindro: ";
                cin >> radio;
            } while (radio < 0);
            do {
                cout << "Entre la altura del cilindro: ";
                cin >> altura;
            } while (altura < 0);

            if (operacion == 'a')
                cout << "El volumen del cilindro es " << volumen(radio, altura) << endl;
            else
                cout << "El \u00e1rea de la superficie del cilindro es " << area(radio, altura) << endl;
            break;

        case 'b': // Esfera
            do {
                cout << "\nEntre el radio de la esfera: ";
                cin >> radio;
            } while (radio < 0);

            if (operacion == 'a')
                cout << "El volumen de la esfera es " << volumen(radio) << endl;
            else
                cout << "El \u00e1rea de la superficie de la esfera es " << area(radio) << endl;
            break;

        case 'c': // Prisma rectangular
            do {
                cout << "\nEntre el largo del prisma: ";
                cin >> largo;
            } while (largo < 0);
            do {
                cout << "Entre el ancho del prisma: ";
                cin >> ancho;
            } while (ancho < 0);
            do {
                cout << "Entre la altura del prisma: ";
                cin >> altura;
            } while (altura < 0);

            if (operacion == 'a')
                cout << "El volumen del prisma es " << volumen(largo, ancho, altura) << endl;
            else
                cout << "El \u00e1rea de la superficie del prisma es " << area(largo, ancho, altura) << endl;
            break;
    }

    return 0;
}

// Definiciones de funciones overload para volumen
double volumen(double radio, double altura) {
    return M_PI * pow(radio, 2) * altura; // Cilindro
}
double volumen(double radio) {
    return (4.0 / 3.0) * M_PI * pow(radio, 3); // Esfera
}
double volumen(double largo, double ancho, double alto) {
    return largo * ancho * alto; // Prisma rectangular
}

// Definiciones de funciones overload para área de superficie
double area(double radio, double altura) {
    return 2 * M_PI * radio * (radio + altura); // Cilindro
}
double area(double radio) {
    return 4 * M_PI * pow(radio, 2); // Esfera
}
double area(double largo, double ancho, double alto) {
    return 2 * (largo * ancho + largo * alto + ancho * alto); // Prisma rectangular
}

