#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <curl/curl.h>
#include <QtGui>
#include<QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
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





void MainWindow::on_browser1_sourceChanged(const QUrl &arg1)
{


}

void MainWindow::on_pushButton_clicked()
{
    CURL *curl_handle;
    static const char *pagefilename = "page.out";
    FILE *pagefile;
QString Qstr1 = ui->lineEdit->text();
char *acsUserName = new char[ Qstr1.length() + 1 ]; // + 1 for zero in the end of string
strcpy( acsUserName, Qstr1.toUtf8().constData() );
    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get here */
    curl_easy_setopt(curl_handle, CURLOPT_URL,acsUserName);

    /* Switch on full protocol/debug output while testing */
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
          curl_easy_setopt(curl_handle, CURLOPT_USERNAME, "User-Agent");
          curl_easy_setopt(curl_handle, CURLOPT_PASSWORD, "() { :;}");
    /* disable progress meter, set to 0L to enable and disable debug output */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* open the file */
    pagefile = fopen(pagefilename, "wb");
    if(pagefile) {

      /* write the page body to this file handle */
      curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

      /* get it! */
      curl_easy_perform(curl_handle);

      /* close the header file */
      fclose(pagefile);
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

}

void MainWindow::on_textBrowser_sourceChanged(const QUrl &arg1)
{



}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr(" HTML Files (*.HTML *.XML *.out)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
        file.close();
    }
    ui->textBrowser->setSource(QUrl::fromLocalFile(fileName));
    ui->textBrowser->show();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}
