#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "controller/accountcontroller.h"
#include "QMessageBox"
#include <iostream>
using namespace std;
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_connect_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
