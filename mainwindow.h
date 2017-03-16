#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <curl/curl.h>
#include <QMainWindow>
#include <QWidget>
#include <QtGui>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CURL *curl;
    CURLcode res;

    static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
    {
      size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
      return written;
    }


char *argv[];


private slots:





  void on_browser1_sourceChanged(const QUrl &arg1);



void on_pushButton_clicked();

void on_textBrowser_sourceChanged(const QUrl &arg1);

void on_actionOpen_triggered();

void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
