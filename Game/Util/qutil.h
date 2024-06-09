/*
创建人：神数不神
创建日期：2024-6-5
无修正
*/
#pragma once
#include <QWidget>
#include <QCoreApplication>
#include <QList>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "../Client/clientcard.h"
#include "../Tag/dfcard.h"
#include "../Tag/dftext.h"
namespace GameClient::Tool {
	using namespace GameClient::Client;
	using namespace GameClient::Tag;
	class QUtil {
/// <summary>
/// 获得当前程序运行的根目录
/// </summary>
/// <returns></returns>
#define QUtilGetRootPath QCoreApplication::applicationDirPath
	    private:
			static QMap<quint64,QString> attributeMap;
			static QMap<quint64,QString> raceMap;
		public:
		/// <summary>
		/// 设置当前窗口的字体
		/// </summary>
		/// <param name="pfont"></param>
		/// <param name="widget"></param>
		/// <param name="size"></param>
		static void SetWidgetFont(QFont* pfont,QWidget* widget, qint32 size,bool bold = false) {
			pfont->setPointSize(size);
			pfont->setBold(true);
			widget->setFont(*pfont);
		};

		/// <summary>
		/// 获取当前卡片存储的图片路径
		/// </summary>
		static QString GetImagePath(quint64 code) {
			return QUtilGetRootPath() + "/Resources/Pics/" + QString::number(code) + ".jpg";
		}

		/// <summary>
		/// 把正常攻击力转为我们需要的类型
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static Value Int32ToValue(qint32 value) {
			if(value == -2) return {value,ValueType::Undefined};//?
			if(value == -3) return {value,ValueType::Infinity};//∞
			return {value,ValueType::Common};
		}

		/// <summary>
		/// 获取属性文本
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		static QString GetAttributeText(quint64 attribute) {
			if (attributeMap.contains(attribute)) return attributeMap[attribute];
			return "???";
		}

		/// <summary>
		/// 获取种族文本
		/// </summary>
		/// <param name="path"></param>
		/// <param name="cards"></param>
		/// <returns></returns>
		static QString GetRaceText(quint64 race) {
			if (raceMap.contains(race)) return raceMap[race];
			return "???";
		}

		/// <summary>
		/// 获取攻守的文本
		/// </summary>
		/// <param name="race"></param>
		/// <returns></returns>
		static QString GetValueText(const Value& value) {
			if(value.vtype == ValueType::Undefined) return "?";//?
			if(value.vtype == ValueType::Infinity) return "\342\210\236"; //∞
			return QString::number(value.value);
		}

		/// <summary>
		/// 读取数据库卡片到游戏
		/// </summary>
		/// <returns></returns>
		static bool LoadDb(const QString& path,QList<ClientCard*>& cards) {
			QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
			db.setDatabaseName(path);
			if (!db.open()) {
				return false;
			}
			QSqlQuery query;
			if (!query.exec("SELECT datas.*,texts.* FROM datas,texts WHERE datas.id=texts.id")) {
				return false;
			}
			while (query.next()) {
				quint64 id = query.value("id").toULongLong(); 
				quint32 ot = query.value("ot").toUInt(); 
				quint64 alias = query.value("alias").toULongLong();
				quint64 type = query.value("type").toULongLong();
				quint64 setcode = query.value("setcode").toULongLong();
				qint64 level = query.value("level").toLongLong();
				quint64 attribute = query.value("attribute").toULongLong();
				quint64 race = query.value("race").toULongLong();
				qint32 atk = query.value("atk").toInt();
				qint32 def = query.value("def").toInt();
				QString name = query.value("name").toString(); 
				QString desc = query.value("desc").toString(); 
				const Value& vatk = Int32ToValue(atk);
				const Value& vdef = Int32ToValue(def);
				cards.append(new ClientCard(id,ot,alias,type,setcode,level,attribute,race,vatk,vdef,name,desc));
			}
			db.close();
			return true;
		}
	};
}