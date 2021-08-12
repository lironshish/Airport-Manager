#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Company.h"
#include "AirportManager.h"
#include "General.h"
#include "main.h"

const char* str[eNofOptions] = { "Add Flight", "Add Airport",
"PrintCompany", "Print all Airports",
	"Print flights between origin-destination",
"Sort Flights", "Search Flight" };


int main(int argc, char* argv[])
{

	char* airportFileName = (char*)malloc(sizeof(char)*(strlen(argv[1])+1));
	char* companyFileName = (char*)malloc(sizeof(char)*(strlen(argv[2]) + 1));
	if (argc != 3) {
		printf("Error in params\n");
		system("pause");
		return -1;
	}
	if (!airportFileName) {
		printf("Error in params\n");
		system("pause");
		return -2;
	}
	sscanf(argv[1], "%s", airportFileName);

	if (!companyFileName) {
		printf("Error in params\n");
		system("pause");
		return -3;
	}
	sscanf(argv[2], "%s", companyFileName);

	AirportManager	manager;
	Company			company;

	initManagerAndCompany(&manager, &company,airportFileName,companyFileName);

	int option;
	int stop = 0;
	
	do
	{
		option = menu();
		switch (option)
		{
		case eAddFlight:
			if (!addFlight(&company, &manager))
				printf("Error adding flight\n");
			break;


		case eAddAirport:
			if (!addAirport(&manager))
				printf("Error adding airport\n");
			break;

		case ePrintCompany:
			printCompany(&company);
			break;

		case ePrintAirports:
			printAirports(&manager);
			break;
		
		case ePrintFlightOrigDest:
			printFlightsCount(&company);
			break;
		
		case eSortFlights:
			sortFlight(&company);
			break;

		case eSearchFlight:
			findFlight(&company);
			break;

		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);


	saveManagerToFile(&manager, airportFileName);
	saveCompanyToFile(&company, companyFileName);

	freeManager(&manager);
	freeCompany(&company);

	system("pause");
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for(int i = 0 ; i < eNofOptions ; i++)
		printf("%d - %s\n",i,str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}

int initManagerAndCompany(AirportManager* pManager ,Company* pCompany, char* airportFileName, char* companyFileName)
{
	int res = initManager(pManager, airportFileName);
	if (!res)
	{
		printf("error init manager\n");
		return 0;
	}

	if (res == FROM_FILE)
		return initCompanyFromFile(pCompany,pManager, companyFileName);
	else
		initCompany(pCompany, pManager);
	return 1;
}