/*--------------------------------------------------*/
/*Search:
PyObject * exchangeGetElkFromTarget(PyObject * poSelf, PyObject * poArgs)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * exchangeGetChequeFromSelf(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonExchange::Instance().GetChequeFromSelf());
}

PyObject * exchangeGetChequeFromTarget(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonExchange::Instance().GetChequeFromTarget());
}
#endif
/*--------------------------------------------------*/
/*Search:
		{"GetElkFromTarget",			exchangeGetElkFromTarget,			METH_VARARGS},

Add after:
*/

#ifdef ENABLE_CHEQUE_SYSTEM
		{"GetChequeFromSelf",			exchangeGetChequeFromSelf,			METH_VARARGS},
		{"GetChequeFromTarget",			exchangeGetChequeFromTarget,		METH_VARARGS},
#endif
/*--------------------------------------------------*/