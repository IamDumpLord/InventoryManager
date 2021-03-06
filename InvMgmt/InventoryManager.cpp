// InventoryManager.cpp : Defines the entry point for the console application.
//

/*   -Jakes Contributions
(InventoryManager.cpp)
	writeToFile fx's 
	insProductFromFile fx's 
	insPerishableFromFile
	displayInfo fx's
(Product.h)
	setDepartment that takes int (uses getDepartment below)
	getDepartment overloaded, takes int returns Department enum
	getDepartmentNum, return int of Department
(Perishable.h)
	setPerishType that takes int (uses getPerishType below)
	getPerishType overloaded, takes in returns PerishType enum
	getPerishNum, return int of PerishType

If I remember correctly we wont be instantiating the base Product, only Perishable.
In that case we can omit the fx's i made in main that deal with Product. I mostly 
used them to test it was working on the base class


*/


#include "stdafx.h"
#include "Product.h"
#include "Perishable.h"
#include <iostream>

//used in fileIO stuff
#include <fstream>
#include <vector>


//overloaded writeTo fxs, setting the bool to false will rewrite an existing file
//uses some extra get fxs to write the enums as numbers 
void writeToFile(string outputFile, bool newFile, vector<Perishable> pList) {
	ofstream file;
	if (!newFile) {
		file.open(outputFile);
	}
	else {
		file.open(outputFile, std::ios_base::app);
	}
	for (size_t i = 0; i < pList.size(); i++) {
		file << pList[i].getName() << ' ' << pList[i].getDepartmentNum() << ' ' << pList[i].getPrice() << ' ' << pList[i].getSalePrice()
			<< ' ' << pList[i].getWeight() << ' ' << pList[i].getID() << ' ' << pList[i].getQuantity() << ' ' << pList[i].getPerishNum()
			<< ' ' << pList[i].getShelfLife() << '\n';
	}
}
void writeToFile(string outputFile, bool newFile, vector<Product> pList) {
	ofstream file;
	if (!newFile) {
		file.open(outputFile);
	}
	else {
		file.open(outputFile, std::ios_base::app);
	}
	for (size_t i = 0; i < pList.size(); i++) {
		file << pList[i].getName() << ' ' << pList[i].getDepartmentNum() << ' ' << pList[i].getPrice() << ' ' << pList[i].getSalePrice()
			<< ' ' << pList[i].getWeight() << ' ' << pList[i].getID() << ' ' << pList[i].getQuantity() << '\n';
	}
}
void writeToFile(string outputFile, bool newFile, Perishable p) {
	ofstream file;
	if (!newFile) {
		file.open(outputFile);
	}
	else {
		file.open(outputFile, std::ios_base::app);
	}
	file << p.getName() << ' ' << p.getDepartmentNum() << ' ' << p.getPrice() << ' ' << p.getSalePrice()
		<< ' ' << p.getWeight() << ' ' << p.getID() << ' ' << p.getQuantity() << ' ' << p.getPerishNum()
		<< ' ' << p.getShelfLife() << '\n';
	
}
void writeToFile(string outputFile, bool newFile, Product p) {
	ofstream file;
	if (!newFile) {
		file.open(outputFile);
	}
	else {
		file.open(outputFile, std::ios_base::app);
	}
	file << p.getName() << ' ' << p.getDepartmentNum() << ' ' << p.getPrice() << ' ' << p.getSalePrice()
		<< ' ' << p.getWeight() << ' ' << p.getID() << ' ' << p.getQuantity() << '\n';

}

//fx's to instantiate vector list from file, made one for Product and Perishable
//uses extra get fxs to read the Department and PerishType int and set to enum
vector<Product> insProductFromFile(string itemFile) {
	ifstream file;
	file.open(itemFile);

	vector<Product> temp;
	Product p;
	string tName;
	int dept;
	double tPrice, tSalePrice, tWeight;
	int tID, tQuantity;

	while (file >> tName >> dept >> tPrice >> tSalePrice >> tWeight >> tID >> tQuantity) {

		p.setName(tName); p.setDepartment(dept); p.setPrice(tPrice); p.setSalePrice(tSalePrice);
		p.setWeight(tWeight); p.setID(tID); p.setQuantity(tQuantity);

		temp.push_back(p);
	}
	return temp;
}
vector<Perishable> insPerishableFromFile(string itemFile) {
	ifstream file;
	file.open(itemFile);

	vector<Perishable> temp;
	Perishable p;
	string tName;
	int dept;
	double tPrice, tSalePrice, tWeight;
	int tID, tQuantity, pType, shelfLife;

	while (file >> tName >> dept >> tPrice >> tSalePrice >> tWeight >> tID >> tQuantity >> pType >> shelfLife) {

		p.setName(tName); p.setDepartment(dept); p.setPrice(tPrice); p.setSalePrice(tSalePrice);
		p.setWeight(tWeight); p.setID(tID); p.setQuantity(tQuantity); p.setPerishType(pType); p.setShelfLife(shelfLife);

		temp.push_back(p);
	}

	return temp;
}

//
void displayInfo(vector<Product> productList) {

	for (size_t i = 0; i < productList.size(); i++)
		cout << productList[i].getName() << ' ' << productList[i].getDepartmentName() << ' '
		<< productList[i].getPrice() << ' ' << productList[i].getSalePrice() << ' ' << productList[i].getWeight()
		<< ' ' << productList[i].getID() << ' ' << productList[i].getQuantity() << '\n';
}
void displayInfo(vector<Perishable> perishList) {

	for (size_t i = 0; i < perishList.size(); i++)
		cout << perishList[i].getName() << ' ' << perishList[i].getDepartmentName() << ' '
		<< perishList[i].getPrice() << ' ' << perishList[i].getSalePrice() << ' ' << perishList[i].getWeight()
		<< ' ' << perishList[i].getID() << ' ' << perishList[i].getQuantity() << ' ' << perishList[i].getPerishName()
		<< ' ' <<  perishList[i].getShelfLife() << '\n';
}

int main()
{
	
	Perishable item = Perishable("perishtest", Meat, 10, 8, 1, 6900, 1, Fridge, 10);
	//Product item = Product("testp", Meat, 10, 9, 8, 7, 6);
	vector<Perishable> pList;

	pList.push_back(item);
	pList.push_back(item);
	pList.push_back(item);
	pList.push_back(item);
	
	//if you change the second param to true it will append it to the existing list.
	//NOTE: it can't handle a .txt of products and perishables, but should be fine
	//since we are just using perishables (right?)
	writeToFile("TestFile.txt", false, pList);

	pList = insPerishableFromFile("TestFile.txt");
	//pList = insProductFromFile("TestFile.txt");

	displayInfo(pList);
	

	system("pause");
    return 0;
}

