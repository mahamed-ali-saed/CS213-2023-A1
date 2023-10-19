// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				photo_editor_v1.cpp
// Last Modification Date:	7/10/2023
// Author1 and ID and Group:	mohamed ali saed  20220300 mahamedali.study@gmail.com
// Author2 and ID and Group:	Ahmed Rabie Ahmed 20221007 a.rabie.ahmed@gmail.com
// Author3 and ID and Group:	Ziad Tawfik AbdElNabi 20221066 ziadtawfik2003@gmail.com

// Purpose:apply  filters to photo

#include <iostream>
#include <vector>
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
void shrink();
void Mirror_Image ();
void Blur_Image();
void Crop_Image();
void Skew_Horizontally();
void Skew_Vertically();



int main()
{
  int chosen;
  cout<<"welcome user \n";
  loadImage();
  cout<<"Please select a filter to apply or 0 to exit: \n"
          "1-Black & White Filter\n"
          "2-Invert Filter\n"
          "3-Merge Filter\n"
          "4-Flip Image\n"
          "5-Darken and Lighten Image\n"
          "6-Rotate Image\n"
          "7-Detect Image Edges\n"
          "8-Enlarge Image\n"
          "9-shrink\n"
          "10-Mirror Image\n"
          "11-Shuffle Image\n"
          "12-Blur Image\n"
          "13-Crop Image\n"
          "14-Skew Horizontally \n"
          "15-Skew Vertically\n"
          "16-Save the image to a file\n"
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
                    shrink();
                    break;
                case 10:
                    Mirror_Image();
                    break;
                case 11:
                    Shuffle_Image();
                    break;
                case 12:
                    Blur_Image();
                    break;
                case 13:
                    Crop_Image();
                    break;
                case 14:
                    Skew_Horizontally();
                    break;
                case 15:
                    Skew_Vertically();
                    break;
                case 16:
                    saveImage ();
                    break;



            }
        cout<<"Please select a filter to apply or 0 to exit: \n"
              "1-Black & White Filter\n"
              "2-Invert Filter\n"
              "3-Merge Filter\n"
              "4-Flip Image\n"
              "5-Darken and Lighten Image\n"
              "6-Rotate Image\n"
              "7-Detect Image Edges\n"
              "8-Enlarge Image\n"
              "9-shrink\n"
              "10-Mirror Image\n"
              "11-Shuffle Image\n"
              "12-Blur Image\n"
              "13-Crop Image\n"
              "14-Skew Horizontally\n"
              "15-Skew Vertically\n"
              "16-Save the image to a file\n"
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
    if(c=='v'){
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
void shrink() {
    vector<vector<int>>visited(256,vector<int>(256));
    cout << "Enter (1/2) to shrink the image by half or (1/3) or (1/4) : \n";
    string s ;
    cin >> s;
    int v = 0;
    if (s == "1/2") {
        for (int i = 0; i < 128; ++i) {
            int u = 0;
            for (int j = 0; j < 128; ++j) {
                int ave = (image[v][u] + image[v][u + 1] + image[v + 1][u + 1] + image[v + 1][u]) / 4;
                cimage[i][j] = ave;
                visited[i][j] = 1;
                u += 2;
            }
            v += 2;
        }
    }
    else if (s == "1/3") {
        for (int i = 0; i < 87; ++i) {
            int u = 0;
            for (int j = 0; j < 87; ++j) {
                int ave = (image[v][u] + image[v][u + 1] + image[v + 1][u + 1] + image[v + 1][u]) / 4;
                cimage[i][j] = ave;
                visited[i][j] = 1;
                u += 3;
            }
            v += 3;
        }
    }
    else {
        for (int i = 0; i < 64; ++i) {
            int u = 0;
            for (int j = 0; j < 64; ++j) {
                int ave = (image[v][u] + image[v][u + 1] + image[v + 1][u + 1] + image[v + 1][u]) / 4;
                cimage[i][j] = ave;
                visited[i][j] = 1;
                u += 4;
            }
            v += 4;
        }
    }
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (!visited[i][j])
                cimage[i][j] = 255;
        }
    }
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {

                image[i][j] = cimage[i][j];
        }
    }
}
//_________________________________________(10)__________________________________________________________________________
void Mirror_Image(){
    cout << "Enter (u) to mirror the upper half , Enter (d) to lower half , Enter (r) to right half and (l) to lift half : \n";
    char c;
    cin >> c; // we take the type of operations the user want
    // make copy of the image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            cimage[i][j] = image[i][j];
        }
    }
    if (c == 'd') {
        // we use the Flip function
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[SIZE-i-1][j];
            }
        }
        for (int i = SIZE / 2; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = cimage[i][j];
                // reuse  the saved half of the image
            }
        }
    }
    else if (c == 'u') {
        //Flip('V');
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[SIZE-i-1][j];
            }
        }
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = cimage[i][j];
            }
        }
    }
    else if (c == 'r') {
          //Flip('H');
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    image[i][j] = cimage[i][SIZE-j-1];
                }
            }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = (SIZE / 2); j < SIZE; ++j) {
                image[i][j] = cimage[i][j];
            }
        }
    }
    else if(c=='l'){
        //Flip('H');
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j] = cimage[i][SIZE-j-1];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                image[i][j] = cimage[i][j];
            }
        }
    }
}
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
void Blur_Image(){


    for (int i = 0; i < SIZE   ; i++) {
        for (int j = 0; j < SIZE  ;  j++) {
            int sum = 0,cnt= 0;
            // the following loop takes a (9 * 9) square metrics of pixels
            for (int k = -3; k < 4; ++k) {
                for (int l = -3; l < 4; ++l) {
                    if (i + k < 0 || i + k > SIZE- 1 || j +l < 0 || j +l > SIZE-1)
                        continue;
                    sum += image[i+k][j+l];
                    cnt++;
                }
            }
            cimage[i][j] = sum / cnt;
        }
    }
    for (int i = 0 ; i < 256; i++) {
        for (int j = 0 ; j< 256; j++) {
            image[i][j] = cimage[i][j];
        }
    }

}
//_________________________________________(13)_________________________________________________________________________
void Crop_Image(){
    int x,y,l,m;
    cout<<"cin x , y , l and m :";cin>>x>>y>>l>>m;
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
    for (int i = x; i < SIZE-l; i++) {
        for (int j = y ; j< SIZE-m; j++) {
            image[i][j] = cimage[i][j];
        }
    }
}
//_________________________________________(14)_________________________________________________________________________
void Skew_Horizontally(){
    double dd,angel,d,dx;
    cout<<"cin angle : ";
    cin>>angel;
    int re,jj=0;
    angel = angel * (M_PI/180);
    //angel = ( angel * 22 ) / ( 180 * 7 ) ;
    //re = 1/(1+(1/tan(angel)));
    d =  (tan(angel)*256);
    dd = d;
    dx = d/SIZE;
    double y=(dd+SIZE)/SIZE;



    unsigned char img_big[SIZE][SIZE+(int)d]  ;
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE+d ; j++ ){
            img_big[i][j] = 255 ;
        }
    }
 //shift
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE ; j++ ){
            img_big[i][j+(int)d] = image[i][j] ;
        }
        d -= dx ;
    }


    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE+(int)dd; j++ ){
            image[i][(int)(j/y)] =  img_big[i][j];
        }
    }



}
//_________________________________________(15)_________________________________________________________________________
void Skew_Vertically(){
        double dd,angel,d,dx;
        cout<<"cin angle : ";
        cin>>angel;
        int re,jj=0;
        angel = angel * (M_PI/180);
        d =  (tan(angel)*256);
        dd = d;
        dx = d/SIZE;
        double y=(dd+SIZE)/SIZE;

        unsigned char img_big[SIZE+(int)d][SIZE] ;
        for ( int i = 0 ; i < SIZE+d ; i++ ){
            for ( int j = 0 ; j < SIZE ; j++ ){
                img_big[i][j] = 255 ;
            }
        }
        //shift
        for ( int i = 0 ; i < SIZE ; i++ ){
            for ( int j = 0 ; j < SIZE ; j++ ){
                img_big[(int)(j+d)][i] = image[j][i] ;
            }
            d -= dx ;
        }



    for (int i = 0; i < SIZE+(int)dd; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            double x=(i/y);
            image[(int)x][j]=img_big[i][j];
        }
    }
//        for ( int i = 0 ; i < SIZE+(int)dd ; i++ ){
//            for ( int j = 0 ; j < SIZE; j++ ){
//                double time= i/y;
//                image[(int)(time)][j] =  img_big[i][j];
//            }
//        }



}

