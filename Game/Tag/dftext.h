/*
创建人：神数不神
创建日期：2024-6-9
无修正
*/
#pragma once
#include <QCoreApplication>
namespace GameClient::Tag {
#define TEXT_NONE  QCoreApplication::translate("GameClass","\50\346\227\240\51",nullptr)//（无）
#define TEXT_NA  QCoreApplication::translate("GameClass","\50\116\57\101\51",nullptr)//（N/A）

#define TEXT_ATTRIBUTE_EARTH QCoreApplication::translate("GameClass","\345\234\260",nullptr)//地
#define TEXT_ATTRIBUTE_WATER QCoreApplication::translate("GameClass","\346\260\264",nullptr)//水
#define TEXT_ATTRIBUTE_FIRE QCoreApplication::translate("GameClass","\347\201\253",nullptr)//火
#define TEXT_ATTRIBUTE_WIND QCoreApplication::translate("GameClass","\351\243\216",nullptr)//风
#define TEXT_ATTRIBUTE_LIGHT QCoreApplication::translate("GameClass","\345\205\211",nullptr)//光
#define TEXT_ATTRIBUTE_DARK QCoreApplication::translate("GameClass","\346\232\227",nullptr)//暗
#define TEXT_ATTRIBUTE_DEVINE QCoreApplication::translate("GameClass","\347\245\236",nullptr)//神

#define TEXT_RACE_WARRIOR QCoreApplication::translate("GameClass","\346\210\230\345\243\253",nullptr)//战士
#define TEXT_RACE_SPELLCASTER QCoreApplication::translate("GameClass","\351\255\224\346\263\225\345\270\210",nullptr)//魔法师
#define TEXT_RACE_FAIRY QCoreApplication::translate("GameClass","\345\244\251\344\275\277",nullptr)	//天使
#define TEXT_RACE_FIEND QCoreApplication::translate("GameClass","\346\201\266\351\255\224",nullptr)//恶魔
#define TEXT_RACE_ZOMBIE QCoreApplication::translate("GameClass","\344\270\215\346\255\273",nullptr)//不死
#define TEXT_RACE_MACHINE QCoreApplication::translate("GameClass","\346\234\272\346\242\260",nullptr)//机械
#define TEXT_RACE_AQUA QCoreApplication::translate("GameClass","\346\260\264",nullptr)//水
#define TEXT_RACE_PYRO QCoreApplication::translate("GameClass","\347\202\216",nullptr)//炎
#define TEXT_RACE_ROCK QCoreApplication::translate("GameClass","\345\262\251\347\237\263",nullptr)//岩石
#define TEXT_RACE_WINDBEAST QCoreApplication::translate("GameClass","\351\270\237\345\205\275",nullptr) // 鸟兽
#define TEXT_RACE_PLANT QCoreApplication::translate("GameClass","\346\244\215\347\211\251",nullptr) // 植物
#define TEXT_RACE_INSECT QCoreApplication::translate("GameClass","\346\230\206\350\231\253",nullptr) // 昆虫
#define TEXT_RACE_THUNDER QCoreApplication::translate("GameClass","\351\233\267",nullptr) // 雷
#define TEXT_RACE_DRAGON QCoreApplication::translate("GameClass","\351\276\231",nullptr) // 龙
#define TEXT_RACE_BEAST QCoreApplication::translate("GameClass","\345\205\275",nullptr) // 兽
#define TEXT_RACE_BEASTWARRIOR QCoreApplication::translate("GameClass","\345\205\275\346\210\230\345\243\253",nullptr) // 兽战士
#define TEXT_RACE_DINOSAUR QCoreApplication::translate("GameClass","\346\201\220\351\276\231",nullptr) // 恐龙
#define TEXT_RACE_FISH QCoreApplication::translate("GameClass","\351\261\274",nullptr) // 鱼
#define TEXT_RACE_SEASERPENT QCoreApplication::translate("GameClass","\346\265\267\351\276\231",nullptr) // 海龙
#define TEXT_RACE_REPTILE QCoreApplication::translate("GameClass","\347\210\254\350\231\253\347\261\273",nullptr) // 爬虫类
#define TEXT_RACE_PSYCHO QCoreApplication::translate("GameClass","\345\277\265\345\212\250\345\212\233",nullptr) // 念动力
#define TEXT_RACE_DEVINE QCoreApplication::translate("GameClass","\345\271\273\347\245\236\345\205\275",nullptr) // 幻神兽
#define TEXT_RACE_CREATORGOD QCoreApplication::translate("GameClass","\345\210\233\351\200\240\347\245\236",nullptr) // 创造神
#define TEXT_RACE_WYRM QCoreApplication::translate("GameClass","\345\271\273\351\276\231",nullptr) // 幻龙
#define TEXT_RACE_CYBERSE QCoreApplication::translate("GameClass","\347\224\265\345\255\220\347\225\214",nullptr) // 电子界


#define TEXT_TYPE_MONSTER QCoreApplication::translate("GameClass","\346\200\252\345\205\275",nullptr)//怪兽
#define TEXT_TYPE_SPELL QCoreApplication::translate("GameClass","\351\255\224\346\263\225",nullptr)//魔法
#define TEXT_TYPE_TRAP QCoreApplication::translate("GameClass","\351\231\267\351\230\261",nullptr)//陷阱
#define TEXT_TYPE_NORMAL QCoreApplication::translate("GameClass", "\351\200\232\345\270\270", nullptr)  // 通常
#define TEXT_TYPE_EFFECT QCoreApplication::translate("GameClass", "\346\225\210\346\236\234", nullptr)  // 效果
#define TEXT_TYPE_FUSION QCoreApplication::translate("GameClass", "\350\236\215\345\220\210", nullptr)  // 融合
#define TEXT_TYPE_RITUAL QCoreApplication::translate("GameClass", "\344\273\252\345\274\217", nullptr)  // 仪式
#define TEXT_TYPE_TRAPMONSTER QCoreApplication::translate("GameClass", "\351\231\267\351\230\261\346\200\252\345\205\275", nullptr)  // 陷阱怪兽
#define TEXT_TYPE_SPIRIT QCoreApplication::translate("GameClass", "\347\201\265\351\255\202", nullptr)  // 灵魂
#define TEXT_TYPE_UNION QCoreApplication::translate("GameClass", "\345\220\214\347\233\237", nullptr)  // 同盟
#define TEXT_TYPE_DUAL QCoreApplication::translate("GameClass", "\344\272\214\351\207\215", nullptr)  // 二重
#define TEXT_TYPE_TUNER QCoreApplication::translate("GameClass", "\350\260\203\346\225\264", nullptr)  // 调整
#define TEXT_TYPE_SYNCHRO QCoreApplication::translate("GameClass", "\345\220\214\350\260\203", nullptr)  // 同调
#define TEXT_TYPE_TOKEN QCoreApplication::translate("GameClass", "\350\241\215\347\224\237\347\211\251", nullptr)  // 衍生物
#define TEXT_TYPE_QUICKPLAY QCoreApplication::translate("GameClass", "\351\200\237\346\224\273", nullptr)  // 速攻
#define TEXT_TYPE_CONTINUOUS QCoreApplication::translate("GameClass", "\\346\260\270\347\273\255", nullptr)  // 永续
#define TEXT_TYPE_EQUIP QCoreApplication::translate("GameClass", "\350\243\205\345\244\207", nullptr)  // 装备
#define TEXT_TYPE_FIELD QCoreApplication::translate("GameClass", "\345\234\272\345\234\260", nullptr)  // 场地
#define TEXT_TYPE_COUNTER QCoreApplication::translate("GameClass", "\345\217\215\345\207\273", nullptr)  // 反击
#define TEXT_TYPE_FLIP QCoreApplication::translate("GameClass", "\345\217\215\350\275\254", nullptr)  // 反转
#define TEXT_TYPE_TOON QCoreApplication::translate("GameClass", "\345\215\241\351\200\232", nullptr)  // 卡通
#define TEXT_TYPE_XYZ QCoreApplication::translate("GameClass", "\350\266\205\351\207\217", nullptr)  // 超量
#define TEXT_TYPE_PENDULUM QCoreApplication::translate("GameClass", "\347\201\265\346\221\206", nullptr)  // 灵摆
#define TEXT_TYPE_SPSUMMON QCoreApplication::translate("GameClass", "\347\211\271\346\256\212\345\217\254\345\224\244", nullptr)  // 特殊召唤
#define TEXT_TYPE_LINK QCoreApplication::translate("GameClass", "\351\223\276\346\216\245", nullptr)  // 链接



}