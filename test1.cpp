/*
 * test1.cpp
 *
 *  Created on: 2017Äê1ÔÂ29ÈÕ
 *      Author: Weiyu
 */
#include <iostream>
using namespace std;

int main()
{
	int number_of_pods, peas_per_pod,total_peas;

	cout << "Press return.\n";
	cout << "Enter the number of pods:\n";
	cin >> number_of_pods;
	cout << "Enter the number of peas in a pod:\n";
	cin >> peas_per_pod;

	total_peas = number_of_pods * peas_per_pod;

	cout << "If you have";
	cout << number_of_pods;
	cout << "pea pods\n";
	cout << "and";
	cout << peas_per_pod;
	cout << " peas in each pod, then\n";
	cout << "you have";
	cout << "total_peas";
	cout << " peas in all pods.\n";

	return 0;
}



