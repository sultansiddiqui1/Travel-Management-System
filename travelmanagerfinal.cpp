#include <iostream>
#include <fstream> //to handle our files.
#include <iomanip> // to show floating point values
#include <stdlib.h>

using namespace std;
void menu(); //prototyping the menu function

class managemenu
{
protected:
  string username; // hdiding the admin name.

public:
  managemenu()
  {
    //constructor
    cout << "\n\n\n\n\n\n\n\t enter your admin user name to continue:";
    cin >> username;
    system("clear");
    menu();
  }
  ~managemenu() {} //destrcutor
};

// creating our classes:

class customers
{
public:
  string name, gender, address;
  int age, mobilenum;
  static int custid; //static int to use custid with inheritance later in the code.
  char all[999];
  // char to use getline later.

  void getdetails()
  {
    ofstream out("old-customers.txt", ios::app);
    // the file in append mode
    {
      cout << "enter customer id:\n";
      cin >> custid;

      cout << "enter customer name:\n";
      cin >> name;

      cout << "enter customer gender:\n";
      cin >> gender;

      cout << "enter  customer mobile number:\n";
      cin >> mobilenum;

      cout << "enter customer age:\n";
      cin >> age;

      cout << "enter customer address:";
      cin >> address;
    }

    out << "\ncustomer id:" << custid << "\nName" << name << "n\age:" << age << "\nmobile number:" << mobilenum << "\ngender:" << gender << "\naddress:" << address << endl;

    out.close();
    cout << "\n saved \n note: your information has been saved for future reference\n"
         << endl;
  }

  void showdetails()
  {
    ifstream in("old-customers.txt");
    {
      if (!in)
      {
        cout << "file error" << endl;
      }
      while (!(in.eof()))
      {
        in.getline(all, 999);
        cout << all << endl;
      }
      in.close();
    }
  }
};
int customers::custid;

class taxis
{ // class to allow customers to book taxis.
public:
  int cabchoice, choice;
  int distance;
  float cabcost;
  static float finalcost; // making it static so that we can use it outside the class as well using the ideas of inheritacne
  string hirecab;

  void cabdetails()
  {
    cout << "we provide the cheapest, fastest and the safest cabs in the city" << endl;
    cout << "\n------welcome to stuti cabs-------\n"
         << endl;
    cout << "1. rent a standard cab- euro 1,5 per kilometer" << endl;
    cout << "2. rent a luxury cab-euro 2,5 per kilomemter" << endl;

    cout << "\n calculating the total cost of your journey with us:" << endl;
    cout << "enter the type of cab you want:( enter 1 or 2)" << endl;
    cin >> cabchoice;
    cout << "enter the distnace you prefer to travel:" << endl;
    cin >> distance;

    if (cabchoice == 1)
    {
      cabcost = distance * 1.5;
      cout << "/nyour total cost:" << cabcost << "euros" << endl;
      cout << "press 1 to confirm your booking or 2 to cancel/ book another cab:" << endl;
      cin >> hirecab;

      system("clear");
      cout << "/nyour total cost:" << cabcost << "euros" << endl;
      cout << "enter continue   to confirm your booking or cancel  to cancel/ book another cab:" << endl;
      cin >> hirecab;

      if (hirecab == "continue")
      {
        finalcost = cabcost;
        cout << "you have succesfully hired  the standard cab" << endl;
        cout << "you can take your recipt from the menu." << endl;
      }
      else if (hirecab == "cancel")
      {
        cabdetails();
      }

      else
      {
        cout << "invalid input, redirecting to previous menu, please wait" << endl;

        system("clear"); // clearing the terminal
        cabdetails();
      }
    }

    else if (cabchoice == 2)
    {
      cabcost = distance * 2.5;
      cout << "/nyour total cost:" << cabcost << "euros" << endl;
      cout << "press 1 to confirm your booking or 2 to cancel/ book another cab:" << endl;
      cin >> hirecab;

      system("clear");
      cout << "\nyour total cost:" << cabcost << "euros" << endl;
      cout << "enter continue   to confirm your booking or cancel  to cancel/ book another cab:" << endl;
      cin >> hirecab;

      if (hirecab == "continue")
      {
        finalcost = cabcost;
        cout << "you have succesfully hired  the luxury cab" << endl;
        cout << "you can take your recipt from the menu." << endl;
      }
      else if (hirecab == "cancel")
      {
        cabdetails();
      }

      else
      {
        cout << "invalid input, redirecting to previous menu, please wait" << endl;

        system("clear"); // clearing the terminal
        cabdetails();
      }
    }
    else
    {

      cout << "invalid input, redirecting to main menu, please wait" << endl;

      system("clear"); // clearing the terminal
      menu();
    }
    cout << "\n press 1 to redirect to the main menu:" << endl;
    cin >> choice;
    system("clear");
    if (choice == 1)
    {
      menu();
    }
    else
    {
      menu();
    }
  }
};

