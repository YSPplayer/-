/*
创建人：神数不神
创建日期：2024-5-24
无修正
*/
#include "GameClientDeckWindow.h"
#include <QScreen>
#include <QtWidgets/QApplication>
#include <QApplication>
#include "Util/qutil.h"
using namespace GameClient;
using namespace GameClient::Tool;
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
    QUtil::InitGameWindows();
    QWidget* parent = QUtil::GetGameRootWidget();
    QUtil::ActivateChildWindow(parent, GAME_WINDOW_DECK);
    SetWindowCenTer(parent);
    parent->showMaximized();
    return a.exec();
}
