#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<qDebug>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QFile file;
    Widget(QWidget *parent = nullptr);
    //保存文件的槽函数
    void on_SaveButton_Clicked();
    //打开文件
    void on_OutButton_Clicked();
    // 清空屏幕
    void on_DeletBitton_Clicked();
    // 关闭提示符
    bool Widget_colse();

    ~Widget();

private slots:
    //QComboBox
    void on_File_activated(int index);

    void on_Look_activated(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
