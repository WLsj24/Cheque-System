/*--------------------------------------------------*/
/*Search:
		uint32_t elk;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		uint32_t cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	uint32_t GetElkFromSelf() const;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	void SetChequeToTarget(uint32_t cheque);
	void SetChequeToSelf(uint32_t cheque);

	uint32_t GetChequeFromTarget() const;
	uint32_t GetChequeFromSelf() const;
#endif
/*--------------------------------------------------*/