/*--------------------------------------------------*/
/*Search:
ACMD(do_shop_yang);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
ACMD(do_shop_cheque);
#endif
/*--------------------------------------------------*/
/*Search:
	{ "shop_yang",			do_shop_yang,				0,			POS_DEAD,	GM_PLAYER	},

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	{ "shop_cheque",		do_shop_cheque,				0,			POS_DEAD,	GM_PLAYER	},
#endif
/*--------------------------------------------------*/