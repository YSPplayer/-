/*
创建人：神数不神
创建日期：2024-5-24
无修正
*/
#include "gamewindow.h"
#include <QScreen>
#include <QtWidgets/QApplication>
#include <QApplication>
using namespace GameClient;
/// <summary>
/// 设置当前窗体水平垂直居中
/// </summary>
void SetWindowCenTer(QWidget* window) {
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height() - 70;//需要减去操作系统菜单栏的高度
    // 计算窗口的位置，使其居中
    int x = (screenWidth - window->width()) / 2;
    int y = (screenHeight - window->height()) / 2;
    window->move(x, y);

}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameWindow* w = new GameWindow;
    SetWindowCenTer(w);
    w->showMaximized();
    return a.exec();
}
