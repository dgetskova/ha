#include <iostream> 
#include <list>
#include <string>

#include <sstream> // za prevrushtaneto ot string v chislo
using namespace std;


double fill_tetrahedron (int num)
{
	double num_d = double (num);

	double v = (pow (num_d, 3)) / ((6*sqrt(2))) ;

	// /1000 zaradi prevryshtaneto ot sm v litri
	double vLitri = v/1000;
	return vLitri;
}


//
int tetrahedron_filled(list <int> tetrahedrons, int water)
{
	tetrahedrons.sort();
	double sum=0;
	double singleLiters=0;
	int countEdgesToReturn = 0;

	 for (std::list<int>::iterator it=tetrahedrons.begin(); it != tetrahedrons.end(); ++it)
	 {
		singleLiters = fill_tetrahedron(*it);
		sum = sum + singleLiters;
		if (sum >= water)
			return countEdgesToReturn;
		countEdgesToReturn++;
		
	 }
	 return countEdgesToReturn;
}

int main ()
{
	list <int> edgesList;
	string edgesCame;
	int water=0;

	cout << "Enter list of edges length : ";
	getline (cin, edgesCame);
	cout << "Enter water : ";
	cin >> water;

	//Proverka za vhodnite danni
	int countEdges = 0;
	for (int c=0; c<edgesCame.length(); c++)
	{
		if ( (edgesCame[c] < '0' && edgesCame[c] > '9') && edgesCame[c] !=' ')
			{
				//if((edgesCame[c] > '0' && edgesCame[c] < '9'))
					cout<<"Wrong input data!"<<endl;
				return -1;
			}
			else
			{
				if (edgesCame[c] >= '0' && edgesCame[c] <= '9')
				{
					while (edgesCame[c] >= '0' && edgesCame[c] <= '9')
					{
						c++;
					}
					countEdges++;
				}

			}
	}
	//v convert postavqme samo chislata(suzdavaneto iziskva predvaritelna proverka za string toest toi trqbva da sudurja samo chisla)
	istringstream convert(edgesCame);
	int edge;
	for (int i=0; i < countEdges; i++)
	{
		convert >> edge;
		edgesList.push_back(edge);
	}
	
	cout << tetrahedron_filled (edgesList, water)<<endl;
	
}
