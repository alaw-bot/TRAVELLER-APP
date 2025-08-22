#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

static bool EducationMode = false;

void menu();    //main menu function prototype
void customerMenu();
int exitApp();

class ManageMenu
{
protected:
    string userName;    

public:

    ManageMenu()
    {
        if (EducationMode == true) cout << " Manage Menu Class is created\n" << endl;
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu() {
        if (EducationMode) { cout << " Manage Menu Class is destroyed" << endl; }
    }//destructor
};

class Customer
{

public:
    string name, gender, address, mobileNo;
    int age, menuBack = 0;
    static int cusID;
    char all[999];

    Customer() {
        if (EducationMode == true) cout << " Customer Class is created" << endl;
    }

    ~Customer() {
        if (EducationMode == true) cout << " Customer Class is destroyed" << endl;
    }

    void getDetails()
    {
        fstream IDfile;
        fstream UserFile;

        ofstream out("Customers.txt", ios::app); //open file using append mode to write customer details
        {

            do {
                system("cls");
                cout << "\n CUSTOMER ID (23XXXX) : ";
                cin >> cusID;
                if (cusID >= 240000 || cusID < 230000) cout << " ID should be in 23XXXX format! " << endl;
                Sleep(1000);
            } while (cusID >= 240000 || cusID < 230000);

            IDfile.open("CustomerIDs.txt", ios::in);

            if (IDfile.fail())
            {
                cout << "\n FILE ERROR!" << endl;
                cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1000);
                system("CLS");
                customerMenu();
            }

            string line;

            while (!IDfile.eof())
            {
                getline(IDfile, line);

                string format = "23XXXX";
                int intline;

                if (line.size() != 0) {
                    intline = stoi(line);
                    if (cusID == intline)
                    {
                        cout << "\n ID UNAVAILABLE!!! " << endl;
                        cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                        system("CLS");
                        getDetails();
                    }
                }
                else break;
            }
            IDfile.close();


            cout << " USERNAME: ";
            getline(cin >> ws, name);
            cout << " AGE: ";
            cin >> age;
            cout << " MOBILE NUMBER: ";
            getline(cin >> ws, mobileNo);
            cout << " ADDRESS: ";
            getline(cin >> ws, address);
            cout << " GENDER: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\n PROGRESS SUCCESSFULLY SAVED!"
            "\n NOTE: We have saved your details for future purposes.\n" << endl;



        UserFile.open("Usernames.txt", ios::app);
        if (UserFile.is_open()) {
            UserFile << name << endl;
            UserFile.close();
        }

        IDfile.open("CustomerIDs.txt", ios::app);
        if (IDfile.is_open()) {
            IDfile << cusID << endl;
            IDfile.close();
        }

        cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
        Sleep(1000);
        system("CLS");
        customerMenu();
    }

    void showDetails() //function to show old customer records
    {
        ifstream in("Customers.txt");
        {
            if (!in)
            {
                cout << " FILE ERROR!" << endl;
                cout << "\n Redirecting "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                Sleep(1500);
                system("CLS");
                menu();
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }

        cout << "\n\n********** PRESS ANY KEY TO RETURN TO ADMIN MENU **********" << endl;
        char key = _getch();
        cout << "\n Please Wait "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
        Sleep(1500);
        system("CLS");
        menu();
    }
};

int Customer::cusID;

class Cabs
{
public:
    char cabChoice;
    float kilometers;
    float cabCost;
    static float lastCabCost;

    Cabs() {
        if (EducationMode == true) cout << " Cabs Class is created" << endl;
    }

    ~Cabs() {
        if (EducationMode == true) cout << " Cabs Class is destroyed" << endl;
    }

    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "\n---------------- EASY CABS ----------------\n" << endl;
        cout << "\n Rent a tuk - Rs.80 per KM            (1)" << endl;
        cout << " Rent a car - Rs.100 per KM           (2)" << endl;
        cout << " Rent a van - Rs.150 per KM           (3)" << endl;
        cout << " Rent a mini bus - Rs.200 per KM      (4)" << endl;
        cout << " Rent a bus - Rs.250 per KM           (5)" << endl;

        cout << "\n GO BACK                              (B)\n" << endl;
     
