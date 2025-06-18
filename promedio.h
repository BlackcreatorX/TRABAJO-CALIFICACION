#ifndef PROMEDIO_H
#define PROMEDIO_H

float funxPromedio(float numNuevo, float promedioAnterior){
	float Promedio=(numNuevo+promedioAnterior)/2;
	return Promedio;
	};

#endif

//recibir mat
/*
//test
int main()
{
	float a;
	float b;
	std::cout<<"prom anterior\n>";
	std::cin>>b;
	std::cout<<"calif nueva\n>";
	std::cin>>a;
	std::cout<<"prom:\n"<<funxPromedio(a, b);
}
*/
