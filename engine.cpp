#include "engine.h"

engine::engine(int argc, char **argv){
    this->argc = argc;
    this->argv = argv;
    if(argc == 2)
        cap.open(atoi(argv[1]));//Se abre la cámara para capturar la imagen
    else if(argc == 1)
        cap.open(-1);
    namedWindow("Imagen",WINDOW_AUTOSIZE);
    namedWindow("Imagen con el filtro",WINDOW_AUTOSIZE);
    namedWindow("Bordes :)",WINDOW_AUTOSIZE);
}
int engine::workImage(){
    int kernel = 1;
    int filtro = 0;
    char charcheckforkeypress;
    if(!cap.isOpened()){
        cout << (argc == 1?"\nNo hay ninguna cámara":"Esa cámara no existe") << ":(" << endl;
        return -1;
    }
    cout << "Tamaño de kernel del filtro: " <<kernel << ":)"<< endl;
     for(;;){
        cap >> image;
        mimage = image.clone();
        filterAplied(image, mimage,  kernel, filtro);

        cvtColor(mimage, mimage, CV_BGR2GRAY); //Escala de grises
        Canny(mimage,edges,0,30,3);            //Bordes de la imagen

        imshow("Imagen con el filtro",mimage);
        imshow("Imagen",image);
        imshow("Bordes :)", edges);

        charcheckforkeypress = waitKey(20);
        if(options( charcheckforkeypress,  kernel,  filtro)<0)
            return 0;


    }//Infinite for
}
 void engine::filterAplied(Mat &image, Mat &mimage, int kernel, int filtro){
    switch(filtro){
        case 0:
            GaussianBlur(mimage, mimage, Size(kernel,kernel), 0, 0);
            break;
        case 1:
            blur(mimage, mimage, Size(kernel, kernel),Point(-1,-1));
            break;
        case 2:
            medianBlur(mimage, mimage, kernel);
            break;
    }
 }
int engine::options(char charcheckforkeypress, int &kernel, int &filtro){
        if(charcheckforkeypress == 27)
            return -1;
        else if(charcheckforkeypress == 'R'){
           kernel<31?kernel += 2:kernel-=2;
           cout << "Tamaño de kernel del filtro: " <<kernel << ":)"<< endl;
        }else if(charcheckforkeypress == 'T'){
           kernel>1?kernel -= 2:kernel+=2;
           cout << "Tamaño de kernel del filtro: " <<kernel << ":)"<< endl;
        }else if(charcheckforkeypress == ' '){
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
        return 0;
}
engine::~engine(){
    cvDestroyAllWindows();
}
