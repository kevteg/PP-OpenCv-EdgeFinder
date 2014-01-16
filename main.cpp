#include <iostream>
#include "engine.h"
int main(int argc, char **argv)
{

    engine program(argc, argv);
    program.workImage();
    /*VideoCapture cap;
    Mat image, mimage, edges;
    int number = 1, filtro = 0;
    char charcheckforkeypress;
    int cam = 0;
    if(argc == 2)
        cam = atoi(argv[1]);
    cap.open(cam); //Se abre la cámara para capturar la imagen
    if(!cap.isOpened()){
        cout << (argc == 1?"\nNo hay ninguna cámara":"Esa cámara no existe") << ":(" << endl;
        return -1;
    }
    namedWindow("Imagen",WINDOW_AUTOSIZE);
    namedWindow("Imagen con el filtro",WINDOW_AUTOSIZE);
    namedWindow("Bordes :)",WINDOW_AUTOSIZE);
    for(;;){
        cap >> image;

        mimage = image.clone();
        switch(filtro){
            case 0:
                GaussianBlur(mimage, mimage, Size(number,number), 0, 0);
                break;
            case 1:
                blur(mimage,mimage,Size(number, number),Point(-1,-1));
                break;
            case 2:
                medianBlur(mimage,mimage,number);
                break;
        }
        cvtColor(mimage, mimage, CV_BGR2GRAY);
        Canny(mimage,edges,0,30,3);

        imshow("Imagen con el filtro",mimage);
        imshow("Imagen",image);
        imshow("Bordes :)", edges);

        cout << "Tamaño de kernel del filtro: " <<number << ":)"<< endl;



        charcheckforkeypress = waitKey(20);

        if(charcheckforkeypress == 27)
            break;
        else if(charcheckforkeypress == 'R')
           number<31?number += 2:number-=2;
        else if(charcheckforkeypress == 'T')
           number>1?number -= 2:number+=2;
        else if(charcheckforkeypress == ' '){
            filtro = -1;
            cout << "Introdusca el filtro nuevo: ";
                while(filtro<0||filtro>2)
                    cin >> filtro;
            if(!filtro)
                cout << "Aplicando filtro gaussian blur" << endl;
            else if(filtro == 1)
                cout << "Aplicando filtro blur" << endl;
            else
                cout << "Aplicando filtro median blur" << endl;
        }


    }
cvDestroyAllWindows();*/
    return 0;
}
