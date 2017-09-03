#include "stdafx.h"
#include "stage15battle.h"
#include "player.h"
#include "camera.h"

stage15battle::stage15battle()
{
}


stage15battle::~stage15battle()
{
}

HRESULT stage15battle::init()
{
	_player->getPlayer()->changebattle = false;
	_player->getPlayer()->changeindex = 0;
	_player->getPlayer()->loadstagenum = 50;
	IMAGEMANAGER->addImage("eotk", "image/undertale/battle/stage15battle/eotk.bmp", 229, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hpmaxn", "image/undertale/battle/hpmax.bmp", 25, 21, false, false);
	IMAGEMANAGER->addImage("hpminn", "image/undertale/battle/hpmin.bmp", 25, 21, false, false);
	IMAGEMANAGER->addImage("lv05", "image/undertale/battle/stage15battle/lv.bmp", 375, 31, false, false);
	IMAGEMANAGER->addImage("gage", "image/undertale/battle/dummy/gage.bmp", 565, 130, false, false);
	IMAGEMANAGER->addImage("miss", "image/undertale/battle/dummy/miss.bmp", 118, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls1", "image/undertale/battle/stage15battle/tls/1.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls2", "image/undertale/battle/stage15battle/tls/2.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls3", "image/undertale/battle/stage15battle/tls/3.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls4", "image/undertale/battle/stage15battle/tls/4.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls5", "image/undertale/battle/stage15battle/tls/5.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls6", "image/undertale/battle/stage15battle/tls/6.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls7", "image/undertale/battle/stage15battle/tls/7.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls8", "image/undertale/battle/stage15battle/tls/8.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls9", "image/undertale/battle/stage15battle/tls/9.bmp", 313, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tls10", "image/undertale/battle/stage15battle/tls/10.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls11", "image/undertale/battle/stage15battle/tls/11.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls12", "image/undertale/battle/stage15battle/tls/12.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls13", "image/undertale/battle/stage15battle/tls/13.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls14", "image/undertale/battle/stage15battle/tls/14.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls15", "image/undertale/battle/stage15battle/tls/15.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls16", "image/undertale/battle/stage15battle/tls/16.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls17", "image/undertale/battle/stage15battle/tls/17.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls18", "image/undertale/battle/stage15battle/tls/18.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls19", "image/undertale/battle/stage15battle/tls/19.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls20", "image/undertale/battle/stage15battle/tls/20.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls21", "image/undertale/battle/stage15battle/tls/21.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls22", "image/undertale/battle/stage15battle/tls/22.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls23", "image/undertale/battle/stage15battle/tls/23.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls24", "image/undertale/battle/stage15battle/tls/24.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls25", "image/undertale/battle/stage15battle/tls/25.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls26", "image/undertale/battle/stage15battle/tls/26.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls27", "image/undertale/battle/stage15battle/tls/27.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls28", "image/undertale/battle/stage15battle/tls/28.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls29", "image/undertale/battle/stage15battle/tls/29.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls30", "image/undertale/battle/stage15battle/tls/30.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls31", "image/undertale/battle/stage15battle/tls/31.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls32", "image/undertale/battle/stage15battle/tls/32.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls33", "image/undertale/battle/stage15battle/tls/33.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls34", "image/undertale/battle/stage15battle/tls/34.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls35", "image/undertale/battle/stage15battle/tls/35.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls36", "image/undertale/battle/stage15battle/tls/36.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls37", "image/undertale/battle/stage15battle/tls/37.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls38", "image/undertale/battle/stage15battle/tls/38.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls39", "image/undertale/battle/stage15battle/tls/39.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls40", "image/undertale/battle/stage15battle/tls/40.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls41", "image/undertale/battle/stage15battle/tls/41.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls42", "image/undertale/battle/stage15battle/tls/42.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls43", "image/undertale/battle/stage15battle/tls/43.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls44", "image/undertale/battle/stage15battle/tls/44.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls45", "image/undertale/battle/stage15battle/tls/45.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls46", "image/undertale/battle/stage15battle/tls/46.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls47", "image/undertale/battle/stage15battle/tls/47.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls48", "image/undertale/battle/stage15battle/tls/48.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls49", "image/undertale/battle/stage15battle/tls/49.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls50", "image/undertale/battle/stage15battle/tls/50.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls51", "image/undertale/battle/stage15battle/tls/51.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls52", "image/undertale/battle/stage15battle/tls/52.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls53", "image/undertale/battle/stage15battle/tls/53.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls54", "image/undertale/battle/stage15battle/tls/54.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls55", "image/undertale/battle/stage15battle/tls/55.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls56", "image/undertale/battle/stage15battle/tls/56.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls57", "image/undertale/battle/stage15battle/tls/57.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls58", "image/undertale/battle/stage15battle/tls/58.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls59", "image/undertale/battle/stage15battle/tls/59.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls60", "image/undertale/battle/stage15battle/tls/60.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls61", "image/undertale/battle/stage15battle/tls/61.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls62", "image/undertale/battle/stage15battle/tls/62.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls63", "image/undertale/battle/stage15battle/tls/63.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls64", "image/undertale/battle/stage15battle/tls/64.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls65", "image/undertale/battle/stage15battle/tls/65.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls66", "image/undertale/battle/stage15battle/tls/66.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls67", "image/undertale/battle/stage15battle/tls/67.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls68", "image/undertale/battle/stage15battle/tls/68.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls69", "image/undertale/battle/stage15battle/tls/69.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls70", "image/undertale/battle/stage15battle/tls/70.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls71", "image/undertale/battle/stage15battle/tls/71.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls72", "image/undertale/battle/stage15battle/tls/72.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls73", "image/undertale/battle/stage15battle/tls/73.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls74", "image/undertale/battle/stage15battle/tls/74.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls75", "image/undertale/battle/stage15battle/tls/75.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls76", "image/undertale/battle/stage15battle/tls/76.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls77", "image/undertale/battle/stage15battle/tls/77.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls78", "image/undertale/battle/stage15battle/tls/78.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls79", "image/undertale/battle/stage15battle/tls/79.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls80", "image/undertale/battle/stage15battle/tls/80.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls81", "image/undertale/battle/stage15battle/tls/81.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls82", "image/undertale/battle/stage15battle/tls/82.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls83", "image/undertale/battle/stage15battle/tls/83.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls84", "image/undertale/battle/stage15battle/tls/84.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls85", "image/undertale/battle/stage15battle/tls/85.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls86", "image/undertale/battle/stage15battle/tls/86.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls87", "image/undertale/battle/stage15battle/tls/87.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls88", "image/undertale/battle/stage15battle/tls/88.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls89", "image/undertale/battle/stage15battle/tls/89.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls90", "image/undertale/battle/stage15battle/tls/90.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls91", "image/undertale/battle/stage15battle/tls/91.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls92", "image/undertale/battle/stage15battle/tls/92.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls93", "image/undertale/battle/stage15battle/tls/93.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls94", "image/undertale/battle/stage15battle/tls/94.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls95", "image/undertale/battle/stage15battle/tls/95.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls96", "image/undertale/battle/stage15battle/tls/96.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls97", "image/undertale/battle/stage15battle/tls/97.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls98", "image/undertale/battle/stage15battle/tls/98.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls99", "image/undertale/battle/stage15battle/tls/99.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls100", "image/undertale/battle/stage15battle/tls/100.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls101", "image/undertale/battle/stage15battle/tls/101.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls102", "image/undertale/battle/stage15battle/tls/102.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls103", "image/undertale/battle/stage15battle/tls/103.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("tls104", "image/undertale/battle/stage15battle/tls/104.bmp", 313, 250, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("battlebox", "image/undertale/battle/flabttle/battlebox.bmp", 165, 140, true, RGB(127, 127, 127));
	IMAGEMANAGER->addImage("....", "image/undertale/battle/dummy/.....bmp", 99, 108, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("heart", "image/undertale/battle/heart.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bttb", "image/undertale/battle/dummy/bttb.bmp", 575, 140, false, false);
	IMAGEMANAGER->addImage("bt2", "image/undertale/battle/stage15battle/bt2.bmp", 609, 236, false, false);
	IMAGEMANAGER->addImage("gibun", "image/undertale/battle/stage15battle/gibun.bmp", 245, 130, false, false);
	lvnum = IMAGEMANAGER->addFrameImage("lvnum", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	tennum = IMAGEMANAGER->addFrameImage("tennum", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	onenum = IMAGEMANAGER->addFrameImage("onenum", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	tennum2 = IMAGEMANAGER->addFrameImage("tennum2", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	onenum2 = IMAGEMANAGER->addFrameImage("onenum2", "image/undertale/battle/number.bmp", 120, 15, 10, 1, false, false);
	ghost = IMAGEMANAGER->addFrameImage("ghost", "image/undertale/monster/ghost/ghost.bmp", 208, 136, 2, 1, false, false);
	napd = IMAGEMANAGER->addFrameImage("napd", "image/undertale/battle/stage15battle/napd.bmp", 3039, 200, 8, 1, true, RGB(255, 0, 255));
	bull123 = IMAGEMANAGER->addFrameImage("bull123", "image/undertale/battle/stage15battle/bull123.bmp", 36, 18, 2, 1, true, RGB(255,0,255));
	bull1234 = IMAGEMANAGER->addFrameImage("bull1234", "image/undertale/battle/stage15battle/bull1234.bmp", 36, 18, 2, 1, true, RGB(255, 0, 255));
	bulllal = IMAGEMANAGER->addFrameImage("bulllal", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllal1 = IMAGEMANAGER->addFrameImage("bulllal1", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllal2 = IMAGEMANAGER->addFrameImage("bulllal2", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllal3 = IMAGEMANAGER->addFrameImage("bulllal3", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllal4 = IMAGEMANAGER->addFrameImage("bulllal4", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllal5 = IMAGEMANAGER->addFrameImage("bulllal5", "image/undertale/battle/stage15battle/bulllal.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllar = IMAGEMANAGER->addFrameImage("bulllar", "image/undertale/battle/stage15battle/bulllar.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllar1 = IMAGEMANAGER->addFrameImage("bulllar1", "image/undertale/battle/stage15battle/bulllar.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllar2 = IMAGEMANAGER->addFrameImage("bulllar2", "image/undertale/battle/stage15battle/bulllar.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllar3 = IMAGEMANAGER->addFrameImage("bulllar3", "image/undertale/battle/stage15battle/bulllar.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bulllar4 = IMAGEMANAGER->addFrameImage("bulllar4", "image/undertale/battle/stage15battle/bulllar.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsml = IMAGEMANAGER->addFrameImage("bullsml", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml1 = IMAGEMANAGER->addFrameImage("bullsml1", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml2 = IMAGEMANAGER->addFrameImage("bullsml2", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml3 = IMAGEMANAGER->addFrameImage("bullsml3", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml4 = IMAGEMANAGER->addFrameImage("bullsml4", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml5 = IMAGEMANAGER->addFrameImage("bullsml5", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml6 = IMAGEMANAGER->addFrameImage("bullsml6", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml7 = IMAGEMANAGER->addFrameImage("bullsml7", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsml8 = IMAGEMANAGER->addFrameImage("bullsml8", "image/undertale/battle/stage15battle/bullsml.bmp", 33, 11, 3, 1, true, RGB(255, 0, 255));
	bullsmr = IMAGEMANAGER->addFrameImage("bullsmr", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsmr1 = IMAGEMANAGER->addFrameImage("bullsmr1", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsmr2 = IMAGEMANAGER->addFrameImage("bullsmr2", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsmr3 = IMAGEMANAGER->addFrameImage("bullsmr3", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsmr4 = IMAGEMANAGER->addFrameImage("bullsmr4", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bullsmr5 = IMAGEMANAGER->addFrameImage("bullsmr5", "image/undertale/battle/stage15battle/bullsmr.bmp", 39, 14, 3, 1, true, RGB(255, 0, 255));
	bttbf = IMAGEMANAGER->addFrameImage("bttbf", "image/undertale/battle/stage15battle/bttbf.bmp", 12075, 140, 21, 1, true, RGB(255, 0, 255));
	stick = IMAGEMANAGER->addFrameImage("stick", "image/undertale/battle/dummy/stick.bmp", 28, 130, 2, 1, true, RGB(255, 0, 255));
	gagef = IMAGEMANAGER->addFrameImage("gagef", "image/undertale/battle/dummy/gagef.bmp", 7345, 130, 13, 1, false, false);
	attack = IMAGEMANAGER->addFrameImage("attack", "image/undertale/battle/dummy/attack.bmp", 693, 154, 7, 1, true, RGB(255, 0, 255));
	
	fight = IMAGEMANAGER->addFrameImage("fight", "image/undertale/battle/dummy/fight.bmp", 330, 42, 3, 1, false, false);
	act = IMAGEMANAGER->addFrameImage("act", "image/undertale/battle/dummy/act.bmp", 330, 42, 3, 1, false, false);
	item = IMAGEMANAGER->addFrameImage("item", "image/undertale/battle/dummy/item.bmp", 330, 42, 3, 1, false, false);
	mercy = IMAGEMANAGER->addFrameImage("mercy", "image/undertale/battle/dummy/mercy.bmp", 330, 42, 3, 1, false, false);

	IMAGEMANAGER->addImage("hp", "image/undertale/battle/dummy/hp.bmp", 101, 13, false, false);
	IMAGEMANAGER->addImage("hp2", "image/undertale/battle/dummy/hp2.bmp", 103, 15, false, false);
	dboxy = 40;
	te = 0;
	te2 = 284;
	rhd = 11;
	epa = 0;
	fcount2 = 0;
	hpx2 = 88;
	fight->setFrameX(0);
	act->setFrameX(1);
	item->setFrameX(1);
	mercy->setFrameX(1);
	vlxkss = true;
	misss = false;
	atts = false;
	sticks = false;
	start = true;
	actchoices = false;
	mercychoices = false;
	pttcos = false;
	fights = true;
	acts = false;
	items = false;
	mercys = false;
	textlast = false;
	plays = false;
	resetbulls = true;
	ptt1s = false;
	ptt2s = false;
	fightchoices = false;
	fightgages = false;
	fightatts = false;
	fightatt2s1 = false;
	fightmisss = false;
	ptt1sco = true;
	bttbs = false;
	closings = false;
	interimclosings = false;
	nothings = true;
	praise = false;
	lastpraise = false;
	rlqns1 = true;
	rlqns2 = false;
	rlqns3 = false;
	text2s = true;
	text3s = true;
	tlstks = false;

	textrc2s = false;
	stickx = 28;

	textrc3s = false;
	textnum = 0;

	hpx = 88;
	tlscount = 0;
	count1 = 0;
	index1 = 0;
	praisecount = 0;
	fcount6 = 0;
	tcount = 0;
	tindex = 0;
	textnum2 = 0;
	textnum3 = 30;
	textnum4 = 50;
	textnum5 = 60;
	bttbcount = 0;
	rlqnsn = 0;
	bbox = RectMake(242 + _camera->getCam()->x, 255 + _camera->getCam()->y, 155, 130);
	bbox2 = RectMake(192 + _camera->getCam()->x, 255 + _camera->getCam()->y, 255, 130);
	
	textrc = RectMake(17 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y, 565, 130);
	textrc2 = RectMake(430, 140, 90, 90);
	textrc3 = RectMake(450, 140, 300, 300);
	
	if (SOUNDMANAGER->isPlaySound("stagesound"))
	{
		SOUNDMANAGER->pause("stagesound");
	}
	if (!SOUNDMANAGER->isPlaySound("midbosssound"))
	{
		SOUNDMANAGER->play("midbosssound", 1.f);
	}

	return S_OK;
}

void stage15battle::release()
{
}

void stage15battle::update()
{
	vlxks();
	dbox = RectMake(295 + _camera->getCam()->x, dboxy + _camera->getCam()->y, 70, 40);
	count++;
	if (plays)play();
	if (start)choice();
	if (actchoices)actchoice();
	if (mercychoices)mercychoice();
	if (ptt1s)ptt1();
	if (ptt2s)ptt2();
	if (pttcos)pttco();
	if (closings)closing();
	if (interimclosings)interimclosing();
	if (tlstks)tlstk();
	if (resetbulls)resetbull();
	if (fightchoices)fightchoice();
	if (fightgages)fightgage();
	if (fightatts)fightatt();
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
	//textrc = RectMake(_camera->getCam()->x + 80, _camera->getCam()->y + 20, 500, 150);
	//textrc = RectMake(37 + _camera->getCam()->x + 20, 255 + _camera->getCam()->y + 10, 565, 130);
	
	ghostFrame();
	TextControlUpdate();
	if (misss)
	{
		count++;

		if (count > 100)
		{
			misss = false;

		}

	}
	if (atts)
	{
		if (tcount % 7 == 0)att++;
		attack->setFrameX(att);
	}
	if (sticks)
	{
		if (tcount % 7 == 0)stickindex++;
		stick->setFrameX(stickindex);
		if (stickindex > stick->getMaxFrameX())stickindex = 0;

	}
	
	lvnum->setFrameX(_player->getPlayer()->Lv);
	onenum2->setFrameX(_player->getPlayer()->MaxHp % 10);
	tennum2->setFrameX((_player->getPlayer()->MaxHp - (_player->getPlayer()->MaxHp % 10)) / 10);
	onenum->setFrameX(_player->getPlayer()->CurHp % 10);
	tennum->setFrameX((_player->getPlayer()->CurHp - (_player->getPlayer()->CurHp % 10)) / 10);
}

void stage15battle::render()
{
	
	
	IMAGEMANAGER->findImage("bt2")->render(getMemDC(), 15 + _camera->getCam()->x, 9 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("fight")->frameRender(getMemDC(), 31 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("act")->frameRender(getMemDC(), 184 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("item")->frameRender(getMemDC(), 337 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	IMAGEMANAGER->findImage("mercy")->frameRender(getMemDC(), 490 + _camera->getCam()->x, 432 + _camera->getCam()->y);
	
	
	
	

	IMAGEMANAGER->findImage("ghost")->frameRender(getMemDC(), 271, 113);

	
	IMAGEMANAGER->findImage("lv05")->render(getMemDC(), 29 + _camera->getCam()->x, 397 + _camera->getCam()->y);
IMAGEMANAGER->findImage("lvnum")->frameRender(getMemDC(), 110, 405);
IMAGEMANAGER->findImage("tennum")->frameRender(getMemDC(), 313, 405);
IMAGEMANAGER->findImage("onenum")->frameRender(getMemDC(), 328, 405);
IMAGEMANAGER->findImage("tennum2")->frameRender(getMemDC(), 376, 405);
IMAGEMANAGER->findImage("onenum2")->frameRender(getMemDC(), 391, 405);
IMAGEMANAGER->findImage("hpminn")->render(getMemDC(), 274 + _camera->getCam()->x, 402 + _camera->getCam()->y, 0, 0, _player->getPlayer()->MaxHp , 21);
IMAGEMANAGER->findImage("hpmaxn")->render(getMemDC(), 274 + _camera->getCam()->x, 401 + _camera->getCam()->y+1, 0, 0, _player->getPlayer()->CurHp , 21);


	if (misss)IMAGEMANAGER->findImage("miss")->render(getMemDC(), 250 + _camera->getCam()->x, 70 + _camera->getCam()->y);
if (atts)IMAGEMANAGER->findImage("attack")->frameRender(getMemDC(), 280 + _camera->getCam()->x, 50 + _camera->getCam()->y);
//IMAGEMANAGER->findImage("tls1")->frameRender(getMemDC(), 214, -1);
	

if (tlstks)tlstk();

if (textrc2s)IMAGEMANAGER->findImage("....")->render(getMemDC(), 410, 135);
if (textrc3s)IMAGEMANAGER->findImage("eotk")->render(getMemDC(), 410, 135);
	TextControl();
	if (actchoices)actchoice();
	if (mercychoices)mercychoice();
	if (fightchoices)fightchoice();
	if (fightgages)fightgage();
	if (fightatts)fightatt();
	if (fightatt2s1)fightatt2();
	if (fightmisss)fightmiss();
	//Rectangle(getMemDC(), textrc.left, textrc.top, textrc.right, textrc.bottom);
IMAGEMANAGER->findImage("bttbf")->frameRender(getMemDC(), 32 + _camera->getCam()->x, 250 + _camera->getCam()->y);
	
	//if (resetbulls)resetbull();
	if (ptt1s)ptt1();
	if (ptt2s)ptt2();
	if (pttcos)pttco();

	if (plays)play();
}
void stage15battle::ghostFrame()
{
	if(!tlstks)ghost->setFrameX(index1);
	bull123->setFrameX(indexbull);
	bull1234->setFrameX(indexbull);
	count1++;
	if (count1 % 5 == 0)indexbull++;
	if (indexbull > bull123->getMaxFrameX())indexbull = 0;

	if (index1 > ghost->getMaxFrameX())
	{
		index1 = 0;
	}
	else if (count1 % 10 == 0)index1++;


	if(!rlqns3)bttbf->setFrameX(bttbcount);
	if (bttbs)
	{
		if (bttbcount < 20)
		{
			if (count1 % 2 == 0)bttbcount++;
		}
	}
	if (!bttbs)
	{
		if (bttbcount > 0)
		{
			if (count1 % 2 == 0)bttbcount-=1;
		}
	}


}

void stage15battle::TextControl()
{
	
HANDLE hInputFile;
	if (textnum == 0)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/ghost1.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 2)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/2.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 3)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/3.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 4)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/4.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 5)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/5.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 7)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/7.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 22)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/22.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 24)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/24.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 26)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/26.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 28)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/28.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 30)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/30.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 32)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/32.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 34)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/34.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 41)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/41.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 43)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/43.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 45)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/45.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 46)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/46.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 47)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/47.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 50)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/50.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 51)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/51.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 52)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/52.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 60)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/60.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 61)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/61.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 62)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/62.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 63)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/63.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 64)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/64.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 65)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/65.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 66)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/66.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 70)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/70.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 71)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/71.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 72)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/72.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 73)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/73.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 74)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/74.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 75)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/75.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
	if (textnum == 76)
		hInputFile = CreateFile(_T("image/undertale/battle/stage15battle/76.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);

	if (!textrc2s&&!textrc3s)
	{
		HFONT font = CreateFont(40, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																													//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)

		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		TCHAR buf[100] = _T("");
		DWORD dwRead;



		ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
		CloseHandle(hInputFile);

		//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
		DrawText(getMemDC(), buf, tindex, &textrc, DT_LEFT);
		DeleteObject(font);
		font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		DeleteObject(font);
	}
	if (textrc2s)
	{
		HFONT font = CreateFont(23, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																													//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)

		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		TCHAR buf[100] = _T("");
		DWORD dwRead;



		ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
		CloseHandle(hInputFile);

		//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
		DrawText(getMemDC(), buf, tindex, &textrc2, DT_LEFT);
		DeleteObject(font);
		font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		DeleteObject(font);
	}
	if (textrc3s)
	{
		HFONT font = CreateFont(23, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "고딕");//글꼴생성
																													//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)

		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		TCHAR buf[100] = _T("");
		DWORD dwRead;



		ReadFile(hInputFile, buf, 999 * sizeof(TCHAR), &dwRead, NULL);
		CloseHandle(hInputFile);

		//TextOut(getMemDC(), 80, 200, buf, 2 * tindex);
		DrawText(getMemDC(), buf, tindex, &textrc3, DT_LEFT);
		DeleteObject(font);
		font = CreateFont(20, 0, 0, 0, 0, 0, 0, 00, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, NULL);
		SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		DeleteObject(font);
	}
}

void stage15battle::play()
{
	_player->getPlayer()->x = plhx;
	_player->getPlayer()->y = plhy;
	plh = RectMakeCenter(plhx, plhy, 16, 16);
	//Rectangle(getMemDC(), plh.left, plh.top, plh.right, plh.bottom);
	if (KEYMANAGER->isStayDown(VK_LEFT))
	{

		plhx -= 1;
	}
	if (KEYMANAGER->isStayDown(VK_RIGHT))
	{
		plhx += 1;
	}
	if (KEYMANAGER->isStayDown(VK_UP))
	{
		plhy -= 1;
	}
	if (KEYMANAGER->isStayDown(VK_DOWN))
	{
		plhy += 1;
	}
	if (!rlqns2)
	{
		if (plh.right > bbox.right - 3)plhx -= 2;
		if (plh.left < bbox.left + 3)plhx += 2;
		if (plh.bottom > bbox.bottom - 3)plhy -= 2;
		if (plh.top < bbox.top + 3)plhy += 2;
	}
	if (rlqns2)
	{
		if (plh.right > bbox2.right - 3)plhx -= 2;
		if (plh.left < bbox2.left + 3)plhx += 2;
		if (plh.bottom > bbox2.bottom - 3)plhy -= 2;
		if (plh.top < bbox2.top + 3)plhy += 2;
	}
	
	if(vlxkss)IMAGEMANAGER->findImage("heart")->render(getMemDC(), plh.left, plh.top);
	if (!vlxkss)
	{
		if(vlxkscount%5==0)IMAGEMANAGER->findImage("heart")->render(getMemDC(), plh.left, plh.top);
	}
}

void stage15battle::choice()
{
	if (fights)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			fights = false;
			mercys = true;
			fight->setFrameX(1);
			mercy->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			fights = false;
			acts = true;
			fight->setFrameX(1);
			act->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			textnum = 2;
			fightchoices = true;
			start = false;
			fight->setFrameX(2);
			
		}

	}
	if (mercys)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			mercys = false;
			items = true;
			mercy->setFrameX(1);
			item->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			mercys = false;
			fights = true;
			mercy->setFrameX(1);
			fight->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			textnum = 3;
			mercychoices = true;
			start = false;
			mercy->setFrameX(2);
		}
	}
	if (acts)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			acts = false;
			fights = true;
			act->setFrameX(1);
			fight->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			acts = false;
			items = true;
			act->setFrameX(1);
			item->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			textnum = 2;
			actchoices = true;
			start = false;
			act->setFrameX(2);
		}
	}
	if (items)
	{
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			items = false;
			acts = true;
			item->setFrameX(1);
			act->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			items = false;
			mercys = true;
			item->setFrameX(1);
			mercy->setFrameX(0);
		}
	/*	if (KEYMANAGER->isOnceDown('Z'))
		{
			

		}*/
	}
}

