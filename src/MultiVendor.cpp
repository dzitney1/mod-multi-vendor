/*
 *MIT License
 *
 *Copyright (c) 2022 Azerothcore & WoWHellgarve
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 * Multi-Vendor Module
 * Original Module From WoWHellgarve 
 * Written for Azerothcore & WoWHellgarve 335 By Developer HolyDEEW
 * Modified for Azerothcore
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"


/*-- DATA NPC_TEMPLATE
SET
@NpcEntry 		:= 666666
@NpcName		:= "Multi-Vendor"
@NpcSubname		:= "WoWHellgarve Vendor"
@NpcDisplayID   := 1298
*/

// trade_goods_enchants-------------------------------------

#define GOSSIP_TEXT_BROWSE_ENCHANT_HEAD "|TInterface/ICONS/inv_helm_armor_cenarion_c_01:24:24:-18|t[Let me browse your Head Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_NECK "|TInterface/ICONS/inv_jewelry_necklace_98:24:24:-18|t[Let me browse your Neck Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_SHOULDER "|TInterface/ICONS/inv_shoulder_17:24:24:-18|t[Let me browse your Shoulder Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_CLOAK "|TInterface/ICONS/spell_shadow_nethercloak:24:24:-18|t[Let me browse your CLOAK Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_CHEST "|TInterface/ICONS/inv_chest_plate03:24:24:-18|t[Let me browse your Chest Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_WRIST "|TInterface/ICONS/inv_misc_desecrated_clothbracer:24:24:-18|t[Let me browse your Wrist Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_HANDS "|TInterface/ICONS/inv_glove_mail_bastion_d_01:24:24:-18|t[Let me browse your Hand Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_LEGS "|TInterface/ICONS/inv_pant_leather_legiondungeon_c_03:24:24:-18|t[Let me browse your Leg Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_FEET "|TInterface/ICONS/inv_boots_plate_pvpwarrior_c_02:24:24:-18|t[Let me browse your Feet Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_RING "|TInterface/ICONS/inv_jewelry_ring_21:24:24:-18|t[Let me browse your Ring Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_WEAPON "|TInterface/ICONS/inv_mace_1h_demonweapon_c_01:24:24:-18|t[Let me browse your Weapon Weapon Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_SHIELD "|TInterface/ICONS/inv_shield_13:24:24:-18|t[Let me browse your Shield Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_2H_WEAPON "|TInterface/ICONS/inv_staff_01:24:24:-18|t[Let me browse your 2H Weapon Enchants]"
#define GOSSIP_TEXT_BROWSE_ENCHANT_OFFHAND "|TInterface/ICONS/inv_misc_orb_04:24:24:-18|t[Let me browse your Offhand Enchants]"

//npc_vendor database
enum shop_list_id
{
    VENDOR_ENCHANT_HEAD_LIST = 6666666,
    VENDOR_ENCHANT_NECK_LIST = 6666667,
    VENDOR_ENCHANT_SHOULDER_LIST = 6666668,
    VENDOR_ENCHANT_CLOAK_LIST = 6666669,
    VENDOR_ENCHANT_CHEST_LIST = 6666670,
    VENDOR_ENCHANT_WRIST_LIST = 6666671,
    VENDOR_ENCHANT_HANDS_LIST = 6666672,
    VENDOR_ENCHANT_LEGS_LIST = 6666673,
    VENDOR_ENCHANT_FEET_LIST = 6666674,
    VENDOR_ENCHANT_RING_LIST = 6666675,
    VENDOR_ENCHANT_WEAPON_LIST = 6666676,
    VENDOR_ENCHANT_SHIELD_LIST = 6666677,
    VENDOR_ENCHANT_2H_WEAPON_LIST = 6666678,
    VENDOR_ENCHANT_OFFHAND_LIST = 6666679,

};


/***********************/
/*NPC_SCRIPTS *********/
/**********************/

class npc_enchant_vendor : public CreatureScript
{
public:
    npc_enchant_vendor() : CreatureScript("npc_enchant_vendor") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    { 
        if (creature->IsVendor())
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_HEAD, GOSSIP_ACTION_TRADE, 1);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_NECK, GOSSIP_ACTION_TRADE, 2);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_SHOULDER, GOSSIP_ACTION_TRADE, 3);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_CLOAK, GOSSIP_ACTION_TRADE, 4);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_CHEST, GOSSIP_ACTION_TRADE, 5);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_WRIST, GOSSIP_ACTION_TRADE, 6);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_HANDS, GOSSIP_ACTION_TRADE, 7);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_LEGS, GOSSIP_ACTION_TRADE, 8);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_FEET, GOSSIP_ACTION_TRADE, 9);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_RING, GOSSIP_ACTION_TRADE, 10);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_WEAPON, GOSSIP_ACTION_TRADE, 11);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_SHIELD, GOSSIP_ACTION_TRADE, 12);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_2H_WEAPON, GOSSIP_ACTION_TRADE, 13);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ENCHANT_OFFHAND, GOSSIP_ACTION_TRADE, 14);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case 1: // Head
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_HEAD_LIST);
            }            
            break;
        case 2: // Neck
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_NECK_LIST);
            }
            break;
        case 3: // Shoulder
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_SHOULDER_LIST);
            }
            break;
        case 4: // CLOAK
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_CLOAK_LIST);
            }
            break;
        case 5: // Chest
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_CHEST_LIST);
            }
            break;
        case 6: // Wrist
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_WRIST_LIST);
            }
            break;
        case 7: // Hands
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_HANDS_LIST);
            }
            break;
        case 8: // Legs
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_LEGS_LIST);
            }
            break;
        case 9: // Feet
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_FEET_LIST);
            }
            break;
        case 10: // Ring
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_RING_LIST);
            }
            break;
        case 11: // Weapon
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_WEAPON_LIST);
            }
            break;
        case 12: // Shield
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_SHIELD_LIST);
            }
            break;
        case 13: // 2H Weapon
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_2H_WEAPON_LIST);
            }
            break;
        case 14: // Offhand
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ENCHANT_OFFHAND_LIST);
            }
            break;
        }
        return true;
    }
};


void AddMultiVendor_scripts()
{
    new npc_enchant_vendor();
}
