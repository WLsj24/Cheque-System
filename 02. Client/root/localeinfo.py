# ********************************************************************** #
#Search:
LOGIN_FAILURE_SHUTDOWN_TIME = "ASDF"

#Add after:
if app.ENABLE_CHEQUE_SYSTEM:
	def NumberToGold(n) :
		if n <= 0 :
			return "0 %s" % (MONETARY_UNIT0)

		return "%s %s" % ('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]), MONETARY_UNIT0)

	def NumberToGoldNotText(n) :
		if n <= 0 :
			return "0 %s" % ("")

		return "%s%s" % ('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]), "")

	def NumberToCheque(n) :
		if n <= 0 :
			return "0 %s" % (CHEQUE_SYSTEM_UNIT_CHEQUE)

		return "%s %s" % ('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]), CHEQUE_SYSTEM_UNIT_CHEQUE) 

	def DO_YOU_BUY_ITEM_YANG_CHEQUE(buyItemName, buyItemCount, buyItemPrice, buyItemCheque) :
		if buyItemCount > 1 :
			return DO_YOU_BUY_ITEM2_CHEQUE % ( buyItemName, buyItemCount, buyItemCheque, buyItemPrice)
		else:
			return DO_YOU_BUY_ITEM1_CHEQUE % ( buyItemName, buyItemCheque, buyItemPrice)

	def DO_YOU_BUY_ITEM_CHEQUE_SIN_YANG(buyItemName, buyItemCount, buyItemCheque) :
		if buyItemCount > 1 :
			return DO_YOU_BUY_ITEM2_CHEQUE1 % ( buyItemName, buyItemCount, buyItemCheque)
		else:
			return DO_YOU_BUY_ITEM1_CHEQUE1 % ( buyItemName, buyItemCheque)
# ********************************************************************** #
#Search:
SHOP_ERROR_DICT = {
	[...]
}

#Add after:
if app.ENABLE_CHEQUE_SYSTEM:
	SHOP_ERROR_DICT["NOT_ENOUGH_CHEQUE"] = SHOP_NOT_ENOUGH_CHEQUE
	SHOP_ERROR_DICT["NOT_ENOUGH_MONEY_CHEQUE"] = SHOP_NOT_ENOUGH_MONEY_CHEQUE
# ********************************************************************** #