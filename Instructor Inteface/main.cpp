#include "teacher.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Teacher w;
    w.show();
    return a.exec();
}
