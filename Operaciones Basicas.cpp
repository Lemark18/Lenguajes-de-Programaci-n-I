/***********************************************
 Contextualización:
Generar un programa que realice lo siguiente:
1. Que pida el ingreso de dos valores (ya sean enteros o decimales).
2. Que los sume, reste, multiplique y divida.
3. Que los muestre en pantalla con su respectivo enunciado.
Para ello, se debe tener en cuenta la siguiente estructura de impresión de datos:
Escribe el primer número:
Escribe el segundo número:
La suma es:
La resta es:
La multiplicación es:
La división es:
***********************************************/

#include <iostream> 

using namespace std;
// se genera la declaración de la variable
int main(){
   double n1,n2;
// se solicitan el primer valor para la operación y la leyenda 
   std::cout << "Escribe el primer número (ya sea entero o decimal): "; 
   std::cin >>n1;
// se solicita el segundo valor para la operación y la leyenda 
   std::cout << "Escribe el segundo número: (ya sea entero o decimal): "; 
   std::cin >>n2;
// se registran las operaciónes a realizar con las variables   
   double suma = n1 + n2;
   double resta = n1 - n2;
   double multiplicacion = n1 * n2;
   double division = n1 / n2;
// se muestra el resultado de la operación y la leyenda 
   std::cout <<"\nEl resultado de la suma es: "<<suma<<std::endl;
   std::cout <<"El resultado de la resta es: "<<resta<<std::endl;
   std::cout <<"El resultado de la multiplicación es: "<<multiplicacion<<std::endl;
   std::cout <<"El resultado de la división es: "<<division<<std::endl;
    
    return 0;
}

