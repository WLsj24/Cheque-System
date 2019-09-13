# ********************************************************************** #
#Search:
					self.tooltipItem.AppendSellingPrice(it["price"])

#Add BEFORE:
					if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
						self.tooltipItem.AppendSellingCheque2(it["cheque"])
# ********************************************************************** #
#Search in def AcceptInputPrice(self):
		price = int(self.priceInputBoard.GetText())

#Add after:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			cheque = int(self.priceInputBoard.GetTextCheque())
# ********************************************************************** #
#Search:
		self.items[int(targetSlotPos)]={
			"vnum":int(vnum),
			"count":int(count),
			"price":int(price),
			"sourceSlot":sourceSlotPos,
			"sourceWindow":attachedInvenType
		}

#Replace with:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			self.items[int(targetSlotPos)]={
				"vnum":int(vnum),
				"count":int(count),
				"price":int(price),
				"cheque":int(cheque),
				"sourceSlot":sourceSlotPos,
				"sourceWindow":attachedInvenType
			}
		else:
			self.items[int(targetSlotPos)]={
				"vnum":int(vnum),
				"count":int(count),
				"price":int(price),
				"sourceSlot":sourceSlotPos,
				"sourceWindow":attachedInvenType
			}
# ********************************************************************** #
#Search:
		net.SendChatPacket("/update_shop_item add|%d|%d|%d|%d|%s"%(int(self.id),int(targetSlotPos),int(sourceSlotPos),int(attachedInvenType),str(price)))

#Replace with:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			net.SendChatPacket("/update_shop_item add|%d|%d|%d|%d|%s|%s"%(int(self.id),int(targetSlotPos),int(sourceSlotPos),int(attachedInvenType),str(price), str(cheque)))
		else:
			net.SendChatPacket("/update_shop_item add|%d|%d|%d|%d|%s"%(int(self.id),int(targetSlotPos),int(sourceSlotPos),int(attachedInvenType),str(price)))
# ********************************************************************** #
#Search in def AcceptEditPrice(self)::
		price = int(self.priceInputBoard.GetText())

#Add after:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			cheque = int(self.priceInputBoard.GetTextCheque())
# ********************************************************************** #
#Search:
		self.items[int(targetSlotPos)]["price"]=price

#Add after:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			self.items[int(targetSlotPos)]["cheque"]=cheque
# ********************************************************************** #
#Search:
		net.SendChatPacket("/update_shop_item price|"+str(self.id)+"|"+str(self.items[int(targetSlotPos)]["id"])+"|"+str(price))

#Replace with:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			net.SendChatPacket("/update_shop_item price|"+str(self.id)+"|"+str(self.items[int(targetSlotPos)]["id"])+"|"+str(price)+"|"+str(cheque))
		else:
			net.SendChatPacket("/update_shop_item price|"+str(self.id)+"|"+str(self.items[int(targetSlotPos)]["id"])+"|"+str(price))
# ********************************************************************** #
#Search:
		self.AddEditOption("get_yang",uiScriptLocale.SHOP_GET_YANG,lambda arg1=data: self.GetShopYang(arg1))

#Add after:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			self.AddEditOption("get_cheque",uiScriptLocale.SHOP_GET_CHEQUE,lambda arg1=data: self.GetShopCheque(arg1))
# ********************************************************************** #
#Search:
	def OnGetYang(self,id):
		self.__OnClosePopupDialog()
		net.SendChatPacket("/shop_yang %d" %(int(id)))

#Add after:
	if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
		def GetShopCheque(self,shop):
			if int(shop["cheque"]) <=0:
				self.PopupMessage(uiScriptLocale.SHOP_NOT_EARNED_CHEQUE)
				return
			self.pop = uiCommon.QuestionDialog()
			self.pop.SetText(uiScriptLocale.SHOP_CHEQUE_QUEST%(localeInfo.NumberToCheque(shop["cheque"]),shop["name"]))
			self.pop.SetAcceptEvent(lambda arg1=str(shop["id"]): self.OnGetCheque(arg1))
			self.pop.SetCancelEvent(ui.__mem_func__(self.__OnClosePopupDialog))
			self.pop.Open()

		def OnGetCheque(self,id):
			self.__OnClosePopupDialog()
			net.SendChatPacket("/shop_cheque %d" %(int(id)))
# ********************************************************************** #
#Search:
			self.tooltip.AutoAppendTextLine(uiScriptLocale.SHOP_EARNED_YANG+str(localeInfo.NumberToMoneyString((shop["gold"]))), POSITIVE_COLOR)
			self.tooltip.AppendSpace(5)

#Add after:
			if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
				self.tooltip.AutoAppendTextLine(uiScriptLocale.SHOP_EARNED_CHEQUE+str(localeInfo.NumberToCheque((shop["cheque"]))), POSITIVE_COLOR)
				self.tooltip.AppendSpace(5)
# ********************************************************************** #