void stage15battle::fightchoice()
{
	IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
	
	IMAGEMANAGER->findImage("hp2")->render(getMemDC(), 320 + _camera->getCam()->x, 272 + _camera->getCam()->y,0,0,88,13);
	IMAGEMANAGER->findImage("hp")->render(getMemDC(), 321 + _camera->getCam()->x, 273 + _camera->getCam()->y, 0, 0, hpx, 13);
	
	if (KEYMANAGER->isOnceDown('X'))
	{
		fightchoices = false;
		start = true;
		tindex = 0;
		textnum = textnum2;
		fight->setFrameX(0);
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		if (!SOUNDMANAGER->isPlaySound("pointselect"))
		{
			SOUNDMANAGER->play("pointselect", 1.f);
		}
		
		fightgages = true;
		fightchoices = false;
	}
}

void stage15battle::fightgage()
{
	IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
	IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
	if (!sticks)
	{
		stickx += 2;
	}
	if (KEYMANAGER->isOnceDown('Z'))
	{
		if (!SOUNDMANAGER->isPlaySound("pointselect"))
		{
			SOUNDMANAGER->play("pointselect", 1.f);
		}
		SOUNDMANAGER->play("playerattack", 1.f);
		sticks = true;
		atts = true;
		fightgages = false;
		fightatts = true;
		textnum = 100;
		tindex = 0;
	}
	if (stickx>596)
	{

		fightgages = false;
		fightmisss = true;
		textnum = textnum3;
		count = 0;
		tindex = 0;
		textrc2s = true;
	}
}

