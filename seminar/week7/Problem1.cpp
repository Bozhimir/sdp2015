#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sales.txt", ios::in);

struct Gas
{
	int counterID;
	double quantity;

	
};


istream& operator >>(istream& in, Gas&g)
{
	if (in)
	{
		int id;
		double q;

		in >> id >> q;
		if (in)
		{
			g.counterID = id;
			g.quantity = q;
		}
	}
	return in;
}

double totalForCounter(int counterId, double pricePerLiter, ifstream in)
{
	if (!in) return 0;
	double total = 0;
	Gas gas;
	while (in >> gas)
	{
		if (gas.counterID == counterId)
		{
			total += gas.quantity*pricePerLiter;
		}
	}
	return total;
}

bool load(ifstream& in, Gas& g)
{
	if (!in) return false;
	in.read((char*)&g, sizeof(g));
	return in.good();
}

double avg(int counterID, ifstream& in)
{
	double avg = 0;
	size_t count = 0;
	Gas gas;
	in.clear();
	in.seekg(0, ios::beg);
	if (!in) return 0;
	while (in >> gas)
	{
		if (gas.counterID = counterID)
		{
			avg += gas.quantity;
			++count;
		}
	}
	return (count==0)?0:avg / count;
}

void writeAverages(ifstream& in)
{
	ofstream output("averages.bin", ios::ate | ios::binary);
	if (!output) return;
	size_t maxCounterID = 10;//getMaxCounterID();
	for (size_t i = 0; i < maxCounterID; i++)
	{
		output.seekp((i - 1)*sizeof(Gas), ios::beg);
		double a = avg(i, in);
		output.write((const char*)&a, sizeof(a));
	}
}
int main()
{


}
