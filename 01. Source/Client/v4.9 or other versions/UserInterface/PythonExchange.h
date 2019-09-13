/*--------------------------------------------------*/
/*Search:
			DWORD					elk;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			DWORD					cheque;
#endif
/*--------------------------------------------------*/
/*Search:
		DWORD			GetElkFromSelf();

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		void			SetChequeToTarget(DWORD cheque);
		void			SetChequeToSelf(DWORD cheque);

		DWORD			GetChequeFromTarget();
		DWORD			GetChequeFromSelf();
#endif
/*--------------------------------------------------*/