//Jahidul Robin CMPSC 121
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>
#include <iomanip>
#include<bits/stdc++.h> 
using namespace std;
 
// Be specific with Capitilization
//Admin
string admin="Admin", adminPass="admin121";
//User
string user="User", userPass="cmpsc121";
string inputUser, inputPass;

// This vector is to contains all of the employee's information.
vector<string> stringVec;

// This has to do with the data that belongs with the employees. 
int info;

// Turns info into a string that can be read.
string employeeData; 

string elementToMod, modElement, 
//When modifying a certain part of an info, elementToMod and modElement becomes the data that was newly set. 
modifiedEData;
//This is the employee's info that was modified with one of the modElements.

 
// This allows an admin or user to find a employee's car information with a email search.
void emailAndVehicle(string email){
  ifstream file;
  size_t pos;
  string line;
  file.open("Employee.txt");
  if(file.is_open())
  {
    //This will allow the program to defferentiate between each line so each line will be assigned it's owen information and not have every other line included
    while(getline(file,line))
    {
      pos = line.find(email);
      if(pos!=string::npos)
      {  
        string arr[14];
        int i = 0;
        stringstream ssin(line);//words are turned into an array
        while (ssin.good() && i < sizeof(arr)){
          ssin >> arr[i];
          ++i;}
      
        cout<<"You entered the email address: "+email+".\n";
        cout<<"Employee First Name: "+arr[0]+"\n";
        cout<<"Employee Last Name: "+arr[1]+"\n";
        cout<<"Employee Car Type: "+arr[9]+"\n";
        cout<<"Employee Car Model: "+arr[10]+"\n";
        cout<<"Employee Car Color: "+arr[11]+"\n";
        cout<<"Employee Car License Plate Number: "+arr[12]+"\n";
        break;
      

      }
    }
  }
}
 
//getInfo accepts an employee name and type of information, and prints out the specific data for the given employee.
void getInfo(string str)
{
  string element;
  stringstream search(str);
  while (search >> element){
    stringVec.push_back(element); //adds all the data to a vector,
     //cout << "[" << word << "] ";
    // cout << element << endl;

 }
 cout << stringVec[info]; //prints out the data at the specified index.
}
 
//modInfo does the same thing as getInfo, without printing anything, so that replaceElement can replace a specific element in the vector.
void modInfo(string str)
{
  string element;
  stringstream search(str);
  while (search >> element){
    stringVec.push_back(element);
     //cout << "[" << element << "] ";
 }
       elementToMod = stringVec[info];
 
}
 
//replaceElement creates a string that concatenates all of an employee's data, and replaces a specific element with a new one.
void replaceElement(string str)
{
 string element;
  stringstream search(str);
  while (search >> element){
    if(element!=elementToMod){
    stringVec.push_back(element);
     modifiedEData+=element+" ";
    }else{
     modifiedEData+=modElement+" ";
    }
 }
}

