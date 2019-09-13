# ********************************************************************** #
#Search:
				self.AppendSellingPrice(player.GetISellItemPrice(window_type, slotIndex))

#Replace with:
				if app.ENABLE_CHEQUE_SYSTEM:
					self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_SELL_PRICE, grp.GenerateColor(1.0, 0.9686, 0.3098, 1.0))
					if player.GetISellItemPrice(window_type, slotIndex) == 0:
						if item.IsAntiFlag(item.ITEM_ANTIFLAG_SELL):
							self.AppendTextLine(localeInfo.TOOLTIP_ANTI_SELL, self.DISABLE_COLOR)
							self.AppendSpace(5)
						else:
							self.AppendTextLine("0 Yang")
					else:
						self.AppendSellingPrice(player.GetISellItemPrice(window_type, slotIndex))
				else:
					self.AppendSellingPrice(player.GetISellItemPrice(window_type, slotIndex))
# ********************************************************************** #
#Search in:
	def SetShopItem(self, slotIndex):

#This:
		price = shop.GetItemPrice(slotIndex)

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			cheque = shop.GetItemCheque(slotIndex)
# ********************************************************************** #
#Search in:
	def SetShopItem(self, slotIndex):

#This:
		self.AppendPrice(price)

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_SELL_PRICE, grp.GenerateColor(1.0, 0.9686, 0.3098, 1.0))
			self.AppendCheque(cheque)
			if price == 0:
				self.AppendTextLine("0 Yang")
			else:
				self.AppendPrice(price)
		else:
			self.AppendPrice(price)
# ********************************************************************** #
#Search:
		self.AppendSellingPrice(shop.GetPrivateShopItemPrice(invenType, invenPos))

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_SELL_PRICE, grp.GenerateColor(1.0, 0.9686, 0.3098, 1.0))
			self.AppendSellingCheque(shop.GetPrivateShopItemCheque(invenType, invenPos))
			if shop.GetPrivateShopItemPrice(invenType, invenPos) == 0:
				self.AppendTextLine("0 Yang")
			else:
				self.AppendSellingPrice(shop.GetPrivateShopItemPrice(invenType, invenPos))
		else:
			self.AppendSellingPrice(shop.GetPrivateShopItemPrice(invenType, invenPos))
# ********************************************************************** #
#Search:
	def AppendPrice(self, price):
		self.AppendSpace(5)
		self.AppendTextLine(localeInfo.TOOLTIP_BUYPRICE  % (localeInfo.NumberToMoneyString(price)), self.GetPriceColor(price))

#Replace with:
	def AppendPrice(self, price):
		if app.ENABLE_CHEQUE_SYSTEM:
			if price <=0:
				return
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_YANG  % (localeInfo.NumberToMoneyString(price)), self.GetPriceColor(price))
			self.AppendSpace(5)
		else:
			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.TOOLTIP_BUYPRICE  % (localeInfo.NumberToMoneyString(price)), self.GetPriceColor(price))
# ********************************************************************** #
#Search:
	def AppendSellingPrice(self, price):
		if item.IsAntiFlag(item.ITEM_ANTIFLAG_SELL):
			self.AppendTextLine(localeInfo.TOOLTIP_ANTI_SELL, self.DISABLE_COLOR)
			self.AppendSpace(5)
		else:
			self.AppendTextLine(localeInfo.TOOLTIP_SELLPRICE % (localeInfo.NumberToMoneyString(price)), self.GetPriceColor(price))
			self.AppendSpace(5)

#Replace with:
	def AppendSellingPrice(self, price):
		if app.ENABLE_CHEQUE_SYSTEM:
			if price<=0:
				return
			if item.IsAntiFlag(item.ITEM_ANTIFLAG_SELL):
				self.AppendTextLine(localeInfo.TOOLTIP_ANTI_SELL, self.DISABLE_COLOR)
				self.AppendSpace(5)
			else:
				self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_YANG % (localeInfo.NumberToGold(price)), self.GetPriceColor(price))
				self.AppendSpace(5)
		else:
			if item.IsAntiFlag(item.ITEM_ANTIFLAG_SELL):
				self.AppendTextLine(localeInfo.TOOLTIP_ANTI_SELL, self.DISABLE_COLOR)
				self.AppendSpace(5)
			else:
				self.AppendTextLine(localeInfo.TOOLTIP_SELLPRICE % (localeInfo.NumberToMoneyString(price)), self.GetPriceColor(price))
				self.AppendSpace(5)

	if app.ENABLE_CHEQUE_SYSTEM:
		def AppendCheque(self, price):
			if price <=0:
				return
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_WON % (localeInfo.NumberToCheque(price)), grp.GenerateColor(0.0, 0.8470, 1.0, 1.0))

		def AppendSellingCheque(self, price):
			if price<=0:
				return
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_WON % (localeInfo.NumberToCheque(price)), grp.GenerateColor(0.0, 0.8470, 1.0, 1.0))

		def AppendSellingCheque2(self, price):
			if price<=0:
				return
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_SELL_PRICE, grp.GenerateColor(1.0, 0.9686, 0.3098, 1.0))
			self.AppendTextLine(localeInfo.CHEQUE_SYSTEM_WON % (localeInfo.NumberToCheque(price)), grp.GenerateColor(0.0, 0.8470, 1.0, 1.0))
# ********************************************************************** #