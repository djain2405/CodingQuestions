#include <iostream>
#include <conio.h>
#include <stdio.h>

void
	sort(char* a[], int n)
{
	char* x = a[2];
	int i = 0;
	int j = 0;
	char* temp;
	//printf("Now %s\n", x);

	for( i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (strcmp(a[j], a[i]) < 0)
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	int count = 0;
	bool isPie = false;
	int piecount = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", a[i]);
		
	}

	printf("----------------------------------\n");
	for (i = 0; i < (n-1); i++)
	{

		while ((strcmp(a[i], a[i+1]) == 0))
		{
			i++;
			count++;

			if(strstr(a[i], "pie") != NULL)
			{
				isPie = true;
				//piecount++;
			}
			else
			{
				isPie = false;
			}
		}

		//printf("Checking %d  %s  %d\n", count, a[i],  i);
		
		if (isPie == true)
		{
			int noOfpies = 0;
			int noOfSlices = 0;

			noOfpies = (count+1)/4;
			noOfSlices = (count+1)%4;

			printf("%s, %d\n", a[i], noOfpies);
			printf("%s, %d\n", a[i], noOfSlices);
		}
		else
		{
			printf("%s, %d\n", a[i], count+1);
		}

		count = 0;

	}

}

int main()
{
	char* dishes[11] = {"glazed donut", "cherry pie slice", "pumpkin pie slice", "redvelvet cupcake", "cherry pie slice", "cherry pie slice", "glazed donut", "cherry pie slice", "pumpkin pie slice", "cherry pie slice", "keylime pie slice"};
	char* p = dishes[2];
	//printf("testing : %s\n", p);
	sort(dishes, 11);
	getchar();
	return 0;
}