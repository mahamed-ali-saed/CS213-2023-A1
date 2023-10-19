// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				photo_editor_v1.cpp
// Last Modification Date:	7/10/2023
// Author1 and ID and Group:	mohamed ali saed  20220300 mahamedali.study@gmail.com
// Author2 and ID and Group:	Ahmed Rabie Ahmed 20221007 a.rabie.ahmed@gmail.com
// Author3 and ID and Group:	Ziad Tawfik AbdElNabi 20221066 ziadtawfik2003@gmail.com
// comment  comeet 
// Purpose:apply  filters to photo

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char cimage[SIZE][SIZE];  //copy of image to use

void loadImage ();
void load_another_Image ();
void saveImage ();
void Rotate_Image();
void Merge_Image();
void Black_and_White();
void Invert_Image();
void Flip_Image();
void Darken_and_Lighten_Image();
void Shuffle_Image();
void Enlarge_Image();
void Detect_Image_Edges();
void Crop_Image();

int main()
{
  int chosen;
  cout<<"welcome user \n";
  loadImage();
  cout<<"Please select a filter to apply or 0 to exit: \n";
    cout<<"1-Black & White Filter\n"
          "2-Invert Filter\n"
          "3-Merge Filter\n"
          "4-Flip Image\n"
          "5-Darken and Lighten Image\n"
          "6-Rotate Image\n"
          "7-Detect_Image_Edges();\n"
          "8-Enlarge_Image();\n"

          "11-Shuffle_Image();\n"
          "13-Crop_Image\n"
          "15 - Save the image to a file\n"
          "0-Exit\n";

    while (cin>>chosen,chosen){          //after cin we check if chosen == 0 while break
            switch (chosen) {            // switch case for every filter
                case 1:
                    Black_and_White();
                    break;
                case 2:
                    Invert_Image();
                    break;
                case 3:
                    load_another_Image ();
                    Merge_Image();
                    break;
                case 4:
                    Flip_Image();
                    break;
                case 5:
                    Darken_and_Lighten_Image();
                    break;
                case 6:
                    Rotate_Image();
                    break;
                case 7:
                    Detect_Image_Edges();
                    break;
                case 8:
                    Enlarge_Image();
                    break;
                case 9:

                    break;
                case 10:

                    break;
                case 11:
                    Shuffle_Image();
                    break;
                case 12:

                    break;
                case 13:
                    Crop_Image();
                    break;
                case 14:

                    break;
                case 15:
                    saveImage ();
                    break;



            }
        cout<<"Please select a filter to apply or 0 to exit: \n";
        cout<<"1-Black & White Filter\n"
              "2-Invert Filter\n"
              "3-Merge Filter\n"
              "4-Flip Image\n"
              "5-Darken and Lighten Image\n"
              "6-Rotate Image\n"
              "7-Detect_Image_Edges();\n"
              "8-Enlarge_Image();\n"

              "11-Shuffle_Image();\n"

              "15 - Save the image to a file\n"
              "0-Exit\n";
    }

  return 0;
}
//______________________________________________________________________________________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_____________________________________________________________________________________________________________________
void load_another_Image () {
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, cimage);
}
//__________________________________________________________________________________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________(1)_________________________________________________________________________
void Black_and_White() {

  //convert every pixel to nearest color black or white
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        if (image[i][j] >= 128)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
  }
}
//_________________________________________(2)_________________________________________________________________________
void Invert_Image(){
    //invert image by 255 - pixel
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
                image[i][j] = 255 - image[i][j];
        }
    }
}
//_________________________________________(3)_________________________________________________________________________
void Merge_Image(){
    //merge by get the middle of 2 pixel in two image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] =  (cimage[i][j]+image[i][j])/2;
        }
    }
}
//_________________________________________(4)_________________________________________________________________________
void Flip_Image(){
    // make copy of the image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    // after user choose h or v we loop and make pixel down up and so on
    char c;cout<<"Flip (h)orizontally or (v)ertically ?: ";cin>>c;
    if(c=='h'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[i][SIZE-j-1];
            }
        }
    }
    else{
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[SIZE-i-1][j];
            }
        }
    }
}
//_________________________________________(5)_________________________________________________________________________
void Darken_and_Lighten_Image(){
    // user choose type
    char c;cout<<"Do you want to (d)arken or (l)ighten? ";cin>>c;
    //to make it lighten we merge every pixel with wight pixel
    if(c=='l'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                    image[i][j] = (image[i][j]+255)/2;

            }
        }
    }
    //to make it darken we merge every pixel with black pixel
    else{
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = (image[i][j]+0)/2;
            }
        }
    }
}
//_________________________________________(6)__________________________________________________________________________
void Rotate_Image(){
    //user chose angle
    int angel;cout<<"Rotate (90), (180) or (360) degrees? ";cin>>angel;
    //we make copy of image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    //we rotate every pixel by angel
    if(angel==90){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[SIZE-j-1][i];
            }
        }
    }
    else if(angel==180){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[SIZE-i-1][SIZE-j-1];
            }
        }
    }
    else if(angel==270){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[j][SIZE-i-1];
            }
        }
    }
}
//_________________________________________(7)__________________________________________________________________________
void Detect_Image_Edges(){
    Black_and_White();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    for (int i = 1; i < SIZE-1; i++) {
        for (int j = 1; j< SIZE-1; j++) {
            if(cimage[i][j]==0 and (cimage[i-1][j]==255 or cimage[i+1][j]==255 or cimage[i][j-1]==255 or cimage[i][j+1]==255)){
                image[i][j]=0;
            }
            else{
                image[i][j]=255;
            }
        }
    }
}
//_________________________________________(8)__________________________________________________________________________
void Enlarge_Image(){
    int cc,c,ii,jj,part;cout<<"Which quarter to enlarge 1, 2, 3 or 4? ";cin>>part;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    ii=0,jj=0;
    if(part==1){
        for (int i = 0; i < SIZE; i+=2) {
            jj=0;
            ii++;
            for (int j = 0; j< SIZE; j+=2) {
                image[i][j] = cimage[ii][jj];
                image[i+1][j] = cimage[ii][jj];
                image[i][j+1] = cimage[ii][jj];
                image[i+1][j+1] = cimage[ii][jj];
                jj++;
            }
        }
    }
    else if(part==2){
        ii=0;
        for (int i = 0; i < SIZE; i+=2) {
            jj=127;
            ii++;
            for (int j = 0; j< SIZE; j+=2) {
                image[i][j] = cimage[ii][jj];
                image[i+1][j] = cimage[ii][jj];
                image[i][j+1] = cimage[ii][jj];
                image[i+1][j+1] = cimage[ii][jj];
                jj++;
            }
        }
    }
    else if(part==3){
        ii=127;
        for (int i = 0; i < SIZE; i+=2) {
            jj=0;
            ii++;
            for (int j = 0; j< SIZE; j+=2) {
                image[i][j] = cimage[ii][jj];
                image[i+1][j] = cimage[ii][jj];
                image[i][j+1] = cimage[ii][jj];
                image[i+1][j+1] = cimage[ii][jj];
                jj++;
            }
        }
    }
    else if(part==4){
        ii=127;
        for (int i = 0; i < SIZE; i+=2) {
            jj=127;
            ii++;
            for (int j = 0; j< SIZE; j+=2) {
                image[i][j] = cimage[ii][jj];
                image[i+1][j] = cimage[ii][jj];
                image[i][j+1] = cimage[ii][jj];
                image[i+1][j+1] = cimage[ii][jj];
                jj++;
            }
        }
    }
}

