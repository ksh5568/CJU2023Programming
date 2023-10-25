#include <stdio.h>
#define G 9.81  // ì¤‘ë ¥ê°€ì†ë„ (ë‹¨ìœ„ : m/s^2)
#define H 100.00  // ì´ˆê¸° ë†’ì´ (ë‹¨ìœ„ : m)
#define KG 1  // ì¼€í‹€ë²¨ ë¬´ê²Œ (ë‹¨ìœ„ : kg)

int main(void)
{
<<<<<<< HEAD
	double nTIME = 0.0000;  // ½Ã°£¿¡ ´ëÇÑ º¯¼ö ¼³Á¤
	double nLAND = 0.0000;  //  Áö¸é ´ëÇÑ º¯¼ö ¼³Á¤
=======
	double nTIME = 0.0000;  // ì‹œê°„ì— ëŒ€í•œ ë³€ìˆ˜ ì„¤ì •
	double nLAND = 0.0000;  //  ì§€ë©´ ëŒ€í•œ ë³€ìˆ˜ ì„¤ì •
>>>>>>> 2e60f0666c1faa9fd7134a6d3e6ffb5bb922d81f

	printf("This is a program that calculates free fall motion.\n");  // ììœ ë‚™í•˜ ìš´ë™ì— ëŒ€í•œ í”„ë¡œê·¸ë¨ì´ë¼ëŠ” ê²ƒì„ ì¶œë ¥
	printf("When Youngsu lets a 1kg kettlebell fall freely from a height of 100m,\n");  // 1kg ì¼€í‹€ë²¨ì´ 100m ë†’ì´ì—ì„œ ë–¨ì–´ì§ˆ ë•Œë¥¼ ì¶œë ¥
	printf("how long does it take for it to reach the ground?\n");  // ì§€ë©´ì— ë„ë‹¬í•˜ê¸°ê¹Œì§€ ê±¸ë¦¬ëŠ” ì‹œê°„ì€ ì–¼ë§ˆì¸ê°€ë¥¼ ì¶œë ¥

	do
	{
<<<<<<< HEAD
		nLAND = H - 0.5 * G * (nTIME * nTIME);  // ÀÚÀ¯³«ÇÏ¿îµ¿ °ø½Ä
		nTIME = nTIME + 0.0001;  // ¹İº¹ µÉ¶§ 0.0001s ¾¿ Áõ°¡

	} while (nLAND > 0.0);  // Áö¸éº¸´Ù ³ôÀ¸¸é °è¼ÓÇÏ¿© ¿¬»ê

=======
		nLAND = H - 0.5 * G * (nTIME * nTIME);  // ììœ ë‚™í•˜ìš´ë™ ê³µì‹
		nTIME = nTIME + 0.0001;  // ë°˜ë³µ ë ë•Œ 0.0001s ì”© ì¦ê°€

	} while (nLAND > 0.0);  // ì§€ë©´ë³´ë‹¤ ë†’ìœ¼ë©´ ê³„ì†í•˜ì—¬ ì—°ì‚°
	
>>>>>>> 2e60f0666c1faa9fd7134a6d3e6ffb5bb922d81f
	printf("\n");
	printf("Time : %.3lf s\n", nTIME);  // ê²°ê³¼ê°’ ì¶œë ¥
}
