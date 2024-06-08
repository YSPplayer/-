/*
创建人：神数不神
创建日期：2024-6-5
无修正
*/
#pragma once
#include <QWidget>
#include <QCoreApplication>
namespace GameClient::Tool {
	class QUtil {
/// <summary>
/// 获得当前程序运行的根目录
/// </summary>
/// <returns></returns>
#define QUtilGetRootPath QCoreApplication::applicationDirPath
		public:
		/// <summary>
		/// 设置当前窗口的字体
		/// </summary>
		/// <param name="pfont"></param>
		/// <param name="widget"></param>
		/// <param name="size"></param>
		static void SetWidgetFont(QFont* pfont,QWidget* widget, qint32 size) {
			pfont->setPointSize(size);
			widget->setFont(*pfont);
		};
		private:

	};

}