void stage15battle::fightatt()
{
	if (fcount2 == 0)
	{
		IMAGEMANAGER->findImage("gage")->render(getMemDC(), textrc.left, textrc.top);
		IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
		if (att > attack->getMaxFrameX())
		{
			fightatt2s1 = true;
			fcount2 = 1;
			te = (312 - stickx) / te2;
			atts = false;
			
		}
	}
	if (fcount2 == 1)
	{
	
		IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
		if(fightatt2s1)IMAGEMANAGER->findImage("stick")->frameRender(getMemDC(), stickx + _camera->getCam()->x, 255 + _camera->getCam()->y);
		if (fightatt2s1 == false)
		{
			sticks = false;
			fcount4++;
			if (fcount4 % 5 == 0)fcount5++;
			gagef->setFrameX(fcount5);
			if (hpx > 0)
			{
				if (!lastpraise)
				{
					textnum = textnum3;
					textrc2s = true;
					if (gagef->getMaxFrameX() == fcount5)fcount2 = 2;
				}
				if (lastpraise)
				{
					textnum = 66;
					if (gagef->getMaxFrameX() == fcount5)fcount2 = 3;
					tindex = 0;
					textrc2s = true;
				}
			}
			if (hpx < 1)
			{
				textrc3s = true;
				textnum = 70;
				if (tindex > 42)
				{
					if (KEYMANAGER->isOnceDown('Z'))
					{
						fcount2 = 4;
						tindex = 0;
						textnum = 71;
					}
				}
				

				
			}
		}
	}
	if (fcount2 == 2)
	{
		if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				interimclosings = true;
				tindex = 0;
				textnum = 100;
				textrc2s = false;

			}
		}
	}
	if (fcount2 == 3)
	{
		textrc2s = false;
		lastpraise = false;
		tlstks = false;
		tlsindex = 0;
		praisecount = 0;
		textnum = 99;
		textnum2 = textnum6;
		textnum4 = 50;
		textnum5 = 60;
		interimclosings = true;
	}
	if (fcount2 == 4)
	{
		if (tindex > 33)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				fcount2 = 5;
				tindex = 0;
				textnum = 72;
			}
		}
	}
	if (fcount2 == 5)
	{
		if (tindex > 45)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				fcount2 = 6;
				tindex = 0;
				textnum = 73;
			}
		}
	}
	if (fcount2 == 6)
	{
		if (tindex > 31)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				fcount2 = 7;
				tindex = 0;
				textnum = 74;
			}
		}
	}
	if (fcount2 == 7)
	{
		if (tindex > 29)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				fcount2 = 8;
				tindex = 0;
				textnum = 75;
			}
		}
	}
	if (fcount2 == 8)
	{
		if (tindex > 9)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				fcount2 = 9;
				tindex = 0;
				textnum = 99;
				textrc3s = false;
			}
		}
	}
	if (fcount2 == 9)
	{
		dkdkdk++;
		if (dkdkdk % 10 == 0)dkdkdk2++;
		IMAGEMANAGER->findImage("napd")->frameRender(getMemDC(), 190, 50);
		napd->setFrameX(dkdkdk2);
		if (dkdkdk2 > 9)
		{
			textnum = 76;
		}
		if (tindex > 31)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				_player->getPlayer()->CurExp -= 1;
				_player->getPlayer()->killghost = true;
				SCENEMANAGER->changeScene("stage15");
				
				//전투종료 경험치1까임
			}
		}
	}
}

