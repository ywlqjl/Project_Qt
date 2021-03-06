#include "editclient.h"
#include "ui_editclient.h"
#include <QMessageBox>
EditClient::EditClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClient)
{
    ui->setupUi(this);
}

EditClient::~EditClient()
{
    delete ui;
}


/**
 * load a Client from the database to the QSqlTableModel.
 * @method loadClient
 * @return {void}.
 */
void EditClient::loadClient()
{
    //connection to the database
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();

    //prepare model for tableview
    model = new QSqlTableModel(this,db);
    model->setTable("TClient");
    model->setFilter(QObject::tr("Id = %1").arg(this->client_id));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}


/**
 * @brief submit these changes.
 */
void EditClient::on_submit_clicked()
{
    model->database().transaction();
    if (model->submitAll())
    {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("tableModel"),tr("Error db: %1").arg(model->lastError().text()));
    }
    accept();
}


/**
 * @brief set the client'id
 */
void EditClient::setClient_id(int value)
{
    client_id = value;
}

/**
 * @brief delete client
 */
void EditClient::on_pushButton_clicked()
{
    model->setFilter(QObject::tr("Id = %1").arg(this->client_id));
    model->select();
    model->removeRows(0,1);
    model->submit();
    bool result = appointmentController.deleteAppointmentByClientId(this->client_id);
    accept();
}
