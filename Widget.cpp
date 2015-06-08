#include "Widget.h"
#include "ui_Widget.h"
#include <QProcess>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ejecutarPushButton_clicked()
{
    QProcess p;
    if (!p.startDetached(ui->aplicacionLineEdit->text())) {
        QMessageBox::critical(this, "Error", "No se puede ejecutar");
    }
}

void Widget::on_quitarPushButton_clicked()
{
    QProcess p;
    if (!p.startDetached(QString("taskkill /IM %1").
                        arg(ui->aplicacionLineEdit->text()))) {
        QMessageBox::critical(this, "Error", "No se puede quitar");
    }
}
