/*--------------------------------------------------*/
/*Search in the end of file:
}

Add BEFORE:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_CHEQUE_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_CHEQUE_SYSTEM", 0);
#endif

#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	PyModule_AddIntConstant(poModule, "ENABLE_OFFLINE_SHOP_USE_CHEQUE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_OFFLINE_SHOP_USE_CHEQUE", 0);
#endif

//If you havent add this, add too
#ifdef ENABLE_GEM_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_GEM_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GEM_SYSTEM", 0);
#endif

#ifdef ENABLE_NEW_EXCHANGE_WINDOW
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EXCHANGE_WINDOW", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EXCHANGE_WINDOW", 0);
#endif
/*--------------------------------------------------*/
