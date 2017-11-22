#include "inwentarz.h"
#include "ui_inwentarz.h"


inwentarz::inwentarz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inwentarz)
{
    ui->setupUi(this);
}

inwentarz::~inwentarz()
{
    delete ui;
}

void stacjonarny::setNrPomieszczenia(int nrPomieszczenia)
{
    pomieszczenie::nrPomieszczenia = nrPomieszczenia;

}
void stacjonarny::setIlosc( int ilosc)
{
    komputer::ilosc = ilosc;
}
void notebook::setNrPomieszczenia(int nrPomieszczenia)
{
    pomieszczenie::nrPomieszczenia = nrPomieszczenia;
}
void notebook::setIlosc( int ilosc)
{
    komputer::ilosc = ilosc;
}
void stacjonarny::setTunerTv(bool tunerTv)
{
    stacjonarny::tunerTv = tunerTv;
}
void notebook::setBateria(bool bateria)
{
    notebook::bateria = bateria;
}


void inwentarz::on_pushButton_zapisz_clicked()
{
    int id = (comboBox_komputer->itemData(comboBox_komputer->currentIndex())).toInt();
if(id == 0)
    stacjonarny s;
//else if(QComboBox.comboBox_komputer->currentIndex = 1)
   // notebook l;

}

void inwentarz::on_spinBox_nrPomieszczenia_valueChanged(int arg1)
{

}
void inwentarz::on_comboBox_komputer_currentIndexChanged(int index)
{

}

void inwentarz::on_spinBox_ilosc_valueChanged(int arg1)
{

}
