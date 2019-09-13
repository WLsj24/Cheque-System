# ********************************************************************** #
#Search:
	def OnPickMoney(self, money):
		chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.GAME_PICK_MONEY % (money))

#Add after:
	if app.ENABLE_CHEQUE_SYSTEM:
		def OnPickCheque(self, cheque):
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.GAME_PICK_CHEQUE % (cheque))
# ********************************************************************** #
#Search:
				if player.ITEM_MONEY == attachedItemIndex:
					self.__PutMoney(attachedType, attachedItemCount, self.PickingCharacterIndex)

#Add after:
				elif player.ITEM_CHEQUE == attachedItemIndex and app.ENABLE_CHEQUE_SYSTEM:
					self.__PutCheque(attachedType, attachedItemCount, self.PickingCharacterIndex)
# ********************************************************************** #
#Search:
	def __DropMoney(self, attachedType, attachedMoney):
		[...]

#Add after:
	if app.ENABLE_CHEQUE_SYSTEM:
		def __PutCheque(self, attachedType, attachedMoney, dstChrID):
			if True == chr.HasInstance(dstChrID) and player.GetMainCharacterIndex() != dstChrID:
				net.SendExchangeStartPacket(dstChrID)
				net.SendExchangeChequeAddPacket(attachedMoney)
			else:
				self.__DropCheque(attachedType, attachedMoney)

		def __DropCheque(self, attachedType, attachedMoney):
			# PRIVATESHOP_DISABLE_ITEM_DROP - 개인상점 열고 있는 동안 아이템 버림 방지
			if uiPrivateShopBuilder.IsBuildingPrivateShop():
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.DROP_ITEM_FAILURE_PRIVATE_SHOP)
				return
			# END_OF_PRIVATESHOP_DISABLE_ITEM_DROP
			
			if attachedMoney>=1000:
				self.stream.popupWindow.Close()
				self.stream.popupWindow.Open(localeInfo.DROP_CHEQUE_FAILURE_1000_OVER, 0, localeInfo.UI_OK)
				return

			itemDropQuestionDialog = uiCommon.QuestionDialog()
			itemDropQuestionDialog.SetText(localeInfo.DO_YOU_DROP_CHEQUE % (attachedMoney))
			itemDropQuestionDialog.SetAcceptEvent(lambda arg=True: self.RequestDropItem(arg))
			itemDropQuestionDialog.SetCancelEvent(lambda arg=False: self.RequestDropItem(arg))
			itemDropQuestionDialog.Open()
			itemDropQuestionDialog.dropType = attachedType
			itemDropQuestionDialog.dropCount = attachedMoney
			itemDropQuestionDialog.dropNumber = player.ITEM_CHEQUE
			self.itemDropQuestionDialog = itemDropQuestionDialog
# ********************************************************************** #
#Search:
				if dropNumber == player.ITEM_MONEY:
					net.SendGoldDropPacketNew(dropCount)
					snd.PlaySound("sound/ui/money.wav")

#Add after:
				elif app.ENABLE_CHEQUE_SYSTEM and dropNumber == player.ITEM_CHEQUE:
					net.SendGoldChequePacketNew(dropCount)
					snd.PlaySound("sound/ui/money.wav")
# ********************************************************************** #
#Search:
					if dropNumber == player.ITEM_MONEY:
						return

#Add after:
					elif app.ENABLE_CHEQUE_SYSTEM and dropNumber == player.ITEM_CHEQUE:
						return
# ********************************************************************** #
# ********************************************************************** #
# ********************************************************************** #
#Search:
		def ShopAdd(self,shop_id,shop_vid,szSign,gold,count,sold,days,date_close):
			if self.uiNewShop:
				shop={
					"id":shop_id,
					"vid":shop_vid,
					"name":szSign.replace("\\"," ").replace("_","#"),
					"gold":gold,
					"sold":sold,
					"items":int(count)-int(sold),
					"days":days,
					"time":date_close
				}
				self.uiNewShop.Load(shop)
				constInfo.MyShops.append(shop)

#Replace with:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			def ShopAdd(self,shop_id,shop_vid,szSign,gold,count,sold,days,date_close,cheque):
				if self.uiNewShop:
					shop={
						"id":shop_id,
						"vid":shop_vid,
						"name":szSign.replace("\\"," ").replace("_","#"),
						"gold":gold,
						"sold":sold,
						"items":int(count)-int(sold),
						"days":days,
						"time":date_close,
						"cheque":cheque
					}
					self.uiNewShop.Load(shop)
					constInfo.MyShops.append(shop)
		else:
			def ShopAdd(self,shop_id,shop_vid,szSign,gold,count,sold,days,date_close):
				if self.uiNewShop:
					shop={
						"id":shop_id,
						"vid":shop_vid,
						"name":szSign.replace("\\"," ").replace("_","#"),
						"gold":gold,
						"sold":sold,
						"items":int(count)-int(sold),
						"days":days,
						"time":date_close
					}
					self.uiNewShop.Load(shop)
					constInfo.MyShops.append(shop)
# ********************************************************************** #
#Search:
		def ShopItem(self,data):
			d=data.split("#")
			id=d[0]
			vnum=d[1]
			count=d[2]
			slot=d[3]
			price=d[4]
			s=d[5]
			a=d[6]
			sockets=[]
			for key in s.split("|"):
				sockets.append(int(key))
			attrs=[]
			for key in a.split("|"):
				a=key.split(",")
				attrs.append([int(a[0]),int(a[1])])
			if self.uiNewShop:
				self.uiNewShop.AddItem(slot,{"id":id,"vnum":vnum,"count":count,"price":price,"sockets":sockets,"attrs":attrs})

#Replace with:
		if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
			def ShopItem(self,data):
				d=data.split("#")
				id=d[0]
				vnum=d[1]
				count=d[2]
				slot=d[3]
				price=d[4]
				cheque=d[5]
				s=d[6]
				a=d[7]
				sockets=[]
				for key in s.split("|"):
					sockets.append(int(key))
			
				attrs=[]
				for key in a.split("|"):
					a=key.split(",")
					attrs.append([int(a[1]),int(a[0])])
				if self.uiNewShop:
					self.uiNewShop.AddItem(slot,{"id":id,"vnum":vnum,"count":count,"price":price,"cheque":cheque,"sockets":sockets,"attrs":attrs})
		else:
			def ShopItem(self,data):
				d=data.split("#")
				id=d[0]
				vnum=d[1]
				count=d[2]
				slot=d[3]
				price=d[4]
				s=d[5]
				a=d[6]
				sockets=[]
				for key in s.split("|"):
					sockets.append(int(key))
				attrs=[]
				for key in a.split("|"):
					a=key.split(",")
					attrs.append([int(a[0]),int(a[1])])
				if self.uiNewShop:
					self.uiNewShop.AddItem(slot,{"id":id,"vnum":vnum,"count":count,"price":price,"sockets":sockets,"attrs":attrs})
# ********************************************************************** #