void stage15battle::fightatt2()
{
	fcount7++;
	IMAGEMANAGER->findImage("hp2")->render(getMemDC(), 276 + _camera->getCam()->x, 89 + _camera->getCam()->y, 0, 0, 88, 13);
	IMAGEMANAGER->findImage("hp")->render(getMemDC(), 277 + _camera->getCam()->x, 90 + _camera->getCam()->y, 0, 0, hpx, 13);
	if (te>0)epa = rhd * (2 - te);
	if (te<0)epa = rhd * (2 + te);
	if (te == 0)epa = rhd * 2;
	epa2 = epa;
	if (hpx>hpx2 - epa2 && hpx>0)hpx -= 1;
	HFONT font = CreateFont(45, 25, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "맑은 고딕");//글꼴생성		//폰트높이, 넓이, 전체문자열각도, 개별문자열각도, 굵기, 문자속성, 문자글꼴, 출력정확도, 클리핑정확도, ... ,.... ,...)
	SetTextColor(getMemDC(), RGB(255, 0, 0));
	SelectObject(getMemDC(), font);

	char str11[128];
	sprintf_s(str11, "%d", epa2);
	TextOut(getMemDC(), dbox.left, dbox.top, str11, strlen(str11));
	if (fcount6 == 0)
	{
		if (dboxy > 30)dboxy -= 1;
		if (fcount7>38)fcount6 = 1;
	}
	if (fcount6 == 1)
	{
		if (dboxy < 50)dboxy += 1;
	}
	if (fcount7 > 160)fightatt2s1 = false;
}

void stage15battle::fightmiss()
{
	
		IMAGEMANAGER->findImage("gagef")->frameRender(getMemDC(), textrc.left, textrc.top);
	fcount4++;
	if (fcount4 % 5 == 0)fcount5++;
	gagef->setFrameX(fcount5);
	if (count < 1)misss = true;
	
	if (textlast == true)
	{
		if (KEYMANAGER->isOnceDown('Z'))
		{
			interimclosings = true;
			tindex = 0;
			textnum = 100;
			textrc2s = false;

		}
	}
			
	
	
}

void stage15battle::actchoice()
{
	if (next == 0)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown('X'))
		{
			actchoices = false;
			start = true;
			tindex = 0;
			textnum = textnum2;
			act->setFrameX(0);
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 1;
			textnum = 4;
		}
	}
	if (next == 1)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 3;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 3;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 5;
			tindex = 0;
			textnum = 5;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 0;
			textnum = 2;
		}
	}
	if (next == 2)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 295 + _camera->getCam()->x, 270 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{

			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 4;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 4;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 7;
			tindex = 0;
			textnum = 43;
			textrc2s = true;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 0;
			textnum = 2;
		}
	}
	if (next == 3)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 310 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 4;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 4;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 1;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 1;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			next = 8;
			tindex = 0;
			textnum = 7;
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			next = 0;
			textnum = 2;
		}
	}
	if (next == 4)
	{
		IMAGEMANAGER->findImage("heart")->render(getMemDC(), 295 + _camera->getCam()->x, 310 + _camera->getCam()->y);
		if (KEYMANAGER->isOnceDown(VK_LEFT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 3;
		}
		if (KEYMANAGER->isOnceDown(VK_RIGHT))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 3;
		}
		if (KEYMANAGER->isOnceDown(VK_DOWN))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 2;
		}
		if (KEYMANAGER->isOnceDown(VK_UP))
		{
			if (!SOUNDMANAGER->isPlaySound("pointmove"))
				SOUNDMANAGER->play("pointmove", 1.f);
			next = 2;
		}
		if (KEYMANAGER->isOnceDown('Z'))
		{
			if (!SOUNDMANAGER->isPlaySound("pointselect"))
			{
				SOUNDMANAGER->play("pointselect", 1.f);
			}
			if (praisecount != 4)
			{
				next = 10;
				tindex = 0;
				textnum = textnum4;
				praisecount += 1;
				praise = true;
			}
			if (praisecount == 4)
			{
					next = 19;
					tindex = 0;
					textnum = textnum5;
					textrc2s = true;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			next = 0;
			textnum = 2;
		}
	}
	if (next == 5)
	{
		if (tindex > 81)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				next = 6;
				tindex = 0;
				textnum = 41;
				textrc2s = true;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 99;
		}

	}
	if (next == 6)
	{
		if (tindex > 20)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				textrc2s = false;
				interimclosings = true;
				tindex = 0;
				textnum = 99;
			}
		}
	}
	if (next == 7)
	{
		if (tindex > 13)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				textrc2s = false;
				interimclosings = true;
				tindex = 0;
				textnum = 99;
			}
		}
	}
	if (next == 8)
	{
		if (tindex > 47)
		{
			if (!lastpraise)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					if (!SOUNDMANAGER->isPlaySound("pointselect"))
					{
						SOUNDMANAGER->play("pointselect", 1.f);
					}
					next = 9;
					tindex = 0;
					textnum = 45;
					textrc2s = true;
				}
			}
			if (lastpraise)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					if (!SOUNDMANAGER->isPlaySound("pointselect"))
					{
						SOUNDMANAGER->play("pointselect", 1.f);
					}
					textnum = 66;
					next = 17;
					tindex = 0;
					textrc2s = true;
				}
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 99;
		}
	}
	if (next == 9)
	{
		if (tindex > 15)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				textrc2s = false;
				interimclosings = true;
				tindex = 0;
				textnum = 99;
			}
		}
	}
	if (next == 10)
	{
		if (textlast==true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				next = 11;
				tindex = 0;
				textnum = textnum5;
				textrc2s = true;
			}
		}
		if (KEYMANAGER->isOnceDown('X'))
		{
			tindex = 99;
		}
	}
	if (next == 11)
	{
		textlast = false;
		next = 12;
	}
	if (next == 12)
	{
		if (textlast == true)
		{
			if (praisecount == 3)
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					if (!SOUNDMANAGER->isPlaySound("pointselect"))
					{
						SOUNDMANAGER->play("pointselect", 1.f);
					}
					next = 13;
					tindex = 0;
					//textnum = 63;
					textnum = 99;
				}
			}
			
			else
			{
				if (KEYMANAGER->isOnceDown('Z'))
				{
					if (!SOUNDMANAGER->isPlaySound("pointselect"))
					{
						SOUNDMANAGER->play("pointselect", 1.f);
					}
					textrc2s = false;
					interimclosings = true;
					tindex = 0;
					textnum = 99;
					textnum6 = textnum2;
				}
			}
		}
	}
	if (next == 13)
	{
		textlast = false;
		next = 14;
		bttbs = true;
		plays = true;
		resetbulls = false;
		textrc2s = false;
	}
	if (next == 14)
	{
		tlstks = true;
		if (tlsindex == 102)next = 15;
		/*if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 15;
				tindex = 0;
				textnum = 64;
			}
		}*/
	}
	if (next == 15)
	{
		textlast = false;
		next = 16;
	}
	if (next == 16)
	{
		/*if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				next = 18;
				textrc2s = false;
				bttbs = false;
				plays = false;
				tindex = 0;
				textnum = 99;
				textnum2 = 47;
				textnum5 = 65;
				lastpraise = true;
				resetbulls = true;
				
			}
		}*/
		next = 18;
		textrc2s = false;
		bttbs = false;
		plays = false;
		tindex = 0;
		textnum = 99;
		textnum2 = 47;
		textnum5 = 65;
		lastpraise = true;
		resetbulls = true;
	}
	if (next == 17)
	{
		if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				textrc2s = false;
				lastpraise = false;
				tlstks = false;
				tlsindex = 0;
				praisecount = 0;
				textnum = 99;
				textnum2 = textnum6;
				textnum4 = 50;
				textnum5 = 60;
				interimclosings = true;
			}
		}
	}
	if (next == 18)
	{
		if (bttbf->getFrameX() == 0)
		{
			start = true;
			textnum = 47;
			actchoices = false;
			act->setFrameX(0);
			next = 0;
		}
	}
	if (next == 19)
	{
		if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{

				_player->getPlayer()->ghostend = true;
				SCENEMANAGER->changeScene("stage15");
				//응원하기 전투종료
			}
		}
	}
	

}

void stage15battle::mercychoice()
{
	if (next == 0)
	{
			IMAGEMANAGER->findImage("heart")->render(getMemDC(), 55 + _camera->getCam()->x, 270 + _camera->getCam()->y);
			
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				next = 1;
				textnum = 99;
				tindex = 0;
			}
			if (KEYMANAGER->isOnceDown('X'))
			{
				mercychoices = false;
				start = true;
				tindex = 0;
				textnum = textnum2;
				mercy->setFrameX(0);
			}
	}
	if (next == 1)
	{
		textrc2s = true;
		textnum = textnum3;
		if (textlast == true)
		{
			if (KEYMANAGER->isOnceDown('Z'))
			{
				if (!SOUNDMANAGER->isPlaySound("pointselect"))
				{
					SOUNDMANAGER->play("pointselect", 1.f);
				}
				next = 2;
				textrc2s = false;
				textlast = false;
				tindex = 0;
				textnum = 99;
			}
		}
	}
	if (next == 2)
	{
		interimclosings = true;
	}
}

