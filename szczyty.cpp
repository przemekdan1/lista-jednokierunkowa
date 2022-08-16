#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>

#define WIELKOSC 30

struct szczyt {
	char nazwa[WIELKOSC];
	char pasmo[WIELKOSC];
	int wyskosc;

	struct szczyt* nastepny;
};

int main()
{
	struct szczyt* glowa = NULL;
	struct szczyt* biezacy, * poprzedni = NULL;


	char dane[WIELKOSC];
	int dane_num;

	printf("Nazwa szczytu: ");
	while ((gets_s(dane, WIELKOSC - 1) != NULL) && (dane[0] != '\0'))
	{
		biezacy = (struct szczyt*)malloc(sizeof(struct szczyt));

		if (glowa == NULL) glowa = biezacy;
		else poprzedni->nastepny = biezacy;


		strcpy_s(biezacy->nazwa, WIELKOSC, dane);
		biezacy->nastepny = NULL;

		printf("Podaj pasmo (nie oszukuj): ");
		gets_s(dane, WIELKOSC - 1);
		strcpy_s(biezacy->pasmo, WIELKOSC, dane);

		printf("Podaj wyskosc n.p.m. (jak zle, to cię znajde!): ");
		scanf_s("%d", &biezacy->wyskosc);


		puts("");
		printf("Nazwa szczytu: ");

		while (getchar() != '\n')
		{
			continue;
		}

		poprzedni = biezacy;
	}




	if (glowa == NULL) puts("\nLista jest pusta.");
	else {
		puts("\nWpisane szczyty do zdobycia: \n");
		biezacy = glowa;
		while (biezacy != NULL)
		{
			printf_s("Nazwa szczytu: %-15s  Pasmo: %-10s Wyskosc: %d\n", biezacy->nazwa,biezacy->pasmo,biezacy->wyskosc);
			biezacy = biezacy->nastepny;
		}

		Sleep(3000);
		puts("\nFajnie. Sporo mam tych planow. Mam nadzieje ze mam czas w weekendy\n\n");
		Sleep(1000);
	}





	if (glowa == NULL)	printf_s("Ngdzie nie jedziesz? :( Zaplanuj sobie cos bo bedzesz siedzial sam w domu.\n\n");
	else
	{
		biezacy = glowa;

		while (biezacy != NULL)
		{
			poprzedni = biezacy;
			biezacy = biezacy->nastepny;

			Sleep(2500);
			printf("Kurde nie mam czasu wtedy Musze niestety usunac z listy: %s \n", poprzedni->nazwa);
			free(poprzedni);

		}

		Sleep(3000);
		puts("\nLista pusta\nNo i znowu zostaje bez planow na weekend : (");

	}

	return 0;
}