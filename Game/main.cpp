/*
�����ˣ���������
�������ڣ�2024-5-24
������
*/
#include "GameClientDeckWindow.h"
#include <QScreen>
#include <QtWidgets/QApplication>
#include <QApplication>
#include "Util/qutil.h"
using namespace GameClient;
using namespace GameClient::Tool;
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
    QUtil::InitGameWindows();
    QWidget* parent = QUtil::GetGameRootWidget();
    QUtil::ActivateChildWindow(parent, GAME_WINDOW_DECK);
    SetWindowCenTer(parent);
    parent->showMaximized();
    return a.exec();
}
