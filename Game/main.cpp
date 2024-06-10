/*
�����ˣ���������
�������ڣ�2024-5-24
������
*/
#include "gameclientwindow.h"
#include <QScreen>
#include <QtWidgets/QApplication>
#include <QApplication>
using namespace GameClient;
/// <summary>
/// ���õ�ǰ����ˮƽ��ֱ����
/// </summary>
void SetWindowCenTer(QWidget* window) {
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height() - 70;//��Ҫ��ȥ����ϵͳ�˵����ĸ߶�
    // ���㴰�ڵ�λ�ã�ʹ�����
    int x = (screenWidth - window->width()) / 2;
    int y = (screenHeight - window->height()) / 2;
    window->move(x, y);

}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameClientWindow* w = new GameClientWindow;
    SetWindowCenTer(w);
    w->showMaximized();

    return a.exec();
}
