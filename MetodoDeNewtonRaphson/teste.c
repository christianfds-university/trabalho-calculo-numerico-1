#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); // Função f(x)

double fderivative(double x); // Função derivada de f(x)

double g(double x); // Função xk = g(xk-1)

void findAlpha(double x0, double parada); // Função que realiza os calculos para encontrar a raiz de f(x)

int main()
{
	double x0, parada;
	double a=1, b=2; // Intervalo onde se encontra a raiz 
	x0 = b; //x0

	parada = pow(10,-6); // Precissão

	findAlpha(1.5, parada); 
}

double f(double x)
{
	return (x*x*x*x*x - x*x*x*x - 3);
}

double fderivative(double x)
{
	return (5*x*x*x*x - 4*x*x*x);
}

double g(double x)
{
	return x - f(x)/fderivative(x);
}

void findAlpha(double x0, double parada)
{
	double xk, xkant; //xk e xk-1
	int k = 0; // Conta o numero de iterações
	//Prints do cabeçalho e da iteração k = 0
	printf("          Metodo de Newton-Raphson\n\n");
	printf("   K  |     xn     |   x - f(x)/fderivative(x)   |       |f(x)|\n");
	printf("  %2d  |            |          %.8lf         |      %.8lf\n", k++, x0, fabs(f(x0)));
	//Calculos Iniciais	
	xkant = x0;
	xk = g(x0);
		
	do //Loop realizado até que se atinja o critério de parada
	{
		printf("  %2d  | %.8lf |          %.8lf         |      %.8lf\n", k++, xkant ,xk, fabs(f(xk)) );
		xkant = xk;
		xk = g(xk);	
	} while (fabs(f(xk)) > parada);

	// Print da ultima iteração e do resultado final
	printf("  %2d  | %.8lf |          %.8lf         |      %.8lf\n", k++, xkant ,xk, fabs(f(xk)) );
	printf("A raiz da funcao e: %.8lf \n", xk);
}
