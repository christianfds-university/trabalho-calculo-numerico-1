#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); //Função f(x)

double phi(double x); //Função xk = phi(xk-1)

void Iteracoes(double x0, double precisao); //Função que realiza os calculos para encontrar a raiz de f(x)

int main()
{
	double x0, precisao;
	double a=1, b=2; //Intervalo onde se encontra a raiz
	x0 = a; //x0

	precisao = pow(10,-6); //Precisão

	Iteracoes(x0, precisao);
}

double f(double x)
{
	return (x*x*x*x*x - x*x*x*x - 3);
}

double phi(double x)
{
	return pow((x*x*x*x + 3) , 1/5.0);
}

void Iteracoes(double x0, double precisao)
{
	double xk, xkant;
	int k = 0;
	//Prints do cabeçalho e da iteração k = 0
	printf("         Metodo do ponto fixo\n\n");
	printf("   K  |   (x^4 + 3)^(1/5)   |        |f(x)|\n");
	printf("  %2d  |      %.8lf     |      %.8lf\n", k++, x0, fabs(f(x0)));
	//Calculos Iniciais
	xkant = x0;
	xk = phi(x0);
	
	do //Loop realizado até que o critério de parada seja atingido
	{
		printf("  %2d  |      %.8lf     |      %.8lf\n", k++, xk, fabs(f(xk)) );
		xkant = xk;
		xk = phi(xk);
	} while (fabs(f(xk)) > precisao);
	//Print da ultima iteração
	printf("  %2d  |      %.8lf     |      %.8lf\n\n", k++, xk, fabs(f(xk)));
	//Print do resultado encontrado para a raiz da equação
	printf("A raiz da funcao e: %.8lf \n", xk);
}

