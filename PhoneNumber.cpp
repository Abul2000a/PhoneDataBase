#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class Contact {
    private:
    string name;
    string surname;
    string phnumber;

    public:
    void addData();
    void print(Contact);
    void readData();
    string searchData();
    void deleteData();
    void updateData();
};

void Contact::addData() {
    Contact man;
    cout << "\n\tEnter Name : ";
    cin.get();
    getline(cin, man.name);
    cout << "\n\tEnter Surname : ";
    cin >> man.surname;
    cout << "\n\tEnter Phone Number : ";
    cin >> man.phnumber;

    ofstream write;
    write.open("DataBase.txt", ios::app);
    
    write << "\n\n" << man.name ;
    write << "\n" << man.surname;
    write << "\n" << man.phnumber;

    write.close();

    cout << "\n\tInformation saved to file";
}

void Contact::print(Contact s) {
    cout << "\n\t---Information---";
    cout << "\n\tName is : " << s.name;
    cout << "\n\tSurname  is : " << s.surname;
    cout << "\n\tPhone Number  is : " << s.phnumber;
}

void Contact::readData() {
    Contact man;
    ifstream read;
    read.open("DataBase.txt");
    while (!read.eof()) {
        read >> man.name;
        read.ignore();
        getline(read, man.surname);
        getline(read, man.phnumber);
        print(man);
    }
    read.close();
}

string Contact::searchData() {
    string id;
    cout << "\n\tEnter Name you want to search : ";
    cin >> id;
    string id_2;
    cout << "\n\tEnter Surname you want to search : ";
    cin >> id_2;
    Contact man;
    ifstream read;
    read.open("DataBase.txt");
    while (!read.eof()) {
        read >> man.name;
        read >> man.surname;
        read.ignore();
        getline(read, man.phnumber);

        if (man.name == id && man.surname == id_2){
            print(man);
        }
    }
    return id;
}

void Contact::deleteData() {
    string id = Contact::searchData();
    cout << "\n\tDo You want to delete Data (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Contact man;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("DataBase.txt");
        while (!read.eof()) {
            read >> man.name;
            read.ignore();
            getline(read, man.surname);
            getline(read, man.phnumber);
            
            if (man.name != id) {
                tempFile << "\n" << man.name;
                tempFile << "\n" << man.surname;
                tempFile << "\n" << man.phnumber;

            }
        }
        read.close();
        tempFile.close();
        remove("DataBase.txt");
        rename("temp.txt", "DataBase.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tData not deleted";
    }
}

void Contact::updateData() {
    string id = Contact::searchData();
    cout << "\n\t Do You want to update Data? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Contact newData;
        cout << "\n\tEnter Name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Surname : ";
        cin >> newData.surname;
        cout << "\n\tEnter Phone Number : ";
        cin >> newData.phnumber;
       
        Contact man;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("DataBase.txt");
        while (!read.eof()) {
            read >> man.name;
            read.ignore();
            getline(read, man.surname);
            getline(read, man.phnumber);
           
            if (man.name != id) {
                tempFile << "\n" << man.name;
                tempFile << "\n" << man.surname;
                tempFile << "\n" << man.phnumber;
                
            }
            else {
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.surname;
                tempFile << "\n"<< newData.phnumber;

            }
        }
        read.close();
        tempFile.close();
        remove("DataBase.txt");
        rename("temp.txt", "DataBase.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tData not deleted";
    }
}

int main()
{


    while (true) {
        Contact book;
        cout << "\n\t1.Add Number";
        cout << "\n\t2.See All";
        cout << "\n\t3.Search Data";
        cout << "\n\t4.Delete Data";
        cout << "\n\t5.Update Data";
        cout << "\n\t6.Exit";
        int choice;
        cout << "\n\tChoose Option >>: ";
        cin >> choice;
        switch (choice) {
        case 1:
            book.addData();
            break;
        case 2:
            book.readData();
            break;
        case 3:
            book.searchData();
            break;
        case 4:
            book.deleteData();
            break;
        case 5:
            book.updateData();
            break;
        case 6:
        cout << " !!!-------- Exiting -------!!!";
        return 0;
            break;
        }
        
    }

}