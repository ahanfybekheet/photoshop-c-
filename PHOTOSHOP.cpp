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
unsigned char image2[SIZE][SIZE];
unsigned char image3[127][127];
char userInput;


void menuDisplay();
void loadImage();
void saveImage();
void BW();
void invertFilter();
void mergeImage();
void flipImage();
void darkenAndLightenImage();
void rotate();
void enlarge();


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
    case 50:
        invertFilter();
        break;
    case 51:
        mergeImage();
        break;
    case 52:
        flipImage();
        break;
    case 53:
        darkenAndLightenImage();
        break;
    case 54:
        rotate();
        break;
    case 56:
        enlarge();
        break;
    default:
        break;
    }
    saveImage();
    return 0;
}

//_________________________________________
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
        cout << "--> ";

        cin >> userInput;
        if ((userInput >= 48 && userInput <= 57) || (userInput == 97 || userInput == 98 || userInput == 99 || userInput == 115))
            break;
        else {
            cout << "Please enter valid input from the menu!!\n\n";
            cin.ignore();
        }
    }
}
//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
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
    if (userInput == '4' || userInput == '6' || userInput == '8' ){
        writeGSBMP(imageFileName, image2);
    }
    else {
        writeGSBMP(imageFileName, image);
    }
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
//_________________________________________
void invertFilter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}
//_________________________________________
void mergeImage(){
    //Load seconde Image
    char mergedImageFileName[100];

    // Get the seconde photo that want to be merged
    cout << "Please enter file name of the image to merge: ";
    cin >> mergedImageFileName;

    // Add to it .bmp extension and load image
    strcat(mergedImageFileName, ".bmp");
    readGSBMP(mergedImageFileName, image2);

    //Merge Two Photos
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j] + (image2[i][j]/2);
        }
    }
}
//_________________________________________
void flipImage(){
    int choose;
    while (true)
    {
        cout << "Flip (1) for horizontally or (2) for vertically: ";
        cin >> choose;
        if (choose == 1 || choose == 2){
            break;
        }
        else {
            cout << "Invalid input.";
            cin.ignore();
        }
    }
    if (choose == 1){
        for (int i =0 ;i <255 ;i++){
            for (int j =255 ;j > 0 ;j--){
                image2[i][255 - j] = image [i][j];
                
            }
        } 
    }
    else {
        for (int i =0 ;i <255 ;i++){
            for (int j =0 ;j <255 ;j++){
                image2[i][j] = image [255-i][j];
            }
        } 
    }
}
//_________________________________________
void darkenAndLightenImage(){
    int chooses;
    cout<<"Please Choose;"<<endl;
    while (true){
        cout<<"\t1- Light"<<endl;
        cout<<"\t2- Dark"<<endl;
        cout<<"--> ";
        cin>>chooses;

        if (chooses == 1 || chooses==2)
            break;
        else{
            cout<<"Please choose valid input\n";
            cin.ignore();
        }
    }
    if (chooses == 1 ){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    // if (image[i][j]  + 0.5*image[i][j] > 255 || image[i][j]  + 0.5*image[i][j] == 255 )
                        // image[i][j] = 255;
                    // else
                        // image[i][j] += 0.5*image[i][j];
                    if (image[i][j]<127)
                        image[i][j] += 127;
                    else
                        image[i][j] =255;
            }
        }
    }else{
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    image[i][j] -=  0.5*(image[i][j]);
            }
        }
    }

}
//_________________________________________
void rotate(){
    int rot;
     while (true){
        cout << "Enter the degree from (90, 180, 270) to rotate: ";
        cin>>rot;

        if (rot == 90 || rot == 180 || rot == 270)
            break;
        else{
            cout<<"Please enter valid number\n";
            cin.ignore();
        }
    }
    if (rot == 90){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j <= SIZE - i; j++) {
                swap(image[i][j], image[SIZE - j][SIZE - i]);
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[255-i][j];
            }
        }
    }
    else if (rot == 180){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[255-i][255-j];
            }
        }
    }
    else if (rot == 270){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j <= SIZE - i; j++) {
                swap(image[i][j], image[SIZE - j][SIZE - i]);
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][255-j];
            }
        }
    }
}
//_________________________________________
void enlarge(){
    int quarter;
    while (true)
    {
        cout << "Please enter the Quarter number (1, 2, 3, 4) you want to enlarge: ";
        cin >> quarter;
        if (quarter == 1 || quarter == 2 || quarter == 3 || quarter == 4){
            break;
        }
        else{
            cout << "Please enter valid number\n";
            cin.ignore();
        }
    }
    if (quarter == 1){
        for (int i = 0; i < 127; i ++){
            for (int j = 0; j < 127; j ++){
                image2[i][j] = image[i][j];
                
                
            }
        }
    }
    if (quarter == 2){
        for (int i = 0; i < 127; i ++){
            for (int j = 127; j < 255; j ++){
                image2[i][j] = image[i][j];
            }
        }
    }
    if (quarter == 3){
        for (int i = 127; i < 255; i ++){
            for (int j = 0; j < 127; j ++){
                image2[i][j] = image[i][j];
            }
        }
    }
    if (quarter == 4){
        for (int i = 127; i < 255; i ++){
            for (int j = 127; j < 255; j ++){
                image2[i][j] = image[i][j];
            }
        }
    }
}