#include "widget.h"

#include <QApplication>

//文本编辑器设计

//功能:
/*
 * 1. 文件打开查看
 * 2. 文件保存
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
