#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Estudiante.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->btnOk, &QPushButton::clicked,
            this, &MainWindow::registrarEstudiante);

    connect(ui->btnCancel, &QPushButton::clicked,
            this, &MainWindow::limpiarFormulario);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::registrarEstudiante() {
    QString nombre = ui->lineEdit->text();
    QString codigo = ui->lineEdit_2->text();

    if (nombre.isEmpty() || codigo.isEmpty()) {
        ui->lblResultado->setStyleSheet("color: red;");
        ui->lblResultado->setText("Complete ambos campos.");
        return;
    }

    Estudiante e(nombre.toStdString(), codigo.toStdString());

    ui->lblResultado->setStyleSheet("");
    ui->lblResultado->setText(
        QString("Estudiante registrado: %1 (%2)").arg(nombre, codigo));

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::limpiarFormulario() {
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lblResultado->setStyleSheet("");
    ui->lblResultado->setText("(sin registros aun)");
}