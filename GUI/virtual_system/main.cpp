#include "loginpage.h"
#include <fstream>
#include <unordered_set>
#include <QApplication>

using namespace std;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}


