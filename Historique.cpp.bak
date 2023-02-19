/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Historique.cpp
 * @title Historique
 * @brief
 */

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void add_to_hist (string name)
{
	ofstream datafile;
	datafile.open("historique.txt",ios::app);
	if (datafile.fail())
		cerr<<"The file can not open."<<endl;
	else
		datafile << name<<endl;
	datafile.close();
}

int search_in_hist (string word)
{
    ifstream datafile;
    datafile.open("historique.txt");
    if(!datafile.is_open())
        cerr<<"The file can not open."<<endl;
    string line;
    while(!datafile.fail() && !datafile.eof())
    {
        datafile >> line;
        if(line==word)
            return 1;
				}

    datafile.close();
				return 0;
}

void historique_file(){
	fstream datafile;
	datafile.open("historique.txt", ios::out);
	if (datafile.fail()){
		cout<<"The file can not open.\n";
		return ;
	}
	datafile.close();
}


