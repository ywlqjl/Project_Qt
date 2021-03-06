#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <vector>
using namespace std;
typedef struct {
    vector<int> startIndex;
    vector<int> cellNeeded;

}ClientRDVInfo;

class Client
{
private:
    int cli_id;
    QString cli_lastname;
    QString cli_firstname;
    QString cli_address;
    QString cli_city;
    int cli_postcode;
    int cli_tel;
    QString cli_comment;
    QDate cli_rdv_date;
    int cli_rdv_duration;
    int cli_priority;
    vector<int> cli_v_resources;

public:
    Client();
    ClientRDVInfo clientRDVInfo;

    QString getCli_lastname() const;
    void setCli_lastname(const QString &value);
    QString getCli_firstname() const;
    void setCli_firstname(const QString &value);
    QString getCli_address() const;
    void setCli_address(const QString &value);
    QString getCli_city() const;
    void setCli_city(const QString &value);
    int getCli_id() const;
    void setCli_id(int value);
    QString getCli_comment() const;
    void setCli_comment(const QString &value);
    QDate getCli_rdv_date() const;
    void setCli_rdv_date(const QDate &value);
    int getCli_rdv_duration() const;
    void setCli_rdv_duration(int value);
    int getCli_priority() const;
    void setCli_priority(int value);

    vector<int>& getCli_v_resources();
    void setCli_v_resources(const vector<int> value);
    int getCli_postcode() const;
    void setCli_postcode(int value);
    int getCli_tel() const;
    void setCli_tel(int value);
};

#endif // CLIENT_H
