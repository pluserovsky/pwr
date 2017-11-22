#ifndef INWENTARZ_H
#define INWENTARZ_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class inwentarz;
}

class inwentarz : public QMainWindow
{
    Q_OBJECT

public:
    explicit inwentarz(QWidget *parent = 0);
    ~inwentarz();

private slots:
    void on_pushButton_zapisz_clicked();

    void on_spinBox_nrPomieszczenia_valueChanged(int arg1);

    void on_comboBox_komputer_currentIndexChanged(int index);

    void on_spinBox_ilosc_valueChanged(int arg1);

private:
    Ui::inwentarz *ui;
};

class pomieszczenie: public inwentarz
{
protected:
    int nrPomieszczenia;
public:
    virtual void setNrPomieszczenia(int nrPomieszczenia) = 0;

};
class komputer: public pomieszczenie
{
protected:
    int ilosc;
public:
    virtual void setIlosc( int ilosc) = 0;
};
class stacjonarny: public komputer
{
private:
    bool tunerTv;
public:
    virtual void setNrPomieszczenia(int nrPomieszczenia);
    virtual void setIlosc( int ilosc);
    void setTunerTv(bool tunerTv);
};
class notebook: public komputer
{
private:
    bool bateria;
public:
    virtual void setNrPomieszczenia(int nrPomieszczenia);
    virtual void setIlosc( int ilosc);
    void setBateria(bool bateria);

};
#endif // INWENTARZ_H