//Below is the function required in goal number 10.
// e2vi("SSmith@gmail.com"); 
int main() { 
  cout << "Select a User: Admin or User: "; cin >> inputUser;
  cout << "Enter your Password: "; cin >> inputPass;
  cout << "Username: " << inputUser << ", Password: " << inputPass << "\n\n";
 
// if user is ADMIN
if(inputUser == admin && inputPass == adminPass){
  cout << "You are an Admin! Type any of the following: " << endl;
  cout << "\t View " << endl;
  cout << "\t Add " << endl;
  cout << "\t Delete " << endl;
  cout << "\t Modify " << endl;
  cout << ">> ";

  string adminAction; cin >> adminAction;
 
  // If the admin seleved view than this program will excute
  if (adminAction == "View" || adminAction == "view") {
    cout << endl << "View Selected" << endl;

    cout << "do you want to view user with email? Y/N: ";
    char response; cin >> response;

    if(response == 'Y' || response == 'y'){
      cout << "Enter the email: ";
      string email; cin >> email;
      emailAndVehicle(email);
    }else{
      cout << "Enter the name of an employee: ";
    
      string name; cin >> name;

      cout << endl << "Type any of the employee data below: " << endl; 
      cout << "\t First_Name " << endl;
      cout << "\t Last_Name " << endl;
      cout << "\t Email_ID " << endl;
      cout << "\t Phone_Number " << endl;
      cout << "\t Apartment_Number " << endl;
      cout << "\t Street_Address " << endl;
      cout << "\t City " << endl;
      cout << "\t State " << endl;
      cout << "\t Zipcode " << endl;
      cout << "\t Vehicle_Type " << endl;
      cout << "\t Vehicle_Model " << endl;
      cout << "\t Vehicle_Color " << endl;
      cout << "\t Vehicle_Tag_Number " << endl;
      cout << ">> ";
    
      cin >> employeeData;

      // Converting the user's input into a findable index.
      if (employeeData == "Firts_Name") {
        info=0;
      } else if(employeeData=="Last_Name"){
        info=1;
      } else if(employeeData=="Email_ID"){
        info=2;
      } else if(employeeData=="Phone_Number"){
        info=3;
      } else if(employeeData=="Apartment_Number"){
        info=4;
      } else if(employeeData=="Street_Address"){
        info=5;
      } else if(employeeData=="City"){
        info=6;
      } else if(employeeData=="State"){
        info=7;
      } else if(employeeData=="Zipcode"){
        info=8;
      } else if(employeeData=="Vehicle_Type"){
        info=9;
      } else if(employeeData=="Vehicle_Model"){
        info=10;
      } else if(employeeData=="Vehicle_Color"){
        info=11;
      } else if(employeeData=="Vehicle_Tag_Number"){
        info=12;
      } else{
        cout<<"Invalid Element\n";
      }
  
      // Calling the function getInfo for the given name and element.
      fstream newfile;
      newfile.open("Employee.txt",ios::in);
      if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
          if (tp.find(name) == 0){
            getInfo(tp);
          }
        }
        newfile.close();
      }
    }  
  } else if (adminAction == "Add" || adminAction == "add"){
    cout << "You selected Add\n\n";
    
    string newInfo, newFName, newLName, newEmail, newPhone, newApartment, newAddress, newCity, newState, newZipCode, newVType, newVModel, newVColor, newVID;

    cout << "Enter the new employee's First Name: "; cin >> newFName;
    cout << "Enter the new employee's Last Name: "; cin >> newLName;
    cout << "Please enter the new employee's Email_ID: "; cin >> newEmail;
    cout << "Please enter the new employee's Phone Number:"; cin >> newPhone;
    cout << "Please enter the new employee's Apartment Number: "; cin >> newApartment;
    cout << "Please enter the new employee's Street Address (Replace Spaces with Underscores) Like this: \"123_Red_Street\": "; cin >> newAddress;
    cout << "Please enter  the new employee's City (Replace Spaces with Underscores) Like this: \"San_Diego\": "; cin >> newCity;
    cout << "Please enter the new employee's State (Replace Spaces with Underscores) Like this: \"New_Jersey\": "; cin >> newState;
    cout << "Please enter the new employee's Zipcode: "; cin >> newZipCode;
    cout << "Please enter the new employee's Vehicle Type (Replace Spaces with Underscores) Like this: \"Station_Wagon\": "; cin >> newVType;
    cout << "Please enter the new employee's Vehicle Model (Replace Spaces with Underscores) Like this: \"2021_Audi_S4\": "; cin >> newVModel;
    cout << "Please enter the new employee's Vehicle Color (Replace Spaces with Underscores) Like this: \"Dark_Red\": "; cin >> newVColor;
    cout << "Please enter the new employee's Vehicle ID: "; cin >> newVID;

    ofstream outfile;
    newInfo = newFName + " " + \
              newLName + " " + \
              newEmail + " " + \
              newPhone + " " + \
              newApartment + " " + \
              newAddress + " " + \
              newCity + " " + \
              newState + " " + \
              newZipCode + " " + \
              newVType + " " + \
              newVModel + " " + \
              newVColor + " " + \
              newVID;

    //FirstName LastName Email PhoneNumber Apartment Address City State Zipcode Type Model Color ID
    outfile.open("Employee.txt", ios_base::app);
    outfile << "\n";
    outfile << newInfo;
  
 } else if(adminAction == "Delete" || adminAction == "delete"){
    string name;
    cout <<"You selected Delete" << endl;
    cout <<"Enter the name of the employee: "; cin >> name;

    string search;
    ifstream myfile;
    myfile.open("Employee.txt"); //open Employee
    ofstream temp;
    temp.open("temp.txt"); //create a temporary file
    while (getline(myfile, search))
    {
      if (search.substr(0, name.size()) != name){
        temp << search << endl;
      }
    }
    myfile.close();
    temp.close();
    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");

 } else if(adminAction=="Modify" || adminAction=="modify"){
    string name;Robert Jackson Robertj402@outlook.com 267-909-0234 aprt_2 353_springfield_road Piladelphia Pennsylvaniva 19154 Sport Mach1 White Kry-4083
Robin Jahidul jahidulirobin@outlook.com 215-302-5619 aprt_201 372_Rockheed Pittsburg Pennsylvaniva 15106 Sport Mustang_GT Black_and_Grey jpk-7723 
Simp Lord Lsimp@gmail.com 909-402-6345 aprt_1 9987 Knights road Philadelphia Pennsylvaniva 19154 truck tesla_cybertruck grey l0l-gas3 
Peter Griffen peterGriffen@psu.edu 215-882-3897 aprt_502 1234 giffentown_blvd Philadelphia Pennsylvaniva 19020  Sports Shelby_gt500 green flk-4021 
Steve Mathew smat68@gmail.com 267-930-2045 aprt_69 10175 Bustleton_Ave Philadelphia PA 19116 SUV RangeRover red ros-4025

    cout <<"You selected Modify" << endl;
    cout <<"Enter the name of the employee: "; cin >> name;

    cout << endl << "Type any of the employee data below to modify: " << endl; 
    cout << "\t First_Name " << endl;
    cout << "\t Last_Name " << endl;
    cout << "\t Email_ID " << endl;
    cout << "\t Phone_Number " << endl;
    cout << "\t Apartment_Number " << endl;
    cout << "\t Street_Address " << endl;
    cout << "\t City " << endl;
    cout << "\t State " << endl;
    cout << "\t Zipcode " << endl;
    cout << "\t Vehicle_Type " << endl;
    cout << "\t Vehicle_Model " << endl;
    cout << "\t Vehicle_Color " << endl;
    cout << "\t Vehicle_Tag_Number " << endl;
    cout << ">> "; cin >> employeeData;

    if(employeeData=="First_Name"){
      info=0;
    } else if(employeeData=="Last_Name"){
      info=1;
    } else if(employeeData=="Email_ID"){
      info=2;
    } else if(employeeData=="Phone_Number"){
      info=3;
    } else if(employeeData=="Apartment_Number"){
      info=4;
    } else if(employeeData=="Street_Address"){
      info=5;
    } else if(employeeData=="City"){
      info=6;
    } else if(employeeData=="State"){
      info=7;
    } else if(employeeData=="Zipcode"){
      info=8;
    } else if(employeeData=="Vehicle_Type"){
      info=9;
    } else if(employeeData=="Vehicle_Model"){
      info=10;
    } else if(employeeData=="Vehicle_Color"){
      info=11;
    } else if(employeeData=="Vehicle_Tag_Number"){
      info=12;
    } else{
      cout << "Invalid Element\n";
    }
  
    fstream newfile;
    newfile.open("Employee.txt",ios::in);
    if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
        if (tp.find(name) == 0){
          modInfo(tp);
        }
      }
      newfile.close();
    }

    //System explains the current element, and asks you to input the replacement element.
    cout<< "The " + employeeData + " you wish to modify is currently: " + elementToMod + "\n";
    cout<< "\n";
    cout<< "Please enter the new " + employeeData + ": "; cin >> modElement;
    
    //Call function replaceElement.
    newfile.open("Employee.txt",ios::in);
    if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
        if (tp.find(name) == 0){
          replaceElement(tp);
        }
      }
      newfile.close();
    }
  
  //Delete the instance of the employee's data that contains the outdated element.
    string search;
    ifstream myfile;
    myfile.open("Employee.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(myfile, search))
    {
      if (search.substr(0, name.size()) != name){
        temp << search << endl;
      }
    }
    myfile.close();
    temp.close();
    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");
  //Add the instance of the employee's data that has been modified to contain the new element.
    ofstream outfile;
    outfile.open("Employee.txt", ios_base::app);
    outfile <<modifiedEData;
  
  }else{
  //Admin has not selected an acceptable action.
    cout << "Error: Please enter either \"View\" to View, \"Add\" to Add, \"Delete\" to Delete, or \"Modify\" to Modify employee data.\n";
  }
  }
  
