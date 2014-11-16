#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdlib.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()

{

    ep = ui->lineEdit_3->text().toDouble();
    n = ui->lineEdit->text().toDouble();
    m = ui->lineEdit_2->text().toDouble();
    ui->tableWidget->setColumnCount(m);
    ui->tableWidget->setRowCount(n);

//               array[0][0] = 1;
//               array[0][1] = 2;
//               array[0][2] = 3;

//               array[1][0] = 3;
//               array[1][1] = 5;
//               array[1][2] = 7;

//               array[2][0] = 1;
//               array[2][1] = 3;
//               array[2][2] = 4;

//               vil[0] = 3;
//               vil[1] = 0;
//               vil[2] = 1;

    ///заповняємо масив рандомними числами
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            array[i][j] = rand()%11;
            vil[i] = rand()%11;
            QTableWidgetItem *ptw=0;
            ptw=new QTableWidgetItem(QString::number(array[i][j]));
            ui->tableWidget->setItem(i,j,ptw);
        }
    }
    /////вводими вільні члени і перші корні
    for (int i = 0; i < n; i++){
        root[i] =vil[i]/array[i][i];
        //root[i] =1;

        ///////////
        ui->tableWidget_3->setColumnCount(m);
        ui->tableWidget_3->setRowCount(n);
        for (int i=0;i<n;i++){
            QTableWidgetItem *ptw=0;
            ptw=new QTableWidgetItem(QString::number(vil[i]));
            ui->tableWidget_3->setItem(i,0,ptw);

        }
    }


    for (int i = 0; i < n; i++){


        ///////////
        ui->tableWidget_4->setColumnCount(m);
        ui->tableWidget_4->setRowCount(n);
        for (int i=0;i<n;i++){
            QTableWidgetItem *ptw=0;
            ptw=new QTableWidgetItem(QString::number(root[i]));
            ui->tableWidget_4->setItem(i,0,ptw);
        }
    }
    flag = true;
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < m; j++ ){
            if (i != j ){
                if ( fabs(array[i][j]) >= fabs(array[i][i])  ){
                    ui->label->setText("pogano");


                }
            }
        }
    }

}
void MainWindow::on_pushButton_3_clicked()
{
    y=0;
    double s = 0,r = 0,u;
    do {

        for (int i = 0; i < n; i++){
            s = 0;
            for (int j = 0; j < m; j++){
                if (i != j ){
                    s+= array[i][j]*root[j];
                }
            }
            u = root[i];
            root[i] = ((vil[i] - s) / array[i][i]);
            r = fabs(  root[i] - u );

    }
        ui->label->setText(QString::number(r));
        y++;
    } while ( ep < r);
    ui->label_5->setText("Кількість ітераці y = "+QString::number(y));
}


void MainWindow::on_pushButton_2_clicked()
{
    y = 0;
    ui->tableWidget_2->setColumnCount(m);
    ui->tableWidget_2->setRowCount(n);
    for (int i=0;i<n;i++){
        QTableWidgetItem *ptw=0;
        ptw=new QTableWidgetItem(QString::number(root[i]));
        ui->tableWidget_2->setItem(i,0,ptw);

    }

}

