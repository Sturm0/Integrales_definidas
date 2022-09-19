#include <iostream>
#include <cmath>
#include <algorithm> // es necesario para usar la función std::max_element
// programa para calcular integrales definidas, por ahora el borde de integración inferior y superior se espera que sea un número positivo. O 0 en el caso del inferior
double funcion(double x) {
	return std::pow(x,2);
}

int main()
{
	double borde_inferior = 5.0;
	double borde_superior = 50.0;
	double paso = .001; // determina el espacio entre cada valor de "y" tomado
	double tamaño_rectangulo = (borde_superior-borde_inferior)/1000; // determina la base del rectangulo

	int tam_rect_arreglo = tamaño_rectangulo/paso; // es el tamaño en posiciones del arreglo que tiene la base del rectangulo
	int largo = (borde_superior-borde_inferior)/paso;
	double valores_funcion[largo];
	double val_x = borde_inferior;

	for (int i = 0; i<largo; i++) {
		//este for se encarga de poblar la lista con valores de la función
		valores_funcion[i] = funcion(val_x);
		val_x += paso;
	}
	

	double resultado = 0;
	for (int i = tam_rect_arreglo; i<=largo; i += tam_rect_arreglo) {
		
		//acá se va a hacer la magia :D
		double* mas_grande = std::max_element(&valores_funcion[i-tam_rect_arreglo],&valores_funcion[i]);
		resultado += *mas_grande * tamaño_rectangulo;
		

	}
	std::cout << resultado << std::endl;	
}