void stage15battle::resetbull()
{
	for (int i = 0; i < 100; i++)
	{
		
	    bullx[i] = 320;
		bully[i] = 150;
			
		_bullet[i].puspeed = 0.1;
		_bullet[i].fires = false;
		_bullet[i].rctpfh = RectMakeCenter(bullx[i], bully[i], 6, 18);
		_bullet[i].rcrkfh = RectMakeCenter(bullx[i], bully[i], 18, 6);
		_bullet[i].ups = false;
	
		_bullet[i].rights = false;
		_bullet[i].lefts = false;
		_bullet[i].downs = false;
		
		//Rectangle(getMemDC(), _bullet[i].rctpfh.left, _bullet[i].rctpfh.top, _bullet[i].rctpfh.right, _bullet[i].rctpfh.bottom);
		//Rectangle(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rcrkfh.top, _bullet[i].rcrkfh.right, _bullet[i].rcrkfh.bottom);
		bull2x[i] = 350;
		bull2y[i] = 160;
		
		_bullet2[i].puspeed = 0.1;
		_bullet2[i].fires = false;
		_bullet2[i].rctpfh = RectMakeCenter(bull2x[i], bull2y[i], 6, 18);
		_bullet2[i].rcrkfh = RectMakeCenter(bull2x[i], bull2y[i], 18, 6);
		_bullet2[i].ups = false;

		_bullet2[i].rights = false;
		_bullet2[i].lefts = false;
		_bullet2[i].downs = false;

		/////////////////////////////////////////////////
		_bullet3[i].fires = false;

		_bullet3[0].puspeed = 0.8;
		_bullet3[0].la = false;
		_bullet3[1].puspeed = 0.7;
		_bullet3[1].la = true;
		_bullet3[2].puspeed = -0.6;
		_bullet3[2].la = false;
		_bullet3[3].puspeed = -1.2;
		_bullet3[3].la = true;
		_bullet3[4].puspeed = -0.4;
		_bullet3[4].la = false;
		_bullet3[5].puspeed = 0.4;
		_bullet3[5].la = true;
		_bullet3[6].puspeed = 1.0;
		_bullet3[6].la = false;
		_bullet3[7].puspeed = -0.9;
		_bullet3[7].la = true;
		_bullet3[8].puspeed = -1.1;
		_bullet3[8].la = false;
		_bullet3[9].puspeed = -1.0;
		_bullet3[9].la = true;
		_bullet3[10].puspeed = -1.0;
		_bullet3[10].la = false;
		_bullet3[11].puspeed = 0.8;
		_bullet3[11].la = false;
		_bullet3[12].puspeed = -0.8;
		_bullet3[12].la = false;

		_bullet3[i].rcbullla = RectMakeCenter(bullx[i], bully[i], 9, 14);
		_bullet3[i].rcbullsm = RectMakeCenter(bullx[i], bully[i], 7, 11);
		////////////////////////////////////////////////////////////////////////////
		_bullet4[i].fires = false;

		_bullet4[0].puspeed = 0.65;
		_bullet4[0].la = true;
		_bullet4[1].puspeed = -1.3;
		_bullet4[1].la = false;
		_bullet4[2].puspeed = -0.9;
		_bullet4[2].la = true;
		_bullet4[3].puspeed = -0.85;
		_bullet4[3].la = false;
		_bullet4[4].puspeed = -0.4;
		_bullet4[4].la = true;
		_bullet4[5].puspeed = -1.25;
		_bullet4[5].la = false;
		_bullet4[6].puspeed = 0.2;
		_bullet4[6].la = false;
		_bullet4[7].puspeed = 0.8;
		_bullet4[7].la = false;
		_bullet4[8].puspeed = -1.1;
		_bullet4[8].la = true;
		_bullet4[9].puspeed = 0.5;
		_bullet4[9].la = true;
		_bullet4[10].puspeed = 0.6;
		_bullet4[10].la = true;
		_bullet4[11].puspeed = -1.1;
		_bullet4[11].la = false;
		_bullet4[12].puspeed = 0.7;
		_bullet4[12].la = false;



		_bullet4[i].rcbullla = RectMakeCenter(bull2x[i], bull2y[i], 9, 14);
		_bullet4[i].rcbullsm = RectMakeCenter(bull2x[i], bull2y[i], 7, 11);

	}
	firecount = 0;
	fireindex = 0;
	plhx = 321;
	plhy = 318;

	//시험삼아
	/*for (int i = 0; i < 100; i++)
	{
		IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
	}*/
	


}

void stage15battle::pttco()
{
	if (rlqns2)
	{
		resetbulls = false;
		rlqns3 = true;
		rlqnsc++;
		bttbf->setFrameX(rlqnsi);
		if (rlqnsn == 0)
		{
				if (rlqnsi < 15)
				{
					if (rlqnsc % 2 == 0)rlqnsi++;
				}
				if (rlqnsi == 15)
				{
					plays = true;
					IMAGEMANAGER->findImage("gibun")->render(getMemDC(), 202 + _camera->getCam()->x, 255 + _camera->getCam()->y);
				}
				if (rlqnsc > 500)rlqnsn = 1;
				
		}
		if (rlqnsn == 1)
		{
			if (rlqnsi > 0)
			{
				plays = false;
				if (rlqnsc % 2 == 0)rlqnsi -= 1;
			}
			if (rlqnsi == 0)
			{
				rlqns1 = false;
				rlqns2 = false;
				pttcos = false;
				closings = true;
				rlqns3 = false;
			}
		}


	}
	else
	{
		if (ptt1sco)
		{
			bttbs = true;
			ptt1s = true;
			pttcos = false;
			resetbulls = false;
			plays = true;
		}
		if (!ptt1sco)
		{
			bttbs = true;
			ptt2s = true;
			pttcos = false;
			resetbulls = false;
			plays = true;
		}
	}

}

