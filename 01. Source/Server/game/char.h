/*--------------------------------------------------*/
/*Search:
	//POINT_MAX_NUM =

Add BEFORE:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	POINT_CHEQUE = 145, // Check if "145" is not been used for other
#endif
/*--------------------------------------------------*/
/*Search:
	long			gold;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int				cheque;
#endif
/*--------------------------------------------------*/
/*Search:
		void			GiveGold(INT iAmount);	// 파티가 있으면 파티 분배, 로그 등의 처리

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		INT				GetCheque() const		{ return m_points.cheque;	}
		void			SetCheque(int cheque)	{ m_points.cheque = cheque;	}
		void			GiveCheque(INT iAmount);
		bool			DropCheque(INT gold);
#endif
/*--------------------------------------------------*/
/*--------------------------------------------------*/
/*--------------------------------------------------*/
/*Search:
} TPrivShop;

Add BEFORE:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	DWORD cheque;
#endif
/*--------------------------------------------------*/