//user IS NOT Admin.
//All below functions are just copies of the admin functions, but modified to include only the options that regular employees are allowed to access.
else if(inputUser == user && inputPass == userPass){
//Delete and Modify actions are disabled.
 cout << "You are a regular employee! Please type \"View\" to View, or \"Add\" to Add some employee data.\n";
 cout << "\n";
 cout << ">> "; 
 string userAction;
 cin >> userAction;
 cout <<"\n";
 
//user selected "View".
if(userAction=="View"){
   cout <<"You selected View\n";
   cout << "do you want to view user with email? Y/N: ";
    char response; cin >> response;
    if(response == 'Y' || response == 'y'){
      cout << "Enter the email: ";
      string email; cin >> email;
      emailAndVehicle(email);
    }else{
      cout <<"\n";
   cout <<"Please enter the name of the employee that you would like to view the data of:\n";
   cout <<"\n";
   string name;
   cin >>name;
   cout<<"\n";
   cout <<"Please type the employee data you would like to view: \"First_Name\", \"Last_Name\", \"Email_ID\", \"Phone_Number\", \"Apartment_Number\", \"Street_Address\", \"City\", \"State\", \"Zipcode\", \"Vehicle_Type\", \"Vehicle_Model\", \"Vehicle_Color\", or \"Vehicle_Tag_Number\".\n";
   cout <<"\n";
   cin >> employeeData;
   cout <<"\n";
 if(employeeData=="First_Name"){
   info=0;
 } else
 if(employeeData=="Last_Name"){
   info=1;
 } else
 if(employeeData=="Email_ID"){
   info=2;
 } else
 if(employeeData=="Phone_Number"){
   info=3;
 } else
 if(employeeData=="Apartment_Number"){
   info=4;
 } else
 if(employeeData=="Street_Address"){
   info=5;
 } else
 if(employeeData=="City"){
   info=6;
 } else
 if(employeeData=="State"){
   info=7;
 } else
 if(employeeData=="Zipcode"){
   info=8;
 } else
 if(employeeData=="Vehicle_Type"){
   info=9;
 } else
 if(employeeData=="Vehicle_Model"){
   info=10;
 } else
 if(employeeData=="Vehicle_Color"){
   info=11;
 } else
 if(employeeData=="Vehicle_Tag_Number"){
   info=12;
 }
 
    //Call getInto.
   fstream newfile;
   newfile.open("Employee.txt",ios::in);
   if (newfile.is_open()){
   string tp;
   while(getline(newfile, tp)){
     if (tp.find(name) == 0){
       getInfo(tp);
     }
   }
   newfile.close();
}
    }  

 
 }else
//user selected "Add".
 if(userAction=="Add"){
   cout <<"You selected Add\n";
   cout <<"\n";
   string newInfo;
   cout << "Please enter the new employee's First Name:\n\n";
   string newFName;
   cin >> newFName;
   cout <<"\n";
   cout << "Please enter the new employee's Last Name:\n\n";
   string newLName;
   cin >> newLName;
   cout <<"\n";
   cout << "Please enter the new employee's Email_ID:\n\n";
   string newEmail;
   cin >> newEmail;
   cout <<"\n";
   cout << "Please enter the new employee's Phone Number (Replace Spaces with Dashes) Like this: \"233-485-345\":\n\n";
   string newPhone;
   cin >> newPhone;
   cout <<"\n";
   cout << "Please enter the new employee's Apartment Number:\n\n";
   string newApartment;
   cin >> newApartment;
   cout <<"\n";
   cout << "Please enter the new employee's Street Address (Replace Spaces with Underscores) Like this: \"123_Red_Street\":\n\n";
   string newAddress;
   cin >> newAddress;
   cout <<"\n";
   cout << "Please enter  the new employee's City (Replace Spaces with Underscores) Like this: \"San_Diego\":\n\n";
   string newCity;
   cin >> newCity;
   cout <<"\n";
   cout << "Please enter the new employee's State (Replace Spaces with Underscores) Like this: \"New_Jersey\":\n\n";
   string newState;
   cin >> newState;
   cout <<"\n";
   cout << "Please enter the new employee's Zipcode:\n\n";
   string newZipCode;
   cin >> newZipCode;
   cout <<"\n";
   cout << "Please enter the new employee's Vehicle Type (Replace Spaces with Underscores) Like this: \"Station_Wagon\":\n\n";
   string newVType;
   cin >> newVType;
   cout <<"\n";
   cout << "Please enter the new employee's Vehicle Model (Replace Spaces with Underscores) Like this: \"2021_Audi_S4\":\n\n";
   string newVModel;
   cin >> newVModel;
   cout <<"\n";
   cout << "Please enter the new employee's Vehicle Color (Replace Spaces with Underscores) Like this: \"Dark_Red\":\n\n";
   string newVColor;
   cin >> newVColor;
   cout <<"\n";
   cout << "Please enter the new employee's Vehicle ID:\n\n";
   string newVID;
   cin >> newVID;
   cout <<"\n";
   ofstream outfile;
   newInfo = newFName+" "+newLName+" "+newEmail+" "+newPhone+" "+newApartment+" "+newAddress+" "+newCity+" "+newState+" "+newZipCode+" "+newVType+" "+newVModel+" "+newVColor+" "+newVID;
   //FirstName LastName Email PhoneNumber Apartment Address City State Zipcode Type Model Color ID
   outfile.open("Employee.txt", ios_base::app);
   outfile <<"\n";
   outfile <<newInfo;
 }else{
   cout << "Error: Please enter either \"View\" to View, or \"Add\" to Add employee data.\n";
 }
}
//user NOT FOUND.
else{
 cout << "Username and or Password is incorrect.\n";
 cout << "\n";
}
} 