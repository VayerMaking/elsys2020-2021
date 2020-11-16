#include<iostream>
using namespace std;

#define M 4

int gaus(float a[][M], int n){
  int i, j, k = 0, c, flag = 0, m = 0;
	float pro = 0;

	// Performing elementary operations
	for (i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			c = 1;
			while ((i + c) < n && a[i + c][i] == 0)
				c++;
			if ((i + c) == n) {
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= n; k++)
				swap(a[j][k], a[j+c][k]);
		}

		for (j = 0; j < n; j++) {

			// Excluding all i == j
			if (i != j) {

				// Converting Matrix to reduced row
				// echelon form(diagonal matrix)
				float pro = a[j][i] / a[i][i];

				for (k = 0; k <= n; k++)
					a[j][k] = a[j][k] - (a[i][k]) * pro;
			}
		}
	}
	return flag;
}

void print4e(float a[][M], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++)
		cout << a[i][j] << " ";
		cout << endl;
	}
}
int main(){
  int n = 3;
	float a[M][M] = {{ 0, 2, 1, 4 },
					{ 1, 1, 2, 6 },
					{ 2, 1, 1, 7 }};
  int gaus_result = 0;
  gaus_result = gaus(a, n);
  print4e(a, n);
  return 0;
}