void stage15battle::ptt1()
{
	firecount++;
	if (firecount > 650)
	{
		ptt1s = false;
		closings = true;
		resetbulls = true;
		ptt1sco = false;
		
	}

	if (fireindex < 100)
	{
		if (firecount % 28 == 0)fireindex++;
	}
	for (int i = 0; i < fireindex; i++)
	{
		_bullet[i].fires = true;
		_bullet2[i].fires = true;
	}
	
	
	for (int i = 0; i < 100; i++)
	{
		if (_bullet[i].lefts == false && _bullet[i].ups == false&& _bullet[i].rights == false&& _bullet[i].downs == false)
		{
			if (_bullet[i].fires == true)
			{
				bullx[i] += 0.2;
				//bully[i] += 2.3;
				bully[i] += _bullet[i].puspeed;
				if (firecount % 10 == 0)_bullet[i].puspeed += 0.2;
				IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rctpfh.top);
			}
		}
		if (_bullet[i].lefts == true)
		{
			bullx[i] -= _bullet[i].puspeed;
			if (firecount % 10 == 0)_bullet[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull1234")->frameRender(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rctpfh.top);
		}
		if (_bullet[i].ups == true)
		{
			bully[i] -= _bullet[i].puspeed;
			if (firecount % 10 == 0)_bullet[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rctpfh.top);
		}
		if (_bullet[i].rights == true)
		{
			bullx[i] += _bullet[i].puspeed;
			if (firecount % 10 == 0)_bullet[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull1234")->frameRender(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rctpfh.top);
		}
		if (_bullet[i].downs == true)
		{
			bully[i] += _bullet[i].puspeed;
			if (firecount % 10 == 0)_bullet[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rctpfh.top);
		}



		if (_bullet[i].rctpfh.bottom>bbox.bottom)
		{
			bully[i]= bully[i] - 1;
			_bullet[i].lefts = true;
			_bullet[i].puspeed = 0.1;
			
		}
		if (_bullet[i].rcrkfh.left<bbox.left)
		{
			bullx[i] = bullx[i] + 1;
			_bullet[i].lefts = false;
			_bullet[i].ups = true;
			_bullet[i].puspeed = 0.1;
			
		}
		if (_bullet[i].ups == true)
		{
			if (_bullet[i].rctpfh.top < bbox.top)
			{
				_bullet[i].ups = false;
				_bullet[i].rights = true;
				_bullet[i].puspeed = 0.1;
			
			}
			
		}
		if (_bullet[i].rights == true)
		{
			if (bullx[i]>plhx)
			{
				_bullet[i].rights = false;
				_bullet[i].downs = true;
				_bullet[i].puspeed = 0.1;
				
			}
		}
		if (_bullet[i].downs == true)
		{
			if (_bullet[i].rctpfh.bottom>bbox.bottom)
			{
				_bullet[i].downs = false;
				_bullet[i].lefts = true;
				_bullet[i].puspeed = 0.1;
				
			}
		}
		_bullet[i].rctpfh = RectMakeCenter(bullx[i], bully[i], 6, 18);
		_bullet[i].rcrkfh = RectMakeCenter(bullx[i], bully[i], 18, 6);
		//Rectangle(getMemDC(), _bullet[i].rctpfh.left, _bullet[i].rctpfh.top, _bullet[i].rctpfh.right, _bullet[i].rctpfh.bottom);
		//Rectangle(getMemDC(), _bullet[i].rcrkfh.left, _bullet[i].rcrkfh.top, _bullet[i].rcrkfh.right, _bullet[i].rcrkfh.bottom);


		if (_bullet2[i].lefts == false && _bullet2[i].ups == false && _bullet2[i].rights == false && _bullet2[i].downs == false)
		{
			if (_bullet2[i].fires == true)
			{
				bull2x[i] += 0.2;
				bull2y[i] += _bullet2[i].puspeed;
				if (firecount % 10 == 0)_bullet2[i].puspeed += 0.2;
				IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
			}
		}
		if (_bullet2[i].rights == true)
		{
			bull2x[i] += _bullet2[i].puspeed;
			if (firecount % 10 == 0)_bullet2[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull1234")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
		}
		if (_bullet2[i].ups == true)
		{
			bull2y[i] -= _bullet2[i].puspeed;
			if (firecount % 10 == 0)_bullet2[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
		}
		if (_bullet2[i].lefts == true)
		{
			bull2x[i] -= _bullet2[i].puspeed;
			if (firecount % 10 == 0)_bullet2[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull1234")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
		}
		if (_bullet2[i].downs == true)
		{
			bull2y[i] += _bullet2[i].puspeed;
			if (firecount % 10 == 0)_bullet2[i].puspeed += 0.2;
			IMAGEMANAGER->findImage("bull123")->frameRender(getMemDC(), _bullet2[i].rcrkfh.left, _bullet2[i].rctpfh.top);
		}


		if (_bullet2[i].rctpfh.bottom>bbox.bottom)
		{
			bull2y[i] = bull2y[i] - 1;
			_bullet2[i].rights = true;
			_bullet2[i].puspeed = 0.1;

		}
		if (_bullet2[i].rcrkfh.right>bbox.right)
		{
			bull2x[i] = bull2x[i] - 1;
			_bullet2[i].rights = false;
			_bullet2[i].ups = true;
			_bullet2[i].puspeed = 0.1;
		}
		if (_bullet2[i].ups == true)
		{
			if (_bullet2[i].rctpfh.top < bbox.top)
			{
				_bullet2[i].ups = false;
				_bullet2[i].lefts = true;
				_bullet2[i].puspeed = 0.1;
			}
		}
		if (_bullet2[i].lefts == true)
		{
			if (bull2x[i]<plhx)
			{
				_bullet2[i].lefts = false;
				_bullet2[i].downs = true;
				_bullet2[i].puspeed = 0.1;
			}
		}
		if (_bullet2[i].downs == true)
		{
			if (_bullet2[i].rctpfh.bottom>bbox.bottom)
			{
				_bullet2[i].downs = false;
				_bullet2[i].rights = true;
				_bullet2[i].puspeed = 0.1;

			}
		}
		_bullet2[i].rctpfh = RectMakeCenter(bull2x[i], bull2y[i], 6, 18);
		_bullet2[i].rcrkfh = RectMakeCenter(bull2x[i], bull2y[i], 18, 6);



		
	}

	
}

void stage15battle::ptt2()
{
	if (firecount > 400)
	{
		ptt2s = false;
		closings = true;
		resetbulls = true;
		ptt1sco = true;
	}
	firecount++;
	if (fireindex < 13)
	{
		if (firecount % 28 == 0)fireindex++;
	}
	for (int i = 0; i < fireindex; i++)
	{
		_bullet3[i].fires = true;
		_bullet4[i].fires = true;
	}


	for (int i = 0; i < 100; i++)
	{

		if (_bullet3[i].fires == true)
		{
			bullx[i] += _bullet3[i].puspeed;

			if (_bullet3[i].puspeed > 0)
			{
				_bullet3[i].puspeed -= 0.01;
			}
			if (_bullet3[i].puspeed < 0)
			{
				_bullet3[i].puspeed += 0.01;
			}
			if (_bullet3[i].la == true)
			{
				bully[i] += 1.3;
				
			}
			if (_bullet3[i].la == false)
			{
				bully[i] += 1.0;
				
			}
			if (_bullet3[0].fires == true)IMAGEMANAGER->findImage("bullsmr")->frameRender(getMemDC(), _bullet3[0].rcbullsm.left, _bullet3[0].rcbullsm.top);
			if (_bullet3[1].fires == true)IMAGEMANAGER->findImage("bulllar")->frameRender(getMemDC(), _bullet3[1].rcbullla.left, _bullet3[1].rcbullla.top);
			if (_bullet3[2].fires == true)IMAGEMANAGER->findImage("bullsml")->frameRender(getMemDC(), _bullet3[2].rcbullsm.left, _bullet3[2].rcbullsm.top);
			if (_bullet3[3].fires == true)IMAGEMANAGER->findImage("bulllal")->frameRender(getMemDC(), _bullet3[3].rcbullla.left, _bullet3[3].rcbullla.top);
			if (_bullet3[4].fires == true)IMAGEMANAGER->findImage("bullsml1")->frameRender(getMemDC(), _bullet3[4].rcbullsm.left, _bullet3[4].rcbullsm.top);
			if (_bullet3[5].fires == true)IMAGEMANAGER->findImage("bulllar1")->frameRender(getMemDC(), _bullet3[5].rcbullla.left, _bullet3[5].rcbullla.top);
			if (_bullet3[6].fires == true)IMAGEMANAGER->findImage("bullsmr1")->frameRender(getMemDC(), _bullet3[6].rcbullsm.left, _bullet3[6].rcbullsm.top);
			if (_bullet3[7].fires == true)IMAGEMANAGER->findImage("bulllal1")->frameRender(getMemDC(), _bullet3[7].rcbullla.left, _bullet3[7].rcbullla.top);
			if (_bullet3[8].fires == true)IMAGEMANAGER->findImage("bullsml2")->frameRender(getMemDC(), _bullet3[8].rcbullsm.left, _bullet3[8].rcbullsm.top);
			if (_bullet3[9].fires == true)IMAGEMANAGER->findImage("bulllal2")->frameRender(getMemDC(), _bullet3[9].rcbullla.left, _bullet3[9].rcbullla.top);
			if (_bullet3[10].fires == true)IMAGEMANAGER->findImage("bullsml3")->frameRender(getMemDC(), _bullet3[10].rcbullsm.left, _bullet3[10].rcbullsm.top);
			if (_bullet3[11].fires == true)IMAGEMANAGER->findImage("bullsmr2")->frameRender(getMemDC(), _bullet3[11].rcbullsm.left, _bullet3[11].rcbullsm.top);
			if (_bullet3[12].fires == true)IMAGEMANAGER->findImage("bullsml4")->frameRender(getMemDC(), _bullet3[12].rcbullsm.left, _bullet3[12].rcbullsm.top);
		}
		_bullet3[i].rcbullla = RectMakeCenter(bullx[i], bully[i], 9, 14);
		_bullet3[i].rcbullsm = RectMakeCenter(bullx[i], bully[i], 7, 11);
           ///////////////////////////////////
		if (_bullet4[i].fires == true)
		{
			bull2x[i] += _bullet4[i].puspeed;

			if (_bullet4[i].puspeed > 0)
			{
				_bullet4[i].puspeed -= 0.01;
			}
			if (_bullet4[i].puspeed < 0)
			{
				_bullet4[i].puspeed += 0.01;
			}
			if (_bullet4[i].la == true)
			{
				bull2y[i] += 1.3;

			}
			if (_bullet4[i].la == false)
			{
				bull2y[i] += 1.0;

			}
			if (_bullet4[0].fires == true)IMAGEMANAGER->findImage("bulllar2")->frameRender(getMemDC(), _bullet4[0].rcbullla.left, _bullet4[0].rcbullla.top);
			if (_bullet4[1].fires == true)IMAGEMANAGER->findImage("bullsml5")->frameRender(getMemDC(), _bullet4[1].rcbullsm.left, _bullet4[1].rcbullsm.top);
			if (_bullet4[2].fires == true)IMAGEMANAGER->findImage("bulllal3")->frameRender(getMemDC(), _bullet4[2].rcbullla.left, _bullet4[2].rcbullla.top);
			if (_bullet4[3].fires == true)IMAGEMANAGER->findImage("bullsml6")->frameRender(getMemDC(), _bullet4[3].rcbullsm.left, _bullet4[3].rcbullsm.top);
			if (_bullet4[4].fires == true)IMAGEMANAGER->findImage("bulllal4")->frameRender(getMemDC(), _bullet4[4].rcbullla.left, _bullet4[4].rcbullla.top);
			if (_bullet4[5].fires == true)IMAGEMANAGER->findImage("bullsml7")->frameRender(getMemDC(), _bullet4[5].rcbullsm.left, _bullet4[5].rcbullsm.top);
			if (_bullet4[6].fires == true)IMAGEMANAGER->findImage("bullsmr3")->frameRender(getMemDC(), _bullet4[6].rcbullsm.left, _bullet4[6].rcbullsm.top);
			if (_bullet4[7].fires == true)IMAGEMANAGER->findImage("bullsmr4")->frameRender(getMemDC(), _bullet4[7].rcbullsm.left, _bullet4[7].rcbullsm.top);
			if (_bullet4[8].fires == true)IMAGEMANAGER->findImage("bulllal5")->frameRender(getMemDC(), _bullet4[8].rcbullla.left, _bullet4[8].rcbullla.top);
			if (_bullet4[9].fires == true)IMAGEMANAGER->findImage("bulllar3")->frameRender(getMemDC(), _bullet4[9].rcbullla.left, _bullet4[9].rcbullla.top);
			if (_bullet4[10].fires == true)IMAGEMANAGER->findImage("bulllar4")->frameRender(getMemDC(), _bullet4[10].rcbullla.left, _bullet4[10].rcbullla.top);
			if (_bullet4[11].fires == true)IMAGEMANAGER->findImage("bullsml8")->frameRender(getMemDC(), _bullet4[11].rcbullsm.left, _bullet4[11].rcbullsm.top);
			if (_bullet4[12].fires == true)IMAGEMANAGER->findImage("bullsmr5")->frameRender(getMemDC(), _bullet4[12].rcbullsm.left, _bullet4[12].rcbullsm.top);
		}
		_bullet4[i].rcbullla = RectMakeCenter(bull2x[i], bull2y[i], 9, 14);
		_bullet4[i].rcbullsm = RectMakeCenter(bull2x[i], bull2y[i], 7, 11);
	}
	//////sm r
	if (_bullet3[0].puspeed > 0.26)
	{
		if (_bullet3[0].puspeed > 0.52)bullsmr->setFrameX(0);
		else
		{
			bullsmr->setFrameX(1);
		}
	}
	if (_bullet3[0].puspeed < 0.26)bullsmr->setFrameX(2);
	if (_bullet3[6].puspeed > 0.33)
	{
		if (_bullet3[6].puspeed > 0.66)bullsmr1->setFrameX(0);
		else
		{
			bullsmr1->setFrameX(1);
		}
	}
	if (_bullet3[6].puspeed < 0.33)bullsmr1->setFrameX(2);
	if (_bullet3[11].puspeed > 0.26)
	{
		if (_bullet3[11].puspeed > 0.52)bullsmr2->setFrameX(0);
		else
		{
			bullsmr2->setFrameX(1);
		}
	}
	if (_bullet3[11].puspeed < 0.26)bullsmr2->setFrameX(2);
	bullsmr3->setFrameX(2);
	if (_bullet4[7].puspeed > 0.26)
	{
		if (_bullet4[7].puspeed > 0.52)bullsmr4->setFrameX(0);
		else
		{
			bullsmr4->setFrameX(1);
		}
	}
	if (_bullet4[7].puspeed < 0.26)bullsmr4->setFrameX(2);
	if (_bullet4[12].puspeed > 0.23)
	{
		if (_bullet4[12].puspeed > 0.46)bullsmr5->setFrameX(0);
		else
		{
			bullsmr5->setFrameX(1);
		}
	}
	if (_bullet4[12].puspeed < 0.23)bullsmr5->setFrameX(2);
	////////////la  r
	if (_bullet3[1].puspeed > 0.23)
	{
		if (_bullet3[1].puspeed > 0.46)bulllar->setFrameX(0);
		else
		{
			bulllar->setFrameX(1);
		}
	}
	if (_bullet3[1].puspeed < 0.23)bulllar->setFrameX(2);
	if (_bullet3[5].puspeed > 0.13)
	{
		if (_bullet3[5].puspeed > 0.26)bulllar1->setFrameX(0);
		else
		{
			bulllar1->setFrameX(1);
		}
	}
	if (_bullet3[5].puspeed < 0.13)bulllar1->setFrameX(2);
	if (_bullet4[0].puspeed > 0.21)
	{
		if (_bullet4[0].puspeed > 0.42)bulllar2->setFrameX(0);
		else
		{
			bulllar2->setFrameX(1);
		}
	}
	if (_bullet4[0].puspeed < 0.21)bulllar2->setFrameX(2);
	if (_bullet4[9].puspeed > 0.16)
	{
		if (_bullet4[9].puspeed > 0.32)bulllar3->setFrameX(0);
		else
		{
			bulllar3->setFrameX(1);
		}
	}
	if (_bullet4[9].puspeed < 0.16)bulllar3->setFrameX(2);
	if (_bullet4[10].puspeed > 0.2)
	{
		if (_bullet4[10].puspeed > 0.4)bulllar4->setFrameX(0);
		else
		{
			bulllar4->setFrameX(1);
		}
	}
	if (_bullet4[10].puspeed < 0.2)bulllar4->setFrameX(2);
	/////////////////sm  l
	if (_bullet3[2].puspeed < -0.2)
	{
		if (_bullet3[2].puspeed < -0.4)bullsml->setFrameX(0);
		else
		{
			bullsml->setFrameX(1);
		}
	}
	if (_bullet3[2].puspeed > -0.2)bullsml->setFrameX(2);
	if (_bullet3[4].puspeed < -0.13)
	{
		if (_bullet3[4].puspeed < -0.26)bullsml1->setFrameX(0);
		else
		{
			bullsml1->setFrameX(1);
		}
	}
	if (_bullet3[4].puspeed > -0.13)bullsml1->setFrameX(2);
	if (_bullet3[8].puspeed < -0.36)
	{
		if (_bullet3[8].puspeed < -0.72)bullsml2->setFrameX(0);
		else
		{
			bullsml2->setFrameX(1);
		}
	}
	if (_bullet3[8].puspeed > -0.36)bullsml2->setFrameX(2);
	if (_bullet3[10].puspeed < -0.33)
	{
		if (_bullet3[10].puspeed < -0.66)bullsml3->setFrameX(0);
		else
		{
			bullsml3->setFrameX(1);
		}
	}
	if (_bullet3[10].puspeed > -0.33)bullsml3->setFrameX(2);
	if (_bullet3[12].puspeed < -0.26)
	{
		if (_bullet3[12].puspeed < -0.52)bullsml4->setFrameX(0);
		else
		{
			bullsml4->setFrameX(1);
		}
	}
	if (_bullet3[12].puspeed > -0.26)bullsml4->setFrameX(2);
	if (_bullet4[1].puspeed < -0.43)
	{
		if (_bullet4[1].puspeed < -0.86)bullsml5->setFrameX(0);
		else
		{
			bullsml5->setFrameX(1);
		}
	}
	if (_bullet4[1].puspeed > -0.43)bullsml5->setFrameX(2);
	if (_bullet4[3].puspeed < -0.28)
	{
		if (_bullet4[3].puspeed < -0.56)bullsml6->setFrameX(0);
		else
		{
			bullsml6->setFrameX(1);
		}
	}
	if (_bullet4[3].puspeed > -0.28)bullsml6->setFrameX(2);
	if (_bullet4[5].puspeed < -0.41)
	{
		if (_bullet4[5].puspeed < -0.82)bullsml7->setFrameX(0);
		else
		{
			bullsml7->setFrameX(1);
		}
	}
	if (_bullet4[5].puspeed > -0.41)bullsml7->setFrameX(2);
	if (_bullet4[11].puspeed < -0.36)
	{
		if (_bullet4[11].puspeed < -0.72)bullsml8->setFrameX(0);
		else
		{
			bullsml8->setFrameX(1);
		}
	}
	if (_bullet4[11].puspeed > -0.36)bullsml8->setFrameX(2);
	/////////////////la  l
	if (_bullet3[3].puspeed < -0.4)
	{
		if (_bullet3[3].puspeed < -0.8)bulllal->setFrameX(0);
		else
		{
			bulllal->setFrameX(1);
		}
	}
	if (_bullet3[3].puspeed > -0.4)bulllal->setFrameX(2);
	if (_bullet3[7].puspeed < -0.3)
	{
		if (_bullet3[7].puspeed < -0.6)bulllal1->setFrameX(0);
		else
		{
			bulllal1->setFrameX(1);
		}
	}
	if (_bullet3[7].puspeed > -0.3)bulllal1->setFrameX(2);
	if (_bullet3[9].puspeed < -0.33)
	{
		if (_bullet3[9].puspeed < -0.66)bulllal2->setFrameX(0);
		else
		{
			bulllal2->setFrameX(1);
		}
	}
	if (_bullet3[9].puspeed > -0.33)bulllal2->setFrameX(2);
	if (_bullet4[2].puspeed < -0.3)
	{
		if (_bullet4[2].puspeed < -0.6)bulllal3->setFrameX(0);
		else
		{
			bulllal3->setFrameX(1);
		}
	}
	if (_bullet4[2].puspeed > -0.3)bulllal3->setFrameX(2);
	if (_bullet4[4].puspeed < -0.13)
	{
		if (_bullet4[4].puspeed < -0.26)bulllal4->setFrameX(0);
		else
		{
			bulllal4->setFrameX(1);
		}
	}
	if (_bullet4[4].puspeed > -0.13)bulllal4->setFrameX(2);
	if (_bullet4[8].puspeed < -0.36)
	{
		if (_bullet4[8].puspeed < -0.72)bulllal5->setFrameX(0);
		else
		{
			bulllal5->setFrameX(1);
		}
	}
	if (_bullet4[8].puspeed > -0.36)bulllal5->setFrameX(2);

	///////////////////////////////////////////////////////////////////////////////////////////

	
}

void stage15battle::interimclosing()
{
	if (nothings == true)
	{
		if (praisecount == 2)
		{
			textnum2 = 46;
			textnum4 = 52;
			textnum5 = 62;
			actchoices = false;
			mercychoices = false;
			fightatts = false;
			fightmisss = false;
			pttcos = true;
			interimclosings = false;
			if (textnum3 == 30)textnum3 = 31;
			if (textnum3 == 32)textnum3 = 33;
			if (textnum3 == 34)textnum3 = 35;
			
		}
		if (praisecount == 3)
		{
			textnum2 = 47;
			textnum5 = 65;
			actchoices = false;
			mercychoices = false;
			fightatts = false;
			fightmisss = false;
			pttcos = true;
			interimclosings = false;
			if (textnum3 == 30)textnum3 = 31;
			if (textnum3 == 32)textnum3 = 33;
			if (textnum3 == 34)textnum3 = 35;
			
		}
		else
		{
			if (fightatts == true)
			{
				if (textnum2 == 0)textnum2 = 21;
				if (textnum2 == 22)textnum2 = 23;
				if (textnum2 == 24)textnum2 = 25;
				if (textnum2 == 26)textnum2 = 27;
				if (textnum2 == 28)textnum2 = 29;


				if (textnum3 == 30)textnum3 = 31;
				if (textnum3 == 32)textnum3 = 33;
				if (textnum3 == 34)textnum3 = 35;
				pttcos = true;
				fightatts = false;
				interimclosings = false;
			}
			if (fightmisss == true)
			{
				if (textnum2 == 0)textnum2 = 21;
				if (textnum2 == 22)textnum2 = 23;
				if (textnum2 == 24)textnum2 = 25;
				if (textnum2 == 26)textnum2 = 27;
				if (textnum2 == 28)textnum2 = 29;


				if (textnum3 == 30)textnum3 = 31;
				if (textnum3 == 32)textnum3 = 33;
				if (textnum3 == 34)textnum3 = 35;
				pttcos = true;
				fightmisss = false;
				interimclosings = false;
			}
			if (mercychoices == true)
			{

				if (textnum2 == 0)textnum2 = 21;
				if (textnum2 == 22)textnum2 = 23;
				if (textnum2 == 24)textnum2 = 25;
				if (textnum2 == 26)textnum2 = 27;
				if (textnum2 == 28)textnum2 = 29;


				if (textnum3 == 30)textnum3 = 31;
				if (textnum3 == 32)textnum3 = 33;
				if (textnum3 == 34)textnum3 = 35;


				mercychoices = false;
				pttcos = true;
				interimclosings = false;
			}
			if (actchoices == true)
			{
				if (textnum2 == 0)textnum2 = 21;
				if (textnum2 == 22)textnum2 = 23;
				if (textnum2 == 24)textnum2 = 25;
				if (textnum2 == 26)textnum2 = 27;
				if (textnum2 == 28)textnum2 = 29;

				actchoices = false;
				pttcos = true;
				interimclosings = false;

				if (praise == true)
				{
					if (praisecount == 1)
					{
						textnum4 = 51;
						textnum5 = 61;
					}
				}
			}
		}
	}
	
}

void stage15battle::closing()
{
	fcount7 = 0;
	gagef->setFrameX(0);
	fcount2 = 0;
	te = 0;
	te2 = 284;
	rhd = 11;
	epa = 0;
	hpx2 = hpx;
	fcount6 = 0;
	att = 0;
	fcount5 = 0;
	stickx = 28;
	praise = false;
	textlast = false;
	next = 0;
	resetbulls = true;
	plays = false;
	bttbs = false;
	if (rlqns1)rlqns2 = true;
	if (bttbf->getFrameX() == 0)
	{
		if (mercy->getFrameX() == 2)mercy->setFrameX(0);
		if (fight->getFrameX() == 2)fight->setFrameX(0);
		if (act->getFrameX() == 2)act->setFrameX(0);
		if (item->getFrameX() == 2)item->setFrameX(0);


		textnum = textnum2;
		start = true;
		closings = false;
	}
	if (textnum2 == 21)textnum2 = 22;
	if (textnum2 == 23)textnum2 = 24;
	if (textnum2 == 25)textnum2 = 26;
	if (textnum2 == 27)textnum2 = 28;
	if (textnum2 == 29)textnum2 = 22;

	if (textnum3 == 31)textnum3 = 32;
	if (textnum3 == 33)textnum3 = 34;
	if (textnum3 == 35)textnum3 = 30;
}

void stage15battle::tlstk()
{
	tlscount++;
	if (tlscount % 10 == 0)tlsindex++;
	if (tlsindex > 104)tlsindex = 103;

	if (tlsindex == 1)IMAGEMANAGER->findImage("tls1")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 2)IMAGEMANAGER->findImage("tls2")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 3)IMAGEMANAGER->findImage("tls3")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 4)IMAGEMANAGER->findImage("tls4")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 5)IMAGEMANAGER->findImage("tls5")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 6)IMAGEMANAGER->findImage("tls6")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 7)IMAGEMANAGER->findImage("tls7")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 8)IMAGEMANAGER->findImage("tls8")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 9)IMAGEMANAGER->findImage("tls9")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 10)IMAGEMANAGER->findImage("tls10")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 11)IMAGEMANAGER->findImage("tls11")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 12)IMAGEMANAGER->findImage("tls12")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 13)IMAGEMANAGER->findImage("tls13")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 14)IMAGEMANAGER->findImage("tls14")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 15)IMAGEMANAGER->findImage("tls15")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 16)IMAGEMANAGER->findImage("tls16")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 17)IMAGEMANAGER->findImage("tls17")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 18)IMAGEMANAGER->findImage("tls18")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 19)IMAGEMANAGER->findImage("tls19")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 20)IMAGEMANAGER->findImage("tls20")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 21)IMAGEMANAGER->findImage("tls21")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 22)IMAGEMANAGER->findImage("tls22")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 23)IMAGEMANAGER->findImage("tls23")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 24)IMAGEMANAGER->findImage("tls24")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 25)IMAGEMANAGER->findImage("tls25")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 26)IMAGEMANAGER->findImage("tls26")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 27)IMAGEMANAGER->findImage("tls27")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 28)IMAGEMANAGER->findImage("tls28")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 29)IMAGEMANAGER->findImage("tls29")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 30)IMAGEMANAGER->findImage("tls30")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 31)IMAGEMANAGER->findImage("tls31")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 32)IMAGEMANAGER->findImage("tls32")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 33)IMAGEMANAGER->findImage("tls33")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 34)IMAGEMANAGER->findImage("tls34")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 35)IMAGEMANAGER->findImage("tls35")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 36)IMAGEMANAGER->findImage("tls36")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 37)IMAGEMANAGER->findImage("tls37")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 38)IMAGEMANAGER->findImage("tls38")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 39)IMAGEMANAGER->findImage("tls39")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 40)IMAGEMANAGER->findImage("tls40")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 41)IMAGEMANAGER->findImage("tls41")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 42)IMAGEMANAGER->findImage("tls42")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 43)IMAGEMANAGER->findImage("tls43")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 44)IMAGEMANAGER->findImage("tls44")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 45)IMAGEMANAGER->findImage("tls45")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 46)IMAGEMANAGER->findImage("tls46")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 47)IMAGEMANAGER->findImage("tls47")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 48)IMAGEMANAGER->findImage("tls48")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 49)IMAGEMANAGER->findImage("tls49")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 50)IMAGEMANAGER->findImage("tls50")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 51)IMAGEMANAGER->findImage("tls51")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 52)IMAGEMANAGER->findImage("tls52")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 53)IMAGEMANAGER->findImage("tls53")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 54)IMAGEMANAGER->findImage("tls54")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 55)IMAGEMANAGER->findImage("tls55")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 56)IMAGEMANAGER->findImage("tls56")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 57)IMAGEMANAGER->findImage("tls57")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 58)IMAGEMANAGER->findImage("tls58")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 59)IMAGEMANAGER->findImage("tls59")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 60)IMAGEMANAGER->findImage("tls60")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 61)IMAGEMANAGER->findImage("tls61")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 62)IMAGEMANAGER->findImage("tls62")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 63)IMAGEMANAGER->findImage("tls63")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 64)IMAGEMANAGER->findImage("tls64")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 65)IMAGEMANAGER->findImage("tls65")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 66)IMAGEMANAGER->findImage("tls66")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 67)IMAGEMANAGER->findImage("tls67")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 68)IMAGEMANAGER->findImage("tls68")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 69)IMAGEMANAGER->findImage("tls69")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 70)IMAGEMANAGER->findImage("tls70")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 71)IMAGEMANAGER->findImage("tls71")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 72)IMAGEMANAGER->findImage("tls72")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 73)IMAGEMANAGER->findImage("tls73")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 74)IMAGEMANAGER->findImage("tls74")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 75)IMAGEMANAGER->findImage("tls75")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 76)IMAGEMANAGER->findImage("tls76")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 77)IMAGEMANAGER->findImage("tls77")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 78)IMAGEMANAGER->findImage("tls78")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 79)IMAGEMANAGER->findImage("tls79")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 80)IMAGEMANAGER->findImage("tls80")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 81)IMAGEMANAGER->findImage("tls81")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 82)IMAGEMANAGER->findImage("tls82")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 83)IMAGEMANAGER->findImage("tls83")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 84)IMAGEMANAGER->findImage("tls84")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 85)IMAGEMANAGER->findImage("tls85")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 86)IMAGEMANAGER->findImage("tls86")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 87)IMAGEMANAGER->findImage("tls87")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 88)IMAGEMANAGER->findImage("tls88")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 89)IMAGEMANAGER->findImage("tls89")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 90)IMAGEMANAGER->findImage("tls90")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 91)IMAGEMANAGER->findImage("tls91")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 92)IMAGEMANAGER->findImage("tls92")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 93)IMAGEMANAGER->findImage("tls93")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 94)IMAGEMANAGER->findImage("tls94")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 95)IMAGEMANAGER->findImage("tls95")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 96)IMAGEMANAGER->findImage("tls96")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 97)IMAGEMANAGER->findImage("tls97")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 98)IMAGEMANAGER->findImage("tls98")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 99)IMAGEMANAGER->findImage("tls99")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 100)IMAGEMANAGER->findImage("tls100")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 101)IMAGEMANAGER->findImage("tls101")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 102)IMAGEMANAGER->findImage("tls102")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 103)IMAGEMANAGER->findImage("tls103")->frameRender(getMemDC(), 214, -1);
	if (tlsindex == 104)IMAGEMANAGER->findImage("tls104")->frameRender(getMemDC(), 214, -1);





}



