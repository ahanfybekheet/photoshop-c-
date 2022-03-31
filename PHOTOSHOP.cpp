// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
char userInput;


void menuDisplay();
void loadImage();
void saveImage();
void BW();
int main()
{
    cout << "Ahlan ya user ya habibi\n";
    loadImage();
    menuDisplay();
    switch (userInput)
    {
    case 48: // if userInput == 0
        exit(0);
        break;
    case 49:
        BW();
        break;
    default:
        break;
    }
    saveImage();
    return 0;
}

//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Ahlan ya user ya habibi";
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void BW() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127) {
                image[i][j] = 255;
            }
            else {
                image[i][j] = 0;
            }

        }
    }
}


void menuDisplay() {

    cout << "Please select a filter to apply or 0 to exit: \nNote: The Answer Is Only One Char 'The App Will Take Only First Char'\n";
    while (true) {
        cout << "\t1- Black & White Filter" << endl;
        cout << "\t2- Invert Filter" << endl;
        cout << "\t3- Merge Filter" << endl;
        cout << "\t4- Flip Image" << endl;
        cout << "\t5- Darken and Lighten Image" << endl;
        cout << "\t6- Rotate Image" << endl;
        cout << "\t7- Detect Image Edges" << endl;
        cout << "\t8- Enlarge Image" << endl;
        cout << "\t9- Shrink Image" << endl;
        cout << "\ta- Mirror 1/2 Image" << endl;
        cout << "\tb- Shuffle Image" << endl;
        cout << "\tc- Blur Image" << endl;
        cout << "\ts- save the image to file" << endl;
        cout << "\t0- Exit" << endl;
        cout << "-->";

        cin >> userInput;
        if ((userInput >= 48 && userInput <= 57) || (userInput == 97 || userInput == 98 || userInput == 99 || userInput == 115))
            break;
        else {
            cout << "Please enter valid input from the menu!!\n\n";
            cin.ignore();
        }
    }
}