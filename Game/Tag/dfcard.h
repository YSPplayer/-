/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#pragma once
namespace GameClient::Tag {
//属性
#define ATTRIBUTE_ALL		0x7f		//全部
#define ATTRIBUTE_EARTH		0x01		//地
#define ATTRIBUTE_WATER		0x02		//水
#define ATTRIBUTE_FIRE		0x04		//火
#define ATTRIBUTE_WIND		0x08		//风
#define ATTRIBUTE_LIGHT		0x10		//光
#define ATTRIBUTE_DARK		0x20		//暗
#define ATTRIBUTE_DEVINE	0x40		//神

//种族
#define RACES_COUNT			26
#define RACE_ALL			0x3ffffff
#define RACE_WARRIOR		0x1			//战士
#define RACE_SPELLCASTER	0x2			//魔法师
#define RACE_FAIRY			0x4			//天使
#define RACE_FIEND			0x8			//恶魔
#define RACE_ZOMBIE			0x10		//不死
#define RACE_MACHINE		0x20		//机械
#define RACE_AQUA			0x40		//水
#define RACE_PYRO			0x80		//炎
#define RACE_ROCK			0x100		//岩石
#define RACE_WINDBEAST		0x200		//鸟兽
#define RACE_PLANT			0x400		//植物
#define RACE_INSECT			0x800		//昆虫
#define RACE_THUNDER		0x1000		//雷
#define RACE_DRAGON			0x2000		//龙
#define RACE_BEAST			0x4000		//兽
#define RACE_BEASTWARRIOR	0x8000		//兽战士
#define RACE_DINOSAUR		0x10000		//恐龙
#define RACE_FISH			0x20000		//鱼
#define RACE_SEASERPENT		0x40000		//海龙
#define RACE_REPTILE		0x80000		//爬虫类
#define RACE_PSYCHO			0x100000	//念动力
#define RACE_DEVINE			0x200000	//幻神兽
#define RACE_CREATORGOD		0x400000	//创造神
#define RACE_WYRM			0x800000	//幻龙
#define RACE_CYBERSE		0x1000000	//电子界
#define RACE_ILLUSION		0x2000000	//

//卡片类型
#define TYPE_MONSTER		0x1			//怪兽
#define TYPE_SPELL			0x2			//魔法
#define TYPE_TRAP			0x4			//陷阱
#define TYPE_NORMAL			0x10		//通常
#define TYPE_EFFECT			0x20		//
#define TYPE_FUSION			0x40		//
#define TYPE_RITUAL			0x80		//
#define TYPE_TRAPMONSTER	0x100		//
#define TYPE_SPIRIT			0x200		//
#define TYPE_UNION			0x400		//
#define TYPE_DUAL			0x800		//
#define TYPE_TUNER			0x1000		//
#define TYPE_SYNCHRO		0x2000		//
#define TYPE_TOKEN			0x4000		//
#define TYPE_QUICKPLAY		0x10000		//速攻
#define TYPE_CONTINUOUS		0x20000		//永续
#define TYPE_EQUIP			0x40000		//装备
#define TYPE_FIELD			0x80000		//场地
#define TYPE_COUNTER		0x100000	//反击
#define TYPE_FLIP			0x200000	//
#define TYPE_TOON			0x400000	//
#define TYPE_XYZ			0x800000	//
#define TYPE_PENDULUM		0x1000000	//
#define TYPE_SPSUMMON		0x2000000	//
#define TYPE_LINK			0x4000000	//
}