void stage15battle::TextControlUpdate()
{
	tcount++;
	if (tcount % 3 == 0)
	{
		if (textnum == 0)
		{
			if (tindex < 24)
				tindex++;
		}
		if (textnum == 2)
		{
			tindex = 99;
		}
		if (textnum == 3)
		{
			tindex = 99;
		}
		if (textnum == 4)
		{
			tindex = 99;
		}
		if (textnum == 5)
		{
			if (tindex < 83)
				tindex++;
		}
		if (textnum == 7)
		{
			if (tindex < 48)
				tindex++;
		}
		if (textnum == 22)
		{
			if (tindex < 49)
				tindex++;
		}
		if (textnum == 24)
		{
			if (tindex < 99)
				tindex++;
		}
		if (textnum == 26)
		{
			if (tindex < 99)
				tindex++;
		}
		if (textnum == 28)
		{
			if (tindex < 99)
				tindex++;
		}
		if (textnum == 32)
		{
			if (tindex < 20)
				tindex++;
			if (tindex > 19)textlast = true;
		}
		if (textnum == 30)
		{
			if (tindex < 14)
				tindex++;
			if (tindex > 12)textlast = true;
		}
		if (textnum == 34)
		{
			if (tindex < 20)
				tindex++;
			if (tindex > 19)textlast = true;
		}
		if (textnum == 41)
		{
			if (tindex < 21)
				tindex++;
		}
		if (textnum == 43)
		{
			if (tindex < 14)
				tindex++;
		}
		if (textnum == 45)
		{
			if (tindex < 16)
				tindex++;
		}
		if (textnum == 46)
		{
			if (tindex < 63)
				tindex++;
		}
		if (textnum == 47)
		{
			if (tindex < 99)
				tindex++;
		}
		if (textnum == 50)
		{
			if (tindex < 44)
				tindex++;
			if (tindex > 43)textlast = true;
		}
		if (textnum == 51)
		{
			if (tindex < 46)
				tindex++;
			if (tindex > 45)textlast = true;
		}
		if (textnum == 52)
		{
			if (tindex < 52)
				tindex++;
			if (tindex > 51)textlast = true;
		}
		if (textnum == 60)
		{
			if (tindex < 8)
				tindex++;
			if (tindex > 7)textlast = true;
		}
		if (textnum == 61)
		{
			if (tindex < 12)
				tindex++;
			if (tindex > 11)textlast = true;
		}
		if (textnum == 62)
		{
			if (tindex < 16)
				tindex++;
			if (tindex > 15)textlast = true;
		}
		if (textnum == 63)
		{
			if (tindex < 24)
				tindex++;
			if (tindex > 23)textlast = true;
		}
		if (textnum == 64)
		{
			if (tindex < 16)
				tindex++;
			if (tindex > 15)textlast = true;
		}
		if (textnum == 65)
		{
			if (tindex < 13)
				tindex++;
			if (tindex > 12)textlast = true;
		}
		if (textnum == 66)
		{
			if (tindex < 16)
				tindex++;
			if (tindex > 15)textlast = true;
		}
		if (textnum == 70)
		{
			if (tindex < 43)
				tindex++;
			if (tindex > 42)textlast = true;
		}
		if (textnum == 71)
		{
			if (tindex < 34)
				tindex++;
			if (tindex > 33)textlast = true;
		}
		if (textnum == 72)
		{
			if (tindex < 46)
				tindex++;
			if (tindex > 45)textlast = true;
		}
		if (textnum == 73)
		{
			if (tindex < 32)
				tindex++;
			if (tindex > 31)textlast = true;
		}
		if (textnum == 74)
		{
			if (tindex < 30)
				tindex++;
			if (tindex > 29)textlast = true;
		}
		if (textnum == 75)
		{
			if (tindex < 10)
				tindex++;
			if (tindex > 9)textlast = true;
		}
		if (textnum == 76)
		{
			if (tindex < 32)
				tindex++;
			if (tindex > 31)textlast = true;
		}
	}
	

	
}
void stage15battle::vlxks()
	{
		vlxkscount++;
		if (vlxkss)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_bullet[i].lefts == false && _bullet[i].ups == false && _bullet[i].rights == false && _bullet[i].downs == false)
				{
					if (_bullet[i].fires == true)
					{
						if (IntersectRect(&vlxksr, &plh, &_bullet[i].rctpfh))
						{
							vlxkss = false;
							vlxkscount = 0;
							_player->getPlayer()->CurHp -= 3;
							SOUNDMANAGER->play("playerhit", 1.f);
						}
					}
				}
				if (_bullet[i].lefts == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet[i].rcrkfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet[i].ups == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet[i].rctpfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet[i].rights == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet[i].rcrkfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet[i].downs == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet[i].rctpfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet2[i].lefts == false && _bullet2[i].ups == false && _bullet2[i].rights == false && _bullet2[i].downs == false)
				{
					if (_bullet2[i].fires == true)
					{
						if (IntersectRect(&vlxksr, &plh, &_bullet2[i].rctpfh))
						{
							vlxkss = false;
							vlxkscount = 0;
							_player->getPlayer()->CurHp -= 3;
							SOUNDMANAGER->play("playerhit", 1.f);
						}
					}
				}
				if (_bullet2[i].rights == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet2[i].rcrkfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet2[i].ups == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet2[i].rctpfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet2[i].lefts == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet2[i].rcrkfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				if (_bullet2[i].downs == true)
				{
					if (IntersectRect(&vlxksr, &plh, &_bullet2[i].rctpfh))
					{
						vlxkss = false;
						vlxkscount = 0;
						_player->getPlayer()->CurHp -= 3;
						SOUNDMANAGER->play("playerhit", 1.f);
					}
				}
				
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[0].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[1].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[2].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[3].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[4].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[5].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[6].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[7].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[8].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[9].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[10].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[11].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet3[12].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[0].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[1].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[2].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[3].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[4].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[5].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[6].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[7].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[8].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[9].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[10].rcbullla))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[11].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}
			if (IntersectRect(&vlxksr, &plh, &_bullet4[12].rcbullsm))
			{
				vlxkss = false;
				vlxkscount = 0;
				_player->getPlayer()->CurHp -= 3;
				SOUNDMANAGER->play("playerhit", 1.f);
			}

		}

		if (vlxkscount > 70)vlxkss = true;

		

	}
