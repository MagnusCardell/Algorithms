#include <iostream>
using namespace std;

void rotateImage( int **im, int N ){
    for(int i=0; i<N; ++i ){
        for(int j=0; j<N; ++j ){
            int temp = im[i][j];
            im[i][j] = im[j][N-i];
            im[j][N-i] = temp;
            cout<<temp<<" ";
        }
        cout<<"\n";
    }
    //delete [] im;
}

int main(){
    int N = 4;
    int **image = new int*[N];
    for (int i =0; i<N; ++i){
        image[i] = new int[N];
    }
    for (int i =0; i<N; ++i){
        for( int j=0; j<N; ++j){
            image[i][j] = i+j;
            cout<<image[i][j]<<" ";
        }
        cout<<"\n";
    }

    rotateImage(image, N);
    delete[] image;
}