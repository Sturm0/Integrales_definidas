#include <iostream>
#include <cmath>
#include <algorithm> // es necesario para usar la función std::max_element
// programa para calcular integrales definidas, por ahora el borde de integración inferior y superior se espera que sea un número positivo. O 0 en el caso del inferior
double funcion(double x) {
	return std::pow(x,2);
}

int main()
{
	double borde_inferior = 0.0;
	double borde_superior = 115000.0;
	double paso = .001; // determina el espacio entre cada valor de "y" tomado
	double tamano_rectangulo = (borde_superior-borde_inferior)/1000; // determina la base del rectangulo

	int tam_rect_arreglo = tamano_rectangulo/paso; // es el tamano en posiciones del arreglo que tiene la base del rectangulo
	
	double valores_funcion[tam_rect_arreglo];
	double val_x = borde_inferior;
	int seccion = 0; //para evitar utilizar demasiada memoria la idea es que cree el arreglo de valores de la funcion para el primer rectangulo, calcule el maximo, sume al resultado y así sucesivamente
	double resultado = 0;

	while (seccion< borde_superior/paso) {
		for (int i = 0; i<tam_rect_arreglo; i++) {
			//este for se encarga de poblar la lista con valores de la función
			valores_funcion[i] = funcion(val_x);
			val_x += paso;
		}
		double* mas_grande = std::max_element(valores_funcion,&valores_funcion[tam_rect_arreglo]);
		resultado += *mas_grande * tamano_rectangulo;

		seccion += tam_rect_arreglo;
	}
	std::cout << resultado << std::endl;
}