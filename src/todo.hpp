#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#define LIST_PATH "lists/"
struct listObj { char isDone = '0'; std::string desc; };

class List{

	std::vector<listObj> objList;

public:
	List(std::string name){

		List::name = name;


		std::ifstream file(LIST_PATH+name+".todo");
		if (!file.is_open())
		{
			std::ofstream newfile(LIST_PATH+name+".todo");
			newfile.close();
			return;
		}

		std::string fileLine;
		while (getline (file, fileLine)){
			listObj tmpObj;

			tmpObj.isDone = fileLine[0];
			fileLine.erase(0,1);
			tmpObj.desc = fileLine;

			objList.push_back(tmpObj);

		}
		file.close();

	}

	std::string name = "";

	//return a complete list of all the obj in the to do list
	std::vector<listObj> getObj(){return objList;};

	// Save change by writting them on the file
	bool write(){

		std::ofstream file(LIST_PATH+name+".todo");
		if(!file.is_open()){
			std::cerr << "Your .todo is not to be found" << std::endl;
			return 0;
		}

		std::string buffer = "";

		for (listObj obj : objList){

		buffer += obj.isDone + obj.desc + "\n";

		}
		file << buffer;

		file.close();
		return 1;
	};

	//add an object to the list
	bool addObj(std::string objDesc){


		listObj tmpObj;
		tmpObj.desc = objDesc;

		objList.push_back(tmpObj);

		return 1;
	}

	//remove an object from the list based on his position in it
	bool removeObj(int objPos){
		objList.erase(objList.begin()+objPos);
		return 1;
	}

};

class Todo{
public:
	Todo(){};

	List* current_list = nullptr;

	bool init(){
    	for (const auto & entry : std::filesystem::directory_iterator(LIST_PATH)){
			if (entry.path().extension() == ".todo"){

			}
		}

		return 1;
	}


}Todo;
