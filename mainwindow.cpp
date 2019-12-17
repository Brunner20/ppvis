#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QDebug>
#include <sstream>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    read r;
    vector<cart> carte=r.read_cart("base.txt");
   // vector<base> bas = r.read_base("cards.txt");

    for(int i=0;i<carte.size();i++){
        ui->listWidget->addItem(QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
ui->listWidget->addItem("sd");
}
/*setlocale(SEEK_SET, "rus");
    string str1 = (string)argv[1];
    string str2 = (string)argv[2];
    read r;
    vector<cart> carte=r.read_cart(str1);
    vector<base> bas = r.read_base(str2);
    session s1(carte, bas);
    s1.beg();
    s1.end(str1);*/
