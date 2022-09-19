#include <iostream>
#include <cmath>
#include <algorithm> // es necesario para usar la función std::max_element
// programa para calcular integrales definidas, por ahora el borde de integración inferior va a ser 0 y el superior un número positivo
float funcion(float x) {
	return std::pow(x,2);
}

int main()
{
	float borde_superior = 5.0;
	float paso = .001; // determina el espacio entre cada valor de "y" tomado
	float tamaño_rectangulo = borde_superior/100; // determina la base del rectangulo

	int tam_rect_arreglo = tamaño_rectangulo/paso; // es el tamaño en posiciones del arreglo que tiene la base del rectangulo
	int largo = borde_superior/paso;
	float valores_funcion[largo];
	float val_x = 0.0;

	for (int i = 0; i<largo; i++) {
		//este for se encarga de poblar la lista con valores de la función
		valores_funcion[i] = funcion(val_x);
		val_x += paso;
	}
	

	float resultado = 0;
	for (int i = tam_rect_arreglo; i<=largo; i += tam_rect_arreglo) {
		
		//acá se va a hacer la magia :D
		float* mas_grande = std::max_element(&valores_funcion[i-tam_rect_arreglo],&valores_funcion[i]);
		resultado += *mas_grande * tamaño_rectangulo;
		

	}
	std::cout << resultado << std::endl;	
}