//_________________________________________(9)__________________________________________________________________________


//_________________________________________(10)__________________________________________________________________________



//_________________________________________(11)__________________________________________________________________________
void Shuffle_Image(){

    //we make copy of image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    // input the new order of part
    int p1,p2,p3,p4,pi,pj;
    cout<<"New order of quarters ? ";cin>>p1>>p2>>p3>>p4;
    if(p1==1){
        pi=0;
        pj=0;
    }
    else if(p1==2){
        pi=0;
        pj=128;
    }
    else if(p1==3){
        pi=128;
        pj=0;
    }
    else if(p1==4){
        pi=128;
        pj=128;
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j< 128; j++) {
            image[i][j] = cimage[i+pi][j+pj];
        }
    }
    if(p2==1){
        pi=0;
        pj=-128;
    }
    else if(p2==2){
        pi=0;
        pj=0;
    }
    else if(p2==3){
        pi=128;
        pj=-128;
    }
    else if(p2==4){
        pi=128;
        pj=0;
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 128; j < 256; j++) {
            image[i][j] = cimage[i+pi][j+pj];
        }
    }
    if(p3==1){
        pi=-128;
        pj=0;
    }
    else if(p3==2){
        pi=-128;
        pj=128;
    }
    else if(p3==3){
        pi=0;
        pj=0;
    }
    else if(p3==4){
        pi=0;
        pj=128;
    }
    for (int i = 128; i < 256; i++) {
        for (int j = 0 ; j< 128; j++) {
            image[i][j] = cimage[i+pi][j+pj];
        }
    }
    if(p4==1){
        pi=-128;
        pj=-128;
    }
    else if(p4==2){
        pi=-128;
        pj=0;
    }
    else if(p4==3){
        pi=0;
        pj=-128;
    }
    else if(p4==4){
        pi=0;
        pj=0;
    }
    for (int i = 128 ; i < 256; i++) {
        for (int j = 128 ; j< 256; j++) {
            image[i][j] = cimage[i+pi][j+pj];
        }
    }

}
//_________________________________________(12)_________________________________________________________________________
//_________________________________________(13)_________________________________________________________________________
//_________________________________________(14)_________________________________________________________________________
void Crop_Image(){
    int l,m;
    cout<<"cin l and m :";cin>>l>>m;
    //we make copy of image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    for (int i = 0 ; i < SIZE; i++) {
        for (int j = 0 ; j< SIZE; j++) {
            image[i][j] = 255;
        }
    }
    for (int i = l; i < SIZE-l; i++) {
        for (int j = m ; j< SIZE-m; j++) {
            image[i][j] = cimage[i][j];
        }
    }
}
//_________________________________________(15)_________________________________________________________________________