        cout << "\n-------------------------------------------\n" << endl;

        cabChoice = _getch();

        if (cabChoice == 'b' || cabChoice == 'B') {
            system("CLS");
            cout << "\n Loading "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1000);
            system("CLS");
            customerMenu();
        }

        cout << "\n\n Distance of the journey in km: ";
        cin >> kilometers;

        char hireCab;

        if (cabChoice == '1') {
            cabCost = kilometers * 80;
            cout << "\n Tour Cost: " << cabCost << " LKR" << endl;
            cout << "\n Hire this cab             (1)";
            cout << "\n Change Vehicle            (2)";
            hireCab = _getch();

            system("CLS");
            if (hireCab == '1') {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired a tuk" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == '2') {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == '2') {
            cabCost = kilometers * 100;
            cout << "\n Tour Cost: " << cabCost << " LKR" << endl;
            cout << "\n Hire this cab             (1)";
            cout << "\n Change Vehicle            (2)";
            hireCab = _getch();

            system("CLS");
            if (hireCab == '1') {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired a car" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == '2') {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        //
        else if (cabChoice == '3') {
            cabCost = kilometers * 150;
            cout << "\n Tour Cost: " << cabCost << " LKR" << endl;
            cout << "\n Hire this Vehicle             (1)";
            cout << "\n Change Vehicle                (2)";
            hireCab = _getch();

            system("CLS");
            if (hireCab == '1') {
                lastCabCost = cabCost;
                cout << "\n You have successfully hired a van" << endl;
                cout << " Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == '2') {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        
        else if (cabChoice == '4') {
            cabCost = kilometers * 200;
            cout << "\n Tour Cost: " << cabCost << " LKR" << endl;
            cout << "\n Hire this cab             (1)";
            cout << "\n Change Vehicle            (2)";
            hireCab = _getch();

            system("CLS");
            if (hireCab == '1') {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired a mini bus" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == '2') {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }

        else if (cabChoice == '5') {
            cabCost = kilometers * 250;
            cout << "\n Tour Cost: " << cabCost << " LKR" << endl;
            cout << "\n Hire this cab             (1)";
            cout << "\n Change Vehicle            (2)";
            hireCab = _getch();

            system("CLS");
            if (hireCab == '1') {
                lastCabCost = cabCost;
                cout << "\n You have successfully hired bus" << endl;
                cout << " Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == '2') {
                cabDetails();
            }
            else {
                cout << "\n Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        
        else {
            cout << "\n Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1000);
            system("CLS");
            customerMenu();
        }

        char input;
        cout << "\n PRESS ANY KEY TO GO TO CUSTOMER MENU ";
        input = _getch();
        system("CLS");

        cout << "\n Loading "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
        Sleep(1000);
        system("CLS");
        customerMenu();
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    char choiceHotel;
    char packChoice1;
    char gotoMenu;
    static float hotelCost;

    Booking() {
        if (EducationMode == true) cout << " Booking Class is created" << endl;
    }

    ~Booking() {
        if (EducationMode == true) cout << " Booking Class is destroyed" << endl;
    }

    void hotels()
    {
        string hotelNo[] = { "MIRISSA", "APPLE TREE", "SIGIRIYA","TRINCOBAY","MAHAWELI" };
        for (int a = 0; a < 5; a++)
        {
            cout <<"\t" << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }

        cout << "\n We have collaborated with the above Hotels only!" << endl;

        cout << "\n ENTER NUMBER OF THE HOTEL FOR THE DETAILS ";
        choiceHotel = _getch();

        system("CLS");

        if (choiceHotel == '1') {
            cout << "-------** WELCOME TO HOTEL MIRISSA **-------\n" << endl;

            cout << "\n Hotel Mirissa Sri Lanka is located in the heart of Mirissa, 200 metres from Whale Watching Mirissa. " << endl;

            cout << "\n Packages offered by Hotel Mirissa:\n" << endl;

            cout << " 1. Bronze Pack : Rs.15000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Accommodation with an outdoor swimming pool\n\t -Free private parking\n\t -A shared lounge and a terrace." << endl;
            cout << "\n 2. Silver Pack : Rs.20000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Offering an outdoor swimming pool and a spa and wellness centre\n\t -Free WiFi access is available in the public areas of the property." << endl;
            cout << "\n 3. Gold Pack : Rs.30000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Free WiFi throughout the hotel\n\t -24h snacks\n\t -Renova Spa \n\t -Wellness Centre & Spa Hotel right on the beach." << endl;

            cout << "\n**** ENTER THE PACKAGE NUMBER OF YOUR CHOICE ******" << endl;
            packChoice1 = _getch();

            if (packChoice1 == '1') {
                hotelCost = 15000.00;
                cout << "\n You have successfully booked Bronze Pack at Hotel Mirissa" << endl;
                cout << " Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '2') {
                hotelCost = 20000.00;
                cout << "\n You have successfully booked Silver Pack at Hotel Mirissa" << endl;
                cout << " Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '3') {
                hotelCost = 30000.00;
                cout << "\n You have successfully booked Gold Pack at Hotel Mirissa" << endl;
                cout << " Goto Menu to take the receipt" << endl;
            }
            else {
                cout << " INVALID INPUT!! Redirecting " << endl;
                cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                hotels();

            }

            cout << "\n PRESS B TO GOTO CUSTOMER MENU ";
            gotoMenu = _getch();

            system("CLS");
            if (gotoMenu == 'b' || gotoMenu == 'B') {
                customerMenu();
            }
            else {
                menu();
            }
        }

        else if (choiceHotel == '2') {
            cout << "-------**WELCOME TO HOTEL APPLE TREE**-------\n" << endl;
            cout << " Packages Offered by APPLE TREE: All includes private villa for each with three meals and following facilities" << endl;
            cout << " Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;



            cout << "\n\n1. Superior Villa For Family Pack :";
            cout << "  Rs.50000.00 for a day" << endl;
            cout << "2. Supeior Villa For Couple Pack :" ;
            cout << "  Rs.40000.00 for a day" << endl;
            cout << "3. Superior Villa For Single Pack :" ;
            cout << "  Rs.30000.00 for a day" << endl;

            cout << "\n***** ENTER THE PACKAGE NUMBER OF YOUR CHOICE ******" << endl;
            packChoice1 = _getch();

            if (packChoice1 == '1') {
                hotelCost = 50000.00;
                cout << "You have successfully booked Family Pack at Apple Tree" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '2') {
                hotelCost = 40000.00;
                cout << "You have successfully booked Couple Pack at Apple Tree" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '3') {
                hotelCost = 30000.00;
                cout << "You have successfully booked Single Pack at Apple Tree" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else {
                cout << " INVALID INPUT!! Redirecting " << endl;
                cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                hotels();
            }

            cout << "\n PRESS B TO GOTO CUSTOMER MENU ";
            gotoMenu = _getch();

            system("CLS");
            if (gotoMenu == 'b' || gotoMenu == 'B') {
                customerMenu();
            }
            else {
                menu();
            }
        }

        else if (choiceHotel == '3') {
            cout << "-------**WELCOME TO HOTEL SIGIRIYA**-------\n" << endl;
            cout << " Set in tropical gardens sigiriya, while hiking the sigiraiya rock " << endl;
            cout << "\n Amazing offer in this summer: Rs.20000.00 for a one day!!!" << endl;

            cout << "\n***** ENTER SPACE TO SELECT THE OFFER ******" << endl;
            packChoice1 = _getch();

            if (packChoice1 == ' ') {
                hotelCost = 20000.00;
                cout << " You have successfully booked Sigiriya Special Pack" << endl;
                cout << " Goto Menu and take the receipt" << endl;
            }
            else {
                cout << " INVALID INPUT!! Redirecting " << endl;
                cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                hotels();
            }

            cout << "\n PRESS B TO GOTO CUSTOMER MENU ";
            gotoMenu = _getch();

            system("CLS");
            if (gotoMenu == 'b' || gotoMenu == 'B') {
                customerMenu();
            }
            else {
                menu();
            }
        }


        else if (choiceHotel == '4') {
            cout << "-------**WELCOME TO HOTEL TRINCOBAY**-------\n" << endl;

            cout << " The garden of food and beverage. Hotel rooms are a second home, only you get to escape." << endl;

            cout << "\n Packages offered by Hotel TrincoBay:\n" << endl;

            cout << "1. Bronze Pack : Rs.14000.00" << endl;
            cout << "\t Facilities:";
            cout << "\n\t Accommodation with an outdoor swimming pool, free private parking, a shared lounge and a terrace." << endl;
            cout << "2. Silver Pack : Rs.18000.00" << endl;
            cout << "\t Facilities:";
            cout << "\tOffering an outdoor swimming pool and a spa and wellness centre, Free WiFi access is available in the public areas of the property." << endl;
            cout << "3. Gold Pack : Rs.28000.00" << endl;
            cout << "\t Facilities:";
            cout << "\tFree WiFi throughout the hotel, 24h snacks, Renova Spa, Wellness Centre & Spa Hotel right on the beach : " << endl;


            cout << "\n***** ENTER THE PACKAGE NUMBER OF YOUR CHOICE ******" << endl;
            packChoice1 = _getch();

            if (packChoice1 == '1') {
                hotelCost = 14000.00;
                cout << "\n You have successfully booked Bronze Pack at TrincoBay" << endl;
                cout << " Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '2') {
                hotelCost = 18000.00;
                cout << "\n You have successfully booked Silver Pack at Hotel TrincoBay" << endl;
                cout << " Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '3') {
                hotelCost = 28000.00;
                cout << "\n You have successfully booked Gold Pack at Hotel TrincoBay" << endl;
                cout << " Goto Menu to take the receipt" << endl;
            }
            else {
                cout << " INVALID INPUT!! Redirecting " << endl;
                cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                hotels();

            }

            cout << "\n PRESS B TO GOTO CUSTOMER MENU ";
            gotoMenu = _getch();

            system("CLS");
            if (gotoMenu == 'b' || gotoMenu == 'B') {
                customerMenu();
            }
            else {
                menu();
            }
        }

        else if (choiceHotel == '5') {
            cout << "-------** WELCOME TO HOTEL MAHAWELI **-------\n" << endl;

            cout << "The of Garden, food and beverage. Hotel rooms are a second home, only you get to escape." << endl;

            cout << " 1. Bronze Pack : Rs.17000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Accommodation with an outdoor swimming pool\n\t -Free private parking\n\t -A shared lounge and a terrace." << endl;
            cout << "\n 2. Silver Pack : Rs.25000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Offering an outdoor swimming pool and a spa and wellness centre\n\t -Free WiFi access is available in the public areas of the property." << endl;
            cout << "\n 3. Gold Pack : Rs.35000.00" << endl;
            cout << " Facilities:";
            cout << "\n\t -Free WiFi throughout the hotel\n\t -24h snacks\n\t -Renova Spa \n\t -Wellness Centre & Spa right on the beach." << endl;


            cout << "\n***** ENTER THE PACKAGE NUMBER OF YOUR CHOICE ******" << endl;
            packChoice1 = _getch();

            if (packChoice1 == '1') {
                hotelCost = 17000.00;
                cout << "\n You have successfully booked Bronze Pack at Hotel Mahaweli" << endl;
                cout << "\n Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '2') {
                hotelCost = 25000.00;
                cout << "\n You have successfully booked Silver Pack at Hotel Mahaweli" << endl;
                cout << "\n Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == '3') {
                hotelCost = 35000.00;
                cout << "\n You have successfully booked Gold Pack at Hotel Mahaweli" << endl;
                cout << "\n Goto Menu to take the receipt" << endl;
            }
            else {
                cout << " INVALID INPUT!! Redirecting " << endl;
                cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                hotels();

            }

            cout << "\n PRESS ANY KEY TO GOTO CUSTOMER MENU ";
            gotoMenu = _getch();

            cout << "\n Loading "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1000);
            system("CLS");
            menu();
        
        }

        else {
            cout << " INVALID INPUT!! Redirecting to Main Menu" << endl;
            cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1500);
            system("CLS");
            menu();
        }
    }
};

float Booking::hotelCost;

class Chargers : public Booking, Cabs, Customer //Multiple Inheritance of some other classes to Chargers
{

public:

    Chargers() {
        if (EducationMode == true) cout << " Chargers Class is created" << endl;
    }

    ~Chargers() {
        if (EducationMode == true) cout << " Chargers Class is destroyed" << endl;
    }

    void printBill()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "************ THE TRAVLLERS APP ***********" << endl;
            outf << "\n**************** RECEIPT ****************" << endl;
            outf << "_________________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "\n***************** THANK YOU ***************\n\n\n" << endl;
        }
        outf.close();
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << " FILE ERROR!" << endl;
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

class Admin : public Customer //inherits Customer
{
public:
    string username;
    string password;

    Admin() {
        if (EducationMode == true) cout << " Admin Class is created" << endl;
    }

    ~Admin() {
        if (EducationMode == true) cout << " Admin Class is destroyed" << endl;
    }

    void AdminMenu() {
        
        int current_line = 0;
        string line;
        char inChoice;

        Customer a2;

        cout << "\n\n ENTER ADMIN USERNAME : ";
        cin >> username;
        cout << " ENTER ADMIN PASSWORD : ";
        cin >> password;

        fstream AdminFile;
        fstream UserFile;
        fstream IDFile;
        fstream ReceiptFile;

        AdminFile.open("AdminUserPassword.txt", ios::in); //read admin data file

        if (AdminFile.fail())
        {
            cout << "\n FILE ERROR!" << endl;
            cout << "\n Redirecting "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
            Sleep(1500);
            system("CLS");
            menu();
        }

        

        while (!AdminFile.eof())
        {
            current_line++;
            getline(AdminFile, line);
            if (current_line == 1) break;
        }


        if (line == username) { 
            cout << "\n USER NAME IS CORRECT" << endl; 

            while (!AdminFile.eof())
            {
                current_line++;
                getline(AdminFile, line);
                if (current_line == 2) break;
            }

            if (line == password) { 
                cout << " PASSWORD IS CORRECT" << endl; 

                cout << "\n Loading "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                Sleep(1500);
                system("CLS");

                cout << "\n******************* ADMIN *****************\n" << endl;
                cout << " DISPLAY OLD CUSTOMERS           (1)" << endl;
                cout << " CLEAR CUSTOMER DATA             (2)" << endl;
                cout << " GO BACK                         (B)" << endl;
                cout << "\n*******************************************\n" << endl;

                inChoice = _getch();

                system("CLS");


                if (inChoice == '1') {
                    a2.showDetails();
                }
                else if (inChoice == '2') {

                    UserFile.open("Usernames.txt", ios::out | ios::trunc);
                    UserFile.close();

                    IDFile.open("CustomerIDs.txt", ios::out | ios::trunc);
                    IDFile.close();

                    fstream CusFile;
                    CusFile.open("Customers.txt", ios::out | ios::trunc);
                    CusFile.close();

                    ReceiptFile.open("receipt.txt", ios::out | ios::trunc);
                    ReceiptFile.close();

                    cout << " SUCCESSFULLY CLEARED EXISTING DATA!!! " << endl;

                    cout << "\n Redirecting to Main Menu "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                    Sleep(1000);
                    system("CLS");
                    menu();
                }
                else if (inChoice == 'b' || inChoice == ' B') {
                    system("CLS");
                    menu();
                }
                else if (inChoice == 'e' || inChoice == ' E') {
                    system("CLS");
                    exitApp();
                }
                else {
                    cout << " INVALID INPUT!! Redirecting to Main Menu" << endl;
                    cout << "\n Please Wait! "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                    Sleep(1500);
                    system("CLS");
                    menu();
                }

            }
            else {
                cout << " PASSWORD IS INCORRECT" << endl;
                cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
                Sleep(1500);
                system("CLS");
                menu();
            }

            AdminFile.close();
        }

        else {
            cout << "\n USER NAME IS INCORRECT" << endl;
            cout << "\n Redirecting "; Sleep(800); cout << ". "; Sleep(800); cout << ". "; Sleep(800); cout << ". ";
            Sleep(1500);
            system("CLS");
            menu();
        }

    }
};

void menu() //menu function contain main menu
{

    char mainChoice;
    char inChoice;
    char gotoMenu;
    string password;
    string username;

    fstream UserFile;
    fstream IDFile;
    fstream ReceiptFile;

    cout << "******************** THE TRAVELLER APP *********************" << endl;
    cout << "\n------------------------ Main Menu -------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\tADMIN                 (1)\t|" << endl;
    cout << "\t|\tCUSTOMER              (2)\t|" << endl;

    cout << "\t|\tEXIT                  (E)\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\n------------------------------------------------------------" << endl;
    cout << "*************************************************************" << endl;

    mainChoice = _getch();

    system("CLS");

    if (mainChoice == '1')
    {
        Admin newAdmin;
        newAdmin.AdminMenu();
        /*
        
        */
    }

    else if (mainChoice == '2') {

        Customer a2;

        string cusUsername, cusPassword;
        char userChoice;

        cout << "******************** THE TRAVELLER APP *********************" << endl;
        cout << "\n------------------------ USER MENU -------------------------" << endl;

        cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
        cout << "\t|\t\t\t\t\t|" << endl;
        cout << "\t|\t\t\t\t\t|" << endl;
        cout << "\t|\t\t\t\t\t|" << endl;

        cout << "\t|     REGISTER AS NEW USER         (1)\t|" << endl;
        cout << "\t|     CONTINUE AS A OLD USER       (2)\t|" << endl;
        cout << "\t|     GO BACK                      (B)\t|" << endl;

        cout << "\t|\t\t\t\t\t|" << endl;
        cout << "\t|\t\t\t\t\t|" << endl;
        cout << "\t|\t\t\t\t\t|" << endl;
        cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

        cout << "\n------------------------------------------------------------" << endl;
        cout << "*************************************************************" << endl;
        userChoice = _getch();

        system("CLS");


        if (userChoice == '1')
        {
            a2.getDetails();

            system("cls");

            customerMenu();
        }
        else if (userChoice == '2')
        {

            cout << " ENTER USERNAME : ";
            getline(cin >> ws, cusUsername);

            UserFile.open("Usernames.txt", ios::in);

            if (UserFile.fail())
            {
                cout << "\n FILE ERROR!" << endl;
                cout << "\n Redirecting "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                Sleep(1500);
                system("CLS");
                menu();
            }

            string line, IDline;

            while (!UserFile.eof())
            {
                getline(UserFile, line);
                if (cusUsername == line) break;
            }
            UserFile.close();

            if (line == cusUsername) { 
                cout << " VALID USERNAME" << endl;

                cout << "\n ENTER ID: ";
                cin >> cusPassword;

                IDFile.open("CustomerIDs.txt", ios::in);

                if (IDFile.fail())
                {
                    cout << "\n FILE ERROR!" << endl;
                    cout << "\n Redirecting "; Sleep(800); cout << ". "; Sleep(800); cout << ". "; Sleep(800); cout << ". ";
                    Sleep(1500);
                    system("CLS");
                    menu();
                }

                while (!IDFile.eof())
                {
                    getline(IDFile, IDline);
                    if (IDline == cusPassword) break;
                }
                IDFile.close();

                if (cusPassword == IDline) {
                    cout << " VALID CUSTOMER ID" << endl;
                    a2.cusID = stoi(cusPassword);

                    Sleep(500);
                    cout << "\n Loading "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                    system("cls");
                    Sleep(1000);
                    customerMenu();

                }
                else {
                    cout << "\t INVALID CUSTOMER ID!" << endl;
                    cout << "\n Redirecting "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                    Sleep(1000);
                    system("CLS");
                    menu();
                }
            }

            else {
                cout << " INVALID USERNAME!" << endl;
                cout << "\n Redirecting "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
                Sleep(1500);
                system("CLS");
                menu();
            }

        }
        else if (userChoice == 'b' || userChoice == 'B')
        {
            cout << "\n Please Wait! "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
            Sleep(1500);
            system("CLS");
            menu();
        }
        else {
            cout << "\n Please Wait! "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
            Sleep(1500);
            system("CLS");
            menu();
        }

    }

    else if (mainChoice == 'e' || mainChoice == 'E')
    {
        system("cls");
        exitApp();
    }

    else
    {
        cout << " INVALID INPUT!!" << endl;
        cout << "\n Please Wait! "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
        Sleep(1500);
        system("CLS");
        exitApp();
    }
}

void customerMenu()
{
    char mainChoice;
    char inChoice;
    char gotoMenu;

    cout << "********************** THE TRAVELLER APP *********************" << endl;
    cout << "\n----------------------- Customer Menu ----------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\tCABS MANAGEAMENT     -> (A)\t|" << endl;
    cout << "\t|\tBOOKINGS MANAGEAMENT -> (B)\t|" << endl;
    cout << "\t|\tCHARGERS & BILL      -> (C)\t|" << endl;
    cout << "\t|\tEXIT                 -> (E)\t|" << endl;

    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\n------------------------------------------------------------" << endl;
    cout << "*************************************************************" << endl;
    mainChoice = _getch();

    system("CLS");
    Cabs a3;
    Booking a4;
    Chargers a5;

    if (mainChoice == 'a' || mainChoice == 'A') {
        a3.cabDetails();
    }

    else if (mainChoice == 'b' || mainChoice == 'B') {
        cout << "-------------> BOOK A HOTEL <---------------\n" << endl;
        a4.hotels();
    }

    else if (mainChoice == 'c' || mainChoice == 'C')
    {
        a5.printBill();
        cout << "\n\n------------- YOUR RECEIPT IS READY! -------------" << endl;
        cout << "------------ Please refer RECEIPT.txt ------------" << endl;

        cout << "\n\n********* PRESS SPACE TO DISPLAY THE BILL *********" << endl;
        cout << "\n------ PRESS B TO GO BACK TO CUSTOMER MENU ------";
        gotoMenu = _getch();

        switch (gotoMenu)
        {
        case ' ':
        {
            cout << "\n Loading Receipt"; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
            Sleep(1500);
            system("CLS");
            a5.showBill();

            cout << "\n\n ------ PRESS ANY KEY TO GO BACK TO MAIN MENU ------";
            gotoMenu = _getch();

            cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1000);
            system("CLS");
            menu();
            
            break;
        }

        case 'b':
        case 'B':
        {
            cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1000);
            system("CLS");
            customerMenu();
            break;
        }

        default:
        {
            system("CLS");
            cout << "\n Redirecting "; Sleep(300); cout << ". "; Sleep(300); cout << ". "; Sleep(300); cout << ". ";
            Sleep(1000);
            system("CLS");
            menu();
            break;
        }
        }
    }

    else if (mainChoice == 'e' || mainChoice == 'E') {
        cout << "\n\n\n*********** THANK YOU FOR USING THE TRAVELLER APP ************\n" << endl;
        Sleep(1500);
        system("CLS");
        exitApp();
    }

    else {
        cout << " INVALID INPUT!!" << endl;
        cout << "\n Please Wait! "; Sleep(500); cout << ". "; Sleep(500); cout << ". "; Sleep(500); cout << ". ";
        Sleep(1500);
        system("CLS");
        exitApp();
    }

}

int exitApp()
{
    system("cls");
    cout << "***************************************************" << endl;
    cout << "\n\n\n\t\t     BYE BYE!!" << endl;
    cout << "        THANK YOU FOR USING TRAVELLERS APP!        \n\n" << endl;
    cout << "***************************************************" << endl;
    return 0;
}

int main()
{
    system("color 0B"); //change terminal color
    cout << "*************** MODE SELECTOR MENU *****************" << endl;
    cout << "\n\n\tREGULAR MODE\t             (R)" << endl;
    cout << "\tEDUCATION MODE               (E)" << endl;
    cout << "\tQUIT                         (Q)" << endl;
    cout << "\n\n***************************************************" << endl;
    char mode;
    mode = _getch();

    switch (mode)
    {
    case 'r':
    case 'R': { EducationMode = false;
        system("cls");
        ManageMenu startObj;
        break; }

    case 'e':
    case 'E': { EducationMode = true;
        system("cls");
        ManageMenu startObj;
        break; }

    case 'q':
    case 'Q': {
        exitApp();
        break;
         }

    default: { system("cls");  cout << " ERROR!! INVALID INPUT" << endl;
        return 0; }
    }

    return 0;
}