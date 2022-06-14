#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   // Aqui é tipo OnCreate fo Form

   // Para evitar que seja redimensionado pelo grip do statusbar
   this->statusBar()->setSizeGripEnabled(false);
   // Para evitar que seja redimensionado
   // basta setar MaximumSize e MinimumSize para p tamanho do Form. Isto
   // tambem desabilita o botão maximizar

   ui->lblTestes->setText("");
}


MainWindow::~MainWindow()
{
   delete ui;
}


void MainWindow::on_btnIfElse_clicked()
{
   if (ui->lblTestes->text().isEmpty())
   {
      ui->lblTestes->setText("Testando comando if else...");
   }
   else
   {
      ui->lblTestes->setText("");
   }
}


void MainWindow::on_btnForLoop_clicked()
{
   ui->lblTestes->setText("");

   for (int i = 1; i <= 20000; i++)
   {
      ui->lblTestes->setText("for loop: " + QString::number(i) + " de 20000");
      qApp->processEvents(); // Para atualizar o texto da Label
   }
}


void MainWindow::on_btnWhileLoop_clicked()
{
   ui->lblTestes->setText("");

   int i = 1;

   while (i <= 20000)
   {
      ui->lblTestes->setText("while loop: " + QString::number(i) + " de 20000");
      qApp->processEvents();
      i++;
   }
}


void MainWindow::on_btnDoWhileLoop_clicked()
{
   ui->lblTestes->setText("");
   int i = 1;

   do
   {
      ui->lblTestes->setText("while loop: " + QString::number(i) + " de 20000");
      qApp->processEvents();
      i++;
   } while (i <= 20000);
}


void MainWindow::on_btnSobre_clicked()
{
   QMessageBox::about(this, QApplication::applicationName(), "Aplicativo desenvolvido por Eduardo Volpi");
}


void MainWindow::on_btnSobreQt_clicked()
{
   QMessageBox::aboutQt(this, QApplication::applicationName());
}


void MainWindow::on_btnInfo_clicked()
{
   QMessageBox::information(this, QApplication::applicationName(), "Esta é uma mensagem informativa do App!");
}


void MainWindow::on_btnErro_clicked()
{
   QMessageBox::critical(this, QApplication::applicationName(), "Esta é uma mensagem de Erro.");
}


void MainWindow::on_btnAlerta_clicked()
{
   QMessageBox::warning(this, QApplication::applicationName(), "Esta é uma mensagem de Alerta");
}


void MainWindow::on_btnQuestao_clicked()
{
   // Crio uma var do tipo standardbutton que recebera o botão
   // clicado
   QMessageBox::StandardButton btnClicked;

   btnClicked = QMessageBox::question(this, "Exemplos", "Deseja Fechar o Programa?", QMessageBox::Yes | QMessageBox::No);

   if (btnClicked == QMessageBox::Yes)
   {
      // close();
      QApplication::quit();
   }
}