float taxis::finalcost;

class booking
{
public:
  int choicehotel, packchoice;
  static float hotelcost; // making it static  variable so that we can use it outside the class with the concept of inheritance.
  void hotels()
  { // function to describe the hotel options

    string hotelno[] = {"Grace hotel", "Borsa Hotel", "Nuri Hotel"};
    for (int i = 0; i < 3; i++)
    {
      cout << (i + 1) << "." << hotelno[i] << "\n";
    }
    cout << "\ncurrently we collaborated the above mentioned hotels, to provide you with the best experience.\n"
         << endl;
    cout << "enter the number of the hotel you want to book:\n"
         << endl;
    cin >> choicehotel;
    system("clear");

    if (choicehotel == 1)
    {
      cout << "------welcome to Hotel Grace----------" << endl;
      cout << "5-star hotel" << endl;
      cout << "Refined hotel with dining, a smoker's lounge & a piano bar, plus warm quarters, a spa & lake views." << endl;
      cout << "packages offered by us for your convinence:" << endl;
      cout << "1. standard pack, excluding any meals: 80 euros" << endl;
      cout << "2. all basic facilities including breakfast, lunch and dinner: 120 euros" << endl;
      cout << "3. premium pack including breakfast, lunch ,dinner and a tour of the city: 150 euros" << endl;
      cout << "4. luxury pack including breakfast, lunch , mid-day snack,dinner  a tour of the city,pick-up and drop facility,and a free spa pass : 250 euros" << endl;

      cout << "n\ press another key to go back or\n enter the pckage number you want to book:" << endl;
      cin >> packchoice;

      if (packchoice == 1)
      {
        hotelcost = 80;
        cout << " you have succesfully booked the standard pack at Grace hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 2)
      {
        hotelcost = 120;
        cout << " you have succesfully booked the basic pack at Grace hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 3)
      {
        hotelcost = 150;
        cout << " you have succesfully booked the premium pack at Grace hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 4)
      {
        hotelcost = 250;
        cout << " you have succesfully booked the luxury pack at Grace hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else
      {
        cout << "invalid input!! redirecting to previous menu\n please wait!" << endl;
        system("clear");
        hotels();
      }
    }

    if (choicehotel == 2)
    {
      cout << "------welcome to Borsa Grace----------" << endl;
      cout << "4-star hotel" << endl;
      cout << "Refined rooms & suites in a polished hotel offering 2 restaurants, a bar & an indoor pool." << endl;
      cout << "packages offered by us for your convinence:" << endl;
      cout << "1. standard pack, excluding any meals: 65 euros" << endl;
      cout << "2. all basic facilities including breakfast, lunch and dinner: 80 euros" << endl;
      cout << "3. premium pack including breakfast, lunch ,dinner and a tour of the city: 88 euros" << endl;
      cout << "4. luxury pack including breakfast, lunch , a tour of the city,pick-up and drop facility,and a drinking card for our bar: 100 euros" << endl;

      cout << "n\ press another key to go back or\n enter the pckage number you want to book:" << endl;
      cin >> packchoice;

      if (packchoice == 1)
      {
        hotelcost = 65;
        cout << " you have succesfully booked the standard pack at Borsa hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 2)
      {
        hotelcost = 80;
        cout << " you have succesfully booked the basic pack at Borsa hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 3)
      {
        hotelcost = 88;
        cout << " you have succesfully booked the premium pack at Borsa hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 4)
      {
        hotelcost = 100;
        cout << " you have succesfully booked the luxury pack at Borsa hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else
      {
        cout << "invalid input!! redirecting to previous menu\n please wait!" << endl;
        system("clear");
        hotels();
      }
    }

    if (choicehotel == 3)
    {
      cout << "------welcome to Nuri Hotel----------" << endl;
      cout << "4-star hotel" << endl;
      cout << "Upmarket hotel offering a grand cafe & an elegant restaurant, plus a pool & a gym." << endl;
      cout << "packages offered by us for your convinence:" << endl;
      cout << "1. standard pack, excluding any meals: 78 euros" << endl;
      cout << "2. all basic facilities including breakfast, lunch and dinner: 90 euros" << endl;
      cout << "3. premium pack including breakfast, lunch ,dinner and a tour of the city: 95 euros" << endl;
      cout << "4. luxury pack including breakfast, lunch , a tour of the city,pick-up and drop facility,and a free one hour barista class at our cafe: 105 euros" << endl;

      cout << "n\ press another key to go back or\n enter the pckage number you want to book:" << endl;
      cin >> packchoice;

      if (packchoice == 1)
      {
        hotelcost = 78;
        cout << " you have succesfully booked the standard pack at Nuri hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 2)
      {
        hotelcost = 90;
        cout << " you have succesfully booked the basic pack at Nuri hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 3)
      {
        hotelcost = 95;
        cout << " you have succesfully booked the premium pack at Nuri hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else if (packchoice == 4)
      {
        hotelcost = 105;
        cout << " you have succesfully booked the luxury pack at Nuri hotel" << endl;
        cout << "please go to the menu to take your recipt" << endl;
      }

      else
      {
        cout << "invalid input!! redirecting to previous menu\n please wait!" << endl;
        system("clear");
        hotels();
      }
    }

    int gomenu;
    cout << "\n press 1 to redirect to menu:";
    cin >> gomenu;
    if (gomenu == 1)
    {
      menu();
    }
    else
    {
      menu();
    }
  }
};

float booking::hotelcost;

class charges : public booking, taxis, customers
{ // using multi-level inherietance beacuse we need the costs in this class

public:
  void printbill()
  {

    // to give the cutomer the bill.
    ofstream outf("recipt.txt");
    {

      outf << "-------Stuti Travel Agency-------" << endl;
      outf << "--------recipt-------" << endl;
      outf << "------------------------------------" << endl;

      outf << "customer Id:" << customers::custid << endl
           << endl;
      outf << "description\t\t Total:" << endl;
      outf << "Hotel Cost:" << fixed << setprecision(2) << booking::hotelcost << endl; // setprecision for the float values.
      outf << "taxi Cost:" << fixed << setprecision(2) << taxis::finalcost << endl;

      outf << "------------------------------------" << endl;
      outf << "total cost:\t\t " << fixed << setprecision(2) << booking::hotelcost + taxis::finalcost << endl;

      outf << "------------------------------------" << endl;
      outf << "enjoy your travels" << endl;

      outf << "thank you for choosing us." << endl;
    }

    outf.close();
  }

  void showbill()
  {

    ifstream inf("recipt.txt");
    {

      if (!inf)
      {
        cout << "File error!!!" << endl;
      }

      while (!(inf.eof()))
      {
        inf.getline(all, 999);
        cout << all << endl;
      }
    }
    inf.close();
  }
};

//creating the main menu:

void menu()
{
  int mainchoice, inchoice, gotomenu;

  cout << "\t\t             *Stuti Travels*\n"
       << endl;
  cout << "------------------Main Menu----------------------------" << endl;
  cout << "\t|\t\t\t\t\t|" << endl;
  cout << "\t|\tCustomer managemenet        ->1\t|" << endl;
  cout << "\t|\tCab managemenet             ->2\t|" << endl;
  cout << "\t|\tHotel Booking  managemenet  ->3\t|" << endl;
  cout << "\t|\tCharges and bills           ->4\t|" << endl;
  cout << "\t|\texit                        ->5\t|" << endl;
  cout << "\t|\t\t\t\t\t|" << endl;
  cout << "\t|---------------------------------------|" << endl;

  cout << "enter the number of your choice:" << endl;
  cin >> mainchoice;
  system("clear");

  customers a2;
  taxis a3;
  booking a4;
  charges a5;

  if (mainchoice == 1)
  {
    cout << "------Customers------" << endl;
    cout << "1.Enter New Customer" << endl;
    cout << "2.See Old Customer" << endl;

    cout << "\nEnter your choice" << endl;
    cin >> inchoice;
    system("clear");
    if (inchoice == 1)
    {
      a2.getdetails();
    }
    else if (inchoice == 2)
    {
      a2.showdetails();
    }

    else
    {
      cout << "invalid choice!!" << endl;
      system("clear");
      menu();
    }
    cout << "\npress 1 to readirect main menu: ";
    cin >> gotomenu;
    system("clear");
    if (gotomenu == 1)
    {
      menu();
    }
    else
    {
      menu();
    }
  }

  else if (mainchoice == 2)
  {
    a3.cabdetails();
  }

  else if (mainchoice == 3)
  {
    cout << "----Book the hotel of your choice------" << endl;

    a4.hotels();
  }
  else if (mainchoice == 4)
  {
    cout << "--Get your recipt---" << endl;
    a5.printbill();

    cout << "your bill is now printed and you can get it from the file path.\n"
         << endl;
    cout << "to preview your bill in the scree, press 1 or press anyother key to go back to the main menu.\n"
         << endl;

    cin >> gotomenu;

    if (gotomenu == 1)
    {
      system("clear");
      a5.showbill();
      cout << "press 1 to redirect to main menu :" << endl;
      cin >> gotomenu;
      system("clear");
      if (gotomenu == 1)
      {
        menu();
      }
      else
      {
        menu();
      }
    }
    else
    {
      system("clear");
      menu();
    }
  }

  else if (mainchoice == 5)
  {
    cout << "--good-bye---" << endl;
    system("clear");
    exit(0);
  }
  else
  {
    cout << "invalid input!!!\n"
         << endl;
    cout << "reditrecting!!" << endl;
    menu();
  }
}

int main()
{
  managemenu start;

  return 0;
}
