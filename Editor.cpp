/* FCAI – OOP Programming – 2023 - Assignment 1
   Program name:             ImageEditor.cpp
   Last Modification Date: 	 9/10/2023
   Asmaa Yasser,  ID:20221022, Group:A Email: asmaayasser200317@gmail.com
   Esraa Mahmoud, ID:20220058, Group:A Email: esraamahmoudd18@gmail.com
   Yasmeen Yehia, ID:20220379, Group:A Email: yasmeenelshamy044@gmail.com
   Purpose: Apply Filters to Images
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
int num;

void loadImage ();
void saveImage ();
void doSomethingForImage ();

int main()
{
  loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char image1FileName[100];
   char image2FileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> image1FileName;

   // Add to it .bmp extension and load image
   strcat (image1FileName, ".bmp");
   readGSBMP(image1FileName, image1);

   cout<<"Please select a filter to apply : \n";
   cout<<"1-\tBlack & White Filter\n"
         "2-\tInvert Filter\n"
         "3-\tMerge Filter \n"
         "4-\tFlip Image\n"
         "5-\tRotate Image\n"
         "6-\tDarken and Lighten Image \n";

    cin>>num;
    if (num==3){
   //Get gray scale image file name to merge with it
   cout<< "Please enter name of image file to merge with:  ";
   cin>> image2FileName;

   // Add to it .bmp extension and load image
   strcat (image2FileName, ".bmp");
   readGSBMP(image2FileName, image2);
    }
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image3);
}

//_________________________________________

void flip() {
    cout<<"Flip (h)orizontally or (v)ertically ?\n";
    char s;
    cin >> s;
    if (s == 'v') {
        for (int i = 0; i < (SIZE + 1) / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                //it replaces each pixel with the corresponding one in the image vertically
                long long temp = image1[i][j];
                image3[i][j] = image1[SIZE - 1 - i][j];
                image3[SIZE - 1 - i][j] = temp;
            }
        }
    } else if (s == 'h') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < (SIZE + 1) / 2; j++) {
                //it will swap each pixel with another horizontally
                long long temp = image1[i][j];
                image3[i][j] = image1[i][SIZE - 1 - j];
                image3[i][SIZE - 1 - j] = temp;
            }
        }
    }
}

void rotate()
{
    //declaration for new image
    int photo[SIZE][SIZE];

    int angle;
    //message to enter angle
    cout<<"rotate(90),(180)or(270)?\n";
    cin>>angle;

    //to loop for a new image and old image in a matrix
    for (int i= 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(angle==90) {
                photo[j][SIZE - 1 - i] = image1[i][j];
            }
            if(angle==180)
            {
                photo[SIZE - 1 - i][SIZE - 1 - j] = image1[i][j];
            }
            if(angle==270){
                photo[SIZE - 1 - j][i] = image1[i][j];
            }

        }
    }

    //this loop to make change in a old image to be a new image
    for (int i= 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image3[i][j] = photo[i][j];
        }
    }
}

//_________________________________________

void doSomethingForImage() {
    char x;

    if (num==4){
        flip();
    }

    if(num==5){
        rotate();
    }

    if (num==6){
        cout<<"Do you want to (d)arken or (l)ighten? \n";
        cin>>x;}


  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if(num==1){
            if(image1[i][j]>127) {
                //it changes color of pixel into white
                image3[i][j]=255;
            } else{
                //it changes color of pixel into black
                image3[i][j]=0;
            }
        }

        //condition for invert filter
        if (num==2)
            image3[i][j] = 255 - image1[i][j];

        if (num==3)
            //Merge two images
            image3[i][j]=(image1[i][j]+image2[i][j])/2;

        if (num==6 && x=='d')
            //Make the image darker by 50%
            image3[i][j]=image1[i][j]/2;

        if (num==6 && x=='l')
            //Make the image lighter by 50%
            image3[i][j]=(255-image1[i][j])/2+image1[i][j];

        }
        
      }

    }
