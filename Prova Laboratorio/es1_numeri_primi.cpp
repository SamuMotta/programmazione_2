/* Definire un metodo che stampa i numeri primi fino ad n
Vengono suggeriti 3 metodi:
1)dato num in [2, n] cerco un suo divisore in [2, num/2] se non lo trovo allora num e' primo;
2)dato num in [2, n] cerco un suo divisore in [2, sqrt(num)] se non lo trovo allora num e' primo;
3)Crivello di Eratostene o metodo del setaccio (2 implementazioni):
per ogni num in [2, n] elimino i suoi multipli, quelli che rimangono sono primi. */
#include <iostream>
#include <cmath>

using namespace std;

void fun1(int n)
{

	for (int i = 2; i <= n; i++)
	{
		bool is_prime = true;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
		{
			cout << i << " e' un numero primo." << endl;
		}
	}
}

void fun2(int n)
{

	for (int i = 2; i <= n; i++)
	{
		bool is_prime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
		{
			cout << i << " e' un numero primo." << endl;
		}
	}
}

void fun3(int vect[], int n)
{

	for (int i = 2; i <= n; i++)
	{
		vect[i] = 0;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{

		if (vect[i] == 0)
		{ //se l'elemento vect[i] e' zero

			for (int j = 2 * i; j <= n; j += i)
			{
				//imposto v[j] a 1, cioe' escludo i suoi multipli
				vect[j] = 1;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (vect[i] == 0)
		{
			cout << i << " e' un numero primo." << endl;
		}
	}
}

int main()
{
	cout << "----------- Funzione 1 -----------" << endl;
	fun1(13);
	cout << "----------- Funzione 2 -----------" << endl;
	fun2(13);
	cout << "----------- Funzione 2 -----------" << endl;
	fun2(100);
}
