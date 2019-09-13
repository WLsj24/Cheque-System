/*--------------------------------------------------*/
/*Search:
			long	price;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			int		cheque;
#endif
/*--------------------------------------------------*/
/*Search:
				price = 0;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
				cheque = 0;
#endif
/*--------------------------------------------------*/