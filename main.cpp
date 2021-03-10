//Name-Tasfique Enam
//Student ID- 5886429
//Assignment 1
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <iomanip>
#include "extention.h"

using namespace std;


int main () {
    int option;
    int n;
    int input;
    string fileName;

    int** magicSquareArray;
    fstream ifs;
    bool check = false;
    bool check2=false;



    do { //do loop for menu function.
        cout << endl;
        cout << "Options-----------------" << endl;
        cout << "1- Construct Magic Square" << endl;
        cout << "2- Check if it is Magic Square or not" << endl;
        cout << "3- Generate Second Magic Square" << endl;
        cout << "0- Quit" << endl;

        cout << "\nEnter option: ";
        cin >> option;


        switch(option) { //switch statement

            case 1: { //case 1 from the menu
                cout << "Enter an odd number ";
                cin >> setw(5) >> n;
                while(n!=3 && n!=5 && n!=7 && n!=9) { //while loop for validation.
                    cout << "Invalid input please, try again. "<< endl;
                    cout << "Enter an odd number ";
                    cin >> setw(5) >> n;
                }
                magicSquareArray = new int *[n];

                for(int i=0; i<n; ++i) {
                    magicSquareArray[i] = new int [n];
                }
                cout << setw(5) << n << endl;
                cout << " " << endl;
                constructMagicSquare(n, magicSquareArray);

                cout << "Do you want to Save this Magic Square? Enter 1 for Yes or 0 for No" << endl;
                cin >> input;
                while(input!=0 && input!=1) {
                    cout << "Invalid Input, Try again. " << endl;
                    cout << "Do you want to Save this Magic Square? Enter 1 for Yes or 0 for No" << endl;
                    cin >> input;
                }
                if(input == 1) { //if option1 was selected.
                    cout << "Enter the file Name " << endl;
                    cin >> fileName;

                    fileName = fileName + ".txt";
                    ifs.open(fileName.c_str(), ios::out);
                    if (ifs.is_open()) {
                        ifs << n;
                        for(int i=0; i<n; i++) {
                                ifs << endl;
                            for(int j=0; j<n; j++) {
                                ifs<<magicSquareArray[i][j]<<" ";
                            }
                        }
                        cout << "Successfully written. " << endl;
                        ifs.close();
                    } else {
                        cout << "Unable to open the file." << endl;
                    }
                } else if(input == 0){
                    cout << "File haven't been written" << endl;
                }
                for(int i = 0; i < n; ++i) {
                    delete[] magicSquareArray[i];
                }
                //Free the array of pointers
                delete[] magicSquareArray;
                check = false;
                check2 =true;

            } break;

            case 2: {

                    if(check2==true)
                    {
                        magicSquareArray = new int *[n];

                    for(int i=0; i<n; ++i) {
                        magicSquareArray[i] = new int [n];
                    }
                    cout << "Enter the name of the TXT File you want to open. " << endl;
                    cin >> fileName;
                    fileName = fileName + ".txt";

                    ifs.open(fileName.c_str(), ios::in);
                    if(!ifs) {
                        cout << "File could not be opened. " << endl;
                    } else {
                        ifs >> n;
                        for(int i=0; i<n; i++) {
                                //ifs >> endl;
                            for (int j=0; j<n; j++) {
                                ifs >> magicSquareArray[i][j]; ///do i need to create an array for this or not?
                            }
                        }
                        if(isMagicSquare(n, magicSquareArray)) {
                            cout << "It is a Magic Square" << endl;
                            check=true;
                        } else {
                            cout << "It is not a Magic Square" << endl;

                        }
                        ifs.close();
                    }
                    for(int i = 0; i < n; ++i) {
                        delete[] magicSquareArray[i];
                    }
                    }
                    else{
                        cout << "Please, create a Magic Square first!" << endl;
                    }
                    //Free the array of pointers
                    delete[] magicSquareArray;


                    }
                     break;

            case 3: {

                if(check == true) {
                    magicSquareArray = new int *[n];

                    for(int i=0; i<n; ++i) {
                        magicSquareArray[i] = new int [n];
                    }

                    fileName = fileName + ".txt";
                    if(!ifs) {
                        cout << "File could not be opened. " << endl;
                    } else {
                        constructMagicSquare(n, magicSquareArray);
                        ifs >> n;
                        for(int i=0; i<n; i++) {
                             for (int j=0; j<n; j++) {
                                ifs >> magicSquareArray[i][j];
                             }
                        }
                        cout << " \n" << endl;
                        createAnotherMagicSquare(n, magicSquareArray);
                        ifs.close();
                    }
                    //createAnotherMagicSquare(n, magicSquareArray);
                     for(int i = 0; i < n; ++i) {
                        delete[] magicSquareArray[i];
                    }
                    //Free the array of pointers
                    delete[] magicSquareArray;

                } else if (check == false) {
                    cout << "Your TXT File doesn't have a Magic Square " << endl;
                }

            } break;

            case 0: {
                cout << "Thanks for using the Program " << endl;
                exit(0);
            }

        }

    }while(option>=0 && option<=3);

}

