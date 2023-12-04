/***********************************************************************************
 Actividad 3. Aplicación para Cálculo de RFC

Contextualización:
Se necesita crear un programa que permita calcular el RFC de los nuevos empleados de
la constructora AMC. Este debe generarse a partir de la captura de nombre, apellido
paterno, apellido materno y fecha de nacimiento.

Actividad:
Con base en las siguientes reglas (en esta aplicación se deberán de usar los conceptos de
Objetos y Clases, vistos en la materia), realizar una aplicación que permita capturar el
RFC de los usuarios. Esta debe realizarse con sus respectivos requerimientos en lenguaje
C++:

¿Cómo se crea el RFC?:

● Primeros 2 caracteres (VE): Se crea con la primera letra del apellido paterno y la
primera vocal interna del apellido paterno (en este ejemplo: VEGA).
● 3ra posición: Es la inicial del apellido materno. De no existir un apellido materno, se
utiliza una (X). (en este ejemplo: CASTRO).
● 4a posición: Es la inicial del primer nombre. Para evitar la formación de una palabra
inconveniente, esta letra se reemplaza con una (X) (en este ejemplo: JESUS).
● 5a y 6a posición: Son los dos últimos dígitos del año de nacimiento. (en este
ejemplo: 26/03/1988).
● 7a y 8a posición: es el mes de nacimiento. (en este ejemplo: 26/03/1988).
● 9a y 10a posición: es el día de nacimiento. (en este ejemplo: 26/03/1988). Por lo
tanto, en este caso puede deducirse que la persona nació el 26 de marzo de 1988.
● XXX es la homoclave, la cual es designada por el SAT a través de papel oficial.
Depende de algunos factores que realiza el SAT por medio de un software
alfanumérico. En esta actividad, el RFC que genere el programa será sin
homoclave
*************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string generarRFC(const string& apellidoPaterno, const string& apellidoMaterno, const string& primerNombre, int year, int mes, int dia) {
    // Primeros 2 caracteres
    string primeros2 = apellidoPaterno.substr(0, 1);
    size_t vocalPos = apellidoPaterno.find_first_of("AEIOU");
    if (vocalPos != string::npos) {
        primeros2 += apellidoPaterno[vocalPos];
    } else {
        // Si no hay vocal interna, agregar una X
        primeros2 += "X";
    }

    // 3ra posición
    string tercera = (apellidoMaterno.empty()) ? "X" : apellidoMaterno.substr(0, 1);

    // 4a posición
    string cuarta = (primerNombre.empty()) ? "X" : primerNombre.substr(0, 1);

    // 5a y 6a posición (dos últimos dígitos del año)
    string quintaYsexta = to_string(year).substr(2, 2);

    // 7a y 8a posición (mes)
    string septimaYoctava = (mes < 10) ? "0" + to_string(mes) : to_string(mes);

    // 9a y 10a posición (día)
    string novenaYdecima = (dia < 10) ? "0" + to_string(dia) : to_string(dia);

    // Homoclave (11a, 12a y 13 posición)
    string homoclave = "XXX";

    // Concatenar y devolver el RFC
    return primeros2 + tercera + cuarta + quintaYsexta + septimaYoctava + novenaYdecima + homoclave;
}

int main() {
    // Datos
    string apellidoPaterno, apellidoMaterno, primerNombre;
    int year, mes, dia;

    // Ingresar datos del usuario
    cout << "Ingrese el apellido paterno: ";
    cin >> apellidoPaterno;
    
    cout << "Ingrese el apellido materno (si no tiene, presione enter): ";
    cin.ignore();  // Limpiar buffer antes de getline
    getline(cin, apellidoMaterno);

    cout << "Ingrese el primer nombre: ";
    cin >> primerNombre;

    cout << "Ingrese el año de nacimiento (4 dígitos): ";
    cin >> year;

    cout << "Ingrese el mes de nacimiento (2 dígitos): ";
    cin >> mes;

    cout << "Ingrese el día de nacimiento (2 dígitos): ";
    cin >> dia;

    // Generar RFC
    string rfc = generarRFC(apellidoPaterno, apellidoMaterno, primerNombre, year, mes, dia);

    // Mostrar RFC
    cout <<"\nRFC GENERADO: " << rfc << endl;

    return 0;
}
