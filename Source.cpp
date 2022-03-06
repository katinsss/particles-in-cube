#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;


double Lx, Ly, Lz;
int N, n;


int main()
{
	ifstream fin("input.txt");
	ofstream fout;

	fout.open("output.txt");
	
	fin >> Lx >> Ly >> Lz >> N;

	vector <double> x;
	vector <double> y;
	vector <double> z;

	x.resize(N);
	y.resize(N);
	z.resize(N);

	double X = 0.0;
	double Y = 0.0;
	double Z = 0.0;

	n = pow(N, 1.0/ 3.0); // kub koren, iz N

	
	int koord = 0; // fixiruem koordinatu
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {

				x[koord] = X;
				y[koord] = Y;
				z[koord] = Z;

				koord++;

				X = X + Lx / (n - 1);
			}
			X = 0.0;

			Y = Y + Ly / (n - 1);
		}
		Y = 0.0;

		Z = Z + Lz / (n - 1);
	}

	fout << "N" << '\t' << "X" << '\t' << "Y" << '\t' << "Z" << '\n';

	koord = 0; // vuvod koordinat
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {

				fout << koord+1 << '\t';
				fout << x[koord] << '\t' << y[koord] << '\t' << z[koord] << '\n';
				koord++;
			}
		}
	}


	fout.close();
	fin.close();


	return 0;

}