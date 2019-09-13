/*--------------------------------------------------*/
/* WARNING:
Maybe ENABLE_OFFLINE_SHOP is different in your source
This is only compatible with Great-OfflineShop
*/
/*--------------------------------------------------*/
/*Add:*/
#define ENABLE_CHEQUE_SYSTEM
#if defined(ENABLE_OFFLINE_SHOP) && defined(ENABLE_CHEQUE_SYSTEM)
#	define ENABLE_OFFLINE_SHOP_USE_CHEQUE
#endif
/*--------------------------------------------------*/