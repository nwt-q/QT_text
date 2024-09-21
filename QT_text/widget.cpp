#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //窗口动态变化,窗口始终保持为最大值
    this->setLayout(ui->verticalLayout);

    // 通过下面这行代码进行显示说明, 让窗口发生变化
    this->setLayout(ui->verticalLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_SaveButton_Clicked()
{
    //1. 打开文件
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"), "D:/Desktop/",tr("Text (*.txt)"));

    file.setFileName(filename);

    if(!file.open(QIODevice::ReadOnly |QIODevice::Text)) {
       QMessageBox::information(NULL, "错误", "file open ERROR", QMessageBox::Yes, QMessageBox::Yes);
       return ;
   }

    QTextStream in(&file);

    // 读取全部文件,读取完毕后关闭文件
    QString content = in.readAll();

    file.close();


    //2. 以只写和方式打开文件写入新文本
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        //清空文本编辑框
        ui->textEdit->clear();
    }else{
        QMessageBox::information(NULL, "错误", "file open ERROR", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        //qDebug() << "file open ERROR \n";
    }

}



void Widget::on_OutButton_Clicked()
{

    // 打开文件
    QFileDialog qFileDialog;
    //打开多个文件
    qFileDialog.setFileMode(QFileDialog::ExistingFiles);
    //设置过滤器
    qFileDialog.setNameFilter("*txt");

    qFileDialog.exec();

    QStringList qstrings = qFileDialog.selectedFiles();

    for(QString filename : qstrings) {

        file.setFileName(filename);

        //清空文本编辑框
        ui->textEdit->clear();

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::information(NULL, "错误", "file open ERROR", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }

        QTextStream in(&file);

        in.setEncoding(QStringConverter::Utf8);

        QString context = in.readAll();

        ui->textEdit->setText(context);
    }
}


void Widget::on_DeletBitton_Clicked()
{
    qDebug() << file.isOpen();
    if(file.isOpen() && Widget_colse()) {
        file.close();
        //清空文本编辑框
        ui->textEdit->clear();
    }
}

bool Widget::Widget_colse()
{
    QMessageBox::StandardButton res = QMessageBox::question(this,
                                                            tr("确认关闭"),
                                                            tr("您确定要关闭文件吗？"),
                                                            QMessageBox::Save | QMessageBox::Cancel,
                                                            QMessageBox::Cancel);

    if (res == QMessageBox::Cancel) {
        return false;
    } else {
        return true;
    }
}

void Widget::on_File_activated(int index)
{
    qDebug() << ui->File->currentText();
    QString select = ui->File->currentText();
    if(select == "打开") {
        on_OutButton_Clicked();
    } else if(select == "保存") {
        on_SaveButton_Clicked();
    } else if(select == "关闭") {
        on_DeletBitton_Clicked();
    }
}


void Widget::on_Look_activated(int index)
{
    int select = ui->Look->currentIndex();
    qDebug() << select;
    if(select == 1) {
        QMessageBox::information(NULL, "无法设置", "进群了解详细 : 787936200", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}


